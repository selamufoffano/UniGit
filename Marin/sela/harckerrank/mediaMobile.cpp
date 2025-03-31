#include<vector>
#include<iostream>

void print(const std::vector<double>& v) {
  for (auto x: v) {
    std::cout<<x<<std::endl;
  }
}


void read(std::vector<double>& v) {
  int size;
  double el;
  std::cin>>size;

  v.clear(); //cancella tutti gli elementi del vettore
  for (;size>0;size--) {
    std::cin>>el;
    v.push_back(el);
  }
}


/*
std::vector<double> moving_averageV0(const std::vector<double> v, int k) 
{
    int media = 0;
    for(int i = 0; i<v.size()-1; i++){
        if(v[i]==0 || v[i]==v.size()-1 ){
            if(v[i]==0 ){

            } if(v[i]==v.size()-1){

            }
        }
        else {
            media += (v[i-k] + v[i+k])/i;
        }
    }

    return media;
}
*/

std::vector<double> moving_average(const std::vector<double>& v, int k) {
    std::vector<double> result;
    int n = v.size();

    if (k <= 1 || n == 0) return result; 

    for (int i = 0; i < n; i++) {
        double sum = 0;
        int count = 0;

        for (int j = -k; j <= k; j++) {
            int index = i + j;
            if (index >= 0 && index < n) {
                sum += v[index];
                count++;
            }
        }

        result.push_back(sum / count); 
        // se io avessi inizilizzato la dimensione del vettore 
        // non era neccessario usare il push_back
    }

    return result;
}


std::vector<double> moving_averageV2(const std::vector<double>& v, int k) {
  std::vector<double> out_v(v.size());
  double s, count;

  for(int i=0; i<v.size(); i++){
    s=0;
    count = 0;
    for(int j = i-k; j<i+k; j++){
      if(j>=0; && j<v.size()){
        s=v.size(j);
        count++;
      }
    }
    out_v(i)=s/count;
  }
  return out_v;
}


int main() {
  std::vector<double> v;

  int mov;
  
  std::cin>>mov;

  read(v);

  std::vector<double> result;

  result = moving_average(v, mov);

  print(result);

  return 0;
}