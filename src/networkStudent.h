#pragma once

#include "student.h"

class NetworkStudent : public Student {
	using Student::Student;
	private:
	int degreeProgram;
	public:
	int getDegreeProgram();
};