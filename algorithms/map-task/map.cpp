#include <iostream>
#include <chrono>
#include <map>
#include <string>

float memory_allocation(int size){
    std::map <int, int> dict;
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i=0;i<size;i++){
        dict.insert({i,i});
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t2 - t1;
    return elapsed.count();
}

int main(){
    std::string str;
    int size[]{10, 100, 1000, 10000, 100000};
    for (auto& i: size){
        str.append(std::to_string(i));
        str.append(" ");
        str.append(std::to_string(memory_allocation(i)));
        str.append(" ");
    }
    str.pop_back();
        std::cout<<str;
        return 0;
    }

