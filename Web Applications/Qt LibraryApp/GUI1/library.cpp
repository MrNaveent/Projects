#include "library.h"
#include "ui_library.h"
Book *b;

void library::on_leabtn_clicked()
{
    QString user = ui->userLineEdit->text();
    b->setLeased(user);
    info::get().saveBooks();
    hide();
}
void library::on_canbtn_clicked()
{
    hide();
}
void library::on_avalbtn_clicked()
{
    b->setAvailable();
    info::get().saveBooks();
    hide();
}


void library::on_resbtn_clicked()
{
    QString user = ui->userLineEdit->text();
    b->setReserved(user);
    info::get().saveBooks();
    hide();
}

library::~library()
{
    delete ui;
}
library::library(Book* _b) :
    ui(new Ui::library)
{
    ui->setupUi(this);
    qDebug() << "book edit";
    qDebug() << _b->printAll();
    b = _b;
    ui->bookId->setText(QString::number(b->getId()));
    ui->status->setText(b->getStatus());
    ui->author->setText(b->getAuthor());
    ui->title->setText(b->getTitle());
    ui->date->setText(QString::number(b->getDate()));
    ui->publisher->setText(b->getPublisher());
    ui->userLineEdit->setText(b->getUser());
}

