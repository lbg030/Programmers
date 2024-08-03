#include<iostream>
#include <string>
#include <cctype> // std::toupper

using namespace std;

int search_x(const string& a){
    size_t idx = a.find("X");
    // cout << idx << endl;
    return (int)idx;
}

void transform_upper(string& a, string& b){
    for(char& c: a){
        c = toupper(static_cast<unsigned char>(c));
    }

    for(char& c: b){
        c = toupper(static_cast<unsigned char>(c));
    }
}

int main(int argc, char** argv)
{
    int N;
    string a,b;
    string res;
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> a >> b;
        transform_upper(a,b);
        
        int idx = search_x(a);
        res += b[idx];
    }

    cout << res;
    return 0;
}