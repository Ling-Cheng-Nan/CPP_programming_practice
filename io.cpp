#include <iostream>
#include <fstream>
#include <vector>

int main(){

    // std::ofstream myfile;
    // std::vector <std::string> names;

    // std::string filename;
    // std::cin >> filename;   

    // myfile.open(filename.c_str(), std::ios::app);
    // // myfile << "Hello~ Sam" << std::endl;
    // try{
    //     if(myfile.is_open()){
    //         std::cout << "open file success n00b.\n";
    //     }else
    //     {
    //         throw "File open failed.";
    //     }
        
    // }
    // catch(const char * err){
    //     std::cout << err << std::endl;
    // }
    // names.push_back("SAM");
    // names.push_back("MAX");
    // names.push_back("JIN");

    // for(std::string name : names){
    //     myfile << name << std::endl;
    // }

    // myfile.close();

    std::vector <std::string> names2;
    std::ifstream infile("taco.txt");
    std::string input;
    // std::string inputstr;
    // while(infile >> inputstr){
    //     names2.push_back(inputstr);
    // }

    // for(std::string name : names2){
    //     std::cout << name << std::endl;
    // }
    // std::ifstream infile("taco2.txt");
    
        if(infile.is_open){
            std::cout << "file opened successful." << endl;
            getline(infile, input);
            std::cout << input << std::endl;
        }
        
    return 0;
}