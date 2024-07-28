#include<iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

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