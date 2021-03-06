#ifndef USER_H
#define USER_H

class User{
    
    private:
        static int users_count;
        std::string status;

    public:         
        static int get_user_count();
        std::string first_name;
        std::string last_name;
        
        std::string getStatus();

        void setStatus(std::string status);

        User();

        User(std::string first_name, std::string last_name);

        ~User();
        
        virtual void output();
        friend void output_status(User user); //friend function definition outside
        friend std::ostream& operator << (std::ostream& output, const User user);
        friend std::istream& operator >> (std::istream &input, User &user);
};

#endif