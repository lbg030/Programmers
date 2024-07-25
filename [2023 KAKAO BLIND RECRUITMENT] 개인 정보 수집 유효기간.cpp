#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>

using namespace std;

vector<string> split(const string text, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(text);

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    string tmp;
    char delimiter = '.';
    map<string, int> term_map;
    
    vector<string> result = split(today, delimiter);
    int today_year = stoi(result[0]);
    int today_month = stoi(result[1]);
    int today_day = stoi(result[2]);
    
    for(const auto& term : terms){
        vector<string> term_result = split(term, ' ');
        term_map[term_result[0]] = stoi(term_result[1]);
    }
    
    int idx = 0;
    for(const auto& privacy_elem : privacies){
        idx++;
        vector<string> privacy = split(privacy_elem, delimiter);
        int privacy_year = stoi(privacy[0]);
        int privacy_month = stoi(privacy[1]);

        vector<string> day_term_split = split(privacy[2], ' ');
        int privacy_day = stoi(day_term_split[0]);
        string privacy_term = day_term_split[1];
 
        privacy_month += term_map[privacy_term];
        while(privacy_month > 12){
            privacy_month -= 12;
            privacy_year++;
        }
        if(today_year > privacy_year){
            answer.push_back(idx);
            continue;
        }

        else if(today_year == privacy_year){ 
            if(today_month > privacy_month){
                answer.push_back(idx);
                continue;
                }
            }
        else{
            continue;
        }
        
        if(today_month > privacy_month){
            answer.push_back(idx);
            continue;
        }
        
        else if(today_month == privacy_month){
            if(today_day >= privacy_day){
            answer.push_back(idx);
            continue;
            }
        }
        else{
            continue;
        }
    }
    
    return answer;
}