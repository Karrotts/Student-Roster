#pragma once
#include "student.h"
#include <string>


class Roster {
public:
	Student** classRosterArray = new Student*[5];
	int studentCount = 0;
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, int degreeProgram);
	void remove(string ID);
	void printAll();
	void printInvalidEmails();
	void printAverageDaysInCourse(Student* s);
	void printByDegreeProgram(int type);
	~Roster();
};