#include <bits/stdc++.h>
using namespace std;

string input, nextinp;

bool isPalindrome(string input)
void solve(string input);


bool isPalindrome(string input){
  int st=0; int end=input.size()-1;
  for(; st<end; st++, end--){
    if(input[st] != input[end]) return false;
  }
  return true;
}

void solve(string input){
  int origsize = input.size();
  int num = stoi(input);
  while(1){
    string cur_num = to_string(num);
    int ans = 0;
    for(; origsize == cur_num.size()){
      cur_num += '0';
    }

    if(isPalindrome(cur_num){
      cout << ans << endl;
    }else{
      ans++;
      num++;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  while(true){
    cin >> input;
    if(input == "0") break;
    solve(input);
  }
  return 0;
}