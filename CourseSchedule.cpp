#include "CourseSchedule.h"
#include <iostream>

bool CourseSchedule::checkDates(const Semester& semester, const Date& starting, const Date& ending)
{
	if (semester.getStartDate() > starting)
	{
		return false; //if the starting date of this course is ahead of the semester starting date, reture false
	}
	else if (semester.getEndDate() < ending)
	{
		return false;//if the ending date of this course is behind the semester date, then return false
	}
	else
	{
		return true;
	}
}

CourseSchedule::CourseSchedule(const string& nameInput, const Semester& semInfo, const int& maxNum)
{
	this->studentName = nameInput;
	this->studentSemester = semInfo;
	this->maxSize = maxNum;
	this->numCourses = 0;
	coursePtr = new Course[maxNum];
}

CourseSchedule::CourseSchedule()
{
	this->studentName = "";
	this->maxSize = 0;
}

string CourseSchedule::getStudentName() const
{
	return studentName;
}

Semester CourseSchedule::getStudentSemester() const
{
	return studentSemester;
}

int CourseSchedule::getNumCourse() const
{
	return numCourses;
}

void CourseSchedule::setStudentName(string nameInput)
{
	// TODO: insert return statement here
	this->studentName = nameInput;
}

bool CourseSchedule::addCourse(const Course& course)
{
	// TODO: insert return statement here

	if (numCourses < maxSize)
	{
		if (checkDates(studentSemester, course.getDateStart(), course.getDateEnd()) == true)
		{
			for (int i = 0; i < numCourses; ++i)
			{
				if (coursePtr[i].getCourseNum() == course.getCourseNum() && coursePtr[i].getCourseName() == course.getCourseName())
				{
					return false;  //if any of the course has same name or course number, then it's already existing. So, return false.
				}
			}

			coursePtr[numCourses] = course;//dynamically allocating this course
			++numCourses;
			return true;
		}

		else
		{
			return false;//exceed semester date duration
		}
	}
	else
	{
		return false;//exceeded max course size
	}
}

bool CourseSchedule::removeCourse(const Course& courseToRemove)
{
	// TODO: insert return statement here
	if (numCourses >= 1)
	{
		int index = -1;

		for (int i = 0; i < numCourses; ++i)
		{
			if (coursePtr[i].getCourseNum() == courseToRemove.getCourseNum() && coursePtr[i].getCourseName() == courseToRemove.getCourseName())
			{
				index = i;// get the locate where to be removed
			}
		}

		if (index == -1)
		{
			return false; //no course in the schedule
		}
		else
		{
			coursePtr[index] = coursePtr[numCourses - 1];//replace with the last course
			--numCourses; //and delete the last course
			return true;
		}

	}
	else
	{
		return false;
	}
}


CourseSchedule::~CourseSchedule()
{
	delete[] coursePtr;
}

ostream& operator<<(ostream& output, const CourseSchedule& schedule)
{
	// TODO: insert return statement here
	output << "\nYour Class Schedule: \n"
		<< "=================================="
		<< "\nName: " << schedule.getStudentName() << endl
		<< "Number of courses: " << schedule.getNumCourse() << endl
		<< "-----------------------------------" << endl;

	for (int i = 0; i < schedule.getNumCourse(); ++i)
	{
		cout << schedule.coursePtr[i] << endl;
	}

	return output;
}