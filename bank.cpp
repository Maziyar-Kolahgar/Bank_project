#include "bank.h"
//vector<Employee> employees;
//vector<Customer> customers;
//string branch_name,branch_code;
//Employee manager,facilities;
//int days;
bool Bank::check_info()
{
    if(branch_code.size()>3)
        return false;
    for(unsigned int i=0;i<branch_code.size();i++)
    {
        if(branch_code[i]!='0'&&branch_code[i]!='1'&&branch_code[i]!='2'&&branch_code[i]!='3'&&branch_code[i]!='4'&&branch_code[i]!='5'&&branch_code[i]!='6'&&branch_code[i]!='7'&&branch_code[i]!='8'&&branch_code[i]!='9')
            return false;
    }
    return true;
}
bool Bank::check_yakta_usernames(string new_user_name)
{
    for(unsigned int i=0;i<employees.size();i++)
    {
        if(new_user_name==employees.at(i).get_user_name())
            return false;
    }
    for(unsigned int i=0;i<customers.size();i++)
    {
        if(new_user_name==customers.at(i).get_user_name())
            return false;
    }
    if(new_user_name==manager.get_user_name()||new_user_name==facilities.get_user_name())
        return false;
    return true;
}
bool Bank::check_yakta_passwords(string new_password)
{
    for(unsigned int i=0;i<employees.size();i++)
    {
        if(new_password==employees.at(i).get_password())
            return false;
    }
    for(unsigned int i=0;i<customers.size();i++)
    {
        if(new_password==customers.at(i).get_password())
           return false;
    }
    if(new_password==manager.get_password()||new_password==facilities.get_password())
        return false;
    return true;
}
bool Bank::check_yakta_national_codes(string new_national_code)
{
    for(unsigned int i=0;i<customers.size();i++)
    {
        if(new_national_code==customers.at(i).get_national_code())
            return false;
    }
    return true;
}
bool Bank::check_yakta_personal_codes(string new_personal_code)
{
    if(new_personal_code==manager.get_personal_code()||new_personal_code==facilities.get_personal_code())
        return false;
    for(unsigned int i=0;i<employees.size();i++)
    {
        if(new_personal_code==employees.at(i).get_personal_code())
            return false;
    }
    return true;
}
bool Bank::check_yakta_account_number(string new_account_number)
{
    for(unsigned int i=0;i<customers.size();i++)
    {
        for(unsigned int j=0;j<customers.at(i).get_accounts().size();j++)
        {
            if(new_account_number==customers.at(i).get_accounts().at(j).get_account_number())
                return false;
        }
    }
    return true;
}
void Bank::save_data()
{
    ofstream fout("Bank_Data",ios::trunc);
    if(fout)
    {
        fout<<branch_name<<" "<<branch_code<<"\nManager:  ";
        fout<<manager.get_name()<<" "<<manager.get_family()<<" ";
        fout<<manager.get_personal_code()<<" "<<manager.get_birthday_date()<<" ";
        fout<<manager.get_user_name()<<" "<<manager.get_password()<<" ";
        fout<<manager.get_salary()<<" "<<manager.get_leave_hours()<<" "<<manager.get_overtime_hours()<<"\nFacilities:  ";
        fout<<facilities.get_name()<<" "<<facilities.get_family()<<" ";
        fout<<facilities.get_personal_code()<<" "<<facilities.get_birthday_date()<<" ";
        fout<<facilities.get_user_name()<<" "<<facilities.get_password()<<" ";
        fout<<facilities.get_salary()<<" "<<facilities.get_leave_hours()<<" "<<facilities.get_overtime_hours()<<"\n";
        fout<<"Employees:   "<<employees.size()<<"\n";
        for(unsigned int i=0;i<employees.size();i++)
        {
            fout<<i+1<<"- "<<employees.at(i).get_name()<<" "<<employees.at(i).get_family()<<" ";
            fout<<employees.at(i).get_personal_code()<<" "<<employees.at(i).get_birthday_date()<<" ";
            fout<<employees.at(i).get_user_name()<<" "<<employees.at(i).get_password()<<" ";
            fout<<employees.at(i).get_salary()<<" "<<employees.at(i).get_leave_hours()<<" "<<employees.at(i).get_overtime_hours()<<"\n";
        }
        fout<<"Customers:   "<<customers.size()<<"\n";
        for(unsigned int i=0;i<customers.size();i++)
        {
            fout<<i+1<<"- "<<customers.at(i).get_name()<<" "<<customers.at(i).get_family()<<" ";
            fout<<customers.at(i).get_national_code()<<" "<<customers.at(i).get_birthday_date()<<" ";
            fout<<customers.at(i).get_user_name()<<" "<<customers.at(i).get_password()<<"\n          Accounts:  "<<customers.at(i).get_accounts().size()<<"\n";
            for(unsigned int j=0;j<customers.at(i).get_accounts().size();j++)
            {
                fout<<"          "<<j+1<<"- "<<customers.at(i).get_accounts().at(j).get_account_number()<<" ";
                fout<<customers.at(i).get_accounts().at(j).get_national_code()<<" "<<customers.at(i).get_accounts().at(j).get_opening_date()<<" ";
                fout<<customers.at(i).get_accounts().at(j).get_stock()<<" "<<customers.at(i).get_accounts().at(j).get_active()<<"\n";
            }
        }
        fout<<days<<"\n";
        fout<<"\nFinished";
        fout.close();
    }
}
void Bank::read_data()
{
    string nothing;
    int inothing;
    long long llnothing;
    ofstream fout("Bank_Data",ios::app); //to make sure we have the file
    ifstream fin("Bank_Data",ios::in);
    while(fin)
    {
        /////manager
        fin>>branch_name>>branch_code>>nothing>>nothing;
        manager.set_name(nothing);
        fin>>nothing;
        manager.set_family(nothing);
        fin>>nothing;
        manager.set_personal_code(nothing);
        fin>>nothing;
        manager.set_birthday_date(nothing);
        fin>>nothing;
        manager.set_user_name(nothing);
        fin>>nothing;
        manager.set_password(nothing);
        fin>>llnothing;
        manager.set_salary(llnothing);
        fin>>inothing;
        manager.set_leave_hours(inothing);
        fin>>inothing;
        manager.set_overtime_hours(inothing);
        /////facilities
        fin>>nothing>>nothing;
        facilities.set_name(nothing);
        fin>>nothing;
        facilities.set_family(nothing);
        fin>>nothing;
        facilities.set_personal_code(nothing);
        fin>>nothing;
        facilities.set_birthday_date(nothing);
        fin>>nothing;
        facilities.set_user_name(nothing);
        fin>>nothing;
        facilities.set_password(nothing);
        fin>>llnothing;
        facilities.set_salary(llnothing);
        fin>>inothing;
        facilities.set_leave_hours(inothing);
        fin>>inothing;
        facilities.set_overtime_hours(inothing);
        /////employees
        unsigned int size;
        fin>>nothing>>size;
        employees.resize(size);
        for(unsigned int i=0;i<size;i++)
        {
            fin>>nothing>>nothing;
            employees.at(i).set_name(nothing);
            fin>>nothing;
            employees.at(i).set_family(nothing);
            fin>>nothing;
            employees.at(i).set_personal_code(nothing);
            fin>>nothing;
            employees.at(i).set_birthday_date(nothing);
            fin>>nothing;
            employees.at(i).set_user_name(nothing);
            fin>>nothing;
            employees.at(i).set_password(nothing);
            fin>>llnothing;
            employees.at(i).set_salary(llnothing);
            fin>>inothing;
            employees.at(i).set_leave_hours(inothing);
            fin>>inothing;
            employees.at(i).set_overtime_hours(inothing);
        }
        /////custemors
        fin>>nothing>>size;
        customers.resize(size);
        unsigned int size2;
        for(unsigned int i=0;i<size;i++)
        {
            fin>>nothing>>nothing;
            customers.at(i).set_name(nothing);
            fin>>nothing;
            customers.at(i).set_family(nothing);
            fin>>nothing;
            customers.at(i).set_national_code(nothing);
            fin>>nothing;
            customers.at(i).set_birthday_date(nothing);
            fin>>nothing;
            customers.at(i).set_user_name(nothing);
            fin>>nothing;
            customers.at(i).set_password(nothing);
            fin>>nothing>>size2;
            for(unsigned int j=0;j<size2;j++)
            {
                fin>>nothing>>nothing;
                Account acc;
                acc.set_account_number(nothing);
                fin>>nothing;
                acc.set_national_code(nothing);
                fin>>nothing;
                acc.set_opening_date(nothing);
                fin>>llnothing;
                acc.set_stock(llnothing);
                bool act;
                fin>>act;
                acc.set_active(act);
                customers.at(i).add_account(acc);
            }
        }
        fin>>days>>nothing>>nothing;
        fin.close();
    }

}
void Bank::increase_stock(int cust_i,int acc_i,long long ns)
{
    customers.at(cust_i).increase_stock(acc_i,ns);
}
void Bank::decrease_stock(int cust_i,int acc_i,long long ns)
{
    customers.at(cust_i).decrease_stock(acc_i,ns);
}
void Bank::set_report(string new_line)
{
    time_t curr_time;
    tm *curr_tm;
    char date1[100];
    time(&curr_time);
    curr_tm=localtime(&curr_time);
    strftime(date1,50," in Date %Y/%m/%d and Time %H:%M ",curr_tm);
    string date2=date1;
    ofstream report_file("report.txt",ios::app);
    if(report_file)
    {
        report_file<<new_line<<date2<<"\n";
        report_file.close();
    }
}
string Bank::increase_leave_hours(int i,string inc)
{
    if(i==-2)
        return manager.increase_leave_hours(inc);
    return employees.at(i).increase_leave_hours(inc);
}
string Bank::increase_overtime(int i,string inc)
{
    if(i==-2)
        return manager.increase_overtime(inc);
    return employees.at(i).increase_overtime(inc);
}
void Bank::reset_days()
{
    if(days<30)
        days++;
    else
    {
        days=1;
        for(unsigned int i=0;i<employees.size();i++)
        {
            if(employees.at(i).get_leave_hours()>15)
                employees.at(i).set_salary(employees.at(i).get_salary()+((employees.at(i).get_leave_hours()-15)*100000));
            employees.at(i).set_salary(employees.at(i).get_salary()-(employees.at(i).get_overtime_hours()*120000));
            if(employees.at(i).get_salary()<0)
                employees.at(i).set_salary(0);
            employees.at(i).set_leave_hours(0);
            employees.at(i).set_overtime_hours(0);


        }
    }
}
void Bank::delete_account(int i_cust,int i_acc)
{
    customers.at(i_cust).delete_account(i_acc);
    if(customers.at(i_cust).get_accounts().size()==0)
    {
        int finali=customers.size()-1;
        if(i_cust==finali)
            customers.pop_back();
        else
        {
            for(int i=i_cust;i<finali;i++)
            {
                swap(customers.at(i),customers.at(i+1));
            }
            customers.pop_back();
        }
    }
}
void Bank::delete_employee(int i_emp)
{
    int finali=employees.size()-1;
    if(i_emp==finali)
        employees.pop_back();
    else
    {
        employees.erase(employees.begin()+i_emp);
    }

}










