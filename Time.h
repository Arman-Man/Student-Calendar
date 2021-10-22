#ifndef	TIME_H
#define TIME_H

#include <string>
#include <iostream>
using namespace std;

class Time
{
    friend ostream& operator<<(ostream&, const Time&);    //prints standard time
    friend istream& operator>>(istream&, Time&);    //enter time in standard time, stores as universal time, form HH:MM AM (or PM)

private:
    int hour;       //0-23 (24 hour clock format)
    int minute;     //0-59
    Time standardToUniversal(string);  //enter "am" if hour is 0-11, enter "pm" if hour is 12-23

public:
    Time(int = 0, int = 0);

    Time& setTime(int, int);    //input form (hour, minute) hour is 0-23, time is 0-59
    Time& setHour(int);
    Time& setMinute(int);

    int getHour() const;
    int getMinute() const;

    //must be in form universal time before using either print function
    void printUniversal() const;        //print universal time (24 hour clock)
    void printStandard()const;          //print standard time (AM/PM)

    double operator-(const Time&) const;
};

#endif
