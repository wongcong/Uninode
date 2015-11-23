/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_userName;
    QLabel *label_passWord;
    QLabel *label_ethernet;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_userName;
    QPushButton *pushButton_login;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_passWord;
    QPushButton *pushButton_loginOut;
    QComboBox *comboBox;
    QTextBrowser *textBrowser_info;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_multiLine;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_rememberINfo;
    QCheckBox *checkBox_autoLogin;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(350, 160);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(350, 160));
        MainWindow->setMaximumSize(QSize(350, 230));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Icon/uninode.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(15, 5, 321, 86));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_userName = new QLabel(layoutWidget);
        label_userName->setObjectName(QStringLiteral("label_userName"));

        verticalLayout->addWidget(label_userName);

        label_passWord = new QLabel(layoutWidget);
        label_passWord->setObjectName(QStringLiteral("label_passWord"));

        verticalLayout->addWidget(label_passWord);

        label_ethernet = new QLabel(layoutWidget);
        label_ethernet->setObjectName(QStringLiteral("label_ethernet"));

        verticalLayout->addWidget(label_ethernet);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        lineEdit_userName = new QLineEdit(layoutWidget);
        lineEdit_userName->setObjectName(QStringLiteral("lineEdit_userName"));

        horizontalLayout->addWidget(lineEdit_userName);

        pushButton_login = new QPushButton(layoutWidget);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setFocusPolicy(Qt::StrongFocus);
        pushButton_login->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_login);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        lineEdit_passWord = new QLineEdit(layoutWidget);
        lineEdit_passWord->setObjectName(QStringLiteral("lineEdit_passWord"));
        lineEdit_passWord->setMaxLength(32);
        lineEdit_passWord->setEchoMode(QLineEdit::Password);
        lineEdit_passWord->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_passWord->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(lineEdit_passWord);

        pushButton_loginOut = new QPushButton(layoutWidget);
        pushButton_loginOut->setObjectName(QStringLiteral("pushButton_loginOut"));
        pushButton_loginOut->setCheckable(false);

        horizontalLayout_2->addWidget(pushButton_loginOut);


        verticalLayout_2->addLayout(horizontalLayout_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMaximumSize(QSize(16777215, 16777215));
        comboBox->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(comboBox);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        textBrowser_info = new QTextBrowser(centralWidget);
        textBrowser_info->setObjectName(QStringLiteral("textBrowser_info"));
        textBrowser_info->setGeometry(QRect(15, 124, 321, 30));
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(15, 95, 321, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_multiLine = new QPushButton(layoutWidget_2);
        pushButton_multiLine->setObjectName(QStringLiteral("pushButton_multiLine"));
        pushButton_multiLine->setMaximumSize(QSize(21, 21));

        horizontalLayout_4->addWidget(pushButton_multiLine);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(100, -1, -1, -1);
        checkBox_rememberINfo = new QCheckBox(layoutWidget_2);
        checkBox_rememberINfo->setObjectName(QStringLiteral("checkBox_rememberINfo"));
        sizePolicy.setHeightForWidth(checkBox_rememberINfo->sizePolicy().hasHeightForWidth());
        checkBox_rememberINfo->setSizePolicy(sizePolicy);
        checkBox_rememberINfo->setMinimumSize(QSize(50, 0));

        horizontalLayout_3->addWidget(checkBox_rememberINfo);

        checkBox_autoLogin = new QCheckBox(layoutWidget_2);
        checkBox_autoLogin->setObjectName(QStringLiteral("checkBox_autoLogin"));
        sizePolicy.setHeightForWidth(checkBox_autoLogin->sizePolicy().hasHeightForWidth());
        checkBox_autoLogin->setSizePolicy(sizePolicy);
        checkBox_autoLogin->setMinimumSize(QSize(50, 0));

        horizontalLayout_3->addWidget(checkBox_autoLogin);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        pushButton_login->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Uninode", 0));
        label_userName->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215  ", 0));
        label_passWord->setText(QApplication::translate("MainWindow", "\345\257\206  \347\240\201  ", 0));
        label_ethernet->setText(QApplication::translate("MainWindow", "\347\275\221  \345\215\241", 0));
        pushButton_login->setText(QApplication::translate("MainWindow", "\347\231\273  \345\275\225", 0));
        pushButton_loginOut->setText(QApplication::translate("MainWindow", "\351\200\200  \345\207\272", 0));
        textBrowser_info->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You must install winpcap.exe!</p></body></html>", 0));
        pushButton_multiLine->setText(QApplication::translate("MainWindow", ">", 0));
        checkBox_rememberINfo->setText(QApplication::translate("MainWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        checkBox_autoLogin->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\347\231\273\351\231\206", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
