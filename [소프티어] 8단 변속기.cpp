#include<iostream>


using namespace std;

// Initial Code
int main(int argc, char** argv)
{
    string inputs;
    int prev = 0;
    int current = 0;
    bool ascending;
    bool flag = true;
    
    getline(cin, inputs);

    prev = inputs[0] - '0';
    current = inputs[2] - '0';
    if(current > prev){
        ascending = true;
    }else{
        ascending = false;
    }

    for(int i=4; i<inputs.size()-2; i+=2){
        if (ascending){
            if(current < (inputs[i] - '0')){
                current = inputs[i] - '0';
            }
            else{
                cout << "mixed" << endl;
                flag = false;
                break;
            }
        }
        //descending
        else{
            if(current > (inputs[i] - '0')){
                current = (inputs[i] - '0');
            }
            else{
                cout << "mixed" << endl;
                flag = false;
                break;
            }
        }
    }
    if(flag){
        if(ascending){
            cout << "ascending" << endl;
        }else{
            cout <<"descending" << endl;
        }
    }
    
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
