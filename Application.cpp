/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 */
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include "Date.h"
#include "Employee.h"
#include "Time.h"
#include "WorkExperience.h"
#include "Application.h"
#include <fstream>
using namespace std;
//we want to use ios::app

Application::~Application()
{
    delete [] previousJobs;
    delete [] languageName;
    talentFile.close();

}
Application::Application(const string& name, const string& last, const Date& openD, const Date& deadline , const Date& dateToday, const string& title, const string& jobType,  const string& jobLocation , const string& majorEdu, const string& levelEdu , const string& skill, int max): ApplicantName(name),ApplicantLastName(last), ApplicationOpenDate(openD), ApplicationDeadline(deadline), AppliedDate(dateToday), position(title), positionType(jobType), positionLocation(jobLocation), applicantFieldOfeducation(majorEdu), levelOfEducation(levelEdu),skills(skill)
{
    fileName="TalentApplicant.txt";
    talentFile.open("TalentApplicant.txt", ios::app);
    //the time and the date of today will be entered by the ctime function
    maxSize=max;
    numberOfPrviousJobs=0;
    numLanguages=0;
    previousJobs=new WorkExperience[maxSize];
    languageName=new string[maxSize];
}
/*******************************************************************
    These are overloaded = asignment operator, and the copy constructor
    we needed to overload this two because we are going to have pointer of Application ( in
    Company file)
    created thus the assignment must be overloaded
 ************************************************************************/
const Application& Application::operator=(const Application& app)
{
    if(&app != this)
    {
        if(maxSize!=app.maxSize)
        {
            delete [] previousJobs;
            delete [] languageName;
            maxSize=app.maxSize;
            previousJobs=new WorkExperience[maxSize];
            languageName=new string[maxSize];
        }
        for(int i=0; i<maxSize;  i++)
        {
            previousJobs[i]=app.previousJobs[i];
            languageName[i]=app.languageName[i];
        }
    }
    return *this;
}

Application::Application(const Application& app): maxSize(app.maxSize)
{
    previousJobs=new WorkExperience[maxSize];
    languageName=new string[maxSize];

    for(int i=0; i<maxSize;  i++)
    {
        previousJobs[i]=app.previousJobs[i];
        languageName[i]=app.languageName[i];
    }
}
/****************************************************
    setFunctions
******************************************************/
Application& Application::setApplicantName(const string& name)
{
    ApplicantName=name;
    return *this;
}
Application& Application::setApplicantLastName(const string& last)
{
    ApplicantLastName=last;
    return *this;
}
Application& Application::setApplicantPhone(const PhoneNumber & ph)
{
    ApplicantPhone=ph;
    return *this;
}
Application& Application::setApplicantEmail(const EMailAddress & email)
{
    ApplicantEmail=email;
    return *this;
}

//this value should be set when object created
Application& Application::setApplicationOpenDate(const Date& openD)
{
    ApplicationOpenDate=openD;
    return *this;
}

Application& Application::setApplicationDeadline(const Date& endD)
{
    return *this;
}
//this value should be set before applicant applying
Application& Application::setAppliedDate(const Date& appliedD) //the Date the user will apply
{
    return *this;
}
Application& Application::setPosition(const string& title ) //position being appliedfor
{
    position=title;
    return *this;
}
Application& Application::setPositionType(const string& jobType) //full-time, part-time, temporary
{
    positionType=jobType;
    return *this;
}
Application& Application::setPositionLocation(const string& location)
{
    positionLocation=location;
    return *this;
}
Application& Application::setApplicantFieldOfeducation(const string& major)
{
    applicantFieldOfeducation=major;
    return *this;
}
Application& Application::setLevelOfEducation(const string& education)
{
    levelOfEducation=education;
    return *this;
    
}
Application& Application::setNumberOfPrviousJobs(int numJob)
{
    numberOfPrviousJobs=(numJob>0 && numJob< maxSize? numJob:0);
    return *this;
}
Application& Application::setSkills(const string& skill)
{
    skills=skill;
    return *this;
}
Application& Application::setMaxSize(const int size)
{
    maxSize=(size>0 && size<7? size: 0);
    return *this;
}
bool Application::addPreviousJob(const WorkExperience& WK)
{
    bool valid{true};
    
    if(numberOfPrviousJobs>0)
     {
        for(int i=0; i<numberOfPrviousJobs; i++)
        {
            if(previousJobs[i].getJobCompanyName()==WK.getJobCompanyName() && previousJobs[i].getJobTitle()==WK.getJobCompanyName())
            {
                valid=false;
            }
        }

         previousJobs[numberOfPrviousJobs]=WK;
         setNumberOfPrviousJobs(numberOfPrviousJobs+1);
         valid=true;
     }
     else
     {
         valid=false;
         
     }
     return valid;
}
bool Application::removePreviousJob(const WorkExperience& WK)
{
    bool valid{false};
    if(numberOfPrviousJobs>0)
    {
        for(int i=0; i<getNumberOfPrviousJobs(); i++)
        {
            if(previousJobs[i].getJobCompanyName()==WK.getJobCompanyName() && previousJobs[i].getJobTitle()==WK.getJobCompanyName())
            {
                numberOfPrviousJobs=i;
            }
        }
         WorkExperience *wk;//not sure if this is the right way to do!
         wk=new WorkExperience[numberOfPrviousJobs];
         previousJobs[numberOfPrviousJobs]=wk[numberOfPrviousJobs];
         setNumberOfPrviousJobs(numberOfPrviousJobs-1);
         valid=true;
    }
    else
    {
        valid=false;
    }
    return valid;
}
void Application::setNumberOfLanguages(int num)
{
    numLanguages=(num>0 && num< maxSize? num:0);
    
}
bool Application::addLangauge(const string& lang)
{
    bool valid{false};
    if(numLanguages>0 && numLanguages<maxSize)
    {
        for(int i=0;  i<getNumberOfLangauges(); i++)
        {
            if(languageName[i]==lang)
            {
                valid=false;
            }
        }
        languageName[numLanguages]=lang;
        setNumberOfLanguages(numLanguages+1);
    }
    return valid;
}
bool Application::removeLanguage(const string& lang)
{
    bool valid{false};
    if(numLanguages>0)
    {
        for(int i=0;  i<getNumberOfLangauges(); i++)
        {
            if(languageName[i]==lang)
            {
                numLanguages=i;
            }
        }
        languageName[numLanguages]=" ";
        setNumberOfLanguages(numLanguages-1);
        
    }
    return valid;
}

