#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    string s;
    cin >> T;
    while(T--){
        int ans = 0;
        cin >> s;
        int count1 = 0, count2 = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') count1++;
            if(s[i] == ')' and count1 > 0){
                ans++;
                count1--;
            }
            if(s[i] == '[') count2++;
            if(s[i] == ']' and count2 > 0){
                ans++;
                count2--;
            }
        }
        cout << ans << endl;
    }
}