/*Adrineh Khodaverdian
 CS/IS 137
 Final Project
 -----------------------------------------------------------------
                           Date
 -----------------------------------------------------------------
 -month:int
 -day: int
 -year: int
 -----------------------------------------------------------------
 +Date( mn :int, dy: int, yr: int )
 +setMonth(mn :int) : Date&
 +setDay(dy :int) : Date&
 +setYear(yr: int): Date&
 +getMonth() const :int
 +getDay() const :int
 +getYear() const :int
 +operator>(date2: Date&) const : bool
 +operator<(date2: Date&) cons : bool
 +operator>=(date2: Date&) const : bool
 +operator<=(date2: Date&) const : bool
 +operator==(date2: Date&) const : bool
 +operator!=(date2: Date&) const : bool
 -----------------------------------------------------------------
                   |friend functions|
  operator<<( output : ostream&, date: const Date&) : ostream&
  operator>>( input  : istream&, date : Date&) : istream&
 
*/
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <iomanip>
using namespace std;
class Date
{
    //allow user input and output as an instance of the class
    friend istream& operator>>(istream&, Date&);
    friend ostream& operator<<(ostream&, const Date&);
private:
    int month; //1-12
    int day; //1-31 depending on month
    int year; //any year
public:
    Date(int = 1, int = 1, int = 2020);
    Date& setMonth(int);
    Date& setDay(int);
    Date& setYear(int);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    //Overload the >, <. >=, <=, ==, and!= operators for this class
    bool operator>(Date&) const;
    bool operator<(Date&) const;
    bool operator>=(Date&) const;
    bool operator<=(Date&) const;
    bool operator==(Date&) const;
    bool operator!=(Date&) const;
    double operator-(Date&)const; //for finding the duration in years

};
#endif

