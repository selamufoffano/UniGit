#include <iostream>
#include <string>

std::string decompress(const std::string& s) {
    std::string result;
    int count = 0;

    for (int i = 0; i < s.size() - 1; i += 2) {
        count = s.at(i + 1) - '0'; 
        for (int j = 0; j < count; j++) {
            result += s.at(i);
        }
    }
    return result;
}

int main() {
    std::string buff;
    std::string res;
    
    std::cin>>buff;
    
    res = decompress(buff);
    
    std::cout<<res;
    
    return 0;
}