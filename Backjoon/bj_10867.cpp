#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int> inputs;
    for(int i=0;i<N;i++){
      int input_value;
      cin >> input_value;
      inputs.push_back(input_value);
    }
    set<int> ans(inputs.begin(), inputs.end());
    
    for(const auto& n : ans){
      cout << n << " ";
    }
    
    
    
    return 0;
}