#pragma once

#include "student.h"

class SoftwareStudent : public Student {
using Student::Student;
private:
	int degreeProgram;
public:
	int getDegreeProgram();
};