#include "Date.h"

ostream& operator<<(ostream& output, const Date& obj) {
    output << obj.month << '/' << obj.day << '/' << obj.year;
    return output;
}

istream& operator>>(istream& input, Date& obj) {
    input >> obj.month;
    input.ignore();
    input >> obj.day;
    input.ignore();
    input >> obj.year;

    return input;
}

int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (testDay > 0 && testDay <= daysPerMonth[month])
    {
        return testDay;
    }

    //determine whether testDay is valid for a specific month
    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
    {
        return testDay;
    }

    cout << "Invalid Day " << testDay << " was set to 1" << endl;
    return 1;  //keep data in valid state
}

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
    setDate(mn, dy, yr);
}

Date& Date::setDate(int mn, int dy, int yr)
{
    if (mn > 0 && mn <= 12)
    {
        setMonth(mn);
    }

    else
    {
        setMonth(1);
    }

    setYear(yr);

    setDay(checkDay(dy));  //to validate the day

    return *this;
}

Date& Date::setMonth(int mn) {
    month = mn;
    return *this;
}

Date& Date::setDay(int dy) {
    day = dy;
    return *this;
}

Date& Date::setYear(int yr) {
    year = yr;
    return *this;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

bool Date::operator>(const Date& right) const {
    if (getYear() > right.year) {
        return true;
    }
    else if (getYear() == right.year && getMonth() > right.month) {
        return true;
    }
    else if (getYear() == right.year && getMonth() == right.month && getDay() > right.day) {
        return true;
    }
    else {
        return false;
    }
}

bool Date::operator==(const Date& right) const {
    if (getYear() == right.year && getMonth() == right.month && getDay() == right.day) {
        return true;
    }
    else {
        return false;
    }
}

bool Date::operator<(const Date& right) const {
    return !(*this > right);
}

bool Date::operator>=(const Date& right) const {
    return (*this > right || *this == right);
}

bool Date::operator<=(const Date& right) const {
    return (*this < right || *this == right);
}

bool Date::operator!=(const Date& right) const {
    return !(*this == right);
}