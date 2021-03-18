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
#include "AssociateApplication.h"
using namespace std;
AssociateApplication::~AssociateApplication()
{
    FrontOfficeAssociateFile.close();
   
}
AssociateApplication::AssociateApplication( const string& name, const string& last, const Date& openD, const Date& deadline , const Date& dateToday, const string& job, const string& jobType,  const string& jobLocation , const string& majorEdu, const string& levelEdu , const string& skill, int max): Application(name,last,openD,deadline,dateToday, job,jobType,jobLocation,majorEdu,levelEdu,skill)
{
    FrontOfficeAssociateFile.open("FrontOfficeAssociateFile.txt", ios::app);
    fileN="FrontOfficeAssociateFile.txt";
   //the time and the date of today will be entered by the ctime function

}

/**************************************************************************************************************
  We will see that each of the jobs will check to see if this is the applicant needed for the Associate work there will be a need for a higer level will be Diploma
*************************************************************************************************************/
string AssociateApplication::getFileName() const
{
    return fileN;
}
bool AssociateApplication::educationLevelMatching()
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
       else if(level=="DIPLOMA" || level=="HIGHSCHOOL" ||level=="ASSOCIATE DEGREE" || level=="SOME COLLEGE")
       {
           valid=true;
       }
 
   }
   return valid;
   
}
/*
For associate I think there is no need to check for experience in real job
*/
bool AssociateApplication::yearsOfexpericeMatching()
{
   bool valid{false};
   for(int i=0; i< getMaxSize(); i++)
   {
       if(getWorkExperience()->getJobBeginningDate().getYear()-getWorkExperience()->getJobEndedDate().getYear()>=0)
           
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
I think for associate even 1 language is enough let's say english
*/
bool AssociateApplication::languageNeeded()
{
   
    bool valid{false};
    if(getNumberOfLangauges()==0 && *getLanaguages()=="English" )
    {
        valid=true;
    }
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

int AssociateApplication::checkSkills()
{
   int count=1;
   string skill=getSkills();
   string skill1="Time-Managememt";
   string skill2="Empathy";
   string skill3="Customer service";
   string skill4="Paitience";

       
    if(skill!="NULL")
    {
       count=1;
    }
    else
    {
       count=0;
    }
   
       
   return count;

}
int AssociateApplication::checkQalifications()
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
void AssociateApplication::printApplicationDetailsTofile()
{
    
   if(!getApplicantName().empty()&& !getApplicantLastName().empty() && !FrontOfficeAssociateFile.fail() && languageNeeded() && checkQalifications()>1)
   {
       FrontOfficeAssociateFile<< "ASSOCIATE APPLICANT:\n\n";
       FrontOfficeAssociateFile<< "Name:" << getApplicantName()<<endl;
       FrontOfficeAssociateFile<< "LastName: "<<getApplicantLastName()<<endl;
    
       FrontOfficeAssociateFile<< "Date Applied: "<<getAppliedDate()<<endl;
       FrontOfficeAssociateFile<<"PhoneNumber: "<<getApplicantPhone()<<endl;
       FrontOfficeAssociateFile<< "Email: "<<getApplicantEmail()<<endl;
       FrontOfficeAssociateFile<< "JobType: " <<getPositionType()<<endl;
       FrontOfficeAssociateFile<< "Associate Postion"<<endl;
       /*******************************************************************************
          This prints out the jobs that the person has worked*/
       for(int i=0; i<getNumberOfPrviousJobs(); i++)
       {
           FrontOfficeAssociateFile<<"Work Experience #"<< i << ": "<< getWorkExperience();
       }
       Application::printApplicationDetailsTofile();
   }//maybe we can use exception handeling here
   else if(FrontOfficeAssociateFile.fail())
   {
       cout<<"Sorry Your File could not be opened"<<endl;
   }
}
