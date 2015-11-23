#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_multiLine_clicked();

    void on_pushButton_login_clicked();

    void timerUpdate();

    void on_pushButton_loginOut_clicked();


    void on_checkBox_rememberINfo_clicked();

    void on_checkBox_autoLogin_clicked();

private:
    Ui::MainWindow *ui;

    //showDetail for monitor a button click
    bool showDetail;

    int indexOfAdapter;

    QStringList adaptersName;
    QStringList adaptersDescription;
};

#endif // MAINWINDOW_H
