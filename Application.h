/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                           Application
 -----------------------------------------------------------------
-ApplicantName:string
-ApplicantLastName:string
-ApplicantPhone: PhoneNumber
-ApplicantEmail: EMailAddress
-timeOfApplication: Time
-ApplicationOpenDate: Date
-ApplicationDeadline: Date
-AppliedDate: Date
-position:string
-positionType:string
-positionLocation:string
-applicantFieldOfeducation:string
-levelOfEducation:string
-numberOfPrviousJobs:int
-maxSize:int
-*previousJobs:  WorkExperience
-numLanguages: int
-*languageName: string
-skills: string
-talentFile: ofstream //this will store the qualifed applicant info
-fileName: string
 -----------------------------------------------------------------
+~Application()
+Application(name : const string & , last: const string &  , openD: const Date &, deadline: const Date &, dateToday: const Date &,title: const string & , jobType const string & , jobLocation const string &,  majorEdu: const string & , levelEdu: const string & , skill: const string &, max: int);
+operator=(app: const Application&): const Application&
+Application(app: const Application&)
+setApplicantName(nm:const string&):Application&
+setApplicantLastName(last: const string&):Application&
+setApplicantPhone(ph: const PhoneNumber&):Application&
+setApplicantEmail(email: const EMailAddress&):Application&
+setTimeOfApplication(time: const Time&):Application&
+setApplicationOpenDate(openD: const Date&):Application&
+setApplicationDeadline(deadline const Date&): Application&
+setAppliedDate(appliedD: const Date&):Application&
+setPosition(title: const string&):Application&
+setPositionType(jobType: const string&):Application&
+setPositionLocation(location: const string&): Application&
+setApplicantFieldOfeducation(major: const string&):Application&
+setLevelOfEducation(education: const string&): Application&
+setNumberOfPrviousJobs(numJob int):Application&
+setSkills(skill: const string&):Application&
+setMaxSize(size : const int):Application&
+addPreviousJob(WK :const WorkExperience&):bool
+removePreviousJob(WK: const WorkExperience&):bool
+setNumberOfLanguages(num: int):void
+addLangauge(lang: const string&):bool
+removeLanguage(lang: const string&):bool
+getApplicantName() const:string
+getApplicantLastName() const:string
+getApplicantPhone() const:PhoneNumber
+getApplicantEmail() const:EmailAddress
+getTimeOfApplication() const: Time
+getApplicationOpenDate() const: Date
+getApplicationDeadline() const: Date
+getAppliedDate() const:Date
+getPosition() const:string
+getPositionType() const:string
+getPositionLocation() const: string
+getApplicantFieldOfeducation() const:string
+getNumberOfPrviousJobs() const:int
+getNumberOfLangauges() const:int
+getLanaguages() const: string*
+getSkills() const:string
+getMaxSize() const: int
+getWorkExperience() const: WorkExperience*
+getFileName() const: string
+educationLevelMatching():bool
+yearsOfexpericeMatching(): bool
+languageNeeded():bool
+checkSkills(): int
+checkQalifications(): int
+printApplicationDetailsTofile(): void
 -----------------------------------------------------------------
 */

#ifndef Application_H
#define Application_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "Employee.h"
#include "Time.h"
#include "PhoneNumber.h"
#include  "EMailAddress.h"
#include <fstream>
#include "WorkExperience.h"
using namespace std;
//we want to use ios::app
class Application //don't forget to add the phone number Date and time
{
    private:
        string ApplicantName;
        string ApplicantLastName;
        PhoneNumber ApplicantPhone;
        EMailAddress ApplicantEmail;

        Date ApplicationOpenDate; //this value should be set when object created
        Date ApplicationDeadline; //this value should be set before applicant applying
        Date AppliedDate; //the Date the user will apply
        string position;  //position being applied for
        string positionType; //full-time, part-time, temporary
        string positionLocation; //front or back office
        string applicantFieldOfeducation; //applicants major should be related
        string levelOfEducation; //for each position is different
        int numberOfPrviousJobs;
        int maxSize;
        WorkExperience *previousJobs; //we ask the user how many experience want to add
        int numLanguages;
        string *languageName;
        string skills;
    /*
     even though the main application file is a base that is a bit generic to distngush the qualifications, it checks simple facts about them and saves into the talent folder
     */
        ofstream talentFile; //this will store the qualifed applicant info
        string fileName;

    public:

        virtual ~Application();
        Application(const string & = "NULL", const string & = "NULL", const Date & = Date(), const Date & = Date(), const Date & = Date(), const string & = "NULL", const string & = "NULL",  const string & = "NULL", const string & = "NULL", const string & = "NULL", const string & = "NULL", int =7);
        const Application& operator=(const Application&);
        Application(const Application&);
        /****************************************************
                    setFunctions
         ******************************************************/
        Application& setApplicantName(const string&);
        Application& setApplicantLastName(const string&);
        Application& setApplicantPhone(const PhoneNumber&);
        Application& setApplicantEmail(const EMailAddress&);


        Application& setApplicationOpenDate(const Date&); //this value should be set when object created
        Application& setApplicationDeadline(const Date&); //this value should be set before applicant applying
        Application& setAppliedDate(const Date&); //the Date the user will apply
        Application& setPosition(const string&);  //position being applied for
        Application& setPositionType(const string&); //full-time, part-time, temporary
        Application& setPositionLocation(const string&); //front or back office
        Application& setApplicantFieldOfeducation(const string&); //applicants major should be related
        Application& setLevelOfEducation(const string&); //for each position is different
        Application& setNumberOfPrviousJobs(int);
        Application& setSkills(const string&);
        Application& setMaxSize(const int);
        bool addPreviousJob(const WorkExperience&);
        bool removePreviousJob(const WorkExperience&);
        void setNumberOfLanguages(int);
        bool addLangauge(const string&);
        bool removeLanguage(const string&);
    
        
        /****************************************************
                    setFunctions
         ******************************************************/
        string getApplicantName() const;
        string getApplicantLastName() const;
        PhoneNumber getApplicantPhone() const;
        EMailAddress getApplicantEmail() const;

        Date getApplicationOpenDate() const; //this value should be set when object created
        Date getApplicationDeadline() const; //this value should be set before applicant applying
        Date getAppliedDate() const; //the Date the user will apply
        string getPosition() const;  //position being applied for
        string getPositionType() const; //full-time, part-time, temporary
        string getPositionLocation() const; //front or back office
        string getApplicantFieldOfeducation() const; //applicants major should be related
        string getLevelOfEducation() const; //for each position is different
        int getNumberOfPrviousJobs() const;
        int getNumberOfLangauges() const;
        string* getLanaguages() const;
        string getSkills() const;
        int getMaxSize() const;
        WorkExperience* getWorkExperience() const;
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

#endif /* Application_h */
