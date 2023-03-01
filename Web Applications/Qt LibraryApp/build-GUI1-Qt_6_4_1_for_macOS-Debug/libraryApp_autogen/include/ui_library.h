/********************************************************************************
** Form generated from reading UI file 'library.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARY_H
#define UI_LIBRARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_library
{
public:
    QGridLayout *gridLayout;
    QLabel *author;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *status;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *cancelBtn;
    QPushButton *resbtn;
    QLabel *label;
    QLabel *date;
    QPushButton *leabtn;
    QLineEdit *userLineEdit;
    QPushButton *avalbtn;
    QLabel *publisher;
    QLabel *title;
    QLabel *label_5;
    QLabel *bookId;

    void setupUi(QWidget *library)
    {
        if (library->objectName().isEmpty())
            library->setObjectName("library");
        library->resize(465, 324);
        library->setMinimumSize(QSize(465, 324));
        library->setStyleSheet(QString::fromUtf8("background:rgb(0, 255, 0)"));
        gridLayout = new QGridLayout(library);
        gridLayout->setObjectName("gridLayout");
        author = new QLabel(library);
        author->setObjectName("author");

        gridLayout->addWidget(author, 6, 1, 1, 3);

        label_3 = new QLabel(library);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        label_7 = new QLabel(library);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 13, 0, 1, 1);

        label_2 = new QLabel(library);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        status = new QLabel(library);
        status->setObjectName("status");

        gridLayout->addWidget(status, 13, 1, 1, 3);

        label_4 = new QLabel(library);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 8, 0, 1, 1);

        label_6 = new QLabel(library);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        cancelBtn = new QPushButton(library);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setStyleSheet(QString::fromUtf8("background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0))"));

        gridLayout->addWidget(cancelBtn, 1, 3, 1, 1);

        resbtn = new QPushButton(library);
        resbtn->setObjectName("resbtn");
        resbtn->setStyleSheet(QString::fromUtf8("background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0))"));

        gridLayout->addWidget(resbtn, 1, 2, 1, 1);

        label = new QLabel(library);
        label->setObjectName("label");

        gridLayout->addWidget(label, 6, 0, 1, 1);

        date = new QLabel(library);
        date->setObjectName("date");

        gridLayout->addWidget(date, 8, 1, 1, 3);

        leabtn = new QPushButton(library);
        leabtn->setObjectName("leabtn");
        leabtn->setStyleSheet(QString::fromUtf8("background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0))"));

        gridLayout->addWidget(leabtn, 1, 0, 1, 1);

        userLineEdit = new QLineEdit(library);
        userLineEdit->setObjectName("userLineEdit");
        userLineEdit->setStyleSheet(QString::fromUtf8("background:qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69))"));

        gridLayout->addWidget(userLineEdit, 3, 1, 1, 1);

        avalbtn = new QPushButton(library);
        avalbtn->setObjectName("avalbtn");
        avalbtn->setStyleSheet(QString::fromUtf8("background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0))"));

        gridLayout->addWidget(avalbtn, 1, 1, 1, 1);

        publisher = new QLabel(library);
        publisher->setObjectName("publisher");

        gridLayout->addWidget(publisher, 7, 1, 1, 1);

        title = new QLabel(library);
        title->setObjectName("title");

        gridLayout->addWidget(title, 5, 1, 1, 1);

        label_5 = new QLabel(library);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        bookId = new QLabel(library);
        bookId->setObjectName("bookId");

        gridLayout->addWidget(bookId, 4, 1, 1, 1);


        retranslateUi(library);

        QMetaObject::connectSlotsByName(library);
    } // setupUi

    void retranslateUi(QWidget *library)
    {
        library->setWindowTitle(QCoreApplication::translate("library", "Form", nullptr));
#if QT_CONFIG(whatsthis)
        library->setWhatsThis(QCoreApplication::translate("library", "<html><head/><body><p>background:</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        author->setText(QCoreApplication::translate("library", "author placeholder", nullptr));
        label_3->setText(QCoreApplication::translate("library", "Title:", nullptr));
        label_7->setText(QCoreApplication::translate("library", "Status:", nullptr));
        label_2->setText(QCoreApplication::translate("library", "User:", nullptr));
        status->setText(QCoreApplication::translate("library", "status placceholder", nullptr));
        label_4->setText(QCoreApplication::translate("library", "Year Published:", nullptr));
        label_6->setText(QCoreApplication::translate("library", "Publisher:", nullptr));
        cancelBtn->setText(QCoreApplication::translate("library", "Cancel", nullptr));
        resbtn->setText(QCoreApplication::translate("library", "Reserved", nullptr));
        label->setText(QCoreApplication::translate("library", "Aauthor:", nullptr));
        date->setText(QCoreApplication::translate("library", "date placeholder", nullptr));
        leabtn->setText(QCoreApplication::translate("library", "Leased", nullptr));
        avalbtn->setText(QCoreApplication::translate("library", "Avaliable", nullptr));
        publisher->setText(QCoreApplication::translate("library", "publisher placeholder", nullptr));
        title->setText(QCoreApplication::translate("library", "title placeolder", nullptr));
        label_5->setText(QCoreApplication::translate("library", "Book Id:", nullptr));
        bookId->setText(QCoreApplication::translate("library", "bookId placeholder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class library: public Ui_library {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARY_H
