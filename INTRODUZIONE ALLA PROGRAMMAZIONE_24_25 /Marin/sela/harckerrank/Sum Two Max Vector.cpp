// Primo gruppo di esercizi
/*

*/
#include <iostream>
#include <vector>
#include <limits>
/*
int find_max_sum(const std::vector<int>& v) {
  /*int max1 = 0; // Primo massimo. è necessario inizializzare altrimenti da errore
  int max2 = 0; // Secondo massimo
  
  int max1 = 0;
  int max2 = 1;
  for (int i = 2; i < v.size(); i++) {
    if (v.at(i) > v.at(max1)) {
        max2 = max1;
        max1 = i;
    } else if (v.at(i) > v.at(max2)) {
        max2 = i;
    }
  }
  return v.at(max1) + v.at(max2);
}
*/
int find_max_sum(const std::vector<int>& v) {
  /*int max1 = 0; // Primo massimo. è necessario inizializzare altrimenti da errore
  int max2 = 0; // Secondo massimo
  */
  int max1 = std::numeric_limits<int>::min();
  int max2 = std::numeric_limits<int>::min();
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > max1) {
        max2 = max1;
        max1 = v[i];
    } else if (v[i] > max2) {
        max2 = v[i];
    }
  }
  return max1 + max2;
}


void read(std::vector<int>& v) {
  int dim;
  std::cin>>dim;
  
  for (int i=0; i<dim; i++){
    int e;
    std::cin>>e; 
    v.push_back(e);
  } 
}

int main() {
  int s;
  std::vector<int> myv;

  read(myv);

  s = find_max_sum(myv);

  std::cout << s;

  return 0;

}