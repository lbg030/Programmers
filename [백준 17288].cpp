#include <iostream>
// using namespace std;
int stoi(char a);
int count_idx(const std::string& inputs, int value, int idx);

int main() 
{   
    int ans = 0;
    std::string inputs;
    std::cin >> inputs;
    // bool sequence = false;

    for(int i=0; i<inputs.size()-2; ++i) {  // size()-2로 변경하여 불필요한 검사 방지
        int curr = stoi(inputs[i]);
        int next1 = stoi(inputs[i+1]);
        int next2 = stoi(inputs[i+2]);
        if(curr + 1 == next1 && next1 + 1 == next2) {
            if(i+3 >= inputs.size() || stoi(inputs[i+3]) != next2 + 1) {
                ans++;
                i += 2;
            } else {
                i = count_idx(inputs, next2, i+2) - 1;
            }
        }
    }
    
    std::cout << ans << std::endl;
    return 0;
}
int stoi(char a){
  return a - '0';
}

int count_idx(const std::string& inputs, int value, int idx) {
    for(int j=idx+1; j<inputs.size(); ++j) {
        if(stoi(inputs[j]) != value + 1) {
            return j;
        }
        value++;
    }
    return inputs.size();
}