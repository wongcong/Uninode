#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutconfig.h"
#include "getinfo.h"
#include <windows.h>
#include <QString>
#include <QStringList>
#include <string>
#include <QLibrary>
#include <QMessageBox>
#include <QTimer>
#include <stdio.h>
#include <QProcess>


using namespace std;

//define some pointers of function
typedef void(*start)(char*,char*,char*,int);
typedef void(*stop)();
typedef char*(*read)();
typedef void(*exitdll)();
start start_auth_thread;
stop stop_auth_thread;
read read_log;
exitdll exit_dll;

//a timer for refresh the application
QTimer *timer;

QLibrary link("link2net.dll");



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_login->setFocus();
    ui->pushButton_login->setShortcut(Qt::Key_Enter);

    showDetail=false;

    //get adapter info
    GetInfo Info;
    adaptersDescription=Info.AdapterDescription;
    adaptersName=Info.AdapterName;
    //add info to combobox
    ui->comboBox->addItems(adaptersDescription);

    //link dll in constructor
    if(link.load())
    {
        start_auth_thread=(start)link.resolve("start_auth_thread");
        stop_auth_thread=(stop)link.resolve("stop_auth_thread");
        exit_dll=(exitdll)link.resolve("exit_dll");
        read_log=(read)link.resolve("read_log");
    }
    else
    {
        QMessageBox::warning(this,"Error","Can not find the dll!\nYou try reinstall winpcap.exe\nIf it doesn't work.\nPlease contact the developer.");
    }

    //read configration
    AboutConfig::checkConfig();
    if(AboutConfig::readConfig())
    {
        ui->comboBox->setCurrentIndex(AboutConfig::IndexOfAdapter);
        ui->lineEdit_userName->setText(AboutConfig::Username);
        ui->lineEdit_passWord->setText(AboutConfig::Password);
        ui->checkBox_rememberINfo->setChecked(true);
        ui->checkBox_autoLogin->setChecked(AboutConfig::AutoLogin);
    }


    //set the maxinum number in textbrowser
    ui->textBrowser_info->document()->setMaximumBlockCount(1024);

    timer=new QTimer(this);
    //link timer with function
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));

    ui->pushButton_loginOut->setEnabled(false);

    //if auto login,just login
    if(AboutConfig::AutoLogin)
    {
        ui->pushButton_login->click();
    }
}

MainWindow::~MainWindow()
{
    exit_dll();
    link.unload();

    delete ui;
}

void MainWindow::on_pushButton_multiLine_clicked()
{
    //An animation
    if(!showDetail)
    {
        setFixedSize(350,230);
        setGeometry(geometry().x(),geometry().y(),geometry().width(),230);
        ui->textBrowser_info->setGeometry(ui->textBrowser_info->geometry().x(),
                                          ui->textBrowser_info->geometry().y(),
                                          ui->textBrowser_info->geometry().width(),94);
        showDetail=true;
    }
    else if(showDetail)
    {
        setFixedSize(350,160);
        setGeometry(geometry().x(),geometry().y(),geometry().width(),160);
        ui->textBrowser_info->setGeometry(ui->textBrowser_info->geometry().x(),
                                          ui->textBrowser_info->geometry().y(),
                                          ui->textBrowser_info->geometry().width(),30);
        showDetail=false;
    }
}

//login
void MainWindow::on_pushButton_login_clicked()
{
    if(ui->lineEdit_userName->text()!="" && ui->lineEdit_passWord->text()!="")
    {
        if(ui->checkBox_rememberINfo->isChecked())
        {
            if(ui->checkBox_autoLogin->isChecked())
            {
                AboutConfig::Username=ui->lineEdit_userName->text();
                AboutConfig::Password=ui->lineEdit_passWord->text();
                AboutConfig::IndexOfAdapter=ui->comboBox->currentIndex();
                AboutConfig::writeConfig(true,true);
            }
            else
            {
                AboutConfig::Username=ui->lineEdit_userName->text();
                AboutConfig::Password=ui->lineEdit_passWord->text();
                AboutConfig::IndexOfAdapter=ui->comboBox->currentIndex();
                AboutConfig::writeConfig(false,true);
            }
        }
        else
        {
            AboutConfig::cleanConfig();
        }

        ui->pushButton_loginOut->setEnabled(true);
        ui->pushButton_login->setEnabled(false);

        int netCardNum=adaptersDescription.indexOf(ui->comboBox->currentText());
        timer->start(100);
        //utf-8 to GBK
        QString netCardName="\\Device\\NPF_"+adaptersName.at(netCardNum);
        QByteArray temp=netCardName.toLatin1();
        char *pNetCardName=temp.data();

        start_auth_thread(ui->lineEdit_userName->text().toLatin1().data(),
                          ui->lineEdit_passWord->text().toLatin1().data(),
                          pNetCardName,1);
        //pNetCardName;//delete the pointer
        ui->textBrowser_info->append("Linking...");
    }
    else QMessageBox::warning(this,"What!","You must forget something.");
}

void MainWindow::timerUpdate()
{
    string tmp = read_log();
    QString temp = QString::fromStdString(tmp);
    if(temp.contains("Success"))
    {
        //invoking cmd.exe to execute two commands
        //ipconfig/release to release IP
        QProcess *refreshDHCP=new QProcess;
        refreshDHCP->start("ipconfig/release");
        refreshDHCP->waitForStarted();
        refreshDHCP->waitForFinished();
        //ipconfig/renew to obtain a new IP
        refreshDHCP->start("ipconfig/renew");
        refreshDHCP->waitForStarted();
        refreshDHCP->waitForFinished();
        ui->textBrowser_info->append("Congratulation!");
    }
    else if(tmp.length() != 0)
    {
        ui->textBrowser_info->moveCursor(QTextCursor::End);
        ui->textBrowser_info->append(QString::fromStdString(tmp));
        ui->textBrowser_info->moveCursor(QTextCursor::End);
    }
}

void MainWindow::on_pushButton_loginOut_clicked()
{
    timer->stop();

    ui->pushButton_login->setEnabled(true);
    ui->pushButton_loginOut->setEnabled(false);

    stop_auth_thread();

    ui->textBrowser_info->append("Exited...");
}



void MainWindow::on_checkBox_rememberINfo_clicked()
{
    if(!ui->checkBox_rememberINfo->isChecked())
    {
        ui->checkBox_autoLogin->setChecked(false);
    }
}

void MainWindow::on_checkBox_autoLogin_clicked()
{
    if(ui->checkBox_autoLogin->isChecked())
    {
        ui->checkBox_rememberINfo->setChecked(true);
    }
}
