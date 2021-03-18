/*Adrineh Khodaverdian,
CS/IS 137
Final Project
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Date.h"
using namespace std;

//constructor validates month and calls utility function to validateday
Date::Date(int mn, int dy, int yr)
{
    setMonth(mn);
    setDay(dy);
    setYear(yr);
}
Date& Date::setMonth(int mn)
{
    mn = (mn > 0 && mn <= 12 ? mn : 1); //if the entered month is invlaid set it 1
    month = mn;
    return *this;
}
Date& Date::setDay(int dy)
{
    static const int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (dy > 0 && dy <= daysPerMonth[month])
    {
        if(dy == /* DISABLES CODE */ (2) && dy == 29 && (year % 400 == 0 ||(year % 4 == 0 && year % 100 !=0)))
        {
            day = dy;
        }
        else{
            day = dy;
            
        }
    }
    else
    {
        dy = 1;
        day = dy;
    }
    //determine whether testDay is valid for a specific month
    return *this;
}
Date& Date::setYear(int yr)
{
    year = (yr >= 1990 ? yr : 1990);
    return *this;
}
int Date::getMonth() const
{
    return month;
}
int Date::getDay() const
{
    return day;
}
int Date::getYear() const
{
    return year;
}
bool Date::operator>(Date& date2) const
{
    bool valid{ false };
    if( this->year > date2.getYear())
    {
        valid = true;
    }
    else if (this->month > date2.getMonth() && this->year == date2.getYear())
    {
        valid = true;
    }
    else if (this->day > date2.getDay() && this->year == date2.getYear() && this->month == date2.getMonth())
    {
        valid = true;
    }
    else
    {
        valid = false;
    }
    return valid;
}
bool Date::operator<(Date& date2) const
{
    bool valid{ false };
    if (this->year < date2.getYear())
    {
        valid = true;
    }
    else if (this->month < date2.getMonth() && this->year == date2.getYear())
    {
        valid = true;
    }
    else if (this->day < date2.getDay() && this->year == date2.getYear() && this->month == date2.getMonth())
    {
        valid = true;
    }
    else
    {
        valid = false;
    }
    return valid;
}
bool Date::operator>=(Date& date2) const
{
    bool valid{ false };
    if (this->year >= date2.getYear())
    {
        valid = true;
    }
    else if (this->month >= date2.getMonth() && this->year == date2.getYear())
    {
        valid = true;
    }
    else if (this->day >= date2.getDay() && this->year == date2.getYear() && this->month == date2.getMonth())
    {
        valid = true;
    }
    else
    {
        valid = false;
    }
    return valid;
}
bool Date::operator<=(Date& date2) const
{
    bool valid{ false };
    if (this->year <= date2.getYear())
    {
        valid = true;
    }
    else if (this->month <= date2.getMonth() && this->year == date2.getYear())
    {
        valid = true;
    }
    else if (this->day <= date2.getDay() && this->year == date2.getYear() && this->month == date2.getMonth())
    {
        valid = true;
    }
    else
    {
        valid = false;
    }
    return valid;
}
bool Date::operator==(Date& date2) const
{
    bool valid{ false };
    if (this->month == date2.getMonth() && this->day == date2.getDay() && this->year == date2.getYear())
    {
        valid = true;
    }
    else
    {
        valid = false;
    }
    return valid;
}
bool Date::operator!=(Date& date2) const
{
    bool valid{ false };
    if (this->month != date2.getMonth() || this->day != date2.getDay() || this->year != date2.getYear())
    {
        valid = true;
    }
    else
    {
        valid = false;
    }
    return valid;
}
double Date::operator-(Date& date2) const
{
    double years=0.0;
    years=date2.getYear()-this->getYear();
    return years;
    
}
istream& operator>>(istream& input, Date& date)
{
    input >> date.month;
    input.ignore();
    input >> date.day;
    input.ignore();
    input >> date.year;
    input.ignore();
    return input;
}
ostream& operator<<(ostream& output, const Date& date)
{
    output << setw(2) << setfill('0') << date.getMonth() << '/' << setw(2) << setfill('0') << date.getDay() << '/' << setfill('0') << date.getYear();
    return output;
}
