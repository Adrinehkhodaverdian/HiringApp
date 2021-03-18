/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                           Time
 -----------------------------------------------------------------
 -hour:int
 -minute: int
 -toUniversal( TimeStatus :string , hr :int , mn :int) :void
 -----------------------------------------------------------------
 +Time(hr:int , mn: int)
 +setHour(hr: int) :Time&
 +setMinute(mn : int) :Time&
 +getHour() const : int
 +getMinute() const: int
 +operator-(t2 :const Time&) : double
 -----------------------------------------------------------------
                   |friend functions|
  operator<<( output : ostream&, time : const Time&) : ostream&
  operator>>( input  : istream&, time : Time&) : istream&
 
 
*/

//Time Class Definition with const member functions
#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

class Time{
    friend ostream& operator<<( ostream&, const Time&);
    friend istream& operator>>(istream&, Time&);
private:
    int hour;  //0-23 (24 hour clock format)
    int minute; //0-59
    void toUniversal(string, int, int);
public:
    //default constructor
    Time(int = 0, int = 0);
    //set functions - not const since they modify private data
    //The & return type enables cascading
    Time& setHour(int);
    Time& setMinute(int);
    //get functions - (normally always declared const)
    int getHour() const;
    int getMinute() const;
    //void printUniversal() const;// to test the time works uncomment.
    double operator-(const Time&);
    
    
};
#endif
