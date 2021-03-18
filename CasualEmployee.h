/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                        CasualEmployeee
 -----------------------------------------------------------------

 -----------------------------------------------------------------
+CasualEmployee(name: const string &,last: const string &,job: const string &,ID: const string & , department: const string & )
+~CasualEmployee();
+DisplayMenu(): void
+checkIDMatchingTitle() const: bool
 -----------------------------------------------------------------
                    Friend Functions
 operator<<( output: ostream&, casualEmp :const CasualEmployee&): ostream&
 */

#ifndef CasualEmployee_h
#define CasualEmployee_h
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Employee.h"
#include <string>
using namespace std;
class CasualEmployee : public Employee
{
    friend ostream& operator<<(ostream&, const CasualEmployee&);
    //friend istream& operator>>( input  : istream&, CasualEmployee: CasualEmployee&) ;
private:

public:
    CasualEmployee(const string & ="NULL", const string & ="NULL", const string & ="NULL", const string & ="NULL",const string & = "NULL");
    //the display menu will give some options for the HR employees that other employees
    // should not have access to, so this is unique.
    virtual void DisplayMenu();
    /*
     The function checks to see if the person entring the ID matches the job Title, because H1234579 is for HR employess and C1234900 is for casual employess
        so this should be verified in the dervied classes.
     */
    virtual bool checkIDMatchingTitle() const;
};
#endif /* CasualEmployee_h */
