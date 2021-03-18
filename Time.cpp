/*
 Adrineh Khodaverdian 10168025
 CS/IS137
 final Project
 */

 #include <iostream>
 #include <iomanip>
 #include "Time.h"
 using namespace std;

 Time::Time(int hr, int mn)
 {
     setHour(hr);
     setMinute(mn);

 }
 /*SET FUNCTIONS: Never const since they need to modify private member data*///setTime function now is set up to enable cascading
 //setHour function is now set up to enable cascading
 Time& Time::setHour(int hr) {
     hour =( (hr >= 0 && hr < 24) ? hr : 0);
     //validates hour, if valid set to h, else setto 0

     return *this;

 } //setMinute function is now set up to enable cascading
 Time& Time::setMinute(int mn) {
     minute = ((mn >= 0 && mn < 60) ? mn : 0);
     //validates minute, if valid set to m, elseset to 0
     return *this;

 }
 /*GET FUNCTIONS: Do not modify private member data normally always const*/
 //getHour
 int Time::getHour() const //must be const since prototype is const
 {
     return hour;
 }
 //get Minute
 int Time::getMinute() const //must be const since prototype is const
 {
     return minute;

 }
 //changes the user input to universal
 void Time::toUniversal(string TimeStatus, int hr, int mn)
 {
     for( int i=0; TimeStatus[i]!='\0'; i++)
     {
         TimeStatus[i]=toupper(TimeStatus[i]);
     }

     if (TimeStatus== "AM")
     {
         if (hr == 12)
         {
             hr = 0;
             hour = hr;
         }
     
         else
         {
             hour = hr;
             setHour(hour);
             minute = mn;
             setMinute(mn);
         }
     }
     else if (TimeStatus == "PM" )
     {
         if( hr==12)
         {
             hr=12;
         }
         else
         {
             hour= hr + 12;
             setHour(hour);
             minute = mn;
             setMinute(mn);
         }

     }
 }

 /*void Time::printUniversal() const
 {

     cout << setfill('0') << setw(2) << getHour() << ":" << setfill('0') << setw(2) << getMinute() << endl;
 }*/
 //to check if the universal works uncomment all the related ones and create a object // in client to test it!

 double Time::operator-(const Time& t2)
 {
     int hr{0};
     int mn{0};
     hr=abs(t2.getHour() - this->getHour());
     mn=abs(t2.getMinute()-this->getMinute());
     float deduction=hr;
     deduction+=mn/60.0;
     return deduction;
 }
 istream& operator>>(istream& input, Time& time)
 {
     string TimeStatus;
     input >> time.hour;
     input.ignore();
     input >> time.minute;
     input.ignore();
     getline(input, TimeStatus);
     //makes this time to universal
     time.toUniversal(TimeStatus, time.hour, time.minute);
     return input;
 }
 ostream& operator<<(ostream& output, const Time& time) //allows cascading
 {

     output << setfill('0') << ((time.getHour() == 0 || time.getHour() == 12) ? 12 : time.getHour() % 12);
     output << ":" << setfill('0') << setw(2) << time.getMinute();
     output << setw(2) << (time.getHour() < 12 ? "AM" : "PM");

     return output;

 }

