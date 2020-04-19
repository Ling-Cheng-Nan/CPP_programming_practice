#include <iostream>
#include <string>
#include "user.h"
#include "teacher.h"
#include "student.h"

void do_user_work(User &user){
    user.output();
}

int main(){

    // User user;
    // std::cin >> user;
    // std::cout << user << std::endl;

    Teacher teacher;
    // teacher.output(); //function only defined in teacher.cpp
    // teacher.first_name = "Sammy";
    // teacher.setStatus("Choper");
    // std::cout << teacher.first_name << std::endl;
    // std::cout << teacher << std::endl;

    User &u1 = teacher;
    u1.output();

    Student student;
    User &u2 = student;
    u2.output();

    do_user_work(u1);
    do_user_work(u2);

    return 0;
}