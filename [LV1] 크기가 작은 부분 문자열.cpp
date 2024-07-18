#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int p_len = p.size();
    vector<unsigned long long> sub_t_vec;
    string subset_t;
    for(int i=0; i<=t.size()-p_len; ++i){
        subset_t = t.substr(i, p_len);
        sub_t_vec.push_back(stoull(subset_t));
    }
    
    unsigned long long ull_p = stoull(p);
    if(!sub_t_vec.empty()){
        for(const auto& elem: sub_t_vec){
            // cout << elem << endl;
            if(ull_p >= elem) answer++;
        }
    }
    
    return answer;
}