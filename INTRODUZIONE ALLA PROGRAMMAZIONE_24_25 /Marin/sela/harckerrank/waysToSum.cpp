#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int count(vector<int>& numbers, int n) {
    if (n == 0) return 1;  
    if (n < 0) return 0; 

    int totalWays = 0;
    //cout << totalWays; 
    for (int i = 0; i < numbers.size(); i++){
        totalWays += count(numbers, n -numbers[i]);
        cout << totalWays;
    }
    cout << endl;
    return totalWays;

}

int main() {
    
    int size, sum;
    //cout << "Inserisci la dimensione del vettore: ";
    cin >> size;

    vector<int> numbers(size);
   // cout << "Inserisci gli elementi del vettore: ";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    //cout << "Inserisci il valore di n: ";
    cin >> sum;
    cout << "Answer: " << count(numbers, sum) << endl;
    return 0;
}






