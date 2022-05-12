#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"

class SecurityStudent : public Student {
    
    public:
        SecurityStudent();

        SecurityStudent(string, string, string, string, int, int*, Degree);

        Degree getDegreeProgram() override;

        void print() override;
    private:
        Degree degree;
        
    };


#endif // SECURITYSTUDENT_H
