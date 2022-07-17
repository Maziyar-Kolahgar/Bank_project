#include "account.h"
Account::Account()
{
    account_number="00000000";
    national_code="0000000000";
    opening_date="1400/01/01";
    stock=0;
    active=true;
}
//string account_number,national_code,opening_date;
//long long stock;
//bool active;
bool Account::check_info()
{
    if(account_number.size()!=8)
        return false;
    for(int i=0;i<8;i++)
    {
        if(account_number[i]!='0'&&account_number[i]!='1'&&account_number[i]!='2'&&account_number[i]!='3'&&account_number[i]!='4'&&account_number[i]!='5'&&account_number[i]!='6'&&account_number[i]!='7'&&account_number[i]!='8'&&account_number[i]!='9')
            return false;
    }
    if(national_code.size()!=10)
        return false;
    for(int i=0;i<10;i++)
    {
        if(national_code[i]!='0'&&national_code[i]!='1'&&national_code[i]!='2'&&national_code[i]!='3'&&national_code[i]!='4'&&national_code[i]!='5'&&national_code[i]!='6'&&national_code[i]!='7'&&national_code[i]!='8'&&national_code[i]!='9')
            return false;
    }
    if(stock<0)
        return false;
    return true;
}
string Account::get_all_info()
{
    string result="Account Number: "+account_number+"\nOpening Date: "+opening_date+"\nStock: ";
    result += (to_string(stock)+" toomans\n");
    if(active)
        result+="This account is Active\n";
    else
        result+="This account id Banned\n";
    return result;
}

















