/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                    CallCenterApplication
 -----------------------------------------------------------------
-BackOfficeCallCenterFile: ofstream
-fileN: string
 -----------------------------------------------------------------
+~CallCenterApplication()
+ CallCenterApplication(name : const string & , last: const string &, openD: const Date &, deadline: const Date &, dateToday: const Date &,title: const string & , jobType const string & , jobLocation const string &,  majorEdu: const string & , levelEdu: const string & , skill: const string &, max:  int);
+getFileName() const: string
+educationLevelMatching():bool
+yearsOfexpericeMatching(): bool
+languageNeeded():bool
+checkSkills(): int
+checkQalifications(): int
+printApplicationDetailsTofile(): void
 -----------------------------------------------------------------
 */
#ifndef CallCenterApplication_h
#define CallCenterApplication_h

#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "Employee.h"
#include "Time.h"
#include "PhoneNumber.h"
#include "EMailAddress.h"
#include <fstream>
#include "WorkExperience.h"
#include "Application.h"
using namespace std;

class CallCenterApplication : public Application
{
    
    private:
        ofstream BackOfficeCallCenterFile;
        string fileN; //this will save the file name so the user can read the file if needed, and this is going to be unique name based on the application
    public:
        virtual ~CallCenterApplication();
        CallCenterApplication(const string & = "NULL", const string & = "NULL",  const Date & = Date(), const Date & = Date(), const Date & = Date(), const string & = "NULL", const string & = "NULL",  const string & = "NULL", const string & = "NULL", const string & = "NULL", const string & = "NULL",  int =7);
        const CallCenterApplication& operator=(const CallCenterApplication&);
        CallCenterApplication(const CallCenterApplication&);
        /**************************************************************************************************************
           We will see that each of the jobs will check to see if this is the applicant needed
         *************************************************************************************************************/
        virtual string getFileName() const;
        virtual bool educationLevelMatching(); //each position is different
        virtual bool yearsOfexpericeMatching(); //each position needs differnet years
        virtual bool languageNeeded();
        virtual int checkSkills();
        virtual int checkQalifications();
        virtual void printApplicationDetailsTofile();
        /*this last function will search through the application
         and add a 1 to the points of the applicant qualification
         if this points get high based on the position the higher than 4 the applicant info will be saved in the HR's file*/
};

#endif /* CallCenterApplication_h */
