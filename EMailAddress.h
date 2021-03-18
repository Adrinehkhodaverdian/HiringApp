/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                          EmailAddress
 -----------------------------------------------------------------
 -userName:string
 -domainName:string

 -----------------------------------------------------------------
 +EmailAddress( userN: const string& ,domianN:cosnt string& )
 +setUserName(userNC : const string& ) : EmailAddrssr&
 +setDomainName(domainN :const string&) : EmailAddress&

 +getUserName() const :string
 +getDomainName() const :string
 -----------------------------------------------------------------
                   |friend functions|
  operator<<( output : ostream&, email: const EmailAddressr&) : ostream&
  operator>>( input  : istream&, email : EmailAddress&) : istream&
 */

#ifndef EMailAddress_h
#define EMailAddress_h
#include <iostream>
#include <string>
using namespace std;
class EMailAddress
{
    //by convention these prototypes are outside of private and public
    friend ostream& operator<<(ostream&, const EMailAddress&);
    friend istream& operator>>(istream&, EMailAddress&);
    
    private:
       string userName;   //the name of email before the @
       string domainName;  //the website prviding the email after the @ sign
    public:
    EMailAddress(const string & = "NULL", const string & = "NULL");
    /**********************Set Functions************************/
    EMailAddress& setUserName( const string& );
    EMailAddress& setDomainName(const string&);
    /**********************get Functions************************/
    string getUserName() const;
    string getDomainName() const;
    
    
    
};

#endif /* EMailAddress_h */
