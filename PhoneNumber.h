/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                          PhoneNumber
 -----------------------------------------------------------------
 -areaCode:string
 -exchange:string
 -line:string
 -----------------------------------------------------------------
 +PhoneNumber( areaC: const string& , ex:cosnt string& , ln: const string&)
 +setAreaCode(areaC : const string& ) : PhoneNumber&
 +setExchange(ex :const string&) : PhoneNumber&
 +setLine(ln: const string&): PhoneNumber&
 +getAreaCode()const :string
 +getExchange() const :string
 +getLine() const :string
 -----------------------------------------------------------------
                   |friend functions|
  operator<<( output : ostream&, phoneNumber: const PhoneNumber&) : ostream&
  operator>>( input  : istream&,  phoneNumber: PhoneNumber&) : istream&
 */

#ifndef PhoneNumber_h
#define PhoneNumber_h

#include <iostream>
#include <string>
using namespace std;

class PhoneNumber
{
    //by convention these prototypes are outside of private and public
    friend ostream& operator<<(ostream&, const PhoneNumber&);
    friend istream& operator>>(istream&, PhoneNumber&);

    private:
     string areaCode;
     string exchange;  //1st three digits of regular phone number
     string line;      //last four digits of regular phone number
    public:
        PhoneNumber(const string& = "NULL", const string& ="NULL", const string & ="NULL");
        PhoneNumber& setAreaCode(const string&);
        PhoneNumber& setExchange(const string&);
        PhoneNumber& setLine(const string&);
        string getAreaCode() const;
        string getExchange() const;
        string getLine() const;
    

    
};
#endif /* PhoneNumber_h */
