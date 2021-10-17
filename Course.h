#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Time.h"
#include "Date.h"
#include <iostream>

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

	Course& setDateStart(int, int, int);
	Course& setDateEnd(int, int, int);
	Course& setTimeStart(int, int);		//0-23 (24 hour clock format)
	Course& setTimeEnd(int, int);		//0-23 (24 hour clock format)

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

#endif