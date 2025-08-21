#include <iostream>
#include <vector>

using namespace std;

long MAX_VALUE = 1000000000;

void calc_fibonacci(int n, vector<long long> & fibonacci){
  for(int i=2; i<n+1; i++){
    long long next_value = fibonacci[i-2] + fibonacci[i-1];
    if (next_value > MAX_VALUE); next_value %= MAX_VALUE;
    fibonacci.push_back(next_value);
  }
}

int main() 
{
    int n;
    vector<long long> fibonacci = {0,1};
    
    cin >> n;
    
    if(n == 0){
      cout << n << endl;
      cout << n << endl;
    }
    else{
      bool is_signed = (n % 2); // is_signed가 false일 때 음수
      int singed_value = is_signed ? 1 : -1;

      calc_fibonacci(abs(n), fibonacci);
      
      if(n > 0){
        cout << "1" << endl;
        cout << fibonacci[n] << endl;
      }
      
      else{
        cout << singed_value << endl;
        cout << fibonacci[abs(n)] << endl;
      }
      
      
    }
    return 0;
}