/****************************************************
            getFunctions
 ******************************************************/
string Application::getApplicantName() const
{
    return ApplicantName;
}
string Application::getApplicantLastName() const
{
    return ApplicantLastName;
}
PhoneNumber Application::getApplicantPhone() const
{
    return ApplicantPhone;
}
EMailAddress Application::getApplicantEmail() const
{
    return ApplicantEmail;
}

Date Application::getApplicationOpenDate() const
{
    return ApplicationOpenDate;
}
Date Application::getApplicationDeadline() const
{
    return ApplicationDeadline;
}
Date Application::getAppliedDate() const
{
    return AppliedDate;
}
string Application::getPosition() const
{
    return position;
}
string Application::getPositionType() const
{
    return positionType;
}
string Application::getPositionLocation() const
{
    return positionLocation;
}
string Application::getApplicantFieldOfeducation() const
{
    return applicantFieldOfeducation;
}

string Application::getLevelOfEducation() const
{
    return levelOfEducation;
}
int Application::getNumberOfPrviousJobs() const
{
    return numberOfPrviousJobs;
}
int Application::getNumberOfLangauges() const
{
    return numLanguages;
}
string Application::getSkills() const
{
    return skills;
}
int Application::getMaxSize() const
{
    return maxSize;
}
WorkExperience* Application::getWorkExperience() const
{
    
    return previousJobs;

}
string* Application::getLanaguages() const
{
    return languageName;
}
/**************************************************************************************************************
   We will see that each of the jobs will check to see if this is the applicant needed
 *************************************************************************************************************/
string Application::getFileName() const
{
    return fileName;
}
/***********************************************************************************************************
    the education level function checks if the user  has entered any of the education levels below, because any applicant with this info should not be accepted to work*/
bool Application::educationLevelMatching() //each position is different
{
    bool valid{false};
    string level=getLevelOfEducation();
    for(int i=0; i<levelOfEducation.length();i++)
    {
        level=toupper(level[i]);
        if(level=="N/A" || level=="NEVER ATTENDED SCHOOL")
        {
            valid=false;
        }
        else
        {
            valid=true;
        }
    }
    return valid;
    
}
bool Application::yearsOfexpericeMatching() //each position needs differnet years
{
    bool valid{false};
    for(int i=0; i< maxSize; i++)
    {
        if(previousJobs[i].getJobBeginningDate().getYear()-previousJobs[i].getJobEndedDate().getYear()>1.0)
            
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
/************************************************************
 The test program if they speak english doesn't have to enter any other language and they recivea point in the language needed*/
bool Application::languageNeeded()
{
    bool valid{false};

    if(getNumberOfLangauges()>=0)
    {
        valid=true;
    }
    return valid;

}
/***********************************************************************
  For the general application it does not need to verify any skills as long it is not empty the applicant gets points
 ************************************************************************/
int Application::checkSkills()
{
    int count=0;

    if(getSkills()!="NULL" && getSkills()!="N/A" && getSkills()!=" ")
    {
        count=1;
    }
    else
    {
        count=0;
    }
    return count;
    
}
/***********************************************************************
  For the general application it does not need to verify any qalifications  as long it is not empty the applicant gets points
 ************************************************************************/
int Application::checkQalifications()
{
    int count=0;
    if(checkSkills()>0 && languageNeeded()==true)
    {
        count=2;
    }
    return count;
}
/***********************************************************************
  For the general application it does not need to verify any qualifications as long as the applicant has entered a skill and it is not  points it saves it into the talent file. we also have to make sure that the applicant info is not computer sample
 ************************************************************************/
void Application::printApplicationDetailsTofile()
{

    if(!getApplicantName().empty()&& !getApplicantLastName().empty() && !talentFile.fail())
    {
        talentFile<< "TALENT INFO:\n\n";
        talentFile<< "Name:" << getApplicantName()<<endl;
        talentFile<< "LastName: "<<getApplicantLastName()<<endl;
        talentFile<< "Date Applied: "<<getAppliedDate()<<endl;
        talentFile<< "PhoneNumber: "<<getApplicantPhone()<<endl;
        talentFile<< "JobType: " <<getPositionType()<<endl;
        talentFile<< "Email: "<<getApplicantEmail()<<endl;
        /*******************************************************************************
           This prints out the jobs that the person has worked*/
        for(int i=0; i<getNumberOfPrviousJobs(); i++)
        {
            talentFile<< "Work Experience #"<< i << ": "<< previousJobs[i];
        }
        
    }//maybe we can use exception handeling here
    else if(talentFile.fail())
    {
        cout<<"Sorry Your File could not be opened"<<endl;
    }
}
        /*this last function will search through the application
         and add a 1 to the points of the applicant qualification
         if this points get high based on the position the higher than 4 the applicant info will be saved in the HR's file*/
        
