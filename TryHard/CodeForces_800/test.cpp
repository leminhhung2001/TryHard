#include <bits/stdc++.h> 
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n; cin >> n;
        string s;
        for(int i=9; i>=1; i--){
            if(n >= i){
                s += char(i + '0');
                n -= i;
            }
        }
        reverse(s.begin(), s.end());
        if(n == 0){
            cout << s << endl;
        }
        else cout << "-1" << endl;

    }
}
