#include <iostream>
using namespace std;

int main() 
{
    long long N;
    cin >> N;
    
    // int divisor = N % 3;
    if(N % 2 == 1){
      cout << "SK";
    }else{
      cout << "CY";
    }
}