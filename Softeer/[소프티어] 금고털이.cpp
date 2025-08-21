#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool compareByPrice(const pair<int, int>& a, const pair<int, int>& b){
    return a.second > b.second;
}

vector<pair<int, int>>save_vector(vector<pair<int,int>>& jewelry_vec, const int& N){

    int jewelry_weight, price;
    for(int i=0; i<N; ++i){
        cin >> jewelry_weight >> price;
        jewelry_vec.push_back(make_pair(jewelry_weight, price));
    }
    return jewelry_vec;
}

int main(int argc, char** argv)
{
    vector<pair<int, int>> jewelry_vec;
    int max_weights, N, jewelry_weight, jewelry_price;
    int current_weight = 0;
    int current_price = 0;
    
    cin >>max_weights >> N;
    save_vector(jewelry_vec, N);

    sort(jewelry_vec.begin(), jewelry_vec.end(), compareByPrice);

    for(const auto& elem : jewelry_vec){
        jewelry_weight = elem.first;
        jewelry_price = elem.second;

        current_price += jewelry_weight * jewelry_price;
        current_weight += jewelry_weight;
        
        if(current_weight >= max_weights){
            current_price -= jewelry_price * (current_weight - max_weights);
            break;
        }
    }
    cout << current_price << endl;
    return 0;
}
