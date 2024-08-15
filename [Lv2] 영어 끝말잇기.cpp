#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check_used(string a, const vector<string>& already_used){
    if(find(already_used.begin(), already_used.end(), a) - already_used.begin() == already_used.size()){
        return false;
    }else{
        return true;
    }
}

bool check_justified(string prev_words, string cur_words){
    if(prev_words[prev_words.size() - 1] == cur_words[0]){
        return true;
    }else{
        return false;
    }
}

vector<pair<int, int>> solution(int n, vector<string> words) {
    vector<pair<int, int>> answer;
    vector<string> already_used;
    string prev_words;
    
    for(int i=0; i<words.size(); ++i){
        string now_words = words[i];
        if(i == 0){
            already_used.push_back(now_words);
            prev_words = now_words;
            continue;
        }else{
            // cout << prev_words[prev_words.size()-1] << " " << now_words[0] << endl;
            if (not check_justified(prev_words, now_words)){
                // cout << "I: " << i << endl;
                answer.push_back(make_pair(i % n + 1, i/n + 1));
                return answer;
            }else{
                if(check_used(now_words, already_used)){
                    answer.push_back(make_pair(i % n + 1, i/n + 1));
                    return answer;
                }
            }
        }
        already_used.push_back(now_words);
        prev_words = now_words;
    }
    answer.push_back(make_pair(0,0));
    return answer;
}