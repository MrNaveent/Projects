/********************************************************************************
** Form generated from reading UI file 'userwin.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIN_H
#define UI_USERWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userwin
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLineEdit *signin;
    QLineEdit *pass1;
    QPushButton *signinbtn;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QLineEdit *signin2;
    QLineEdit *pass2;
    QLabel *label_2;
    QPushButton *regbtn;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *userwin)
    {
        if (userwin->objectName().isEmpty())
            userwin->setObjectName("userwin");
        userwin->resize(800, 600);
        userwin->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(userwin);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        font.setItalic(true);
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("\n"
"background : rgb(255, 0, 0);\n"
""));
        label_3->setLineWidth(3);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        signin = new QLineEdit(centralwidget);
        signin->setObjectName("signin");
        signin->setStyleSheet(QString::fromUtf8("background:rgb(255, 250, 20)"));

        verticalLayout_2->addWidget(signin);

        pass1 = new QLineEdit(centralwidget);
        pass1->setObjectName("pass1");
        pass1->setStyleSheet(QString::fromUtf8("background:rgb(255, 250, 20)"));
        pass1->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(pass1);

        signinbtn = new QPushButton(centralwidget);
        signinbtn->setObjectName("signinbtn");
        signinbtn->setEnabled(true);
        signinbtn->setStyleSheet(QString::fromUtf8("background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0))"));

        verticalLayout_2->addWidget(signinbtn);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("\n"
"background : rgb(85, 255, 127)"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);

        signin2 = new QLineEdit(centralwidget);
        signin2->setObjectName("signin2");
        signin2->setStyleSheet(QString::fromUtf8("background:rgb(255, 250, 20)"));

        verticalLayout_2->addWidget(signin2);

        pass2 = new QLineEdit(centralwidget);
        pass2->setObjectName("pass2");
        pass2->setStyleSheet(QString::fromUtf8("background:rgb(255, 250, 20)"));
        pass2->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(pass2);


        verticalLayout->addLayout(verticalLayout_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        regbtn = new QPushButton(centralwidget);
        regbtn->setObjectName("regbtn");
        regbtn->setEnabled(true);
        regbtn->setStyleSheet(QString::fromUtf8("\n"
"background : qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0))"));

        verticalLayout->addWidget(regbtn);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        userwin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(userwin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        userwin->setMenuBar(menubar);
        statusbar = new QStatusBar(userwin);
        statusbar->setObjectName("statusbar");
        userwin->setStatusBar(statusbar);

        retranslateUi(userwin);

        QMetaObject::connectSlotsByName(userwin);
    } // setupUi

    void retranslateUi(QMainWindow *userwin)
    {
        userwin->setWindowTitle(QCoreApplication::translate("userwin", "userwin", nullptr));
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("userwin", "SIGN IN ", nullptr));
        signin->setPlaceholderText(QCoreApplication::translate("userwin", "EMAIL", nullptr));
        pass1->setPlaceholderText(QCoreApplication::translate("userwin", "Password", nullptr));
        signinbtn->setText(QCoreApplication::translate("userwin", "Sign in", nullptr));
        label_4->setText(QCoreApplication::translate("userwin", "REGISTER", nullptr));
        signin2->setText(QString());
        signin2->setPlaceholderText(QCoreApplication::translate("userwin", "EMAIL", nullptr));
        pass2->setPlaceholderText(QCoreApplication::translate("userwin", "Password", nullptr));
        label_2->setText(QString());
        regbtn->setText(QCoreApplication::translate("userwin", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userwin: public Ui_userwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIN_H
