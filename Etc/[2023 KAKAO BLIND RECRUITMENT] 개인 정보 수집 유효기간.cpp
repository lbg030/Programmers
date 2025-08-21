#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> split(const string& text, char delimiter) {
    vector<string> tokens;
    stringstream ss(text);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<int> solution(const string& today, const vector<string>& terms, const vector<string>& privacies) {
    vector<int> answer;
    unordered_map<string, int> term_map;
    
    // 현재 날짜 파싱
    vector<string> today_split = split(today, '.');
    int today_year = stoi(today_split[0]);
    int today_month = stoi(today_split[1]);
    int today_day = stoi(today_split[2]);
    
    // 용어와 유효 기간 매핑
    for(const auto& term : terms) {
        vector<string> term_split = split(term, ' ');
        term_map[term_split[0]] = stoi(term_split[1]);
    }
    
    // 개인정보와 날짜 비교
    for (int i = 0; i < privacies.size(); ++i) {
        const auto& privacy_elem = privacies[i];
        vector<string> privacy_split = split(privacy_elem, '.');
        int privacy_year = stoi(privacy_split[0]);
        int privacy_month = stoi(privacy_split[1]);

        vector<string> day_term_split = split(privacy_split[2], ' ');
        int privacy_day = stoi(day_term_split[0]);
        string privacy_term = day_term_split[1];
        
        int term_duration = term_map[privacy_term];
        privacy_month += term_duration;
        
        // 연, 월 계산
        while (privacy_month > 12) {
            privacy_month -= 12;
            privacy_year++;
        }
        
        // 현재 날짜와 비교
        if (today_year > privacy_year ||
            (today_year == privacy_year && (today_month > privacy_month || 
            (today_month == privacy_month && today_day >= privacy_day)))) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
