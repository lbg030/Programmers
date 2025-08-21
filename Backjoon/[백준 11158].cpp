#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string str, char delimiter);

int main() 
{
    int N;
    cin >> N;
    cin.ignore();
    vector<string> forbidden = {"u", "ur"};
    vector<string> forbid_sentence = {"would", "should"};
    string lol = "lol";
    char separator = ' ';
    vector<string> lines;
    
    for(int i=0; i<N; i++){
      string line;
      getline(cin, line);
      vector<string> ans = split(line, separator);
      int loud = 0;
      
      for (const auto& n : ans) {
        for (const auto& forbid : forbidden) {
          if (n == forbid){
            loud += 10;
            // cout << n << " ";
          }
        }
        if (n.find(lol) != string::npos){
          // cout << n << endl;
          loud += 10;
        }
      }
      for(int j=0; j<ans.size()-1; j++){
        for (const auto& f_s : forbid_sentence){
          if(ans[j] == f_s and ans[j+1] == "of"){
            loud += 10;
            j++;
          }
        }
      }
      cout << loud << endl;
    }
    return 0;
}

vector<string> split(string input, char delimiter){
  vector<string> answer;
  stringstream ss(input);
  string temp;
  
  while(getline(ss, temp, delimiter)){
    answer.push_back(temp);
  }
  
  return answer;
}