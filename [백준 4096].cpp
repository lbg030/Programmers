#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int count_zero(string inputs);
bool check_pel(string a);
string make_input(int zero_cnt, string real_value);
// 0 Count하고, 나머지 수 count해서, +1 씩 해가며, first, second 비교

string make_input(int zero_cnt, string real_value){
  string tmp;
  for(int i=0; i<zero_cnt; i++){
    tmp += "0";
  }
  tmp += real_value;
  
  return tmp;
}

int count_zero(string inputs){
  // vector<string> ans;
  int cnt = 0;
  for(auto n : inputs){
    // cout << cnt << endl;
    if(n != '0'){
      return cnt;
    }
    cnt++;
  }
  return cnt;
}

bool check_pel(string a){
  // odds
  int center = a.size() / 2;
  string first, second;
  if (a.size() % 2){
    first = a.substr(0, center);
    second = a.substr(center+1, a.size());
    reverse(second.begin(), second.end());
  }
  // even
  else{
    first = a.substr(0, center);
    second = a.substr(center, a.size());
    reverse(second.begin(), second.end());
  }
  if(first == second){
    return true;
  }
  return false;
}

int main() 
{
    while(1){
      string input;
      string first, second, real_value;
      int zero_cnt;
      int sum_cnt = 0;
      bool pelin = false;
      
      cin >> input;
      if(input == "0"){
        break;
      }
      while(1){
        pelin = check_pel(input);
        if(pelin){
          cout << sum_cnt << endl;
          break;
        }
        sum_cnt++;

        zero_cnt = count_zero(input);
        real_value = to_string(stoi(input) + 1);
        
        //자리 수가 바뀌었을 때
        if(real_value.size()+zero_cnt != input.size()){
          // cout << real_value.substr: " << real_value.substr(zero_cnt, real_value.size()).size() << " " << input.size() << endl;
          zero_cnt--;
        }
        input = make_input(zero_cnt, real_value);
        
        // cout << "input: " << input << endl;
      }
    }
    return 0;
}