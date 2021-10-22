#include "Semester.h"

ostream& operator<<(ostream& output, const Semester& input)
{
	output << input.semesterName << " (" << input.startDate << "-" << input.endDate << ")" << endl;

	return output;
}

istream& operator>>(istream& input, Semester& output)
{
	cout << "Please enter your semester and year (like: Fall 2019): ";
	input >> output.semesterName;

	cout << "Please enter the starting date for this semester (like: 09/03/2019)" << endl;
	input >> output.startDate;

	cout << "Please enter the ending date for this semester (like 12/12/2019): ";
	input >> output.endDate;

	return input;
}

Semester::Semester(const string& nameInput, const Date& start1, const Date& end1)
{
	semesterName = nameInput;
	startDate = start1;
	endDate = end1;
}

Semester::Semester()
{
	semesterName = "";
}

void Semester::setSemesterName(string& semName)
{
	this->semesterName = semName;
}

void Semester::setStartDate(int month, int day, int year)
{
	startDate.setMonth(month);
	startDate.setDay(day);
	startDate.setYear(year);
}

void Semester::setEndDate(int month, int day, int year)
{
	endDate.setDate(month, day, year);
}


string Semester::getSemesterName() const
{
	return this->semesterName;
}

Date Semester::getStartDate() const
{
	return this->startDate;
}

Date Semester::getEndDate() const
{
	return this->endDate;
}