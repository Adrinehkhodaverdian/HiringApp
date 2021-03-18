/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                AccountingApplication
 -----------------------------------------------------------------
-BackOfficeAccountingFile: ofstream
-fileN: string
 -----------------------------------------------------------------
+~AccountingApplication()
+AccountingApplication(name : const string & , last: const string & , time: const Time & , openD: const Date &, deadline: const Date &, dateToday: const Date &,title: const string & , jobType const string & , jobLocation const string &,  majorEdu: const string & , levelEdu: const string & , skill: const string &, max: const int);
+getFileName() const: string
+educationLevelMatching():bool
+yearsOfexpericeMatching(): bool
+languageNeeded():bool
+checkSkills(): int
+checkQalifications(): int
+printApplicationDetailsTofile(): void
 -----------------------------------------------------------------
 */

#ifndef AccountingApplication_h
#define AccountingApplication_h
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
//using namespace std;
using std::string;


class AccountingApplication : public Application
{
    
    private:
        ofstream BackOfficeAccountingFile;
        string fileN;
    public:
        virtual ~AccountingApplication();
        AccountingApplication(const string & = "NULL", const string & = "NULL", const Date & = Date(), const Date & = Date(), const Date & = Date(), const string & = "NULL", const string & = "NULL",  const string & = "NULL", const string & = "NULL", const string & = "NULL", const string & = "NULL", int =7);
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
#endif /* AccountingApplication_h */
