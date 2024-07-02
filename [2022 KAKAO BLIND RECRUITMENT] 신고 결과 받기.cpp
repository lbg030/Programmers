#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> idx_map;
    map<string, set<string>> report_map;
    
    for(int i=0; i<id_list.size(); ++i){
        idx_map[id_list[i]] = i;
    }
    
    for (const auto& elem : report){
        istringstream iss(elem);
        string reporter;
        string reported;
        iss >> reporter >> reported;
        report_map[reported].insert(reporter);
    }
    
    for (const auto& v : report_map){
        if(v.second.size() >=k ){
            for (const auto& report_user : v.second){
                answer[idx_map[report_user]]++;
            }
        }
    }
    
    return answer;
}