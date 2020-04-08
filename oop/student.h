#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "user.h"

class Student : public User{

    public:
        void output();
        Student();
};

#endif