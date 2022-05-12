#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <iostream>
#include <cstring>
#include "student.h"
#include "degree.h"
#include "securitystudent.h"
#include "networkstudent.h"
#include "softwarestudent.h"
#include "roster.h"

using namespace std;

Roster::Roster() {
    
    }

void Roster::add(string studID, string fName, string lName, string emAddr, int a, int day0, int day1, int day2, Degree degree) {
    
	int numberOfDaysIn[] = {day0, day1, day2};
    
	if (degree == Degree::NETWORKING) {
        
		classRosterArray[addIndex++] = new NetworkStudent(studID, fName, lName, emAddr, a, numberOfDaysIn, degree);
        
        }
        
	if (degree == Degree::SECURITY) {
        
		classRosterArray[addIndex++] = new SecurityStudent(studID, fName, lName, emAddr, a, numberOfDaysIn, degree);
        
        }
        
	if (degree == Degree::SOFTWARE) {
        
		classRosterArray[addIndex++] = new SoftwareStudent(studID, fName, lName, emAddr, a, numberOfDaysIn, degree);
        
        }
        
    }

void Roster::printAll() {
    
	cout << "Displaying roster:" << endl << endl;
    
	for (int i = 0; i < 5; i++) {
        
		(*classRosterArray[i]).print();
        
        }
        
	cout << endl;
    
    }

void Roster::printnumDays(string studentID) {
    
	/*for (int i = 0; i < 5; i++) {
        
		if ((*classRosterArray[i]).getStudentID() == studentID) {
            
			int average = 0;
            
			average = ((*classRosterArray[i]).getNumDays()[0] + (*classRosterArray[i]).getNumDays()[1]
				+ (*classRosterArray[i]).getNumDays()[2]) / 3;
			cout << "Average days for student: " << studentID << " to finish 3 courses: " << average << endl;
            
            }
            
        }
        
	cout << endl;*/
    
    for (int i = 0; i < 5; i++) {

		string searchStudent = (*classRosterArray[i]).getStudentID();

		if (searchStudent == studentID) {

			float average = 0;

			int sum = 0;

			for (int j = 0; j < 3; j++) {

				sum += (*classRosterArray[i]).getNumDays()[j];

			}
            
            average = sum / 3;

			cout << "Average days for student: " << studentID << " to finish 3 courses: " << average << endl << endl;

		}

	}

}

void Roster::printByDegree(string degree) {
    
	Degree defaultDeg = Degree::SOFTWARE;
    
	if (degree == "SECURITY") {
        
		defaultDeg = Degree::SECURITY;
		cout << "Security program students: " << endl;
        
        }
        
	if (degree == "NETWORKING") {
        
		defaultDeg = Degree::NETWORKING;
		cout << "Networking program students: " << endl;
        
        }
        
	if (degree == "SOFTWARE") {
        
		defaultDeg = Degree::SOFTWARE;
		cout << "Software program students: " << endl;
        
        }
        
	cout << endl;
	for (int i = 0; i < 5; i++) {
        
		if (defaultDeg == (*classRosterArray[i]).getDegreeProgram()) {
			(*classRosterArray[i]).print();
            
            }
            
        }
        
	cout << endl;
    
    }

void Roster::printBadEmails() {
    
	cout << "Bad emails:" << endl << endl;
        
	for (int i = 0; i < 5; i++) {
        
		bool characterAt = false;
		bool characterPeriod = false;
		bool characterSpace = false;
		string email = "";
		email = (*classRosterArray[i]).getEmailAddress();
        
		for (char &character : email) {
            
			if (character == '@') {
                
				characterAt = true;
                
                }
                
			if (character == '.') {
                
				characterPeriod = true;
                
                }
                
			if (character == ' ') {
                
				characterSpace = true;
                
                }
                
            }
            
		if (characterAt == false || characterPeriod == false || characterSpace == true) {
            
			cout << (*classRosterArray[i]).getEmailAddress() << endl;
            
            }
            
        }
        
	cout << endl;
    
    }

void Roster::remove(string studentID) {
    
	bool toRemove = false;
	for (int i = 0; i < 5; i++) {
        
		if (classRosterArray[i] != NULL) {
            
			if (studentID == classRosterArray[i]->getStudentID()) {
                
				classRosterArray[i] = nullptr;
				toRemove = true;
                
                }
            } 
        }
	if (!toRemove) {
        
		cout << "Student: " << studentID << " not found." << endl;
        
        }
        
    }



int main() {
    	
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Antonio,Barros-Limon,abar207@my.wgu.edu,36,15,11,19,SOFTWARE"
	};

	Roster classRoster;

	Degree myDegree;

	for (int i = 0; i < 5; i++) {
        
        string input = studentData[i];
		istringstream ss(input);
		string item;
		string tempArray[9];

		int x = 0;
		while (getline(ss, item, ',')) {
			tempArray[x] = item;
			x += 1;
		}
		if (tempArray[8] == "SECURITY") {
			myDegree = Degree::SECURITY;
		}
		else if (tempArray[8] == "SOFTWARE") {
			myDegree = Degree::SOFTWARE;
		}
		else if (tempArray[8] == "NETWORK") {
			myDegree = Degree::NETWORKING;
		}
		classRoster.add(tempArray[0], tempArray[1], tempArray[2], tempArray[3], stoi(tempArray[4]), stoi(tempArray[5]),
			stoi(tempArray[6]), stoi(tempArray[7]), myDegree);
            
        }

    cout << endl;
	cout << "Course: Scripting and Programming - Applications – C867" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "Student ID: 000950459" << endl;
	cout << "Name: Antonio Barros-Limon" << endl << endl;

	classRoster.printAll();

	classRoster.printBadEmails();

	classRoster.printnumDays("A1");

	classRoster.printByDegree("SOFTWARE");
	
	classRoster.remove("A3");
	
	classRoster.remove("A3");
    
    cout << endl;
    
    }

Roster::~Roster() {
    
    }
