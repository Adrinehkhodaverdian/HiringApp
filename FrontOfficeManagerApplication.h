/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                FrontOfficeManagerApplication
 -----------------------------------------------------------------
-FrontOfficeManagerFile: ofstream
-fileN: string
 -----------------------------------------------------------------
+~FrontOfficeManagerApplication()
+FrontOfficeManagerApplication(name : const string & , last: const string & , openD: const Date &, deadline: const Date &, dateToday: const Date &,title: const string & , jobType const string & , jobLocation const string &,  majorEdu: const string & , levelEdu: const string & , skill: const string &, max: int);
+getFileName() const: string
+educationLevelMatching():bool
+yearsOfexpericeMatching(): bool
+languageNeeded():bool
+checkSkills(): int
+checkQalifications(): int
+printApplicationDetailsTofile(): void
 -----------------------------------------------------------------
 */

#ifndef FrontOfficeManagerApplication_h
#define FrontOfficeManagerApplication_h
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

class FrontOfficeManagerApplication : public Application
{
    
    private:
        ofstream FrontOfficeManagerFile;
        string fileN;
    
    public:
        virtual ~FrontOfficeManagerApplication();
        FrontOfficeManagerApplication(const string & = "NULL", const string & = "NULL", const Date & = Date(), const Date & = Date(), const Date & = Date(), const string & = "NULL", const string & = "NULL",  const string & = "NULL", const string & = "NULL", const string & = "NULL", const string & = "NULL", int =7);
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

#endif /* FrontOfficeManagerCareer_h */
