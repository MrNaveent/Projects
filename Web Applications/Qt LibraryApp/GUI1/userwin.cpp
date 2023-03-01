#include "userwin.h"
#include "./ui_userwin.h"
#include "./info.h"

userwin::~userwin()
{
    delete ui;
}

userwin::userwin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::userwin)
{
    ui->setupUi(this);
}

QString creg(QString email, QString pass){

    if(info::get().getUsers().contains(email)){
        qDebug () << "Member already exists";
        return "present";
    }
    if(email == ""){
        qDebug () << "Blank field";
        return "blank";
    }

    qDebug () << "no errors";
    return "noerrors";
}

void userwin::on_regbtn_clicked()
{
    QString email = ui->signin2->text();
    QString pass = ui->pass2->text();
    QString response = creg(ui->signin2->text(), ui->pass2->text());
    if(response == "noerrors"){
        User u(email, pass);
        info::get().getUsers().add(u);
        info::get().saveUsers();
        QMessageBox::information(this, "Registration", "Member added");
    }
    else{
        if(response == "present"){
            QMessageBox::warning(this, "Registration", "Member exist");
        }
        else if (response == "blank"){
            QMessageBox::warning(this, "Registration", "Blank Field");
        }
    }
}


QString csignin(QString email, QString pass){
    if(pass == ""){
        return "passblank";
    }

    else{
        if (email == ""){
            return "blank";
        }
        else{
            return "noerrors";
        }
    }
}

void userwin::on_signinbtn_clicked()
{
    QString email = ui->signin->text();
    QString pass = ui->pass1->text();
    QString response = csignin(email, pass);
    if(response == "noerrors"){
        if(info::get().getUsers().contains(email)){
            if(info::get().getUsers().get(email).checkPassword(pass)){
                info::get().setCurrUser(email);
                hide();
                MainWindow *mainWindow = new class MainWindow(this);
                mainWindow->show();
            }
            else{
                qDebug() << "Invalid pass";
                QMessageBox::warning(this, "Signin ", "Invalid password");
            }
        }
        else{
            qDebug() << "Invalid email";
            QMessageBox::warning(this, "Signin ", "Invalid email");
        }
    }
    else if(response == "passblank"){
        QMessageBox::warning(this, "Signin ", "Blank password");
    }
    else if(response == "blank"){
        QMessageBox::warning(this, "Signin ", "Blank email");
    }

}



