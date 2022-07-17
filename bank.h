#ifndef BANK_H
#define BANK_H
#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include"employee.h"
#include"customer.h"
#include"account.h"
using namespace std;
class Bank
{
public:
    Bank():branch_name("Branch_name"),branch_code("0"),days(1){}
    inline vector<Employee> get_employees(){return employees;}
    inline vector<Customer> get_customers(){return customers;}
    inline string get_branch_name(){return branch_name;}
    inline string get_branch_code(){return branch_code;}
    inline Employee get_manager(){return manager;}
    inline Employee get_facilities(){return facilities;}
    inline int get_days(){return days;}
    inline void set_employees(vector<Employee> emps){employees=emps;}
    inline void set_customers(vector<Customer> custs){customers=custs;}
    inline void set_branch_name(string bn){branch_name=bn;}
    inline void set_branch_code(string bc){branch_code=bc;}
    inline void set_manager(Employee m){manager=m;}
    inline void set_facilities(Employee f){facilities=f;}
    inline void set_days(int d){days=d;}
    inline void add_customer(Customer c){customers.push_back(c);}
    inline void add_employee(Employee e){employees.push_back(e);}
    inline void add_account(Account a,int i){customers.at(i).add_account(a);}
    void delete_account(int,int);
    void delete_employee(int);
    bool check_info();
    bool check_yakta_usernames(string);
    bool check_yakta_passwords(string);
    bool check_yakta_national_codes(string);
    bool check_yakta_personal_codes(string);
    bool check_yakta_account_number(string);
    void reset_days();
    void save_data();
    void read_data();
    void increase_stock(int,int,long long);
    void decrease_stock(int,int,long long);
    string increase_leave_hours(int,string);
    string increase_overtime(int,string);
    void set_report(string);
private:
    vector<Employee> employees;
    vector<Customer> customers;
    string branch_name,branch_code;
    Employee manager,facilities;
    int days;

};

#endif // BANK_H
