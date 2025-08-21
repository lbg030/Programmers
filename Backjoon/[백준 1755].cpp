#include <iostream>
#include <vector>
// #include <string>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

string num_to_string(int a);
string split(string number, map<string, string> map_int_string, char delimeter =' ');

vector<string> int_string = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


int main() 
{
    // 14 28 42
    // 14 28
    int start,end;
    vector<string> num_vector;
    map<string, string> map_int_string;
    
    cin >> start >> end;
    
    for(int i=0;i<int_string.size(); ++i){
      map_int_string[int_string[i]] = to_string(i);
    }

    for(int i=start; i<end+1; ++i){
      num_vector.push_back(num_to_string(i));
    }
    
    sort(num_vector.begin(), num_vector.end());
    
    for(int i=0; i < num_vector.size(); i++){
      // cout << "n : " << n << endl;
      if(i % 10 == 0 && i != 0) cout << endl;
      string n = num_vector[i];
      split(n, map_int_string);
    }
    
    return 0;
}

 string num_to_string(int a){
  // cout << "a: " << a << endl;
  string s_num = to_string(a);
  // cout << s_num << endl;
  string res = "";
  if(a >= 10){
    for(int j=0; j<s_num.size(); j++){
      // cout << s_num.size() << " S = " << s_num << endl;
      res += int_string[s_num[j] - '0'];
      // cout << s_num[j] << " res: " << int_string[s_num[j] - '0'] << endl;
      // cout << "res: " << res << endl;
      if(j==0) res += " ";
    }
  }
  else{
    res += int_string[stoi(s_num)];
  }
  return res;
}

string split(string number, map<string, string> map_int_string, char delimeter){
  string res;
  stringstream ss(number);
  string temp;
  while(getline(ss, temp, delimeter)){
    if(!temp.empty()){
      res += map_int_string[temp];
    }
  }
  cout << res << " ";
  return res;
}