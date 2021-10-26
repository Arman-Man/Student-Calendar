#include "Course.h"
#include <iomanip>

ostream& operator<<(ostream& output, const Course& obj) {
	output << "Course Info: " << obj.getCourseNum() << " -- " << obj.getCourseName() << endl
		<< "# of Units: " << obj.getCourseUnits() << endl
		<< "Course Dates: " << obj.getDateStart() << " - " << obj.getDateEnd() << endl
		<< "Meeting Days: " << obj.getCourseDays() << endl
		<< "Meeting Time: " << obj.getTimeStart() << " - " << obj.getTimeEnd() << endl
		<< "Daily Duration: " << fixed << setprecision(2) << obj.calcDailyFunction()
		<< " hours" << endl;
	return output;
}

Course::Course(const string& cNum, const string& cName, const string& cDays, int cUnits,
	const Date& dStart, const Date& dEnd, const Time& tStart, const Time& tEnd) :
	dateStart(dStart), dateEnd(dEnd), timeStart(tStart), timeEnd(tEnd) {
	setCourseNum(cNum);
	setCourseName(cName);
	setCourseDays(cDays);
	setCourseUnits(cUnits);
}

Course::~Course() {
	cout << "\nA course has been deleted." << endl;
}

Course& Course::setCourseNum(string cNum) {
	courseNum = cNum;
	return *this;
}

Course& Course::setCourseName(string cName) {
	courseName = cName;
	return *this;
}

Course& Course::setCourseDays(string cDays) {
	courseDays = cDays;
	return *this;
}

Course& Course::setCourseUnits(int cUnits) {
	courseUnits = cUnits;
	return *this;
}

Course& Course::setDateStart(int month, int day, int year) {
	dateStart.setDate(month, day, year);
	return *this;
}

Course& Course::setDateEnd(int month, int day, int year) {
	dateEnd.setDate(month, day, year);
	return *this;
}

Course& Course::setTimeStart(int hour, int minute) {
	timeStart.setTime(hour, minute);
	return *this;
}

Course& Course::setTimeEnd(int hour, int minute) {
	timeEnd.setTime(hour, minute);
	return *this;
}

string Course::getCourseNum() const {
	return courseNum;
}
string Course::getCourseName() const {
	return courseName;
}
string Course::getCourseDays() const {
	return courseDays;
}
int Course::getCourseUnits() const {
	return courseUnits;
}

Date Course::getDateStart() const {
	return dateStart;
}

Date Course::getDateEnd() const {
	return dateEnd;
}

Time Course::getTimeStart() const {
	return timeStart;
}

Time Course::getTimeEnd() const {
	return timeEnd;
}

double Course::calcDailyFunction() const {
	return double(abs(getTimeStart() - getTimeEnd()));
}