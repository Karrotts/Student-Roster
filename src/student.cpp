#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

//Accesser
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int Student::getDaysToComplete(int index) {
	return daysToComplete[index];
}

int Student::getDegreeProgram() {
	return degreeType;
}

//Mutators
void Student::setStudentID(string ID) {
	studentID = ID;
}

void Student::setFirstName(string name) {
	firstName = name;
}

void Student::setLastName(string name) {
	lastName = name;
}

void Student::setEmailAddress(string address) {
	emailAddress = address;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToComplete(int numOfDays, int index) {
	daysToComplete[index] = numOfDays;
}

//Virtual set
void Student::setDegreeProgram() {}

void Student::print() {
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "daysInCourse: {";
	cout << getDaysToComplete(0) << ", ";
	cout << getDaysToComplete(1) << ", ";
	cout << getDaysToComplete(2) << "}\t";
	cout << " Degree Program: ";
	if (degreeType == SECURITY) {
		cout << "SECURITY" << endl;;
	} else
	if (degreeType == SOFTWARE) {
		cout << "SOFTWARE" << endl;
	} else
	if (degreeType == NETWORK) {
		cout << "NETWORK" << endl;
	}
}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, int degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysToComplete[0] = daysToComplete1;
	this->daysToComplete[1] = daysToComplete2;
	this->daysToComplete[2] = daysToComplete3;
	this->degreeType = degreeProgram;
}

Student::~Student() {
}