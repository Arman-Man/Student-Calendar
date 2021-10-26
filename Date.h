#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);     //input form MM/DD/YYYY


private:
    int month; //1-12
    int day; //1-31 depending on month
    int year; //any year

    int checkDay(int) const;    //utility function to check if day is proper for month and year

public:
    Date(int = 1, int = 1, int = 1990);

    Date& setDate(int, int, int);       //input form (month, day, year)
    Date& setMonth(int);
    Date& setDay(int);
    Date& setYear(int);

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    bool operator>(const Date&) const;
    bool operator==(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>=(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator!=(const Date&) const;

};

#endif
