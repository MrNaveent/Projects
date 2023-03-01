#ifndef USERWIN_H
#define USERWIN_H

#include <QMainWindow>

#ifndef mainwindow
#define mainwindow
#include "mainwindow.h"
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class userwin; }
QT_END_NAMESPACE

class userwin : public QMainWindow
{
    Q_OBJECT

public:
    userwin(QWidget *parent = nullptr);
    ~userwin();

private slots:
    void on_signinbtn_clicked();
    void on_regbtn_clicked();


private:
    Ui::userwin *ui;
};
#endif // USERWIN_H
