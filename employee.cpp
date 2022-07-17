#include "employee.h"
Employee::Employee()
{
    name="noname";
    family="nofamily";
    personal_code="000";
    birthday_date="1400/01/01";
    user_name="user_name";
    password="1111";
    salary=0;
    leave_hours=0;
    overtime_hours=0;
}
//string name,family,personal_code,birthday_date,user_name,password;
//long long salary;
//int leave_hours,overtime_hours;
bool Employee::check_info()
{
    if(name.size()<2||family.size()<2||user_name.size()==0||password.size()==0)
        return false;
    for(unsigned int i=0;i<name.size();i++)
    {
        if((int(name.at(i))<97||int(name.at(i))>122)&&(int(name.at(i))<65||int(name.at(i))>90))
            return false;
    }
    for(unsigned int i=0;i<family.size();i++)
    {
        if((int(family.at(i))<97||int(family.at(i))>122)&&(int(family.at(i))<65||int(family.at(i))>90))
            return false;
    }
    if(personal_code.size()!=3)
        return false;
    for(int i=0;i<3;i++)
    {
        if(personal_code[i]!='0'&&personal_code[i]!='1'&&personal_code[i]!='2'&&personal_code[i]!='3'&&personal_code[i]!='4'&&personal_code[i]!='5'&&personal_code[i]!='6'&&personal_code[i]!='7'&&personal_code[i]!='8'&&personal_code[i]!='9')
            return false;
    }
    int ns=0;
    vector<int> poss;
    for(unsigned int i=0;i<birthday_date.size();i++)
    {
        if(birthday_date.at(i)=='/')
        {
            ns++;
            poss.push_back(i);
        }
    }
    if(ns!=2)
        return false;
    string y="",m="",d="";
    for(int i=0;i<poss.at(0);i++)
        y.push_back(birthday_date.at(i));
    for(int i=poss.at(0)+1;i<poss.at(1);i++)
        m.push_back(birthday_date.at(i));
    for(unsigned int i=poss.at(1)+1;i<birthday_date.size();i++)
        d.push_back(birthday_date.at(i));
    for(unsigned int i=0;i<y.size();i++)
    {
        if(y[i]!='0'&&y[i]!='1'&&y[i]!='2'&&y[i]!='3'&&y[i]!='4'&&y[i]!='5'&&y[i]!='6'&&y[i]!='7'&&y[i]!='8'&&y[i]!='9')
            return false;
    }
    for(unsigned int i=0;i<m.size();i++)
    {
        if(m[i]!='0'&&m[i]!='1'&&m[i]!='2'&&m[i]!='3'&&m[i]!='4'&&m[i]!='5'&&m[i]!='6'&&m[i]!='7'&&m[i]!='8'&&m[i]!='9')
            return false;
    }
    for(unsigned int i=0;i<d.size();i++)
    {
        if(d[i]!='0'&&d[i]!='1'&&d[i]!='2'&&d[i]!='3'&&d[i]!='4'&&d[i]!='5'&&d[i]!='6'&&d[i]!='7'&&d[i]!='8'&&d[i]!='9')
            return false;
    }
    int yy=stoi(y),mm=stoi(m),dd=stoi(d);
    if(yy<1250||yy>1400||mm<1||mm>12||dd<1||dd>31||(mm>6&&dd==31)||(mm==12&&dd==30))
        return false;
    if(salary<0||leave_hours<0||overtime_hours<0)
        return false;
    return true;
}
string Employee::increase_leave_hours(string lineedit)
{
    if(lineedit=="")
        return "First fill the line edit";
    for(unsigned int i=0;i<lineedit.size();i++)
    {
        if(lineedit[i]!='0'&&lineedit[i]!='1'&&lineedit[i]!='2'&&lineedit[i]!='3'&&lineedit[i]!='4'&&lineedit[i]!='5'&&lineedit[i]!='6'&&lineedit[i]!='7'&&lineedit[i]!='8'&&lineedit[i]!='9')
        {
            return "invalid input in lineedit";
        }
    }
    if(lineedit.size()>2)
        return "you can enter 0 to 99 only";
    int inc=stoi(lineedit);
    if(inc==0)
        return "no Change";
    string r=to_string(leave_hours)+" --> ";
    if(inc+leave_hours>15)
    {
        if(salary-(inc*100000)<0)
            return "not enough salary";
        salary-=(inc*100000);
        leave_hours+=inc;
        return r+to_string(leave_hours)+"\nSalary now: "+to_string(salary);
    }
    leave_hours+=inc;
    return r+to_string(leave_hours)+"\nSalary now: "+to_string(salary);
}
string Employee::increase_overtime(string lineedit)
{
    if(lineedit=="")
        return "First fill the lineedit";
    for(unsigned int i=0;i<lineedit.size();i++)
    {
        if(lineedit[i]!='0'&&lineedit[i]!='1'&&lineedit[i]!='2'&&lineedit[i]!='3'&&lineedit[i]!='4'&&lineedit[i]!='5'&&lineedit[i]!='6'&&lineedit[i]!='7'&&lineedit[i]!='8'&&lineedit[i]!='9')
        {
            return "invalid input in lineedit";
        }
    }
    if(lineedit.size()>2)
        return "you can enter 0 to 99 only";
    if(overtime_hours==12)
        return "you used all of your overtime hours already";
    int inc=stoi(lineedit);
    if(inc==0)
        return "no Change";
    if(inc+overtime_hours>12)
        return "you can use only 12 hours a month and "+to_string(inc+overtime_hours)+">12";
    string previous=to_string(overtime_hours);
    overtime_hours+=inc;
    salary+=(120000*inc);
    return previous+" --> "+to_string(overtime_hours)+"\nSalary now: "+to_string(salary);

}
string Employee::get_all_info()
{
    string result = "Name: "+name+"\nFamily: "+family+"\nPersonal code: "+personal_code+"\nBirthday Date: ";
    result += (birthday_date+"\nUsername: "+user_name+"\nPassword: "+password+"\nSalary: "+to_string(salary));
    result += ("\nRest hours used: "+to_string(leave_hours)+"\nOvertime hours used: "+to_string(overtime_hours));
    return result;
}
