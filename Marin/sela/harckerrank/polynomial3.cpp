#include<iostream>
#include<vector>
#include<list>
class Polynomial{
  public:
    Polynomial();
    Polynomial(const Polynomial& p);
    void set(int exponent, int coeff);
    int at(int exponent) const;
    void read();
    int evaluate(int x) const;
    Polynomial differentiate(int order) const;
    int degree() const;
    void print() const;
    
  private:
    int intpow(int base, int exponent) const;
    std::list<std::pair<int, int>> coefficients; 
};


//////// Pre-implemented part/////////////

//Do not change this method! It reads a Polynomial 
void Polynomial::read() {
  int coeff, exponent;
  do {
    std::cin>>exponent;
    if (exponent>=0)  {
      std::cin>>coeff;
      set(exponent, coeff);
    }
  } while (exponent>=0);
}


//Do not change this method! It prints a Polynomial
void Polynomial::print() const {
  int n = degree();

  for (int i=0; i<=n; i++) {
    if (at(i)!=0) 
      std::cout<<"+("<<at(i)<<")x^"<<i;
  }
  std::cout<<std::endl;
}



//Do not change this method! It simply computes the integer power
//It could be useful!
int Polynomial::intpow(int base, int exponent) const {
  int res=1;

  while (exponent>0) {
    res = res*base;
    exponent--;
  }
  return res;
}


//Methods for exercise 1


//Default constructor: builds the polynomial 0
Polynomial::Polynomial() {
}

//Copy constructor
Polynomial::Polynomial(const Polynomial& p) : coefficients(p.coefficients) {
}

//Returns the coefficient of the terms  x^exponent
//If it has not been added it returns 0
//Notice that we have only one version of at
//It does not return a reference, just an int. So we can only read with at!
int Polynomial::at(int exponent) const {
    for (const auto& pair : coefficients) {
        if (pair.first == exponent) {
            return pair.second;
        }
    }
    return 0;
}



//Set to coeff the coefficient of x^exponent. If this is present, 
//it will be overwritten. Setting the coefficient to 0 means 
//the removal from the polynomial representation
void Polynomial::set(int exponent, int coeff) {
    if (coeff == 0) {
        for (auto it = coefficients.begin(); it != coefficients.end(); ++it) {
            if (it->first == exponent) {
                coefficients.erase(it);
                return;
            }
        }
    } else {
        for (auto it = coefficients.begin(); it != coefficients.end(); ++it) {
            if (it->first == exponent) {
                it->second = coeff;
                return;
            }
        }
        coefficients.emplace_back(exponent, coeff);
    }
}


//Evaluate a polynomial for a certain x
int Polynomial::evaluate(int x) const {
    int result = 0;
    for (const auto& pair : coefficients) {
        result += pair.second * intpow(x, pair.first);
    }
    return result;
}


//Methods for exercise 2


//Returns the degree of a polynomial. The polynomial 0 has degree 0
int Polynomial::degree() const {
    int maxExponent = 0;
    for (const auto& pair : coefficients) {
        if (pair.second != 0 && pair.first > maxExponent) {
            maxExponent = pair.first;
        }
    }
    return maxExponent;
}


//Methods for exercise 3

//This *recursive* function computes the n-th derivative of the polynomial
Polynomial Polynomial::differentiate(int order) const {
    if (order == 0) {
        return *this;
    }

    Polynomial derivative;
    for (const auto& pair : coefficients) {
        if (pair.first > 0) {
            derivative.set(pair.first - 1, pair.second * pair.first);
        }
    }
    return derivative.differentiate(order - 1);
}

int main() {
  Polynomial x;
  x.read();
  int a;
  std::cin>>a;
  x.differentiate(a).print();
  return 0;
}
