#include "customer.h"
Customer::Customer()
{
    name="noname";
    family="nofamily";
    national_code="0000000000";
    birthday_date="1400/01/01";
    user_name="user_name";
    password="1111";
}
//string name,family,national_code,birthday_date,user_name,password;
//vector<Account> accounts;
bool Customer::check_info()
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
    if(national_code.size()!=10)
        return false;
    for(int i=0;i<10;i++)
    {
        if(national_code[i]!='0'&&national_code[i]!='1'&&national_code[i]!='2'&&national_code[i]!='3'&&national_code[i]!='4'&&national_code[i]!='5'&&national_code[i]!='6'&&national_code[i]!='7'&&national_code[i]!='8'&&national_code[i]!='9')
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
    return true;
}
void Customer::delete_account(int i_acc)
{
    int finali=accounts.size()-1;
    if(i_acc==finali)
        accounts.pop_back();
    else
    {
        accounts.erase(accounts.begin()+i_acc);
    }
}
void Customer::increase_stock(int acc_i,long long ns)
{
    accounts.at(acc_i).increase_stock(ns);
}
void Customer::decrease_stock(int acc_i,long long ns)
{
    accounts.at(acc_i).decrease_stock(ns);
}
string Customer::get_all_info()
{
    string result="Name and Family: "+name+" "+family+"\nNational Code: "+national_code+"\nBirthday Date: "+birthday_date;
    result += ("\nUsername: "+user_name+"\nPassword: "+password+"\nAccounts:\n");
    for(unsigned int i=0;i<accounts.size();i++)
    {
        result += (to_string(i+1)+"- "+accounts.at(i).get_account_number()+"\n");
    }
    return result;
}
string Customer::get_all_info_with_accounts()
{
    string result="Name and Family: "+name+" "+family+"\nNational Code: "+national_code+"\nBirthday Date: "+birthday_date;
    result += ("\nUsername: "+user_name+"\nPassword: "+password+"\nAccounts:\n\n");
    for(unsigned int i=0;i<accounts.size();i++)
    {
        result += (to_string(i+1)+":\naccount number: "+accounts.at(i).get_account_number()+"\nOpening Date: ");
        result += (accounts.at(i).get_opening_date()+"\nStock: "+to_string(accounts.at(i).get_stock()));
        if(accounts.at(i).get_active())
            result += "\nthis account is active\n\n";
        else
            result += "\nthis account is banned\n\n";
    }
    return result;
}

