/*
 Adrineh Khodaverdian
 CS/IS 137
 
 */
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
#include "FrontOfficeManagerApplication.h"
using namespace std;
FrontOfficeManagerApplication::~FrontOfficeManagerApplication()
{
    FrontOfficeManagerFile.close();
   
}
FrontOfficeManagerApplication::FrontOfficeManagerApplication(const string& name, const string& last, const Date& openD, const Date& deadline , const Date& dateToday, const string& job, const string& jobType,  const string& jobLocation , const string& majorEdu, const string& levelEdu , const string& skill, int max): Application(name,last,openD,deadline,dateToday, job,jobType,jobLocation,majorEdu,levelEdu,skill)
{
    FrontOfficeManagerFile.open("FrontOfficeManagerFile.txt", ios::app);
    fileN="FrontOfficeManagerFile.txt";
   //the time and the date of today will be entered by the ctime function

}

/**************************************************************************************************************
  We will see that each of the jobs will check to see if this is the applicant needed for the IT work there will be a need for a higer level will be bachelors and the field should be realted to IT
*************************************************************************************************************/
string FrontOfficeManagerApplication::getFileName() const
{
    return fileN;
}
bool FrontOfficeManagerApplication::educationLevelMatching()
{
   bool valid{false};
   string level=getLevelOfEducation();
   
   string major=getApplicantFieldOfeducation();
   for(int i=0; i<getLevelOfEducation().length();i++)
   {
       level=toupper(level[i]);
       major=toupper(major[i]);
       if(level=="NO DEGREE" || level=="LESS THAN HIGHSCHOOL" ||level=="HIGHSCHOOL OR LESS" || level=="N/A" || level=="NEVER ATTENDED SCHOOL")
       {
           valid=false;
       }
       else if(level=="DIPLOMA" && level=="HIGHSCHOOL"&& level=="ASSOCIATE DEGREE" && level=="N/A" && level=="SOME COLLEGE")
       {
           valid=true;
       }
       else
       {
           valid=true;
       }
   }
   return valid;
   
}
/*
The front office manager is the person who deals with customers and employees every working day, this this person needs a min experience in the working enviroment for 3 years
*/
bool FrontOfficeManagerApplication::yearsOfexpericeMatching()
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
English is a must for the front manager
*/
bool FrontOfficeManagerApplication::languageNeeded()
{
   
    bool valid{false};
    if(getNumberOfLangauges()==0 && *getLanaguages()=="English" )
    {
        valid=true;
    }
    else if( getNumberOfLangauges()>=0)
    {
        valid=true;
    }
    else
    {
       valid=false;
    }

    return valid;

}

int FrontOfficeManagerApplication::checkSkills()
{
    int count=1;
    string skill=getSkills();
    string skill1="Time-Managememt";
    string skill2="Empathy";
    string skill3="Customer service";
    string skill4="Paitience";
    string skill5="Mangement";
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
            else if(skill[i]==skill5[i])
            {
                count+=2;
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
int FrontOfficeManagerApplication::checkQalifications()
{
   int count=1;
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
void FrontOfficeManagerApplication::printApplicationDetailsTofile()
{
    
   if(!getApplicantName().empty()&& !getApplicantLastName().empty() && !FrontOfficeManagerFile.fail() && languageNeeded() && (checkQalifications()>0))
   {
       FrontOfficeManagerFile<< "FRONT OFFICE MANAGER APPLICANT:\n\n";
       FrontOfficeManagerFile<< "Name:" << getApplicantName()<<endl;
       FrontOfficeManagerFile<< "LastName: "<<getApplicantLastName()<<endl;
    
       FrontOfficeManagerFile<< "Date Applied: "<<getAppliedDate()<<endl;
       FrontOfficeManagerFile<<"PhoneNumber: "<<getApplicantPhone()<<endl;
       FrontOfficeManagerFile<< "Email: "<<getApplicantEmail()<<endl;
       FrontOfficeManagerFile<< "JobType: " <<getPositionType()<<endl;
       FrontOfficeManagerFile<< "Front office Manager Postion"<<endl;
       /*******************************************************************************
          This prints out the jobs that the person has worked*/
       for(int i=0; i<getNumberOfPrviousJobs(); i++)
       {
           FrontOfficeManagerFile<<"Work Experience #"<< i << ": "<< getWorkExperience();
       }
       Application::printApplicationDetailsTofile();
   }//maybe we can use exception handeling here
   else if(FrontOfficeManagerFile.fail())
   {
       cout<<"Sorry Your File could not be opened"<<endl;
   }
}
