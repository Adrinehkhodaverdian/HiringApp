/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 */

#include <stdio.h>
#include<iostream>
#include <string>
#include "Company.h"
#include "Date.h"
#include "Application.h"
using namespace std;



Company::Company(const string& nm,const string& loc, const string& service,const string& f, const Date& openD, const Date& presentD, int numEmp , int numJobs, int maxS): name(nm), location(loc), services(service), field(f), openningDay(openD), presentDay(presentD),numberOfEmployees(numEmp),numberOfJobs(numJobs), maxSize(maxS)
{
   
  
    maxSize=maxS;
    employee=new Employee[maxSize]; //alocates memory to have emplyees in company
    applications=new Application[maxSize]; //alocates memory to have job applications
}
Company::~Company()
{
    delete [] employee;
    delete [] applications;
    
}

bool Company::checkDates (const Company& cmp, Date startD , Date presentD)
{
    bool valid{false};
    if(startD< presentD)
    {
        valid=true;
    }
    else
    {
        valid=false;
    }
    return valid;
}
/*
***********The set Functions*************
*/
Company& Company::setMaxSize(const int & max)
{
    maxSize=(max>=0 && max<100 ? max: 0);
    return *this;
}
Company& Company::setName(const string& nm)
{
    name=nm;
    return *this;
}
Company& Company::setLocation(const string& loc)
{
    location=loc;
    return *this;
}
Company& Company::setServices(const string& loc)
{
    location=loc;
    return *this;
}

Company& Company::setField(const string& Field)
{
    field=Field;
    return *this;
}

Company& Company::setOpenningDate(const Date& openD)
{
    openningDay=openD;
    return *this;
}
Company& Company::setPresentDate(const Date& presentD)
{
    presentDay=presentD;
    return *this;
}

Company& Company::setNumberOfEmployess(int numEmp)
{
    numberOfEmployees=(numEmp >=0 ? numEmp :  0);
    return *this;
}
Company& Company::setNumberOfJobs(int numJobs)
{
    numberOfJobs=(numJobs >=0 ? numJobs : 0);
    return *this;
    
}
bool Company::addEmployee(const Employee& Emp)
{
    bool valid{false};

    if(numberOfEmployees< maxSize)
    {
       for(int i=0; i<getNumberOfEmployess(); i++)
       {
           if(employee[i].getEmployeeName()==Emp.getEmployeeName() && employee[i].getEmployeeLastName()==Emp.getEmployeeLastName())
           {
               valid=false;
           }
           
       }
       employee[numberOfEmployees]=Emp;
       setNumberOfEmployess(numberOfEmployees+1);
       valid=true;
    }
    else
    {
        valid=false;
    }

    return valid;

}
bool Company::removeEmployee(const Employee& Emp)
{
    bool valid{false};

   if(numberOfEmployees>0)
    {
       for(int i=0; i<getNumberOfEmployess(); i++)
       {
           if(employee[i].getEmployeeName()==Emp.getEmployeeName() && employee[i].getEmployeeLastName()==Emp.getEmployeeLastName())
           {
               numberOfJobs=i;
           }
       }
        Employee *emps; //not sure if this is the right way to do!
        emps=new Employee[numberOfEmployees];
        employee[numberOfEmployees]=emps[numberOfEmployees];
        setNumberOfEmployess(numberOfEmployees-1);
        valid=true;
    }
    else
    {
        valid=false;
        
    }
    
    return valid;
}

bool Company::addApplication(const Application& app)
{
    bool valid{false};

   if(numberOfJobs< maxSize)
    {
       for(int i=0; i<getNumberOfJobs(); i++)
       {
           if(applications[i].getApplicantName()==app.getApplicantName() && applications[i].getApplicantLastName()==app.getApplicantLastName())
           {
               valid=false;
           }
           
       }
        
       applications[numberOfJobs]=app;
        
       setNumberOfJobs(numberOfJobs+1);
       valid=true;
    }
    else
    {
        valid=false;
    }
    return valid;
}
bool Company::removeApplication(const Application& app)
{
    bool valid{true};

   if(numberOfJobs>0)
    {
       for(int i=0; i<getNumberOfJobs(); i++)
       {
           if(applications[i].getApplicantName()==app.getApplicantName() && applications[i].getApplicantLastName()==app.getApplicantLastName() && applications[i].getPosition()==app.getPosition())
           {
               numberOfJobs=i;
           }
       }
        Application *apps; //not sure if this is the right way to do!
        apps=new Application[numberOfJobs];
        applications[numberOfJobs]=apps[numberOfJobs];
        setNumberOfJobs(numberOfJobs-1);
        valid=true;
    }
    else
    {
        valid=false;
        
    }
    
    return valid;
    return valid;
}
/*
***********The get Functions*****************
*/
string Company::getName() const
{
    return name;
}
string Company::getLocation() const
{
    return location;
}
string Company::getServices() const
{
    return services;
}
string Company::getField() const
{
    return field;
}
Date Company::getOpenningDate() const
{
    return openningDay;
}
Date Company::getPresentDate() const
{
    return presentDay;
    
}
int Company::getNumberOfEmployess() const
{
    return numberOfEmployees;
}
int Company::getNumberOfJobs() const
{
    return numberOfJobs;
}
double Company::calcDailyDuration() const
{
    double duration=this->presentDay.getYear()-this->openningDay.getMonth();
    return duration;
}
Employee* Company::getEmployees() const
{
    return employee;
}
