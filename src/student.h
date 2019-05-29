#pragma once
#include <string>
using namespace std;

class Student {
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysToComplete[3];
		int degreeType;
	public:
		//Accessors
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		int getDaysToComplete(int index);
		virtual int getDegreeProgram();
		
		//Mutators
		void setStudentID(string ID);
		void setFirstName(string name);
		void setLastName(string name);
		void setEmailAddress(string address);
		void setAge(int age);
		void setDaysToComplete(int numOfDays, int index);
		void setDegreeProgram();

		//Constructor
		Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, int degreeProgram);

		//Destuctor
		~Student();

		//Print
		virtual void print();
};