#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"

class NetworkStudent : public Student {
    
    public:
        NetworkStudent();

        NetworkStudent(string, string, string, string, int, int*, Degree);

        Degree getDegreeProgram() override;

        void print() override;

    private:
        Degree degree;
        
    };


#endif // NETWORKSTUDENT_H
