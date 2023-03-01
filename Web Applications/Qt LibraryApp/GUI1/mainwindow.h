#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QMessageBox>

#include <userwin.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_delaccbtn_clicked();
    void on_bookedcb_toggled(bool checked);
    void on_rentalscb_toggled(bool checked);
    void on_fbcb_toggled(bool checked);
    void on_mybookscb_toggled(bool checked);
    void on_valtitle_textEdited(const QString &arg1);
    void on_valauthor_textEdited(const QString &arg1);
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_signoutbtn_pressed();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
