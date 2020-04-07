#include <iostream>
#include <string>
#include <vector>

class User{
    private:
        std::string status;
        
    public:
        std::string first_name;
        std::string last_name;
        
        std::string getStatus(){
            return status;
        }

        void setStatus(std::string status){
            if(status == "Gold" || status == "Silver" || status == "Choper"){
                this->status = status;
            }
            else{
                this->status = "No valid status";
                std::cout << this->status << std::endl;
            }
        }

        User(){
            std::cout << "Constructor created!"  << std::endl;
        }

        User(std::string first_name, std::string last_name){
            
            this->first_name = last_name;
            this->last_name  = last_name;

            status = "Not assigned yet.";
        }

        // ~User(){
        //     std::cout << "Destructor...." << std::endl;
        // }
};

int add_user_if_not_exists(std::vector<User> &users, User user){
    
    for(int i = 0 ; i < users.size() ; i++){
        /*if match, return index i */
        if((users[i].first_name == user.first_name) && 
           (users[i].last_name == user.last_name)){
            return i;
        }
    }
    users.push_back(user);

    return users.size()-1;
}

int main(){

    // User user1, user2 , user3, user4, user5;
    // User user("Jane", "Mood");

    // user1.first_name = "Sam";
    // user1.last_name  = "Ling";

    // user2.first_name = "Sam";
    // user2.last_name  = "Cheng";
    
    // user3.first_name = "Sammmy";
    // user3.last_name  = "Lou";    
    
    // user4.first_name = "Max";
    // user4.last_name  = "Smith";
    
    // user5.first_name = "Sammmy";
    // user5.last_name  = "Lou";
    
    // std::vector<User> users;
    // users.push_back(user1);
    // users.push_back(user2);
    // users.push_back(user3);
    // users.push_back(user1);

    // std::cout << users.size() << std::endl;
    // std::cout << add_user_if_not_exists(users, user4) << std::endl;
    // std::cout << users.size() << std::endl;
    // std::cout << add_user_if_not_exists(users, user5) << std::endl;
    // std::cout << users.size() << std::endl;



    // std::cout << users[0].first_name + users[0].last_name << std::endl;
    User user;
    user.setStatus("Taco");


    return 0;
}