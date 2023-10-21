#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int a,b;

    std::cin >> a >> b;

    vector<int> sa(a);
    vector<int> sb(b);

    for(int i=0; i < a; i++){
        std::cin >> sa[i];
    }
    for(int j=0; j < b; j++){
        std::cin >> sb[j];
    }

    vector<int> s_union, s_intersection;
    s_union = sa;

    for(int i = 0; i < b; i++){
        bool unique = true;
        for(int j = 0; j < a; j++){
            if(sa[j] == sb[i]){
                unique = false;
                s_intersection.push_back(sa[j]);
            }
        }
        if(unique) {s_union.push_back(sb[i]);}
    }

    sort(s_union.begin(), s_union.end());
    sort(s_intersection.begin(), s_intersection.end());

    if(s_union.empty()){
        std::cout << "None";
    }
    for(auto i : s_union){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    if(s_intersection.empty()){
        std::cout << "None";
    }
    for(auto i : s_intersection){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}