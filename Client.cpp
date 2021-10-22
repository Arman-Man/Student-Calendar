#include <iostream>
#include <string>
using namespace std;

#include "CourseSchedule.h"

int main()
{
	string studentName;
	string semesterName;
	Date startDate;
	Date endDate;
	int maxSize;
	char selection;

	cout << "Please enter your name: ";
	getline(cin, studentName);
	cout << "Please enter the semester: ";
	getline(cin, semesterName);
	cout << "Please enter the starting date (xx/xx/xxxx month/day/year): ";
	cin >> startDate;
	cout << "Please enter the ending date (xx/xx/xxxx momth/day/year): ";
	cin >> endDate;
	cout << "What's the maximum number of classes allowed to take: ";
	cin >> maxSize;

	Semester studentSemester(studentName, startDate, endDate);
	CourseSchedule studentCourseSchedule(studentName, studentSemester, maxSize);

	selection = 'P'; //just a random char to start the while loop
	
	while (selection != 'Q' && selection != 'q')
	{
		cout << "COURSE ENTRY MENU FOR: " << studentSemester << endl
			<< "----------------------------------------------------" << endl
			<< "1) Enter a new course" << endl
			<< "2) Remove a course" << endl
			<< "3) Print a Semester Schedule" << endl
			<< "q) Quit the program" << endl;
		cin >> selection;

		if (selection == '1')
		{
			Time startTime;
			Time endTime;
			Date startDateInput;
			Date endDateInput;
			double courseUnits;
			string courseName, courseNum, classDays;

			if (studentCourseSchedule.getNumCourse() == maxSize)
			{
				cout << "\nYou have reached the maximum course capacity. Please remove a course before adding a new one!" << endl;
			}
			else
			{
				cout << "Please enter course number: ";
				getline(cin, courseNum);
				cout << "Please enter course name: ";
				getline(cin, courseName);
				cout << "Please enter course unit(s): ";
				cin >> courseUnits;
				cin.ignore();
				cout << "Please enter class meeting days: ";
				cin >> classDays;
				cout << "Please enter class starting time (xx:xxAM/PM hour/minuteAM/PM): ";
				cin >> startTime;
				cout << "Please enter class ending time (xx:xxAM/PM hour/minuteAM/PM): ";
				cin >> endTime;
				cout << "Please enter start date (xx/xx/xxxx month/day/year): )";
				cin >> startDateInput;
				cout << "Please enter end date (xx/xx/xxxx month/day/year): ";
				cin >> endDateInput;
			}
			Course studentCourse(courseNum, courseName, classDays, courseUnits, startDateInput, endDateInput, startTime, endTime);


			if (studentCourseSchedule.addCourse(studentCourse))
			{
				cout << "Course added!" << endl;
			}
			else
			{
				cout << "Invalid input!" << endl;
			}
		}
		else if (selection == '2')
		{
			string courseNum;
			string courseName;

			if (studentCourseSchedule.getNumCourse() == 0)
			{
				cout << "\nYour schedule is empty now! There is NO course to be removed!" << endl;
			}

			cout << "Enter the course number you want to remove: ";
			getline(cin, courseNum);
			cout << "Enter the course name you want to remove: ";
			getline(cin, courseName);

			Course courseRemove(courseNum, courseName);

			if (studentCourseSchedule.removeCourse(courseRemove))
			{
				cout << "Course removed successfully!" << endl;
			}
			else
			{
				cout << "Invalid input!" << endl;
			}
		}

		else if (selection == '3')
		{
			cout << studentCourseSchedule;
		}

		else if (selection == 'q' || selection == 'Q')
		{
			cout << "Program ended! Thank you for using this program!" << endl;
		}

		else
		{
			cout << "Invalid selection! Enter again: ";
		}
	}

	return 0;
}