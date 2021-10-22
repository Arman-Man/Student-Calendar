#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H
#include <iostream>
#include "Semester.h"
#include "Course.h"
#include "Date.h"
#include "Time.h"

using namespace std;

class CourseSchedule {
	friend ostream& operator<< (ostream&, const CourseSchedule&);
private:
	string studentName;
	Semester studentSemester;
	Course* coursePtr;
	int maxSize;
	int numCourses;

	//utility fucntion
	bool checkDates(const Semester&, const Date&, const Date&);

public:
	CourseSchedule(const string&, const Semester&, const int&);
	CourseSchedule();
	string getStudentName() const;
	Semester getStudentSemester() const;
	int getNumCourse () const;

	void setStudentName(string);
	bool addCourse(const Course&);
	bool removeCourse(const Course&);

	~CourseSchedule();
};
#endif