#include "Time.h"
#include <iomanip>

ostream& operator<<(ostream& output, const Time& obj) {
    output << ((obj.hour == 0 || obj.hour == 12) ? 12 : obj.hour % 12) << ":"
        << setfill('0') << setw(2) << obj.minute
        << (obj.hour < 12 ? " AM" : " PM");
    return output;
}

istream& operator>>(istream& input, Time& obj) {
    string timeOfDay;

    input >> obj.hour;
    input.ignore();
    input >> obj.minute;
    input >> timeOfDay;

    //input validation, default 0:00 AM
    obj.hour = (obj.hour > 12) ? 0 : obj.hour;
    obj.minute = (obj.minute > 59) ? 0 : obj.minute;
    timeOfDay = (timeOfDay != "am" && timeOfDay != "AM" && timeOfDay != "Am" &&
        timeOfDay != "pm" && timeOfDay != "PM" && timeOfDay != "Pm") ? "AM" : timeOfDay;

    obj.standardToUniversal(timeOfDay);
    return input;
}

Time Time::standardToUniversal(string timeOfDay) {
    if (timeOfDay == "am" || timeOfDay == "AM" || timeOfDay == "Am") {
        setHour((getHour() != 12) ? getHour() : 0);
    }
    else if (timeOfDay == "pm" || timeOfDay == "PM" || timeOfDay == "Pm") {
        setHour((getHour() != 12) ? getHour() + 12 : 12);
    }

    return *this;
}

Time::Time(int h, int m)
{
    setTime(h, m);
}

Time& Time::setTime(int h, int m)
{
    setHour(h);
    setMinute(m);
    return *this;
}

Time& Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    return *this;
}

Time& Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;
    return *this;
}

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

void Time::printUniversal()const
{
    cout << setfill('0') << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << endl;
}

void Time::printStandard()const
{
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
        << setfill('0') << setw(2) << getMinute()
        << (getHour() < 12 ? " AM" : " PM") << endl;
}

double Time::operator-(const Time& right) const {
    double hours = abs(getHour() - right.getHour());
    double minutes = abs(((double(getMinute()) - double(right.getMinute())) / 60));
    return hours + minutes;
}