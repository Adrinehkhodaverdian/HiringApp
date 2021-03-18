
/*
Adrineh Khodaverdian 10168025
CS/IS137
final Project
Hiring app
*/

#include <string> //help us with string inputs
#include <stdexcept> //enables class exception handeling
#include <iomanip> //for digit manlipultation
#include <vector> //to use vector functions and polymprphism
#include <algorithm> //allows the use of STL library
#include <iterator> //to iterate over the compnents of a vector
#include <stdexcept>
#include "Employee.h"
#include "HREmployee.h"
#include "CasualEmployee.h"
#include "Company.h"
#include "Application.h"
#include "WorkExperience.h"
#include "BackOfficeManagerApplication.h"
#include "AccountingApplication.h"
#include "CallCenterApplication.h"
#include "ITApplication.h"
#include "AssociateApplication.h"
#include "FrontOfficeManagerApplication.h"
#include <fstream> //library used to read and write into text files
#include <cctype> //used for string manipulation
#include <iostream>
using namespace std;
int main() {

    char choice{ '\0' };

    ifstream inputFile; //the second file that will real all the data
    ofstream ouputFile;
    string info{ '\0' };
    const int numJobs = 4;
    /********************************************************************
    Variables used for the employee class instance initilization
    ********************************************************************
    */
    string EmpName{ '\0' }; //to save employee name
    string EmpLastName{ '\0' }; //to save employee last name
    string title{ '\0' }; //to get the title of the employee entering the portal
    string ID{ '\0' }; //to get employee id
    string derpartment{ '\0' }; //to get employee department, because all employees
    //don't have the same permisions
    Employee* genEmp = nullptr;// using polymporphism to access virtual functions
    /********************************************************************
    Variables used for the Application class instance initilization
    ********************************************************************
    */
    string applicantName{ '\0' };
    string applicantLast{ '\0' };
    string jobType{ '\0' };
    string level{ '\0' };
    string skills{ '\0' };
    string position; //will save applicant postion
    string location; //will save location of applicant work place
    int numLang{ 0 };
    int count{ 0 }; //counts the jobs applied for
    int numExperience = 0;// the number of work experiences that the applicant has
    PhoneNumber applicantPhone; //application ph
    EMailAddress applicantEmail; //application email
    //the vector that will save all the applications and help us to iterate through it
    vector<Application*> myApplications;


    Date applicationOpen(10, 11, 2020);
    Date applicationDead(2, 20, 2021);
    Date infoDate;
    /********************************************************************
    Variables used for the WorkExperience class instance initilization
    ********************************************************************
    */
    string major{ '\0' };
    string fileName;
    int years;
    string JobTitle;
    Date JobBeginningDate;
    Date JobEndedDate;
    string JobCompanyName;
    string ThreeDuties;
    string reasonForleaving;
    /********************************************************************
    Variables used for the Company class instance initilization
    ********************************************************************
    */
    //companyies opening date
    Date openDate(1 / 12 / 1990);
    Date presentDate;
    EMailAddress emailComp("info", "ShopWithUS.com");
    PhoneNumber compPhone("1", "800", "1111111");
    Company ShopWithUs("Shop With Us!", "8000 W Olympic Blvd, Beverly Hills, CA,90211.",
    "Shop With Us! Is happy to be one of the biggest chain discount store.\nShop With Us,is a third party company that helps the small business and even chain stores to sell products rapidly.\nWith only 10 employees working in each location!",
    " Third Party Discount Store!", openDate, presentDate, 4, 4, 10);

    int option{ 0 };
    do
    {
        cout << "Welcome to " << ShopWithUs.getName() << " Home Page" << endl;
        cout << "Main Menu:" << endl;
        cout << "1)Our Services." << endl;
        cout << "2)About Us!" << endl;
        cout << "3)Careers." << endl;
        cout << "4)Employee Portal." << endl;
        cout << "q)quit." << endl;
        cout << "Please enter choice: ";

        cin >> choice;
        choice = tolower(choice);
        /*
         ****************************************
         Option 1 just displays details about company
         ****************************************
         */
        if (choice == '1')
        {
            cout << ShopWithUs.getServices() << endl << endl;
        }
        /*
         ****************************************
         Option 2 is the about us
         ****************************************
         */
        else if (choice == '2')
        {
            cout << ShopWithUs.getName() << endl;
            cout << "We are located in " << ShopWithUs.getLocation() << endl;
            cout << ShopWithUs.getName() << "Is one of the greatest " << ShopWithUs.getField() << endl;
            cout << "In the United States, Our company started it's operation from " << ShopWithUs.getOpenningDate() << "\nAnd we are thankful to be in service for the community for " << ShopWithUs.getPresentDate().getYear() - ShopWithUs.getOpenningDate().getYear() << "years" << endl;
            cout << "For more Information about our company please email us at: " << emailComp << endl;
            cout << "or visit us at SHOPWITHUS.com\n" << endl;
        }
        /*
         ****************************************
         Option 3 shows how many open positions exist,and asks to fill
         in a genreal application, set's the informations and creates files based on the applications applied
         ****************************************
         */
        else if (choice == '3')
        {
            cout << "We are happy to hear to see you becoming a part of the ShopWithUs family!" << endl;
            cout << "There are " << ShopWithUs.getNumberOfJobs() << " hiring positions." << endl;
            cout << "To start please fill in a manual application....." << endl;
            cin.ignore();
            cout << "Please enter your first name :" << endl;
            getline(cin, applicantName);
            cout << "Please enter your last Name : " << endl;
            getline(cin, applicantLast);
            cout << "Enter your highest level of education: " << endl;
            getline(cin, level);
            cout << "Enter your field of eduction: " << endl;
            getline(cin, major);
            cout << "Are you applying for Full time or Part time? :" << endl;
            getline(cin, jobType);
            cout << "Please enter your phone number(999)999-9999:" << endl;
            cin >> applicantPhone;
            cout << "Please enter your Email (i.e. username domain.com withount @ sign):" << endl;
            cin >> applicantEmail;
            cout<< "Please enter today's date (12/12/2020):"<<endl;
            cin>>presentDate;
            cout << "How many Previous Experience would you like to add? :" << endl;
            cin >> numExperience;
            WorkExperience* wk = new WorkExperience[numExperience];

            for (int i = 0; i < numExperience; i++)
            {
                cin.ignore();
                cout << "Enter Job Title " << i + 1 << ": ";
                getline(cin, JobTitle);
                cout << "Company Name " << i + 1 << ": ";
                getline(cin, JobCompanyName);
                cout << "Enter Job start date: ";
                cin >> JobBeginningDate;
                cout << "Enter job end date, if you are still working enter todays date: " << endl;
                cin >> JobEndedDate;
                cout << "Enter reason for leaving " << i + 1 << ": ";
                getline(cin, reasonForleaving);

                years = JobEndedDate.getYear() - JobEndedDate.getYear();
                /*
                this is why enables cascading in our set functions
                */
                wk[i].setJobCompanyName(JobCompanyName).setJobBeginningDate(JobBeginningDate);
                wk[i].setJobEndedDate(JobEndedDate).setJobTitle(JobTitle);
                wk[i].setReasonForleaving(reasonForleaving).setYearsOfExperience(years);
            }
            do
            {
                cout << "Menu:" << endl;
                cout << "1)Back Office Manager Position." << endl;
                cout << "2)Associate position." << endl;
                cout << "3)Accounting position." << endl;
                cout << "4)IT positon." << endl;
                cout << "0)exit" << endl;
                cout << "Please enter your choice: ";
                cin >> option;
                /*we want to make sure the output file is open for the program to save the aapplication
                 also it is ios::out, because after a new person want to use and apply for the job
                 they should not be able to see the former applicants information*/
                ouputFile.open("Apply.txt",ios::out);
                if (option == 1)
                {
                    position = "Back OFFice Manager";
                    cout << "How many languages besides english are you fluent in? ";
                    cin >> numLang;

                    cin.ignore();
                    skills = "managemnt";
                    BackOfficeManagerApplication* BMApp = new BackOfficeManagerApplication(applicantName, applicantLast, applicationOpen, applicationDead, presentDate, position, jobType, ShopWithUs.getLocation(), major, level, skills, numExperience);
                    BMApp->setNumberOfLanguages(numLang);
                    BMApp->setApplicantEmail(applicantEmail);
                    BMApp->addPreviousJob(*wk);
                    BMApp->setApplicantPhone(applicantPhone);
                    BMApp->printApplicationDetailsTofile();
                    cout << "Back Office Manager Application was filled in successfully\n\n";
                    myApplications.push_back(BMApp);
                    count++;
                }
                else if (option == 2)
                {
                    position = "Associate";
                    AssociateApplication* assoiApp = new AssociateApplication(applicantName, applicantLast, applicationOpen, applicationDead, presentDate, position, jobType, ShopWithUs.getLocation(), major, level, skills, numExperience);
                    assoiApp->setNumberOfLanguages(1);
                    assoiApp->setApplicantEmail(applicantEmail);
                    assoiApp->addPreviousJob(*wk);
                    assoiApp->setApplicantPhone(applicantPhone);
                    assoiApp->printApplicationDetailsTofile();
                    cout << "Associate Application was filled in successfully\n\n";

                    myApplications.push_back(assoiApp);
                    count++;
                }
                else if (option == 3)
                {
                    cout << "Enter one major skill: ";
                    cin >> skills;
                    position = "Accountant";
                    AccountingApplication* accApp = new AccountingApplication(applicantName, applicantLast, applicationOpen, applicationDead, presentDate, position, jobType, ShopWithUs.getLocation(), major, level, skills, numExperience);
                    accApp->setApplicantEmail(applicantEmail);
                    accApp->addPreviousJob(*wk);
                    accApp->setApplicantPhone(applicantPhone);
                    accApp->printApplicationDetailsTofile();
                    count++;
                    cout << "Accounting Application was filled in successfully\n\n";
                    myApplications.push_back(accApp);

                }
                else if (option == 4)
                {
                    cout << "How many programming languages do you know? ";
                    cin >> numLang;
                    cout << "Enter one major skill: ";
                    cin >> skills;
                    position = "IT Specialist";
                    ITApplication* itApp = new ITApplication(applicantName, applicantLast, applicationOpen, applicationDead, presentDate, position, jobType, ShopWithUs.getLocation(), major, level, skills, numExperience);
                    itApp->setNumberOfLanguages(numLang);
                    itApp->setApplicantEmail(applicantEmail);
                    itApp->addPreviousJob(*wk);
                    itApp->setApplicantPhone(applicantPhone);
                    itApp->printApplicationDetailsTofile();

                    count++;
                    cout << "IT Application was filled in successfully\n\n";

                    myApplications.push_back(itApp);
                }
                else if (option == 0)
                {
                    cout << "Redirecting to main menu" << endl;
                    cout << "Your information is also saved in our talent file! We will contanct you if another position will be opened!" << endl;
                    Application *talentApp=new Application(applicantName, applicantLast, applicationOpen, applicationDead, presentDate, position, jobType, ShopWithUs.getLocation(), major, level, skills, numExperience);
                    talentApp->setApplicantPhone(applicantPhone);
                    talentApp->setApplicantEmail(applicantEmail);
                    talentApp->addPreviousJob(*wk);
                    talentApp->printApplicationDetailsTofile();

                }
                else
                {
                    cout<< "Invlaid entery"<<endl;
                }

                cout<< "your Applied positions have been saved to Apply.txt"<<endl;
                if(ouputFile.fail())
                {

                    cout<< "File couldn't open"<<endl;
                }
                else
                {
                    /***********************************************************
                    This part of the program only saves the applicants applied postion for the applicant. in apply.txt
                     ************************************************************/
                    for(int index=0; index< count; index++)
                    {
                        ouputFile<<myApplications[index]->getApplicantName();
                        ouputFile<<myApplications[index]->getApplicantLastName();
                        ouputFile<<endl;
                        ouputFile<<myApplications[index]->getPosition()<<" : ";
                        ouputFile<<myApplications[index]->getAppliedDate()<<endl;
                       
                    }
                }
                ouputFile.close();
            } while (option != 0 && count<numJobs);

            }
            /********************************************************************
            Option 4 displays two different menus based on the employee types.
            ********************************************************************
            */
            else if (choice == '4')
            {
                
                    cin.ignore();
                    cout << "Please enter your name: ";
                    getline(cin, EmpName);
                    cout << "Please enter your last name: ";
                    getline(cin, EmpLastName);
                    cout << "Please enter your job title: ";
                    getline(cin, title);
                    cout << "Please enter your alphanumeric Employee ID#: ";
                    getline(cin, ID);
                    cout << "Please enter your department: ";
                    getline(cin, derpartment);
                    if (derpartment != "hr" && derpartment != "HR")
                    {
                        CasualEmployee casualEmp(EmpName, EmpLastName, title, ID, derpartment);
                        genEmp = &casualEmp;
                        genEmp->DisplayMenu();
                        cin >> choice;
                    }
                    else
                    {
                        HREmployee hrEmp(EmpName, EmpLastName, title, ID, derpartment);
                        genEmp = &hrEmp;
                        genEmp->DisplayMenu();
                        cin >> choice;
                        if (choice == '1')
                        {
                            cout<<"Recall: THIS FILES CONTAIN ONLY  THE INFO OF THE APPLICANTS WITH ADEQUATE SKILLS AND EXPEREIENCE FOR THE RELEVANT ROLE."<<endl;
                            for(int index=0; index<myApplications.size(); index++)
                            {
                                inputFile.open(myApplications[index]->getFileName());
                                cout <<myApplications[index]->getFileName() <<endl<<endl;
                                while(!inputFile.fail())
                                {
                                    if(inputFile.fail())
                                    {
                                        cout << "File did not open successfully!" << endl;
                                    }
                                    else{
                                        getline(inputFile,info);
                                        cout<<info<<"    ";
                                        cout<<endl;
                                       
                                    }
                                }
                                cout<<"\n";
                                inputFile.close();
                            }
                        }
                        else if (choice == '2')
                        {
                            cout << "The payroll department can be only accessed directly through our website ShopWithUs.com, or call " << compPhone << endl;
                        }
                        else
                        {
                            cout<< "invalid entery."<<endl;
                        }
                    }
            
            }
            else if (choice == 'q' || choice == 'Q')
            {
                cout << "Quit" << endl;
            }
            else
            {
                cout << "Invalid Entry!" << endl;
                cout << "Please try again!" << endl;
            }
    } while (choice != 'q');
return 0;
}
