#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "degree.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

		void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, int degreeProgram) {
			if (degreeProgram == SECURITY) {
				classRosterArray[studentCount] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete1, daysToComplete2, daysToComplete3, SECURITY);
			}
			if (degreeProgram == NETWORK) {
				classRosterArray[studentCount] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete1, daysToComplete2, daysToComplete3, NETWORK);
			}
			if (degreeProgram == SOFTWARE) {
				classRosterArray[studentCount] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete1, daysToComplete2, daysToComplete3, SOFTWARE);
			}
			studentCount++;
		}

		void Roster::remove(string ID) {
			bool studentFound = false;
			for (int i = 0; i < studentCount; ++i) {
				if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == ID) {
					cout << "Student: " << ID << " was removed!" << endl;
					classRosterArray[i] = nullptr;
					studentFound = true;
					break;
				}
			}
			if (!studentFound) {
				cout << "Error - student: " << ID << " was not found!" << endl;
			}
		};

		void Roster::printAll() {
			for (int i = 0; i < studentCount; ++i) {
				cout << i+1 << "\t";
				classRosterArray[i]->print();
			}
			cout << endl;
		};

		void Roster::printInvalidEmails() {
			bool isBadEmail;
			int periodCount, atCount;
			for (int i = 0; i < studentCount; ++i) {
				isBadEmail = false;
				periodCount = 0;
				atCount = 0;
				string address = classRosterArray[i]->getEmailAddress();
				for (int j = 0; j < address.length(); ++j) {
					if (address[j] != ' ') {
						if (address[j] == '@') {
							atCount++;
						}
						if (address[j] == '.') {
							periodCount++;
						}
					}
					else {
						isBadEmail = true;
					}
				}

				if (periodCount < 1 || atCount != 1) {
					isBadEmail = true;
				}

				if (isBadEmail) {
					cout << address << " is a bad Email." << endl;
				}
			}
			cout << endl;
		};
		
		void Roster::printAverageDaysInCourse(Student* s) {
			cout << "Average Days in Course for student " << s->getStudentID() << ": " << (s->getDaysToComplete(0) + s->getDaysToComplete(1) + s->getDaysToComplete(2))/3 <<endl;
		};

		void Roster::printByDegreeProgram(int type) {
			for (int i = 0; i < studentCount; ++i) {
				if (classRosterArray[i]->getDegreeProgram() == type) {
					classRosterArray[i]->print();
				}
			}
			cout << endl;
		};

		Roster::~Roster() {
		}

int main() {

	//course title, the programming language used, your student ID, and your name.
	cout << "Course Title: Scripting and Programming - Applications" << endl;
	cout << "Programming Lanuage Used: C++" << endl;
	cout << "StudentID: #000886340" << endl;
	cout << "Wesley B. Miller" << endl << endl;

	Roster classRoster;
	const string studentData[] =
	{
	  "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Wesley,Miller,wmill48@wgu.edu,22,20,25,30,SOFTWARE"
	};

	//Convert the studentData array and add to classRoster
	for (int i = 0; i < 5; ++i) {
		string input = studentData[i];
		istringstream ss(input);
		string info = "";
		string data[9];
		int degree = 0;

		int x = 0;
		while (getline(ss, info, ',')) {
			data[x] = info;
			x += 1;
		}
		
		if (data[8] == "SECURITY") {
			degree = SECURITY;
		}
		if (data[8] == "SOFTWARE") {
			degree = SOFTWARE;
		}
		if (data[8] == "NETWORK") {
			degree = NETWORK;
		}

		classRoster.add(data[0], data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[7]), degree);
	}


	classRoster.printAll();
	classRoster.printInvalidEmails();
	for (int i = 0; i < 5; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]);
	}
	cout << endl; //space it out a little

	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");

	//Release classRoster through deconstructor
	classRoster.~Roster();
	
}

