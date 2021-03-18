/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                          WorkExperience
 -----------------------------------------------------------------
-yearsOfExperience:int
-JobTitle:string
_JobBeginningDate: Date
_JobEndedDate:Date
-JobCompanyName:string
-ThreeDuties: string
-reasonForleaving: string
 -----------------------------------------------------------------
+WorkExperience(y: int , jobT: const string &, beginD: const Date & , endD: const Date & , companyName: const string & , threeD const string &, reason: const string &)
+setYearsOfExperience(years: int): WorkExperience&
+setJobTitle(const string&): WorkExperience&
+setJobBeginningDate(const Date&): WorkExperience&
+setJobEndedDate(const Date&): WorkExperience&
+setJobCompanyName(const string&): WorkExperience&
+setThreeDuties(const string&): WorkExperience&
+setReasonForleaving(const string&): WorkExperience&
+getYearsOfExperience() const: int
+getJobTitle() const: string
+getJobBeginningDate() const:Date
+getJobEndedDate() const:Date
+getJobCompanyName() const:string
+getThreeDuties() const:string
+getReasonForleaving() const:string
 -----------------------------------------------------------------
                    friend Functions
 operator<<(ostream&, const WorkExperience&): ostream&
 */


#ifndef WorkExperience_h
#define WorkExperience_h
#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "Employee.h"
#include "Time.h"
using namespace std;

class WorkExperience
{
    friend ostream& operator<<(ostream&, const WorkExperience&);
private:
    int yearsOfExperience;
    string JobTitle;
    Date JobBeginningDate;
    Date JobEndedDate;
    string JobCompanyName;
    string ThreeDuties; //we will allow the user to enter the three duties they did
    //the duties could also be created as an array of size 3 to save the data
    string reasonForleaving;
public:
    WorkExperience(int =0 , const string & = "NULL",  const Date & = Date(), const Date & = Date(), const string & = "NULL", const string & = "NULL", const string & = "NULL");
    /******************setFunctions*************************/
    WorkExperience& setYearsOfExperience(int);
    WorkExperience& setJobTitle(const string&);
    WorkExperience& setJobBeginningDate(const Date&);
    WorkExperience& setJobEndedDate(const Date&);
    WorkExperience& setJobCompanyName(const string&);
    WorkExperience& setThreeDuties(const string&); //we will allow the user to enter //the three duties they did
    WorkExperience& setReasonForleaving(const string&);
    /**************getFunction*****************************/
    int getYearsOfExperience() const;
    string getJobTitle() const;
    Date getJobBeginningDate() const;
    Date getJobEndedDate() const;
    string getJobCompanyName() const;
    string getThreeDuties() const;
    string getReasonForleaving() const;

    
};
#endif /* WorkExperience_h */
