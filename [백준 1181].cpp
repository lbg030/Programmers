#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void print_v(vector<string>& inputs);

int main() 
{
    int T;
    vector<string> inputs;
    set<string> s;
    cin >> T;
    cin.ignore();
    
    while(T--){
      string line;
      getline(cin, line);
      // inputs.push_back(line);
      s.insert(line);
    }
    inputs.assign(s.begin(), s.end());
    
    sort(inputs.begin(), inputs.end(), [](string first, string second) -> bool{
      if (first.size() != second.size()){
        return first.size() < second.size();
      }
      return first < second;
    });
    
    print_v(inputs);
    return 0;
}


void print_v(vector<string>& inputs){
  for (auto i : inputs){
    cout << i << endl;
  }
}