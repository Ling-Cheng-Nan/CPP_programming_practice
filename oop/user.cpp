#include <iostream>
#include <string>
#include "user.h"

// class User{
  
        int User::get_user_count(){
            return users_count;
        }

        std::string User::getStatus(){
            return status;
        }

        void User::setStatus(std::string status){
            if(status == "Gold" || status == "Silver" || status == "Choper"){
                this->status = status;
            }
            else{
                this->status = "No valid status";
                std::cout << this->status << std::endl;
            }
        }

        User::User(){
            std::cout << "Constructor created!"  << std::endl;
            users_count++;
        }

        User::User(std::string first_name, std::string last_name){
            
            this->first_name = last_name;
            this->last_name  = last_name;
            status = "Not assigned yet.";

            users_count++;

        }

        User::~User(){
            // std::cout << "Destructor...." << std::endl;
            users_count--;
        }

        void User::output(){
            std::cout << "I'm a user.\n";
        }

        void output_status(User user); //a friend function definition outside
        std::ostream& operator << (std::ostream& output, const User user);
        std::istream& operator >> (std::istream &input, User &user);
// };

int User::users_count = 0;

void output_status(User user){
    std::cout << user.status << std::endl;
}

/*operator oveloading ostream*/
std::ostream& operator << (std::ostream& output, const User user){
    
    output << "First name:" << user.first_name 
           << "\nLast name:" << user.last_name 
           << "\nStatus:" << user.status <<std::endl;
    return output;
}

/*operator oveloading istream*/
std::istream& operator >> (std::istream &input, User &user){
    
    input >> user.first_name >> user.last_name >> user.status;
    
    return input;
}