// Primo gruppo di esercizi
/*

*/
#include<vector>
#include<iostream>
int find_max_sum(const std::vector<int> & v) {
  return 0;
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
