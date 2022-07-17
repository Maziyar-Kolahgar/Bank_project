#include "mainwindow.h"
#include "ui_mainwindow.h"
//Ui::MainWindow *ui;
//Bank bank;
//int index_customer;
//int index_employee;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    index_customer=-1;
    index_employee=-1;
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::set_bank(Bank b)
{
    bank=b;
}
//////////Main menu page:
void MainWindow::on_pushButton_exit_clicked()
{
    bank.save_data();
    ui->centralwidget->close();
    this->close();
}
void MainWindow::on_pushButton_customer_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_employee_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
//Customer Username&Password Login page:
void MainWindow::on_pushButton_back_clicked()
{
    ui->textBrowser->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_username->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_ok_clicked()
{
    if(ui->lineEdit_username->text()==""||ui->lineEdit_password->text()=="")
    {
        ui->textBrowser->setText("First fill both Username and Password");
    }
    else
    {
        index_customer=-1;
        for(unsigned int i=0;i<bank.get_customers().size();i++)
        {
            if(ui->lineEdit_username->text().toStdString()==bank.get_customers().at(i).get_user_name())
            {
                index_customer=i;
            }
        }
        if(index_customer==-1)
        {
            ui->textBrowser->setText("There in no Customer with this Username");
        }
        else
        {
            if(bank.get_customers().at(index_customer).get_password()==ui->lineEdit_password->text().toStdString())
            {
                QString na=QString::fromStdString(bank.get_customers().at(index_customer).get_name());
                ui->label_welcom_customer->setText("Welcome "+na);
                bank.set_report("Customer with national code "+bank.get_customers().at(index_customer).get_national_code()+" logined");
                ui->stackedWidget->setCurrentIndex(2);
            }
            else
            {
                 ui->textBrowser->setText("Wrong Password");
            }
        }

    }
}
//////////Customer page:
void MainWindow::on_pushButton_back2_clicked()
{
    ui->textBrowser->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_username->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_settle_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_pushButton_removal_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_pushButton_display_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    QString r=QString::fromStdString(bank.get_customers().at(index_customer).get_all_info());
    ui->pg6_customer_info->setText(r);
}
//Customer settle to account page:
void MainWindow::on_pg4_pushbutton_back_clicked()
{
    ui->pg4_lineedit_acc_num->setText("");
    ui->pg4_lineedit_money->setText("");
    ui->pg4_textBrowser->setText("");
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_pg4_pushbutton_ok_clicked()
{
    string lineedit_accnum=ui->pg4_lineedit_acc_num->text().toStdString();
    string lineedit_money=ui->pg4_lineedit_money->text().toStdString();
    if(lineedit_accnum==""||lineedit_money=="")
        ui->pg4_textBrowser->setText("First fill both Lineedits");    
    else
    {
        int t=0;
        for(unsigned int i=0;i<bank.get_customers().at(index_customer).get_accounts().size();i++)
        {
            if(bank.get_customers().at(index_customer).get_accounts().at(i).get_account_number()==lineedit_accnum)
            {
                t++;
                int tt=0;
                for(unsigned int j=0;j<lineedit_money.size();j++)
                {
                     if(lineedit_money[j]!='0'&&lineedit_money[j]!='1'&&lineedit_money[j]!='2'&&lineedit_money[j]!='3'&&lineedit_money[j]!='4'&&lineedit_money[j]!='5'&&lineedit_money[j]!='6'&&lineedit_money[j]!='7'&&lineedit_money[j]!='8'&&lineedit_money[j]!='9')
                         tt++;
                }
                if(tt!=0)
                {
                    ui->pg4_textBrowser->setText("Write a number in Money lineedit");
                    return;
                }
                else if(lineedit_money.size()>10)
                {
                    ui->pg4_textBrowser->setText("Maximum amount is 9,999,999,999");
                    return;
                }
                else
                {
                    if(stoi(ui->pg4_lineedit_money->text().toStdString())==0)
                    {
                        ui->pg4_textBrowser->setText("no change");
                        return;
                    }
                    string previos_stock=to_string( bank.get_customers().at(index_customer).get_accounts().at(i).get_stock());
                    bank.increase_stock(index_customer,i,(long long)stoi(lineedit_money));
                    string result=previos_stock+" --> "+to_string( bank.get_customers().at(index_customer).get_accounts().at(i).get_stock());
                    QString r=QString::fromStdString("Done\n"+result);
                    ui->pg4_textBrowser->setText(r);
                    bank.save_data();
                    bank.set_report("Customer("+bank.get_customers().at(index_customer).get_national_code()+") Change his account("+bank.get_customers().at(index_customer).get_accounts().at(i).get_account_number()+") Money: "+result);
                    return;
                }
            }
        }
        if(t==0)
        {
            ui->pg4_textBrowser->setText("Not found");
        }
    }
}
//Customer removal from account page:
void MainWindow::on_pg5_pushbutton_back_clicked()
{
    ui->pg5_lineedit_accnum->setText("");
    ui->pg5_lineedit_money->setText("");
    ui->pg5_textBrowser->setText("");
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_pg5_pushbutton_ok_clicked()
{
    string lineedit_accnum=ui->pg5_lineedit_accnum->text().toStdString();
    string lineedit_money=ui->pg5_lineedit_money->text().toStdString();
    if(lineedit_accnum==""||lineedit_money=="")
    {
        ui->pg5_textBrowser->setText("First fill both Lineedits");
        return;
    }
    for(unsigned int i=0;i<lineedit_money.size();i++)
    {
        if(lineedit_money[i]!='0'&&lineedit_money[i]!='1'&&lineedit_money[i]!='2'&&lineedit_money[i]!='3'&&lineedit_money[i]!='4'&&lineedit_money[i]!='5'&&lineedit_money[i]!='6'&&lineedit_money[i]!='7'&&lineedit_money[i]!='8'&&lineedit_money[i]!='9')
        {
            ui->pg5_textBrowser->setText("invalid Money");
            return;
        }
    }
    if(lineedit_money.size()>10)
    {
        ui->pg4_textBrowser->setText("Maximum amount is 9,999,999,999");
        return;
    }
    int t=0;
    for(unsigned int i=0;i<bank.get_customers().at(index_customer).get_accounts().size();i++)
    {
        if(bank.get_customers().at(index_customer).get_accounts().at(i).get_account_number()==lineedit_accnum)
        {
            t++;
            long long m=(long long)stoi(lineedit_money);
            if(m>bank.get_customers().at(index_customer).get_accounts().at(i).get_stock())
            {
                ui->pg5_textBrowser->setText("There in not enough Money");
                return;
            }
            if(m==0)
            {
                ui->pg5_textBrowser->setText("no change");
                return;
            }
            string before=to_string(bank.get_customers().at(index_customer).get_accounts().at(i).get_stock());
            bank.decrease_stock(index_customer,i,m);
            string after=to_string(bank.get_customers().at(index_customer).get_accounts().at(i).get_stock());
            string result=before+" --> "+after;
            QString r=QString::fromStdString("Done\n"+result);
            ui->pg5_textBrowser->setText(r);
            bank.save_data();
            bank.set_report("Customer("+bank.get_customers().at(index_customer).get_national_code()+") Change his account("+bank.get_customers().at(index_customer).get_accounts().at(i).get_account_number()+") Money: "+result);
            return;
        }
    }
    if(t==0)
    {
        ui->pg5_textBrowser->setText("Not Found");
        return;
    }
}
//Customer display info page:
void MainWindow::on_pg6_pushButton_ok_clicked()
{
    if(ui->pg6_lineedit->text()=="")
    {
        ui->pg6_accinfo->setText("fill the lineedit first");
        return;
    }
    string accnum=ui->pg6_lineedit->text().toStdString();
    for(unsigned int i=0;i<bank.get_customers().at(index_customer).get_accounts().size();i++)
    {
        if(accnum==bank.get_customers().at(index_customer).get_accounts().at(i).get_account_number())
        {
            QString r=QString::fromStdString(bank.get_customers().at(index_customer).get_accounts().at(i).get_all_info());
            ui->pg6_accinfo->setText(r);
            return;
        }
    }
    ui->pg6_accinfo->setText("Not Found");
}
void MainWindow::on_pg6_pushButton_back_clicked()
{
    ui->pg6_accinfo->setText("");
    ui->pg6_lineedit->setText("");
    ui->stackedWidget->setCurrentIndex(2);
}
//emploee Username&Password Login page:
void MainWindow::on_pg7_pushButton_back_clicked()
{
    ui->pg7_lineedit_password->setText("");
    ui->pg7_lineedit_username->setText("");
    ui->pg7_textBrowser->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pg7_pushButton_ok_clicked()
{
    string lineedit_username=ui->pg7_lineedit_username->text().toStdString();
    string lineedit_password=ui->pg7_lineedit_password->text().toStdString();
    if(lineedit_username==""||lineedit_password=="")
    {
        ui->pg7_textBrowser->setText("First fill both line edits");
        return;
    }
    //manager:
    if(lineedit_username==bank.get_manager().get_user_name())
    {
        if(lineedit_password==bank.get_manager().get_password())
        {
            index_employee=-2;
            ui->pg7_lineedit_password->setText("");
            ui->pg7_lineedit_username->setText("");
            ui->pg7_textBrowser->setText("");
            ui->stackedWidget->setCurrentIndex(7);
            QString d=QString::fromStdString(to_string(bank.get_days()));
            ui->pg8_days->setText("Day "+d);
            bank.set_report("Manager("+bank.get_manager().get_personal_code()+") logined");
            return;
        }
        ui->pg7_textBrowser->setText("Wrong password");
        return;
    }
    //employess:
    for(unsigned int i=0;i<bank.get_employees().size();i++)
    {
        if(lineedit_username==bank.get_employees().at(i).get_user_name())
        {
            if(lineedit_password==bank.get_employees().at(i).get_password())
            {
                index_employee=i;
                ui->pg7_lineedit_password->setText("");
                ui->pg7_lineedit_username->setText("");
                ui->pg7_textBrowser->setText("");
                ui->stackedWidget->setCurrentIndex(7);
                QString d=QString::fromStdString(to_string(bank.get_days()));
                ui->pg8_days->setText("Day "+d);
                bank.set_report("employee("+bank.get_employees().at(index_employee).get_personal_code()+") logined");
                return;
            }
            ui->pg7_textBrowser->setText("Wrong password");
            return;
        }
    }
    ui->pg7_textBrowser->setText("Not Found");
}
//////////employee page:
void MainWindow::on_pg8_pushButton_back_clicked()
{
    ui->pg7_lineedit_password->setText("");
    ui->pg7_lineedit_username->setText("");
    ui->pg7_textBrowser->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pg8_pushButton_vacation_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    QString before_leave,before_salary;
    if(index_employee!=-2)
    {
        before_leave=QString::fromStdString(to_string(bank.get_employees().at(index_employee).get_leave_hours()));
        before_salary=QString::fromStdString(to_string(bank.get_employees().at(index_employee).get_salary()));
    }
    else
    {
        before_leave=QString::fromStdString(to_string(bank.get_manager().get_leave_hours()));
        before_salary=QString::fromStdString(to_string(bank.get_manager().get_salary()));
    }
    ui->pg9_textbrowser_info->setText("You used "+before_leave+" hours already (max=15h)\nyour Salary: "+before_salary);
}
void MainWindow::on_pg8_pushButton_overtime_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    QString before_overtime,before_salary;
    if(index_employee!=-2)
    {
        before_overtime=QString::fromStdString(to_string(bank.get_employees().at(index_employee).get_overtime_hours()));
        before_salary=QString::fromStdString(to_string(bank.get_employees().at(index_employee).get_salary()));
    }
    else
    {
        before_overtime=QString::fromStdString(to_string(bank.get_manager().get_overtime_hours()));
        before_salary=QString::fromStdString(to_string(bank.get_manager().get_salary()));
    }
    ui->pg10_textbrowser_info->setText("You used "+before_overtime+" hours already (max=12h)\nyour Salary: "+before_salary);
}
void MainWindow::on_pg8_pushButton_yourinfo_clicked()
{
    if(index_employee==-2)
    {
        QString emp_info=QString::fromStdString(bank.get_manager().get_all_info());
        ui->pg11_textbrowser->setText(emp_info);
    }
    else
    {
        QString emp_info=QString::fromStdString(bank.get_employees().at(index_employee).get_all_info());
        ui->pg11_textbrowser->setText(emp_info);
    }
    ui->stackedWidget->setCurrentIndex(10);
}
void MainWindow::on_pg8_pushButton_customerinfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}
void MainWindow::on_pg8_pushButton_create_acc_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}
void MainWindow::on_pg8_pushButton_delete_acc_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}
void MainWindow::on_pg8_pushButton_employeeinfo_clicked()
{
    if(index_employee==-2)
        ui->stackedWidget->setCurrentIndex(16);
    else
    {
        ui->pg8_textBrowser->setText("this button is not available for you\nit is just for the manager");
    }
}
void MainWindow::on_pg8_pushButton_add_emp_clicked()
{
    if(index_employee==-2)
        ui->stackedWidget->setCurrentIndex(17);
    else
    {
        ui->pg8_textBrowser->setText("this button is not available for you\nit is just for the manager");
    }
}
void MainWindow::on_pg8_pushButton_delete_emp_clicked()
{
    if(index_employee==-2)
        ui->stackedWidget->setCurrentIndex(18);
    else
    {
        ui->pg8_textBrowser->setText("this button is not available for you\nit is just for the manager");
    }
}
//employee vacations page:
void MainWindow::on_pg9_pushbutton_back_clicked()
{
    ui->pg8_textBrowser->setText("");
    ui->pg9_lineedit->setText("");
    ui->pg9_textbrowser_result->setText("");
    ui->stackedWidget->setCurrentIndex(7);

}
void MainWindow::on_pg9_pushbutton_ok_clicked()
{
    string lineedit_input=ui->pg9_lineedit->text().toStdString();
    QString r=QString::fromStdString(bank.increase_leave_hours(index_employee,lineedit_input));
    ui->pg9_textbrowser_result->setText(r);
    if(r.at(0)!='F'&&r.at(0)!='i'&&r.at(0)!='y'&&r.at(0)!='n')
    {
        Employee emp;
        if(index_employee==-2)
            emp=bank.get_manager();
        else
            emp=bank.get_employees().at(index_employee);
        bank.set_report("employee("+emp.get_personal_code()+") get "+lineedit_input+" hours rest");
        bank.save_data();
        QString before_leave=QString::fromStdString(to_string(emp.get_leave_hours()));
        QString before_salary=QString::fromStdString(to_string(emp.get_salary()));
        ui->pg9_textbrowser_info->setText("You used "+before_leave+" hours already (max=15h)\nyour Salary: "+before_salary);
    }
}
//employee overtime page:
void MainWindow::on_pg10_pushbutton_ok_clicked()
{
    string lineedit_input=ui->pg10_lineedit->text().toStdString();
    QString r=QString::fromStdString(bank.increase_overtime(index_employee,lineedit_input));
    ui->pg10_textbrowser_result->setText(r);
    if(r.at(0)!='F'&&r.at(0)!='i'&&r.at(0)!='y'&&r.at(0)!='n')
    {
        Employee emp;
        if(index_employee==-2)
            emp=bank.get_manager();
        else
            emp=bank.get_employees().at(index_employee);
        bank.set_report("employee("+emp.get_personal_code()+") get "+lineedit_input+" hours overtime");
        bank.save_data();
        QString before_overtime=QString::fromStdString(to_string(emp.get_overtime_hours()));
        QString before_salary=QString::fromStdString(to_string(emp.get_salary()));
        ui->pg10_textbrowser_info->setText("You used "+before_overtime+" hours already (max=12h)\nyour Salary: "+before_salary);
    }
}
void MainWindow::on_pg10_pushbutton_back_clicked()
{
    ui->pg8_textBrowser->setText("");
    ui->pg10_lineedit->setText("");
    ui->pg10_textbrowser_result->setText("");
    ui->stackedWidget->setCurrentIndex(7);
}
//employee display page:
void MainWindow::on_pg11_pushbutton_back_clicked()
{
    ui->pg8_textBrowser->setText("");
    ui->stackedWidget->setCurrentIndex(7);
}
//employee customer info page:
void MainWindow::on_pg12_pushbutton_back_clicked()
{
    ui->pg12_lineedit_nationalcode->setText("");
    ui->pg12_textbrowser_info->setText("");
    ui->pg8_textBrowser->setText("");
    ui->stackedWidget->setCurrentIndex(7);
}
void MainWindow::on_pg12_pushbutton_ok_clicked()
{
    string lineedit=ui->pg12_lineedit_nationalcode->text().toStdString();
    if(lineedit=="")
    {
        ui->pg12_textbrowser_info->setText("Enter the national code in lineedit first");
        return;
    }
    for(unsigned int i=0;i<bank.get_customers().size();i++)
    {
        if(lineedit==bank.get_customers().at(i).get_national_code())
        {
            QString r=QString::fromStdString(bank.get_customers().at(i).get_all_info_with_accounts());
            ui->pg12_textbrowser_info->setText(r);
            return;
        }
    }
    ui->pg12_textbrowser_info->setText("Not Found or invalid input");
}
//employee create account pages:
void MainWindow::on_pg13_pushbutton_back_clicked()
{
    ui->pg8_textBrowser->setText("");
    ui->stackedWidget->setCurrentIndex(7);
}
void MainWindow::on_pg13_pushbutton_new_clicked()
{
    time_t curr_time;
    tm *curr_tm;
    char date1[100];
    time(&curr_time);
    curr_tm=localtime(&curr_time);
    strftime(date1,50," %Y/%m/%d ",curr_tm);
    QString date_now=QString::fromStdString(date1);
    ui->pg14_openingdate->setText(date_now);
    ui->stackedWidget->setCurrentIndex(13);
}
void MainWindow::on_pg14_pushbutton_back_clicked()
{
    ui->pg14_textbrowser_result->setText("");
    ui->pg14_name->setText("");
    ui->pg14_family->setText("");
    ui->pg14_national_code->setText("");
    ui->pg14_birthday->setText("");
    ui->pg14_username->setText("");
    ui->pg14_password->setText("");
    ui->pg14_accnum->setText("");
    ui->pg14_stock->setText("");
    ui->stackedWidget->setCurrentIndex(12);
}
void MainWindow::on_pg14_pushbutton_ok_clicked()
{
    string st=ui->pg14_stock->text().toStdString();
    if(st=="")
    {
        ui->pg14_textbrowser_result->setText("complete all lines first");
        return;
    }
    for(unsigned int j=0;j<st.size();j++)
    {
         if(st[j]!='0'&&st[j]!='1'&&st[j]!='2'&&st[j]!='3'&&st[j]!='4'&&st[j]!='5'&&st[j]!='6'&&st[j]!='7'&&st[j]!='8'&&st[j]!='9')
         {
             ui->pg14_textbrowser_result->setText("invalid stock");
             return;
         }
    }
    if(st.size()>7)
    {
        ui->pg14_textbrowser_result->setText("maximum base stock you can add is 9,999,999");
        return;
    }
    if(stoi(st)<50000)
    {
        ui->pg14_textbrowser_result->setText("base stock should be more than 50,000");
        return;
    }
    Customer cust;
    Account acc;
    cust.set_name(ui->pg14_name->text().toStdString());
    cust.set_family(ui->pg14_family->text().toStdString());
    cust.set_national_code(ui->pg14_national_code->text().toStdString());
    cust.set_birthday_date(ui->pg14_birthday->text().toStdString());
    cust.set_user_name(ui->pg14_username->text().toStdString());
    cust.set_password(ui->pg14_password->text().toStdString());
    acc.set_account_number(ui->pg14_accnum->text().toStdString());
    acc.set_national_code(ui->pg14_national_code->text().toStdString());
    acc.set_opening_date(ui->pg14_openingdate->text().toStdString());
    acc.set_stock(stoi(st));
    if(!bank.check_yakta_national_codes(cust.get_national_code()))
    {
        ui->pg14_textbrowser_result->setText("this national code is already used");
        return;
    }
    if(!bank.check_yakta_usernames(cust.get_user_name()))
    {
        ui->pg14_textbrowser_result->setText("this Username is already used");
        return;
    }
    if(!bank.check_yakta_account_number(acc.get_account_number()))
    {
        ui->pg14_textbrowser_result->setText("this account number is already used");
        return;
    }
    if(cust.check_info()&&acc.check_info())
    {
        cust.add_account(acc);
        bank.add_customer(cust);
        ui->pg14_textbrowser_result->setText("Dane");
        string report="a new Customer("+cust.get_national_code()+") created an account ("+acc.get_account_number()+")";
        bank.set_report(report);
        bank.save_data();
        return;
    }
    ui->pg14_textbrowser_result->setText("fill all lineedits correctly");
}
void MainWindow::on_pg13_pushbutton_add_clicked()
{
    time_t curr_time;
    tm *curr_tm;
    char date1[100];
    time(&curr_time);
    curr_tm=localtime(&curr_time);
    strftime(date1,50," %Y/%m/%d ",curr_tm);
    QString date_now=QString::fromStdString(date1);
    ui->pg15_opening_date->setText(date_now);
    ui->stackedWidget->setCurrentIndex(14);
}
void MainWindow::on_pg15_pushbutton_back_clicked()
{
    ui->pg15_accnum->setText("");
    ui->pg15_national_code->setText("");
    ui->pg15_stock->setText("");
    ui->pg15_textbrowser->setText("");
    ui->stackedWidget->setCurrentIndex(12);
}
void MainWindow::on_pg15_pushbutton_ok_clicked()
{
    int i=-1;
    string nc=ui->pg15_national_code->text().toStdString();
    for(unsigned int j=0;j<bank.get_customers().size();j++)
    {
        if(bank.get_customers().at(j).get_national_code()==nc)
        {
            i=j;
        }
    }
    if(i==-1)
    {
        ui->pg15_textbrowser->setText("this customer not found");
        return;
    }
    string st=ui->pg15_stock->text().toStdString();
    if(st=="")
    {
        ui->pg15_textbrowser->setText("complete lines first");
        return;
    }
    for(unsigned int j=0;j<st.size();j++)
    {
         if(st[j]!='0'&&st[j]!='1'&&st[j]!='2'&&st[j]!='3'&&st[j]!='4'&&st[j]!='5'&&st[j]!='6'&&st[j]!='7'&&st[j]!='8'&&st[j]!='9')
         {
             ui->pg15_textbrowser->setText("invalid stock");
             return;
         }
    }
    if(st.size()>7)
    {
        ui->pg15_textbrowser->setText("maximum money you can add is 9,999,999");
        return;
    }
    if(stoi(st)<50000)
    {
        ui->pg15_textbrowser->setText("base stock should be more than 50,000");
        return;
    }
    Account acc;
    acc.set_account_number(ui->pg15_accnum->text().toStdString());
    acc.set_national_code(ui->pg15_national_code->text().toStdString());
    acc.set_opening_date(ui->pg15_opening_date->text().toStdString());
    acc.set_stock(stoi(ui->pg15_stock->text().toStdString()));
    if(!bank.check_yakta_account_number(acc.get_account_number()))
    {
        ui->pg15_textbrowser->setText("this account number is already used");
        return;
    }
    if(acc.check_info())
    {
        bank.add_account(acc,i);
        ui->pg15_textbrowser->setText("Dane");
        string report="Customer("+bank.get_customers().at(i).get_national_code()+") created an account ("+acc.get_account_number()+")";
        bank.set_report(report);
        bank.save_data();
        return;
    }
    ui->pg15_textbrowser->setText("fill all lineedits correctly");
}
//employee delete account page:
void MainWindow::on_pg16_pushbutton_back_clicked()
{
    ui->pg16_lineedit_accnum->setText("");
    ui->pg16_textbrowser->setText("");
    ui->pg8_textBrowser->setText("");
    ui->stackedWidget->setCurrentIndex(7);
}
void MainWindow::on_pg16_pushbutton_ok_clicked()
{
    if(ui->pg16_lineedit_accnum->text()=="")
    {
        ui->pg16_textbrowser->setText("fill the lineedit first");
        return;
    }
    string accnum=ui->pg16_lineedit_accnum->text().toStdString();
    for(unsigned int i=0;i<bank.get_customers().size();i++)
    {
        for(unsigned int j=0;j<bank.get_customers().at(i).get_accounts().size();j++)
        {
            if(bank.get_customers().at(i).get_accounts().at(j).get_account_number()==accnum)
            {
                bank.delete_account(i,j);
                ui->pg16_textbrowser->setText("Done");
                string report="employee("+bank.get_employees().at(index_employee).get_personal_code()+")";
                report += (" deleted the account("+accnum+")");
                bank.set_report(report);
                bank.save_data();
                return;
            }
        }
    }
    ui->pg16_textbrowser->setText("not found");
}
//employee display employee info page:
void MainWindow::on_pg17_pushbutton_back_clicked()
{
    ui->pg8_textBrowser->setText("");
    ui->pg17_personal_code->setText("");
    ui->pg17_textbrowser->setText("");
    ui->stackedWidget->setCurrentIndex(7);
}
void MainWindow::on_pg17_pushbutton_ok_clicked()
{
    string personal_code=ui->pg17_personal_code->text().toStdString();
    if(personal_code=="")
    {
        ui->pg17_textbrowser->setText("Enter the Personal Code first");
        return;
    }
    for(unsigned int i=0;i<bank.get_employees().size();i++)
    {
        if(bank.get_employees().at(i).get_personal_code()==personal_code)
        {
            QString result=QString::fromStdString(bank.get_employees().at(i).get_all_info());
            ui->pg17_textbrowser->setText(result);
            return;
        }
    }
    ui->pg17_textbrowser->setText("not found");
}
//employee add employee page:
void MainWindow::on_pg18_pushbutton_back_clicked()
{
    ui->pg8_textBrowser->setText("");
    ui->pg18_name->setText("");
    ui->pg18_family->setText("");
    ui->pg18_birthday->setText("");
    ui->pg18_personal_code->setText("");
    ui->pg18_username->setText("");
    ui->pg18_password->setText("");
    ui->pg18_salary->setText("");
    ui->pg18_textbrowser->setText("");
    ui->stackedWidget->setCurrentIndex(7);
}
void MainWindow::on_pg18_pushbutton_ok_clicked()
{
    string salary=ui->pg18_salary->text().toStdString();
    if(salary=="")
    {
        ui->pg18_textbrowser->setText("fill all informations first");
        return;
    }
    for(unsigned int i=0;i<salary.size();i++)
    {
        if(salary[i]!='0'&&salary[i]!='1'&&salary[i]!='2'&&salary[i]!='3'&&salary[i]!='4'&&salary[i]!='5'&&salary[i]!='6'&&salary[i]!='7'&&salary[i]!='8'&&salary[i]!='9')
        {
            ui->pg18_textbrowser->setText("invalid salary");
            return;
        }
    }
    if(salary.size()>10)
    {
        ui->pg18_textbrowser->setText("maximum salary is 9,999,999,999");
        return;
    }
    if(salary.size()<7)
    {
        ui->pg18_textbrowser->setText("minimum salary is 1,000,000");
        return;
    }
    Employee emp;
    emp.set_name(ui->pg18_name->text().toStdString());
    emp.set_family(ui->pg18_family->text().toStdString());
    emp.set_birthday_date(ui->pg18_birthday->text().toStdString());
    emp.set_personal_code(ui->pg18_personal_code->text().toStdString());
    emp.set_user_name(ui->pg18_username->text().toStdString());
    emp.set_password(ui->pg18_password->text().toStdString());
    emp.set_salary(stoi(salary));
    if(!bank.check_yakta_personal_codes(emp.get_personal_code()))
    {
        ui->pg18_textbrowser->setText("this personal code is already used");
        return;
    }
    if(!bank.check_yakta_usernames(emp.get_user_name()))
    {
        ui->pg18_textbrowser->setText("this Username is already used");
        return;
    }
    if(emp.check_info())
    {
        bank.add_employee(emp);
        ui->pg18_textbrowser->setText("Done");
        string report="the manager(100) added a new employee("+emp.get_personal_code()+")";
        bank.set_report(report);
        bank.save_data();
        return;
    }
    ui->pg18_textbrowser->setText("fill all informations correctly");
}
//employee delete employee page:
void MainWindow::on_pg19_pushbutto_back_clicked()
{
    ui->pg8_textBrowser->setText("");
    ui->pg19_personal_code->setText("");
    ui->pg19_textbrowser->setText("");
    ui->stackedWidget->setCurrentIndex(7);
}
void MainWindow::on_pg19_pushbutto_ok_clicked()
{
    string personal_code=ui->pg19_personal_code->text().toStdString();
    if(personal_code=="")
    {
        ui->pg18_textbrowser->setText("Enter the Personal Code first");
        return;
    }
    for(unsigned int i=0;i<bank.get_employees().size();i++)
    {
        if(bank.get_employees().at(i).get_personal_code()==personal_code)
        {
            bank.delete_employee(i);
            ui->pg19_textbrowser->setText("Done");
            string report="the manager(100) deleted the employee("+personal_code+")";
            bank.set_report(report);
            bank.save_data();
            return;
        }
    }
    ui->pg19_textbrowser->setText("Not Found");
}





























































