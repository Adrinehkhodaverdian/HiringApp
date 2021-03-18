/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 */

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "Employee.h"

using namespace std;

Employee::Employee(const string& name, const string& last, const string & job, const string & ID, const string& department): EmployeeName(name), EmployeeLastName(last), jobTitle(job), EmployeeID(ID), Department(department)
{
    //member initializer syntax
}
/******************************************************
           The set Functions
 ********************************************************/
Employee::~Employee()
{
    //I don't know
}
Employee& Employee::setEmployeeName(const string& name)
{
    EmployeeName=name;
    return  *this;

}
Employee& Employee::setEmployeeLastName(const string& last)
{
    EmployeeLastName=last;
    return  *this;
}
Employee& Employee::setEmployeeJobTitle(const string& jobT)
{
    jobTitle=jobT;
    return  *this;
}
Employee& Employee::setEmployeeID(const string& ID)
{
    EmployeeID=ID;
    return  *this;
}
Employee& Employee::setDepartment(const string& department)
{
    Department=department;
    
    return *this;
}
/******************************************************
           The get Functions
 ********************************************************/
string Employee::getEmployeeName() const
{
    return EmployeeName;
    
}
string Employee::getEmployeeLastName() const
{
    return EmployeeLastName;
}
string Employee::getEmployeeJobTitle() const
{
    return jobTitle;
}
string Employee::getEmployeeID() const
{
    return EmployeeID;
}
string Employee::getDepartment() const
{
    return Department;
}
void Employee::DisplayMenu()
{
    cout<<"Menu:";
}

bool Employee::checkIDMatchingTitle() const
{

    return true;
    
}
