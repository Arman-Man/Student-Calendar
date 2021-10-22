#ifndef COURSE_H
#define COURSE_H

#include "Time.h"
#include "Date.h"
#include <string>
#include <iostream>
using namespace std;

class Course
{
	friend ostream& operator<<(ostream&, const Course&);
private:
	string courseNum;
	string courseName;
	string courseDays;
	int courseUnits;
	Date dateStart;
	Date dateEnd;
	Time timeStart;
	Time timeEnd;

public:
	Course(const string& cNum = "None", const string& cName = "None", const string& cDays = "None", int cUnits = 0,
		const Date& dStart = Date(), const Date& dEnd = Date(), const Time& tStart = Time(), const Time& tEnd = Time());
	~Course();

	Course& setCourseNum(string);
	Course& setCourseName(string);
	Course& setCourseDays(string);
	Course& setCourseUnits(int);

	Course& setDateStart(int, int, int);	//input form (month, day, year)
	Course& setDateEnd(int, int, int);		//input form (month, day, year)
	Course& setTimeStart(int, int);		//input form (hour, minute) hour is 0-23, time is 0-59
	Course& setTimeEnd(int, int);		//input form (hour, minute) hour is 0-23, time is 0-59

	string getCourseNum() const;
	string getCourseName() const;
	string getCourseDays() const;
	int getCourseUnits() const;

	Date getDateStart() const;
	Date getDateEnd() const;
	Time getTimeStart() const;
	Time getTimeEnd() const;

	double calcDailyFunction() const;
};

#endif#pragma once

