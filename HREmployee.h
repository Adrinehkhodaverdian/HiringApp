/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                          HREmployeee
 -----------------------------------------------------------------

 -----------------------------------------------------------------
+HREmployee(name: const string &,last: const string &,job: const string &,ID: const string & , department: const string & )
+~HREmployee();
+DisplayMenu(): void
+checkIDMatchingTitle() const: bool
 -----------------------------------------------------------------
                    Friend Functions
 operator<<( output: ostream&, HREmp :const HREmployee&): ostream&
 
 */
#ifndef HREmployee_h
#define HREmployee_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Date.h"
#include "Employee.h"
using namespace std;

class HREmployee : public Employee
{
    friend ostream& operator<<( ostream&, const HREmployee&);
private:
    
public:
    ~HREmployee();
    HREmployee(const string & ="NULL", const string & ="NULL", const string & ="NULL", const string & ="NULL", const string & ="NULL");
    //the display menu will give some options for the HR employees that other employees
    // should not have access to, so this is unique.
    virtual void DisplayMenu()override;
    /*
     The function checks to see if the person entring the ID matches the job Title, because H1234579 is for HR employess and C1234900 is for casual employess
        so this should be verified in the dervied classes.
     */
    virtual bool checkIDMatchingTitle() const  override;
    /*
     The below function uses the Search Applicants files and finds the qualifed ones,
     prinrs them to a file, and then the HR department can refer to it.
     */
    void qualifiedApplicantsInfo();
    
};

#endif /* HREmployee_h */
