#include <iostream>
#include "student.h"
#include "degree.h"
#include <string>

using namespace std;

Student::Student() {

    }

Student::Student(string studID, string fName, string lName, string emAddr, int a, int* numOfDays) {
    
	studentID = studID;
	firstName = fName;
	lastName = lName;
	emailAddress = emAddr;
	age = a;
	numDays[0] = numOfDays[0];
	numDays[1] = numOfDays[1];
	numDays[2] = numOfDays[2];
    
    }

string Student::getFirstName() {
    
	return firstName;
    
    }

void Student::setFirstName(string fName) {
    
	firstName = fName;
    
    }

string Student::getLastName() {
    
	return lastName;
    
    }

void Student::setLastName(string lName) {
    
	lastName = lName;
    
    }

string Student::getEmailAddress() {
    
	return emailAddress;
    
    }

void Student::setEmailAddress(string emAddr) {
    
	emailAddress = emAddr;
    
    }

int Student::getAge() {
    
	return age;
    
    }

void Student::setAge(int a) {
    
	age = a;
    
    }

string Student::getStudentID() {
    
	return studentID;
    
    }

void Student::setStudentID(string studentID) {
    
	Student::studentID = studentID;
    
    }

int *Student::getNumDays() {
    
	return numDays;
    
    }

void Student::setNumDays(int day0, int day1, int day2) {
    
	Student::numDays[0] = day0;
	Student::numDays[1] = day1;
	Student::numDays[2] = day2;
    
    }

void Student::setDegree(string degree) {
    
	degree = degree;
    
    }

Degree Student::getDegreeProgram() {
    
	return Degree::SOFTWARE;
    
    }

void Student::print() {
    
    }

// default deconstructor definition
Student::~Student() {

    }

