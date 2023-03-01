#include "library.h"
#include "./info.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

void surfing(QListWidget* values, QString valtitle, QString valauthor, bool isfree, bool ismyBooks, bool isreserved ,bool isleased){
    values->clear();
    info::get().getBooks().forEach<Book>([values, valtitle, valauthor, isfree, ismyBooks,  isreserved, isleased](auto book){
        if(book.getTitle().contains(valtitle, Qt::CaseInsensitive) &&
                book.getAuthor().contains(valauthor, Qt::CaseInsensitive)&&
                (!isfree || book.getStatus() == "available") &&
                (!isreserved || book.getStatus() == "reserved") &&
                (!isleased || book.getStatus() == "leased") &&
                (!ismyBooks || book.getUser() == info::get().getCurrUser())
                ){
            QString str = "\nbook id: " + QString::number(book.getId())+" ";
            if(book.getUser() == info::get().getCurrUser()){
                str += "\nAdded to your Account\n";
            }
            str += "\ntitle: " + book.getTitle() + "\nauthor: " + book.getAuthor() + "\n   status: " + book.getStatus() + "\n";
            if(info::get().getCurrUser() == "librarian"){
                str+= "user: " + book.getUser()+"\n";
            }
            values->addItem(str);
        }
        return false;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    surfing(ui->listWidget, "", "", false, false, false, false);
    if(info::get().getCurrUser() == "librarian"){
        ui->delaccbtn->setDisabled(true);
    }
    if(info::get().getCurrUser() != "librarian"){
        ui->bookedcb->hide();
        ui->rentalscb->hide();

    }
}

void MainWindow::on_rentalscb_toggled(bool checked)
{
    QString istitle = ui->valtitle->text();
    QString isauthor = ui->valauthor->text();
    bool isfree = ui->fbcb->checkState();
    bool ismyBooks = ui->mybookscb->checkState();
    bool isbooked = ui->bookedcb->checkState();
    surfing(ui->listWidget, istitle, isauthor, isfree, ismyBooks, isbooked, checked);
    ui->bookedcb->setDisabled(checked);
}


void MainWindow::on_bookedcb_toggled(bool checked)
{
    QString istitle = ui->valtitle->text();
    QString isauthor = ui->valauthor->text();
    bool isfree = ui->fbcb->checkState();
    bool ismyBooks = ui->mybookscb->checkState();
    bool isrentals = ui->rentalscb->checkState();
    surfing(ui->listWidget, istitle, isauthor, isfree, ismyBooks, checked, isrentals);
    ui->rentalscb->setDisabled(checked);
}

void MainWindow::on_fbcb_toggled(bool checked)
{
    QString valtitle = ui->valtitle->text();
    QString valauthor = ui->valauthor->text();
    bool ismyBooks = ui->mybookscb->checkState();
    bool isbooked = ui->bookedcb->checkState();
    bool isrentals = ui->rentalscb->checkState();
    surfing(ui->listWidget, valtitle, valauthor, checked, ismyBooks, isbooked, isrentals);
}
void MainWindow::on_mybookscb_toggled(bool checked)
{
    QString istitle = ui->valtitle->text();
    QString isauthor = ui->valauthor->text();
    bool isfree = ui->fbcb->checkState();
    bool isbooked = ui->bookedcb->checkState();
    bool isrentals = ui->rentalscb->checkState();
    surfing(ui->listWidget, istitle, isauthor, isfree, checked, isbooked, isrentals);
}

void MainWindow::on_valtitle_textEdited(const QString &arg1)
{
    QString valauthor = ui->valauthor->text();
    bool isfree = ui->fbcb->checkState();
    bool ismyBooks = ui->mybookscb->checkState();
    bool isbooked = ui->bookedcb->checkState();
    bool isrentals = ui->rentalscb->checkState();
    surfing(ui->listWidget, arg1, valauthor, isfree, ismyBooks, isbooked, isrentals);
}
void MainWindow::on_valauthor_textEdited(const QString &arg1)
{
    QString valtitle = ui->valtitle->text();
    bool isfree = ui->fbcb->checkState();
    bool ismyBooks = ui->mybookscb->checkState();
    bool isbooked = ui->bookedcb->checkState();
    bool isrentals = ui->rentalscb->checkState();
    surfing(ui->listWidget, valtitle, arg1, isfree, ismyBooks, isbooked, isrentals);
}

void MainWindow::on_delaccbtn_clicked()
{
    QString currUser = info::get().getCurrUser();
    bool hasBooks = info::get().getBooks().forEach<Book>([currUser](auto book){
        if(book.getUser() == currUser){
            return true;
        }
        return false;
    });
    if(hasBooks){
        QMessageBox::warning(this, tr("My Application"),
                             tr("To delete account, release all reserved books."),
                             QMessageBox::Ok);
    }
    else{

        int ret = QMessageBox::warning(this, tr("My Application"),
                                       tr("Confirm delete?"),
                                       QMessageBox::Yes | QMessageBox::No);
        qDebug() << ret;
        if (ret == 16384){
            qDebug() << "yes was clicked";
            info::get().getUsers().deleteElement(info::get().getCurrUser());
            info::get().saveUsers();
            info::get().setCurrUser("");
            hide();

            userwin *userwin = new class userwin(this);
            userwin->show();
        }
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << "a";
    auto bookId = item->data(0).toString().split(" ")[2].toInt();
    qDebug() << "book id: " << QString::number(bookId);
    Book* b = &info::get().getBooks().get(bookId);
    if(info::get().getCurrUser() != "librarian"){
        qDebug() << "normal user";
        if(b->getStatus() == "available"){
            b->setReserved(info::get().getCurrUser());
            info::get().saveBooks();
        }
        else{
            if(b->getUser() == info::get().getCurrUser()&& b->getStatus() == "reserved"){
                b->setAvailable();
                info::get().saveBooks();
            }
        }
    }
    else{
        library *library = new class library(b);
        library->setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint);
        library->exec();

    }
    QString valtitle = ui->valtitle->text();
    QString valauthor = ui->valauthor->text();
    bool isfree = ui->fbcb->checkState();
    bool ismyBooks = ui->mybookscb->checkState();
    bool isbooked = ui->bookedcb->checkState();
    bool isrentals = ui->rentalscb->checkState();
    surfing(item->listWidget(), valtitle, valauthor, isfree, ismyBooks, isbooked, isrentals);
}


void MainWindow::on_signoutbtn_pressed()
{
    info::get().setCurrUser("");

    hide();

    userwin *userwin = new class userwin(this);
    userwin->show();
}




