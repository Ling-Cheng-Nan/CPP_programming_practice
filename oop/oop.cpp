#include <iostream>

class User{
    private:
        std::string status;
        
    public:
        std::string first_name;
        std::string last_name;
        
        std::string getStatus(){
            return status;
        }

    // std::string setStatus(std::string sta){
    //     status = sta;
    // }

};

int main(){

    User me;
    me.first_name = "Sam";
    me.last_name = "Ling";
    // me.setStatus("Gold");
    
    me.getStatus();

    return 0;
}