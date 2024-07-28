#include<iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Initial Code
vector<string> split_time(string a, char delimiter){
    vector<string> res;
    std::istringstream split_string(a);
    string token;

    while(getline(split_string, token, delimiter)){
        res.push_back(token);
    }
    return res;
    
}

int main(int argc, char** argv)
{
    int hour = 0;
    int minutes = 0;
    string start;
    string end;
    vector<string> start_time;
    vector<string> end_time;
    
    for(int i=0; i<5; i++){
        cin >> start;
        cin >> end;

        start_time = split_time(start, ':');
        end_time = split_time(end, ':');

        int start_hour = stoi(start_time[0]);
        int start_miniutes = stoi(start_time[1]);

        int end_hour = stoi(end_time[0]);
        int end_miniutes = stoi(end_time[1]);

        hour += (end_hour - start_hour);
        minutes += (end_miniutes - start_miniutes);
    }
    int answer = hour * 60 + minutes;
    cout << answer << endl;
    return 0;
}

// Trying to Clean code
#include<iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> split_time(string a, char delimiter){
    vector<int> res;
    std::istringstream split_string(a);
    string token;

    while(getline(split_string, token, delimiter)){
        res.push_back(stoi(token));
    }
    return res;
}

int calcuate_times(const std::vector<int>& start_time, const std::vector<int>& end_time){
    int start_hour = start_time[0];
    int start_minutes = start_time[1];
    int end_hour = end_time[0];
    int end_minutes = end_time[1];

    return 60 * (end_hour - start_hour) + end_minutes - start_minutes;
    
}

void process_calculate(int& total_time){
    string start_str, end_str;
    for(int i=0; i<5; i++){
        cin >> start_str >> end_str;
    
        std::vector<int> start_time = split_time(start_str, ':');
        std::vector<int> end_time = split_time(end_str, ':');
    
        total_time += calcuate_times(start_time, end_time);
    }
}

int main(){
    int total_time = 0;
    process_calculate(total_time);
    cout << total_time;

    return 0;
}