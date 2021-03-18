/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include "Date.h"
#include "Employee.h"
#include "HREmployee.h"
using namespace std;

HREmployee::~HREmployee()
{
    
}
HREmployee::HREmployee(const string & name, const string& last, const string & job, const string & ID, const string& department):Employee(name,last, job, ID, department)
{
    
}
//the display menu will give some options for the HR employees that other employees
// should not have access to, so this is unique.
void HREmployee::DisplayMenu()
{
    if(checkIDMatchingTitle())
    {
        cout << "Welcome To HR Department main menu!"<<endl;
        cout << "1) To review the application submitted."<<endl;
        cout << "2) For information about the payroll departmet."<<endl;
        cout << "0) To exit"<<endl;
        
    }
    else{
        cout<<"The entered ID does not match with entered department"<<endl;
    }
}
/*
 The function checks to see if the person entring the ID matches the job Title, because H1234579 is for HR employess and C1234900 is for casual employess
    so this should be verified in the dervied classes.
 */
bool HREmployee::checkIDMatchingTitle() const
{
    string id=getEmployeeID();
    bool valid{true};
   if(getDepartment()=="HR"|| getDepartment()=="hr")
    {
        if(id[0]=='H' || id[0]=='h')
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
void HREmployee::qualifiedApplicantsInfo()
{
    cout<<"Info";
    
}


ostream& operator<<( ostream& output, const HREmployee& Emp)
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
