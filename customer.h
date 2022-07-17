#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<vector>
#include"account.h"
using namespace std;

class Customer
{
public:
    Customer();
    inline string get_name(){return name;}
    inline string get_family(){return family;}
    inline string get_national_code(){return national_code;}
    inline string get_birthday_date(){return birthday_date;}
    inline string get_user_name(){return user_name;}
    inline string get_password(){return password;}
    inline vector<Account> get_accounts(){return accounts;}
    inline void set_name(string n){name=n;}
    inline void set_family(string f){family=f;}
    inline void set_national_code(string nc){national_code=nc;}
    inline void set_birthday_date(string bd){birthday_date=bd;}
    inline void set_user_name(string un){user_name=un;}
    inline void set_password(string p){password=p;}
    inline void set_accounts(vector<Account> accs){accounts=accs;}
    inline void add_account(Account acc){accounts.push_back(acc);}
    void delete_account(int);
    bool check_info();
    void increase_stock(int,long long);
    void decrease_stock(int,long long);
    string get_all_info();
    string get_all_info_with_accounts();

private:
    string name,family,national_code,birthday_date,user_name,password;
    vector<Account> accounts;
};

#endif // CUSTOMER_H
