/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include "Date.h"
#include "Employee.h"
#include "CasualEmployee.h"
using namespace std;


CasualEmployee::CasualEmployee(const string& nm, const string& last, const string& title, const string& ID,const string& dep): Employee( nm, last, title, ID, dep)
{
    //
}

//the display menu will give some options for the HR employees that other employees
// should not have access to, so this is unique.
void CasualEmployee::DisplayMenu()
{
    if(checkIDMatchingTitle())
    {
        cout << "Welcome To Employee Department main menu!"<<endl;
        cout << "To get information about your employement status,weekly schedule, or payroll info, please dial 1-800-MYInfo, on the back of your Employment ID card, in case of other emergencies please contact your manager"<<endl;
        cout<< "0)to exit!"<<endl;
    }
    else
    {
        cout<< "Information provided does not match!"<<endl;
    }

}
/*
 The function checks to see if the person entring the ID matches the job Title, because H1234579 is for HR employess and C1234900 is for casual employess
    so this should be verified in the dervied classes.
 */
bool CasualEmployee::checkIDMatchingTitle() const
{
    string id=getEmployeeID();
    bool valid{true};
   if(getDepartment()!="HR"|| getDepartment()!="hr")
    {
        if(id[0]!='H' || id[0]!='h')
        {
            valid=true;
        }
        else
        {
            valid=false;
        }
    }
    return valid;
}
/*
 The below function uses the Search Applicants files and finds the qualifed ones,
 prinrs them to a file, and then the HR department can refer to it.
 */
ostream& operator<<( ostream& output, const CasualEmployee& Emp)
{
    output << "------------------------------------"<<endl;
    output <<"-"<< Emp.getEmployeeName()<<endl;
    output <<"-"<< Emp.getEmployeeLastName()<<endl;
    output <<"-"<< Emp.getEmployeeJobTitle()<<endl;
    output <<"-"<< Emp.getDepartment()<<endl;
    output <<"-"<< Emp.getEmployeeID()<<endl;
    output<< "------------------------------------"<<endl;
    return output;
    
}
