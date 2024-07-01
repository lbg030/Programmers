#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> make_table(){
    map<char, int> character_table;
    string type = "RTCFJMAN";
    for(char a : type){
        character_table[a] = 0;
    }
    
    return character_table;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int>character_table = make_table();
    vector<string> compared = {"RT", "CF", "JM", "AN"};
    
    int stand = 4;
    for(int i=0; i<choices.size(); ++i){
        string item = survey[i];
        
        char A = item[0];
        char B = item[1];
        
        int sub = choices[i] - stand;
        if(sub > 0){
            character_table[B] += sub;
        }
        else{
            character_table[A] += abs(sub);
        }
        
    }
    
    for(const auto& elem : compared){
        char type_a = elem[0];
        char type_b = elem[1];
        
        if(character_table[type_a] > character_table[type_b]){
            answer += type_a;
        }
        else if(character_table[type_a] < character_table[type_b]){
            answer += type_b;
        }
        else{
            answer += (type_a < type_b) ? type_a : type_b;
        }
    }
    
    return answer;
}