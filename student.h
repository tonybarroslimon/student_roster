#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;

class Student
{

public:

	//constructor
	Student();

	Student(string, string, string, string, int, int*);

	//accessors for each instance variable
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getStudentID();
	int getAge();
	int *getNumDays();
	
	//mutator for each instance variable
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setStudentID(string studentID);
	void setNumDays(int day0, int day1, int day2);
	void setDegree(string degree);
	
	virtual void print();
	virtual Degree getDegreeProgram();

	~Student();

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDays[3];
    
};


#endif // STUDENT_H
