#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

int binary(int num){
    int result = 0;
    for(int i = 1; num >0; i*=10){
        int binary = num % 2;
        result += binary * i;
        num /= 2;
    }
    return result;
}

pair<string, int> remove_zero(string s){
    string res = "";
    int zero_count = 0;
    for(const auto& item : s){
        if(item != '0'){
            res += item;
        }else{
            zero_count++;
        }
    }
    return make_pair(res, zero_count);
}

vector<int> solution(string s) {
    vector<int> answer;
    int zero = 0;
    int total_count = 0;
    
    while(s != "1"){
        pair<string, int> remove_zero_result = remove_zero(s);
        s = remove_zero_result.first;
        zero += remove_zero_result.second;
        
        int s_size = s.size();
        bitset<100> decim_to_bin(s_size);
        string binary_string = decim_to_bin.to_string();
        
        size_t first_found = binary_string.find('1');
        if (first_found != string::npos){
		    binary_string = binary_string.substr(first_found);
            }
        // s = to_string(binary(s.size()));
        s = binary_string;
        // cout << binary_string << endl;
        total_count++;
        // break;
    }
    answer.push_back(total_count);
    answer.push_back(zero);
    return answer;
}