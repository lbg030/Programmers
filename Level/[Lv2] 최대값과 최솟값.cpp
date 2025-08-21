#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> int_vec;
    stringstream ss(s);
    ss.str(s);
    
    string word;
    while(ss >> word) {
        // cout << word << endl;
        int_vec.push_back(stoi(word));
    }
    // for(const auto& item : int_vec){
    //     cout << item << endl;
    // }
    int max = *max_element(int_vec.begin(), int_vec.end());
    int min = *min_element(int_vec.begin(), int_vec.end());
    
    answer += to_string(min) + " " + to_string(max);
    return answer;
}