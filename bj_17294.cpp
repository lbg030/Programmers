#include <iostream>
using namespace std;

bool solve(string &inputs){
  int diff = (inputs[0] - '0') - (inputs[1] - '0');
  
  for(int i=2;i<inputs.size(); i++){
    if(inputs[i-1] - inputs[i] != diff){
      
      return false;
    }
  }
  return true;
}

int main() 
{
    string inputs;
    string correct = "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    string incorrect = "흥칫뿡!! <(￣ ﹌ ￣)>";
    string ans;
    bool cute;
    
    cin >> inputs;
    
    cute = solve(inputs);
    ans = cute ? correct : incorrect;
    cout << ans << endl;
    return 0;
}