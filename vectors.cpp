#include <iostream>
#include <vector>

// using namespace std;
void print_vector(std::vector<int> vec){
    for(int i = 0 ; i < vec.size() ; i++){
        std::cout << vec[i] << " " ;
    }
    std::cout << std::endl;
}

int main(){
    std::vector <int> data = {109, 87, 65, 43, 21, -5};
    data.push_back(12);
    data.push_back(34);
    data.push_back(56);
    data.push_back(78);
    data.push_back(90);

    print_vector(data);

    return 0;
}