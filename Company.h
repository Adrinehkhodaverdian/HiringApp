/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                           Company
 -----------------------------------------------------------------
-name:string
-location:string
-services:string
-field:string
-maxSize:int
-openningDate: Date
-presentDay: Date
-numberOfEmployees:int
-numberOfJobs: int
-employee: Employee*
-applications: Application*
-checkDates(const Company&, Date , Date ):bool
-operator=(const Company&) = delete : const Company&
-Company(const Company&) = delete;
 -----------------------------------------------------------------
+Company(nm :const string&,loc: const string& , service: const string&, major: const string&, openD: const Date&, presentD: const Date& , numEmp : int,  numJobs: int, maxS: int )
+~Company()
+setMaxSize(const int&: size):Company&
+setName(const string&: nm):Company&
+setLocation(const string&: loc):Company&
+setServices(const string& : service):Company&
+setField(const string&: major):Company&
+setOpenningDate(const Date& : openD):Company&
+setPresentDate(const Date& : presentD):Company&
+setNumberOfEmployess(int: numEmp):Company&
+setNumberOfJobs(int: numJobs):Company&
+addEmployee(const Employee&: emp): bool
+removeEmployee(const Employee&: emp) :bool
+addApplication(const Application&: app): bool
+removeApplication(const Application&: app):bool
+getName() const:string
+getLocation() const :string
+getServices() const ::string
+getField() const :string
+getOpenningDate() const:Date
+getPresentDate() const:Date
+getNumberOfEmployess() const:int
+getNumberOfJobs() const:int
+calcDailyDuration() const:double
 -----------------------------------------------------------------
 
 
 */

#ifndef Company_h
#define Company_h
#include<iostream>
#include <string>
#include "Date.h"
#include "Application.h"
#include "Employee.h"
using namespace std;

class Company
{
    private:
        string name;
        string location;
        string services;
        string field;
        int maxSize;
        Date openningDay;
        Date presentDay;
        int numberOfEmployees;
        int numberOfJobs;
        Employee *employee;
        Application *applications;
        bool checkDates(const Company&, Date , Date );
        const Company& operator=(const Company&) = delete;
        Company(const Company&) = delete;
    public:
    Company(const string & = "NULL", const string & = "NULL", const string & ="NULL", const string & = "NULL",  const Date & = Date(), const Date & = Date(), int =0, int = 0, const int =10);
    
    
        virtual ~Company();
    /*
      ***********The set Functions*************
     */
        Company& setMaxSize(const int&);
        Company& setName(const string&);
        Company& setLocation(const string&);
        Company& setServices(const string&);
        Company& setField(const string&);
        Company& setOpenningDate(const Date&);
        Company& setPresentDate(const Date&);
        Company& setNumberOfEmployess(int);
        Company& setNumberOfJobs(int);
        bool addEmployee(const Employee&);
        bool removeEmployee(const Employee&);
        bool addApplication(const Application&);
        bool removeApplication(const Application&);
    /*
     ***********The get Functions*****************
     */
        string getName() const;
        string getLocation() const;
        string getServices() const ;
        string getField() const ;
        Date getOpenningDate() const;
        Date getPresentDate() const;
        int getNumberOfEmployess() const;
        int getNumberOfJobs() const;
        double calcDailyDuration() const;
        Employee* getEmployees() const;
    
};
#endif /* Company_h */
