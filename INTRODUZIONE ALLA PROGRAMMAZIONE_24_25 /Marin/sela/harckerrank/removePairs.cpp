#include <iostream>
#include <string>

using std::string;
void remove_pairs(std::string& s) {
    std::string auxS = "";
    // verifico che la stringa non sia vuota
    if(s.length()==0){
        return;
    } else {
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && s[i] == s[i - 1]) {
                continue;  
            } else {
                auxS += s[i];
            }
        }
    }
    s = auxS; 
}

int main() {
    /*
    std::string s = "";
    remove_pairs(s);
    std::cout << s << std::endl;
    return 0;
    */
    
    string a;
    getline(std::cin, a);
    
    remove_pairs(a);
    
    std::cout<<a<<std::endl;
    
    return 0;
}
