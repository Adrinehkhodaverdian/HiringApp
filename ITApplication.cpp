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
#include "ITApplication.h"
using namespace std;
ITApplication::~ITApplication ()
{
    BackOfficeITApplicationFile.close();
   
}
ITApplication::ITApplication(const string& name, const string& last, const Date& openD, const Date& deadline , const Date& dateToday, const string& job, const string& jobType,  const string& jobLocation , const string& majorEdu, const string& levelEdu , const string& skill, int max): Application(name,last,openD,deadline,dateToday, job,jobType,jobLocation,majorEdu,levelEdu,skill)
{
    BackOfficeITApplicationFile.open("BackOfficeITFile.txt", ios::app);
    fileN="BackOfficeITFile.txt";
   //the time and the date of today will be entered by the ctime function

}

/**************************************************************************************************************
  We will see that each of the jobs will check to see if this is the applicant needed for the IT work there will be a need for a higer level will be bachelors and the field should be realted to IT
*************************************************************************************************************/
string ITApplication::getFileName() const
{
    return fileN;
}
bool ITApplication::educationLevelMatching()
{
   bool valid{false};
   string level=getLevelOfEducation();
   
   string major=getApplicantFieldOfeducation();
   for(int i=0; i<getLevelOfEducation().length();i++)
   {
       level=toupper(level[i]);
       major=toupper(major[i]);
       if(level=="NO DEGREE" ||level=="LESS THAN HIGHSCHOOL"|| level=="HIGHSCHOOL OR LESS" || level=="N/A" || level=="NEVER ATTENDED SCHOOL")
       {
           valid=false;
       }
       else if(level=="DIPLOMA" || level=="HIGHSCHOOL" ||level=="ASSOCIATE DEGREE"  || level=="SOME COLLEGE")
       {
           valid=true;
       }
       else if( major=="COMPUTER SCIENCE"|| major=="IT" || major=="SOFTWARE ENGINEERING" || major=="COMPUTER PROGRAMMING")
       {
           valid=true;
           if(level=="BACHELORS" || level=="BACHELOR" || level=="MASTERS" || level=="MASTER" )
          {
              valid=true;
          }
       }
   }
   return valid;
   
}
/*
it requires the the years of experince be more than 1 I think for IT is more about knowledge than years of experience
*/
bool ITApplication::yearsOfexpericeMatching()
{
   bool valid{false};
   for(int i=0; i< getMaxSize(); i++)
   {
       if(getWorkExperience()->getJobBeginningDate().getYear()-getWorkExperience()->getJobEndedDate().getYear()>1)
           
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
For IT the lanaguages are going to be programming langauges wheras to other jobs
 The programmer should at least know 3 langauges
*/
bool ITApplication::languageNeeded()
{
   
   bool valid{false};
   if( getNumberOfLangauges()>2)
       
   {
       valid=true;
   }
   else
   {
       valid=false;
   }

   return valid;
   
}

int ITApplication::checkSkills()
{
   int count=1;
   string skill=getSkills();
   string skill1="Time-Managememt";
   string skill2="Coding";
   string skill3="Python";
   string skill4="Problem-solving";
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
int ITApplication::checkQalifications()
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
void ITApplication::printApplicationDetailsTofile()
{
    
   if(!getApplicantName().empty()&& !getApplicantLastName().empty() && !BackOfficeITApplicationFile.fail() && languageNeeded())
   {
       BackOfficeITApplicationFile<< "IT APPLICANT:\n\n";
       BackOfficeITApplicationFile<< "Name:" << getApplicantName()<<endl;
       BackOfficeITApplicationFile<< "LastName: "<<getApplicantLastName()<<endl;
    
       BackOfficeITApplicationFile<< "Date Applied: "<<getAppliedDate()<<endl;
       BackOfficeITApplicationFile<<"PhoneNumber: "<<getApplicantPhone()<<endl;
       
       BackOfficeITApplicationFile<< "Email: "<<getApplicantEmail()<<endl;
       BackOfficeITApplicationFile<< "JobType: " <<getPositionType()<<endl;
       BackOfficeITApplicationFile<< "IT Postion"<<endl;
       /*******************************************************************************
          This prints out the jobs that the person has worked*/
       for(int i=0; i<getNumberOfPrviousJobs(); i++)
       {
           BackOfficeITApplicationFile<<"Work Experience #"<< i << ": "<< getWorkExperience();
       }
       Application::printApplicationDetailsTofile();
   }//maybe we can use exception handeling here
   else if(BackOfficeITApplicationFile.fail())
   {
       cout<<"Sorry Your File could not be opened"<<endl;
   }
}
