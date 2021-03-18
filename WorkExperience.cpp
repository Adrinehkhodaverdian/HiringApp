/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 */


#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "Employee.h"
#include "WorkExperience.h"
#include "Time.h"
using namespace std;


int yearsOfExperience;
string JobTitle;
Date JobBeginningDate;
Date JobEndedDate;
string JobCompanyName;
string ThreeDuties; //we will allow the user to enter the three duties they did
string reasonForleaving;

WorkExperience::WorkExperience(int y, const string& JobT,  const Date& beginD, const Date& endD, const string& JobCompanyN, const string& threeD , const string& reason ) : yearsOfExperience(y),JobTitle(JobT), JobBeginningDate(beginD), JobEndedDate(endD),JobCompanyName(JobCompanyN), ThreeDuties(threeD), reasonForleaving(reason)
{
    //the member initilazier used
}
/******************sets the years worked with each company*************************/
WorkExperience& WorkExperience::setYearsOfExperience(int y)
{
    yearsOfExperience=(y>=0 ? y: 0);
    return *this;
}
/******************sets the previous job title************************/
WorkExperience& WorkExperience::setJobTitle(const string& title)
{
    JobTitle=title;
    return *this;
    
}
/******************sets the start Date of a job*************************/
WorkExperience& WorkExperience::setJobBeginningDate(const Date& beginD)
{
    JobBeginningDate=beginD;
    return *this;
    
}
/******************sets the day last worked for the job************************/
WorkExperience& WorkExperience::setJobEndedDate(const Date& endDate)
{
    JobEndedDate=endDate;
    return *this;
}
WorkExperience& WorkExperience::setJobCompanyName(const string& companyName)
{
    JobCompanyName=companyName;
    return *this;
    
}
//we will allow the user to enter //the three duties they did
WorkExperience& WorkExperience::setThreeDuties(const string& duties)
{
    ThreeDuties=duties;
    return *this;
}
WorkExperience& WorkExperience::setReasonForleaving(const string& reason )
{
    reasonForleaving=reason;
    return *this;
}
/**************getFunction*****************************/
int WorkExperience::getYearsOfExperience() const
{
    return yearsOfExperience;
}
string WorkExperience::getJobTitle() const
{
    return JobTitle;
}
Date WorkExperience::getJobBeginningDate() const
{
    return JobBeginningDate;
}
Date WorkExperience::getJobEndedDate() const
{
    return JobEndedDate;
}
string WorkExperience::getJobCompanyName() const
{
    return JobCompanyName;
}
string WorkExperience::getThreeDuties() const
{
    return ThreeDuties;
    
}
string WorkExperience::getReasonForleaving() const
{
    return reasonForleaving;
}

ostream& operator<<(ostream& outPut, const WorkExperience& WK)
{
    outPut<< " CompanyName: "<< WK.getJobCompanyName()<<endl;
    outPut<< " Job Title: "<< WK.getJobTitle()<<endl;
    outPut<< " StartDate: "<< WK.getJobBeginningDate()<<endl;
    outPut<< " EndDate: "<< WK.getJobEndedDate()<<endl;
    outPut<< " Duties: " << WK.getThreeDuties()<<endl;
    outPut<< " Reason For leaving : " << WK.getReasonForleaving()<<endl;

    return outPut;
    
}

