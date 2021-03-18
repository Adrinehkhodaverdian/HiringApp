/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 */

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "Date.h"
#include "Employee.h"
#include "Time.h"
#include "PhoneNumber.h"
#include "EMailAddress.h"
#include <fstream>
#include "WorkExperience.h"
#include "Application.h"
#include "BackOfficeManagerApplication.h"
using namespace std;


BackOfficeManagerApplication::~BackOfficeManagerApplication()
{
    BackOfficeManagementFile.close();
}
BackOfficeManagerApplication::BackOfficeManagerApplication(const string& name, const string& last, const Date& openD, const Date& deadline , const Date& dateToday, const string& job, const string& jobType,  const string& jobLocation , const string& majorEdu, const string& levelEdu , const string& skill,int max): Application(name,last,openD,deadline,dateToday, job,jobType,jobLocation,majorEdu,levelEdu,skill)
{
    BackOfficeManagementFile.open("BackOfficeManagementFile.txt", ios::app);
    //the time and the date of today will be entered by the ctime function
    fileN="BackOfficeManagementFile.txt";
    
}

/**************************************************************************************************************
   We will see that each of the jobs will check to see if this is the applicant needed
 *************************************************************************************************************/
string BackOfficeManagerApplication::getFileName() const
{
    return fileN;
}
bool BackOfficeManagerApplication::educationLevelMatching()
{
    bool valid{false};
    string level=getLevelOfEducation();
    for(int i=0; i<getLevelOfEducation().length();i++)
    {
        level=toupper(level[i]);
        if(level=="NO DEGREE"|| level=="LESS THAN HIGHSCHOOL"||level=="HIGHSCHOOL OR LESS" ||level=="N/A" || level=="NEVER ATTENDED SCHOOL")
        {
            valid=false;
        }
        else if(level=="DIPLOMA" || level=="HIGHSCHOOL"|| level=="ASSOCIATEDEGREE" || level=="SOME COLLEGE")
        {
            valid=false;
        }
        else //
        {
            valid=true;
        }
    }
    return valid;
    
}
bool BackOfficeManagerApplication::yearsOfexpericeMatching()
{
    bool valid{false};
    for(int i=0; i< getMaxSize(); i++)
    {
        if(getWorkExperience()->getJobBeginningDate().getYear()-getWorkExperience()->getJobEndedDate().getYear()>3.0)
            
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
 For the back office management the manager is required to know spanish, so if it will not be under the langauges then it is not accepted, English is a must
 */
bool BackOfficeManagerApplication::languageNeeded()
{
    
    bool valid{false};

    if(getNumberOfLangauges()>=0 )
    {
        valid=true;
    }
    else if(*getLanaguages()=="Spanish")
        
    {
        valid=true;
    }
    else
    {
        valid=false;
    }

    return valid;
    
}

int BackOfficeManagerApplication::checkSkills()
{
    int count=1;
    string skill=getSkills();
    string skill1="Managememt";
    string skill2="Leadership";
    string skill3="Customer service";
    string skill4="Planning";
    for( int i=0; i<skill.length(); i++)
    {
        if(isalpha(skill[i]) && isspace(skill[i+1]))
        {
            if(skill[i]==skill1[i])
            {
                count++;
            }
            else if(skill[i]==skill2[i])
            {
                count++;
            }
            else if(skill[i]==skill3[i])
            {
                count++;
            }
            else if(skill[i]==skill4[i])
            {
                count++;
            }
        }
        else if(skill!="NULL")
        {
            count=1;
        }
        else
        {
            count=0;
        }
    }
        
    return count;

}
int BackOfficeManagerApplication::checkQalifications()
{
    int count=0;
    if(languageNeeded())
    {
        count++;
    }
    else if(yearsOfexpericeMatching())
    {
        count++;
    }
    else if(educationLevelMatching())
    {
        count++;
    }
    count+=checkSkills();
    return count;
}
/*
 The information should also be saved in the talent file for other positions thus we also call the application::printApplicationDetailsTofile function*/
void BackOfficeManagerApplication::printApplicationDetailsTofile()
{
    if(!getApplicantName().empty()&& !getApplicantLastName().empty() && !BackOfficeManagementFile.fail() && languageNeeded() && checkSkills()>1 && checkQalifications()>0)
    {
      
        BackOfficeManagementFile<<"BACK OFFICE MANAGER APPLICANT:\n\n";
        BackOfficeManagementFile<< "Name:" << getApplicantName()<<endl;
        BackOfficeManagementFile<< "LastName: "<<getApplicantLastName()<<endl;
        BackOfficeManagementFile<< "Date Applied: "<<getAppliedDate()<<endl;
        BackOfficeManagementFile<< "PhoneNumber: "<<getApplicantPhone()<<endl;
        BackOfficeManagementFile<< "JobType: " <<getPositionType()<<endl;
        BackOfficeManagementFile<< "Email: "<<getApplicantEmail()<<endl;
        BackOfficeManagementFile<< "Back office Manager Postion"<<endl;
        /*******************************************************************************
           This prints out the jobs that the person has worked*/
        for(int i=0; i<getNumberOfPrviousJobs(); i++)
        {
            BackOfficeManagementFile<< "Work Experience #"<< i << ": "<< getWorkExperience();
        }
        Application::printApplicationDetailsTofile();
    }//maybe we can use exception handeling here
    else if(BackOfficeManagementFile.fail())
    {
        cout<<"Sorry Your File could not be opened"<<endl;
    }
}

/*this last function will search through the application
 and add a 1 to the points of the applicant qualification
 if this points get high based on the position the higher than 4 the applicant info will be saved in the HR's file*/
