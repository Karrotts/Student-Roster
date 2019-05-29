#pragma once

#include "student.h"

class SecurityStudent : public Student {
using Student::Student;
private:
	int degreeProgram;
public:
	int getDegreeProgram();
};