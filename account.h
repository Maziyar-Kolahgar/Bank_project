#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<vector>
using namespace std;

class Account
{
public:
    Account();
    Account(string an,string nc,string od,long int s,bool a):account_number(an),national_code(nc),opening_date(od),stock(s),active(a){}
    inline string get_account_number(){return account_number;}
    inline string get_national_code(){return national_code;}
    inline string get_opening_date(){return opening_date;}
    inline long long get_stock(){return stock;}
    inline bool get_active(){return active;}
    inline void set_account_number(string an){account_number=an;}
    inline void set_national_code(string nc){national_code=nc;}
    inline void set_opening_date(string od){opening_date=od;}
    inline void set_stock(long long s){stock=s;}
    inline void set_active(bool a){active=a;}
    inline void increase_stock(long long incs){stock+=incs;}
    inline void decrease_stock(long long decs){stock-=decs;}
    bool check_info();
    string get_all_info();



private:
    string account_number,national_code,opening_date;
    long long stock;
    bool active;

};

#endif // ACCOUNT_H
