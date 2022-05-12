#include "securitystudent.h"
#include <iostream>

SecurityStudent::SecurityStudent() {
    
    }

SecurityStudent::SecurityStudent(string studID, string fName, string lName, string emAddr, int a, int *numOfDays, Degree degreeType) : Student(studID, fName, lName, emAddr, a, numOfDays) {
    
	degree = degreeType;
    
}

Degree SecurityStudent::getDegreeProgram() {
    
	return degree;
    
}

void SecurityStudent::print() {
    
	cout << "\t" << "First Name: " << getFirstName() << "\t" << "Last Name: " << getLastName() << "\t" << "Age: " << getAge()
		<< "\t" << "daysInCourse: {"; cout << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "}";
	cout << " Degree Program: Security" << '\n';
    
}

