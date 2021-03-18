/*Adrineh Khodaverdian
 CS/IS 137
 Final Project*/

#include <stdio.h>
#include <iomanip>
using namespace std;

#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(const string& areaC, const string& ex, const string & ln):
areaCode(areaC), exchange(ex),line(ln)
{
   //used member initilizer
}
PhoneNumber& PhoneNumber::setAreaCode(const string& areaC)
{
    areaCode=areaC;
    return *this;
}

PhoneNumber& PhoneNumber::setExchange(const string& ex)
{
    exchange=ex;
    return *this;
}
PhoneNumber& PhoneNumber::setLine(const string& ln)
{
    line=ln;
    return *this;
}
string PhoneNumber::getAreaCode() const
{
    return areaCode;
}
string PhoneNumber::getExchange() const
{
    return exchange;
}
string PhoneNumber::getLine() const
{
    return line;
    
}
//global overloaded stream insertion operator, can NOT be
//a member function if we want to invoke it like so:  cout << PhoneNumberObject;
//is a friend so it can access private member data and save overhead
ostream& operator<<(ostream& output, const PhoneNumber& number)
{
   output << "(" << number.getAreaCode() << ") "
          << number.getExchange() << "-" << number.getLine();
   return output;  //enables cout << a << b << c;
}

//global overloaded stream extraction operator, can NOT be
//a member function if we can tto invoke it like so:  cin >> PhoneNumberObject;
//is a friend so it can access private member data and save overhead
istream& operator>>(istream& input, PhoneNumber& number)
{
   input.ignore();  //to skip the "("
   input >> setw(3) >> number.areaCode;
   input.ignore(2); //to skip the ") and the space
   input >> setw(3) >> number.exchange;
   input.ignore();  //to skip the dash (-)
   input >> setw(4) >> number.line;
   return input;  //enables cin >> a >> b >> c;
}
