#ifndef SEMESTER_H
#define SEMESTER_H
#include <string>
#include <iostream>
#include "Date.h"
using namespace std;

class Semester
{

	friend ostream& operator<<(ostream&, const Semester&); //overload << operator
	friend istream& operator>>(istream&, Semester&);       //overload >> operator

private:
	string semesterName;
	Date startDate;
	Date endDate;

public:
	Semester(const string&, const Date& = Date(), const Date& = Date());
	Semester();
	void setSemesterName(string&);
	void setStartDate(int, int, int);
	void setEndDate(int, int, int);
	string getSemesterName() const;
	Date getStartDate() const;
	Date getEndDate() const;
};

#endif