#include<iostream>

using namespace std;

int get_digit(const string& str, int index){
    return str[index] - '0';
}

string determine(const string& inputs){
    bool is_ascending = get_digit(inputs, 0) < get_digit(inputs, 2);
    
    for(size_t i=2; i<inputs.size(); i += 2){
        int prev = get_digit(inputs, i-2);
        int current = get_digit(inputs, i);
        
        if(is_ascending){
            if(current < prev){
                return "mixed";
            }
        }else{
            if(current > prev){
                return "mixed";
            }
        }
    }
    return is_ascending ? "ascending" : "descending";
}

// Initial Code
int main(int argc, char** argv)
{
    string inputs;
    string res;
    getline(cin, inputs);
    res = determine(inputs);

    cout << res << endl;
        
    return 0;
}

// Trying to Clean code
#include <iostream>
#include <string>

using namespace std;

// 문자열에서 숫자를 추출하는 함수
int get_digit(const string& str, int index) {
    return str[index] - '0';
}

// 순서를 판별하는 함수
string determine_order(const string& inputs) {
    bool is_ascending = get_digit(inputs, 0) < get_digit(inputs, 2);
    
    for (size_t i = 2; i < inputs.size(); i += 2) {
        int prev = get_digit(inputs, i - 2);
        int current = get_digit(inputs, i);

        if (is_ascending) {
            if (current < prev) {
                return "mixed";
            }
        } else {
            if (current > prev) {
                return "mixed";
            }
        }
    }

    return is_ascending ? "ascending" : "descending";
}

int main() {
    string inputs;
    getline(cin, inputs);

    cout << determine_order(inputs) << endl;

    return 0;
}
