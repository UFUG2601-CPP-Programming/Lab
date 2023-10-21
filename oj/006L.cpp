#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        int l, start, end;
        cin >> l >> start >> end;
        vector<int> a;
        for(int j=0; j<l; j++){
            int d;
            cin>>d;
            a.push_back(d);
        }
        bool k_s = (a[start + 1] - a[start]) > 0;
        bool k_n = k_s;
        for(int k = start + 2; k <= end; k++){
            k_n = a[k]-a[k-1];
            if(k_s != k_n) {
                cout << "UP&DOWN" << endl;
                break;
            }
        }
        if(k_s == k_n){
            if(k_s) cout << "UP" << endl;
            else cout << "DOWN" << endl;
        }
    }
    return 0;
}