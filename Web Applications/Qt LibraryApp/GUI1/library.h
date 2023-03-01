#include <QDialog>
#include "info.h"
#ifndef library_H
#define library_H
namespace Ui {
class library;
}
class library : public QDialog{
    Q_OBJECT
public:
    explicit library(Book *b);
    ~library();
private slots:
    void on_leabtn_clicked();
    void on_canbtn_clicked();
    void on_avalbtn_clicked();
    void on_resbtn_clicked();

private:
    Ui::library *ui;
};

#endif
