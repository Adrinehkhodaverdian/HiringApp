/*Adrineh Khodaverdian
 CS/IS 137
 Final Project*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;
#include "EMailAddress.h"

EMailAddress::EMailAddress(const string & userN, const string & host): userName(userN), domainName(host)
{
    
}
/**********************Set Functions************************/
EMailAddress& EMailAddress::setUserName( const string& userN)
{
    
    for(int i=0; i<userN.length(); i++)
    {
        userName=(!isspace(userN[i])? userN :"NULL");
    }
    return *this;
    
}
EMailAddress& EMailAddress::setDomainName(const string& host)
{
    return *this;
}
/**********************get Functions************************/
string EMailAddress::getUserName() const
{
    return userName;
}
string EMailAddress::getDomainName() const
{
    return domainName;
}

//global overloaded stream insertion operator, can NOT be
//is a friend so it can access private member data and save overhead
ostream& operator<<(ostream& output, const EMailAddress& email)
{
   output << email.userName << "@ "<< email.domainName;
   return output;  //enables cout << a << b << c;
}

//global overloaded stream extraction operator, can NOT be
//is a friend so it can access private member data and save overhead
istream& operator>>(istream& input,EMailAddress& email)
{

    input >>email.userName;
    input.ignore(1); //to skip the @
    input >>email.domainName;
    return input;

}
