#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Primes {
    private:
        std::vector<int> primes; 
        bool is_prime(int n) {
            if (n < 2) return false;
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) return false;
            }
            return true;
        }

        void generate_primes(int size) {
            int n = 2; 
            while (primes.size() < size) {
                if (is_prime(n)) {
                    primes.push_back(n);
                }
                n++;
            }
    }

    public:
        Primes(int size) {
            generate_primes(size);
        }

        int get_prime(int n) {
            if (n < primes.size()) {
                return primes[n]; 
            } else {
                int last = primes.back() + 1;
                while (primes.size() <= n) {
                    if (is_prime(last)) {
                        primes.push_back(last);
                    }
                    last++;
                }
                return primes[n];
            }
        }
};

// se n < size l'n-mo numero primo deve essere preso dal vettore
// se n>=size allora deve essere calcolato a partire dal numero primo più grande presente nella struttura
int main() {
  int size, n;
  std::cin>>size;
  std::cin>>n;

  Primes p(size);

  std::cout<<p.get_prime(n);

  return 0;
}

