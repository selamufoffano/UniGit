#include<vector>
#include<cmath>
#include<iostream>
void print(const std::vector<int>& v) {
  for (auto x: v) {
    std::cout<<x<<std::endl;
  }
}

std::vector<int> fill_with_primes(int size) {
  std::vector<int> Vprimo;  
  int n = 2;  
  while (Vprimo.size() < size) {
      bool primo = true;
      for (int i = 2; i <= std::sqrt(n); i++) {  // Check divisibility up to sqrt(n)
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
  return Vprimo;  // Return the vector with the found prime numbers
}

int main() {
  int size;

  std::cin>>size;

  std::vector<int> v;

  v = fill_with_primes(size);

  print(v);

  return 0;
}