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
#include "CallCenterApplication.h"
using namespace std;
CallCenterApplication::~CallCenterApplication()
{
    BackOfficeCallCenterFile.close();
   
}
CallCenterApplication::CallCenterApplication(const string& name, const string& last, const Date& openD, const Date& deadline , const Date& dateToday, const string& job, const string& jobType,  const string& jobLocation , const string& majorEdu, const string& levelEdu , const string& skill, int max): Application(name,last,openD,deadline,dateToday, job,jobType,jobLocation,majorEdu,levelEdu,skill)
{
    BackOfficeCallCenterFile.open("BackOfficeCallCenterFile.txt", ios::app);
    fileN="BackOfficeCallCenterFile.txt";
   //the time and the date of today will be entered by the ctime function

}

/**************************************************************************************************************
  We will see that each of the jobs will check to see if this is the applicant needed for the call center work there will be a need of no degree to be specific, yet applicants without Highschool will be not accepted
*************************************************************************************************************/
string CallCenterApplication::getFileName() const
{
    return fileN;
}
bool CallCenterApplication::educationLevelMatching()
{
   bool valid{false};
   string level=getLevelOfEducation();
   
   string major=getApplicantFieldOfeducation();
   for(int i=0; i<getLevelOfEducation().length();i++)
   {
       level=toupper(level[i]);
       major=toupper(major[i]);
       if(level=="NO DEGREE"||level=="LESS THAN HIGHSCHOOL" || level=="N/A" || level=="ELEMENTARY" || level=="NEVER ATTENDED SCHOOL")
       {
           valid=false;
       }
       else if(level=="DIPLOMA" && level=="HIGHSCHOOL" && level=="ASSOCIATE DEGREE" && level=="SOME COLLEGE")
       {
           valid=true;
           
       }
   }
   return valid;
   
}
/*
it requires the the years of experince be more than 3
*/
bool CallCenterApplication::yearsOfexpericeMatching()
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
 For call center if is suffiecent for the applicant to know 1 language, no matter what it is
*/
bool CallCenterApplication::languageNeeded()
{
   
   bool valid{false};

   if( getNumberOfLangauges()>0)
       
   {
       valid=true;
   }
   else
   {
       valid=false;
   }

   return valid;
   
}

int CallCenterApplication::checkSkills()
{
   int count=1;
   string skill=getSkills();
   string skill1="Time-Managememt";
   string skill2="Empathy";
   string skill3="Customer service";
   string skill4="Patience";
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
int CallCenterApplication::checkQalifications()
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
void CallCenterApplication::printApplicationDetailsTofile()
{
   if(!getApplicantName().empty()&& !getApplicantLastName().empty() && !BackOfficeCallCenterFile.fail() && (checkQalifications()>2))
   {
       BackOfficeCallCenterFile<< "CALL CENTER APPLICANT:\n\n";
       BackOfficeCallCenterFile<< "Name:" << getApplicantName()<<endl;
       BackOfficeCallCenterFile<< "LastName: "<<getApplicantLastName()<<endl;
       BackOfficeCallCenterFile<< "Date Applied: "<<getAppliedDate()<<endl;
       BackOfficeCallCenterFile<< "PhoneNumber: "<<getApplicantPhone()<<endl;
       BackOfficeCallCenterFile<< "Email: "<<getApplicantEmail()<<endl;
       BackOfficeCallCenterFile<< "JobType: " <<getPositionType()<<endl;
       BackOfficeCallCenterFile<< "CallCenter Postion"<<endl;
       /*******************************************************************************
          This prints out the jobs that the person has worked*/
       for(int i=0; i<getNumberOfPrviousJobs(); i++)
       {
           BackOfficeCallCenterFile<< "Work Experience #"<< i << ": "<< getWorkExperience();
       }
       Application::printApplicationDetailsTofile();
   }//maybe we can use exception handeling here
   else if(BackOfficeCallCenterFile.fail())
   {
       cout<<"Sorry Your File could not be opened"<<endl;
   }
}
