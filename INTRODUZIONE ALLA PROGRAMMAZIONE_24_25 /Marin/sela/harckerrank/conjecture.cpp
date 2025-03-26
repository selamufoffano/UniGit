#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> prime(int limit) {
    vector<int> Vprimo;
    int n = 2;
    while (Vprimo.size() < limit) {
        bool primo = true;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                primo = false;
                break;
            }
        }
        if (primo) {
            Vprimo.push_back(n);
        }
        n++;
    }
    return Vprimo;
}

void goldbach(int evenNumber, const vector<int>& primes, vector<int>& v1, vector<int>& v2, int i, int j) {
    if (i >= primes.size()) {
        v1.push_back(0);
        v2.push_back(0);
        return;
    }
    if (j >= primes.size()) {
        goldbach(evenNumber, primes, v1, v2, i + 1, i);
        return;
    }
    if (primes[i] + primes[j] == evenNumber) {
        v1.push_back(primes[i]);
        v2.push_back(primes[j]);
        return;
    }
    goldbach(evenNumber, primes, v1, v2, i, j + 1); 
}

int main() {
    int n;
    cin >> n;
    
    vector<int> v1, v2;
    vector<int> primes = prime(n+1);     
    for (int i = 0; i < n; i++) {
        int evenNumber = 4 + 2 * i; 
        goldbach(evenNumber, primes, v1, v2, 0, 0);
    }

    for (size_t i = 0; i < v1.size(); i++) {
        cout << v1[i] << " , " << v2[i] << endl;
    }
    return 0;
}
