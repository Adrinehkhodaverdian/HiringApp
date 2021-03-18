/*Adrineh Khodaverdian,
CS/IS 137
Final Project
 -----------------------------------------------------------------
                          Employeee
 -----------------------------------------------------------------
-EmployeeName:string
-EmployeeLastName:string
-jobTitle:string
-EmployeeID:string
-Department:string
 -----------------------------------------------------------------
+Employee(name: const string &,last: const string &,job: const string &,ID: const string & , department: const string & );
+~Employee();
+setEmployeeName(name:const string&):Employee&
+setEmployeeLastName(const string&): Employee&
+setEmployeeJobTitle(const string&): Employee&
+setEmployeeID(const string&):Employee&
+setDepartment(const string&):Employee&
+getEmployeeName() const:string
+getEmployeeLastName() const:string
+getEmployeeJobTitle() const:string
+getEmployeeID()const :string
+getDepartment() const:string
+DisplayMenu(): void
+checkIDMatchingTitle() const: bool
 -----------------------------------------------------------------
*/


#ifndef EMPLOYEE_h
#define EMPLOYEE_h
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Application.h"
#include "Employee.h"
//using namespace std;

class Employee
{

    private:
        string EmployeeName;  //used to get the employee name
        string EmployeeLastName; //used to get employee last name
        string jobTitle;
        string EmployeeID;
        string Department;
    public:
        Employee(const string & = "NULL", const string & ="NULL", const string & = "NULL", const string & = "NULL", const string & = "NULL");
        virtual ~Employee();
        /******************************************************
         
                   The set Functions
         ********************************************************/

        Employee& setEmployeeName(const string&);
        Employee& setEmployeeLastName(const string&);
        Employee& setEmployeeJobTitle(const string&);
        Employee& setEmployeeID(const string&);
        Employee& setDepartment(const string&);
        /******************************************************
                   The get Functions
         ********************************************************/
        string getEmployeeName() const;
        string getEmployeeLastName() const;
        string getEmployeeJobTitle() const;
        string getEmployeeID()const ;
        string getDepartment() const;
        /*
         We make the Display Menu Pure virtual because the HR employees will have other accesses that regular employess do not, such as seeing the job applicants.
         and the menu should be displayed after the employee has entered their inforomation.
         */
        virtual void DisplayMenu();
        /*
         The function checks to see if the person entring the ID matches the job Title, because H1234579 is for HR employess and C1234900 is for casual employess
            so this should be verified in the dervied classes.
         */
    virtual bool checkIDMatchingTitle() const;
    
    
    
};

#endif /* Employee_h */
