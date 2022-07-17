#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include<vector>
using namespace std;

class Employee
{
public:
    Employee();
    inline string get_name(){return name;}
    inline string get_family(){return family;}
    inline string get_personal_code(){return personal_code;}
    inline string get_birthday_date(){return birthday_date;}
    inline string get_user_name(){return user_name;}
    inline string get_password(){return password;}
    inline long long get_salary(){return salary;}
    inline int get_leave_hours(){return leave_hours;}
    inline int get_overtime_hours(){return overtime_hours;}
    inline void set_name(string n){name=n;}
    inline void set_family(string f){family=f;}
    inline void set_personal_code(string pc){personal_code=pc;}
    inline void set_birthday_date(string bd){birthday_date=bd;}
    inline void set_user_name(string un){user_name=un;}
    inline void set_password(string p){password=p;}
    inline void set_salary(long long s){salary=s;}
    inline void set_leave_hours(int lh){leave_hours=lh;}
    inline void set_overtime_hours(int oth){overtime_hours=oth;}
    bool check_info();
    string increase_leave_hours(string);
    string increase_overtime(string);
    string get_all_info();

private:
    string name,family,personal_code,birthday_date,user_name,password;
    long long salary;
    int leave_hours,overtime_hours;
};

#endif // EMPLOYEE_H
