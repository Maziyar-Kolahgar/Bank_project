#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "bank.h"
#include <QMainWindow>
#include <iostream>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_bank(Bank);

private slots:
    void on_pushButton_exit_clicked();
    void on_pushButton_customer_clicked();
    void on_pushButton_back_clicked();
    void on_pushButton_ok_clicked();
    void on_pushButton_back2_clicked();
    void on_pushButton_settle_clicked();
    void on_pg4_pushbutton_back_clicked();
    void on_pg4_pushbutton_ok_clicked();
    void on_pushButton_removal_clicked();
    void on_pg5_pushbutton_back_clicked();
    void on_pg5_pushbutton_ok_clicked();
    void on_pushButton_display_clicked();
    void on_pg6_pushButton_ok_clicked();
    void on_pg6_pushButton_back_clicked();
    void on_pushButton_employee_clicked();
    void on_pg7_pushButton_back_clicked();
    void on_pg7_pushButton_ok_clicked();
    void on_pg8_pushButton_vacation_clicked();
    void on_pg9_pushbutton_back_clicked();
    void on_pg9_pushbutton_ok_clicked();
    void on_pg8_pushButton_back_clicked();
    void on_pg8_pushButton_overtime_clicked();
    void on_pg10_pushbutton_ok_clicked();
    void on_pg10_pushbutton_back_clicked();
    void on_pg11_pushbutton_back_clicked();
    void on_pg8_pushButton_yourinfo_clicked();
    void on_pg12_pushbutton_back_clicked();
    void on_pg8_pushButton_customerinfo_clicked();
    void on_pg12_pushbutton_ok_clicked();
    void on_pg8_pushButton_create_acc_clicked();
    void on_pg13_pushbutton_back_clicked();
    void on_pg13_pushbutton_new_clicked();
    void on_pg14_pushbutton_back_clicked();
    void on_pg14_pushbutton_ok_clicked();
    void on_pg13_pushbutton_add_clicked();
    void on_pg15_pushbutton_back_clicked();
    void on_pg15_pushbutton_ok_clicked();
    void on_pg8_pushButton_delete_acc_clicked();
    void on_pg16_pushbutton_back_clicked();
    void on_pg16_pushbutton_ok_clicked();
    void on_pg8_pushButton_employeeinfo_clicked();
    void on_pg17_pushbutton_back_clicked();
    void on_pg17_pushbutton_ok_clicked();
    void on_pg8_pushButton_add_emp_clicked();
    void on_pg18_pushbutton_back_clicked();
    void on_pg18_pushbutton_ok_clicked();
    void on_pg8_pushButton_delete_emp_clicked();
    void on_pg19_pushbutto_back_clicked();
    void on_pg19_pushbutto_ok_clicked();

private:
    Ui::MainWindow *ui;
    Bank bank;
    int index_customer;
    int index_employee;

};
#endif // MAINWINDOW_H
