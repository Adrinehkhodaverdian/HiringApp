
/*
 Adrineh Khodaverdian
 CS/IS137
 Final project
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
#include "AccountingApplication.h"
using namespace std;
AccountingApplication::~AccountingApplication()
{
   BackOfficeAccountingFile.close();
   
}
AccountingApplication::AccountingApplication(const string& name, const string& last, const Date& openD, const Date& deadline , const Date& dateToday, const string& job, const string& jobType,  const string& jobLocation , const string& majorEdu, const string& levelEdu , const string& skill, int max): Application(name,last,openD,deadline,dateToday, job,jobType,jobLocation,majorEdu,levelEdu,skill)
{
   BackOfficeAccountingFile.open("BackOfficeAccountingFile.txt", ios::app);
    fileN="BackOfficeAccountingFile.txt";
   //the time and the date of today will be entered by the ctime function

}

/**************************************************************************************************************
  We will see that each of the jobs will check to see if this is the applicant needed for the accountant work there will be a need for a higer level that diploma or associate
*************************************************************************************************************/
string AccountingApplication::getFileName() const
{
    return fileN;
}

bool AccountingApplication::educationLevelMatching()
{
   bool valid{false};
   string level=getLevelOfEducation();
   
   string major=getApplicantFieldOfeducation();
   for(int i=0; i<getLevelOfEducation().length();i++)
   {
       level=toupper(level[i]);
       major=toupper(major[i]);
       if(level=="NO DEGREE"|| level=="LESS THAN HIGHSCHOOL"||level=="HIGHSCHOOL OR LESS" ||level=="N/A" || level=="NEVER ATTENDED SCHOOL")
       {
           valid=false;
       }
       else if(level=="DIPLOMA" || level=="HIGHSCHOOL"||level=="ASSOCIATE DEGREE" || level=="SOME COLLEGE")
       {
           valid=false;
       }
       else if( major=="ACCOUNTING"|| major=="BUSINESS" || major=="ECONOMY" || major=="MATHEMATICS")
       {
           valid=true;
       }
       else if(level=="BACHELORS" || level=="BACHELOR")
       {
           valid=true;
       }
   }
   return valid;
   
}
/*
it requires the the years of experince be more than 3
*/
bool AccountingApplication::yearsOfexpericeMatching()
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
For the back office management the manager is required to know spanish, so if it will not be under the langauges then it is not accepted
*/
bool AccountingApplication::languageNeeded()
{
   
   bool valid{false};
   for(int i=0; i< getMaxSize(); i++)
   {
       if( getNumberOfLangauges()>0)
           
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

int AccountingApplication::checkSkills()
{
   int count=1;
   string skill=getSkills();
   string skill1="Accounting";
   string skill2="Detail-oriented";
   string skill3="Customer service";
   string skill4="punctual";
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
int AccountingApplication::checkQalifications()
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
void AccountingApplication::printApplicationDetailsTofile()
{
   if(!getApplicantName().empty()&& !getApplicantLastName().empty() && !BackOfficeAccountingFile.fail() && checkSkills()>1 && checkQalifications()>1)
   {
       BackOfficeAccountingFile<< "ACCOUNTING APPLICANT:\n";
       BackOfficeAccountingFile<< "Name:" << getApplicantName()<<endl;
       BackOfficeAccountingFile<< "LastName: "<<getApplicantLastName()<<endl;
       BackOfficeAccountingFile<< "Date Applied: "<<getAppliedDate()<<endl;
       BackOfficeAccountingFile<< "PhoneNumber: "<<getApplicantPhone()<<endl;
       BackOfficeAccountingFile<< "JobType: " <<getPositionType()<<endl;
       BackOfficeAccountingFile<< "Email: "<<getApplicantEmail()<<endl;
       BackOfficeAccountingFile<< "Accounting Position"<<endl;
       /*******************************************************************************
          This prints out the jobs that the person has worked*/
       for(int i=0; i<getNumberOfPrviousJobs(); i++)
       {
           BackOfficeAccountingFile<< "Work Experience #"<< i << ": "<< getWorkExperience();
       }
       Application::printApplicationDetailsTofile();
   }//maybe we can use exception handeling here
   else if(BackOfficeAccountingFile.fail())
   {
       cout<<"Sorry Your File could not be opened"<<endl;
   }
}
