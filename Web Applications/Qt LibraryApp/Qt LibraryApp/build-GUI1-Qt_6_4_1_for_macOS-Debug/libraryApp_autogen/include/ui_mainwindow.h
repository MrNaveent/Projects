/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *delaccbtn;
    QListWidget *listWidget;
    QPushButton *signoutbtn;
    QLineEdit *valtitle;
    QLabel *label_2;
    QCheckBox *mybookscb;
    QCheckBox *fbcb;
    QLineEdit *valauthor;
    QLabel *label;
    QCheckBox *bookedcb;
    QCheckBox *rentalscb;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 671);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        delaccbtn = new QPushButton(centralwidget);
        delaccbtn->setObjectName("delaccbtn");

        gridLayout->addWidget(delaccbtn, 9, 3, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setLayoutDirection(Qt::LeftToRight);
        listWidget->setAlternatingRowColors(true);

        gridLayout->addWidget(listWidget, 6, 2, 1, 7);

        signoutbtn = new QPushButton(centralwidget);
        signoutbtn->setObjectName("signoutbtn");

        gridLayout->addWidget(signoutbtn, 9, 8, 1, 1);

        valtitle = new QLineEdit(centralwidget);
        valtitle->setObjectName("valtitle");
        valtitle->setStyleSheet(QString::fromUtf8("background:rgb(255, 250, 20)"));

        gridLayout->addWidget(valtitle, 1, 4, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        mybookscb = new QCheckBox(centralwidget);
        mybookscb->setObjectName("mybookscb");

        gridLayout->addWidget(mybookscb, 1, 8, 1, 1);

        fbcb = new QCheckBox(centralwidget);
        fbcb->setObjectName("fbcb");

        gridLayout->addWidget(fbcb, 1, 7, 1, 1);

        valauthor = new QLineEdit(centralwidget);
        valauthor->setObjectName("valauthor");
        valauthor->setStyleSheet(QString::fromUtf8("background:rgb(255, 250, 20)"));

        gridLayout->addWidget(valauthor, 0, 4, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 3, 1, 1);

        bookedcb = new QCheckBox(centralwidget);
        bookedcb->setObjectName("bookedcb");

        gridLayout->addWidget(bookedcb, 2, 7, 1, 1);

        rentalscb = new QCheckBox(centralwidget);
        rentalscb->setObjectName("rentalscb");

        gridLayout->addWidget(rentalscb, 2, 8, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 6, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        delaccbtn->setText(QCoreApplication::translate("MainWindow", "Delete account", nullptr));
        signoutbtn->setText(QCoreApplication::translate("MainWindow", "Sign out", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", " Author: Name", nullptr));
        mybookscb->setText(QCoreApplication::translate("MainWindow", "Owned", nullptr));
        fbcb->setText(QCoreApplication::translate("MainWindow", "Free Books", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", " Book Title:", nullptr));
        bookedcb->setText(QCoreApplication::translate("MainWindow", "Booked", nullptr));
        rentalscb->setText(QCoreApplication::translate("MainWindow", "Rentals", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Filters:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
