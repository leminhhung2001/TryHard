#include<bits/stdc++.h>

using namespace std;

vector<int> v;
int main(){
    int n, k;
    cout << "The numbers of Array n = "; cin >> n;
    for(int i=0; i<n; i++){
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) cout << v[i] << " ";
    cout << endl;
    cout << "+++++++++++++++++++++++++++++++++++" << endl;
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() + 1 << endl;
    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() + 1 << endl;
}