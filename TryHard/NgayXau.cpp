#include<bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main(){
    int T;
    cin >> T;
    int m, n, p;
    while(T--){
        int ans = 318;
        cin >> m >> n >> p;
        for(int i=2019; i>p; i--){
            if(i % 4 == 0){
                if(i % 100 == 0 and i % 400 == 0){
                    ans += 365;
                }
                else{
                    ans += 366;
                }   
            }
            else ans += 365;
        }
        if(p % 4 == 0){
            if(p % 100 == 0 and p % 400 == 0){
                ans += 365;
                for(int i=1; i<n; i++){
                    if(i == 2){
                        ans -= 28;
                    } 
                    else if(i == 1 || i == 3 || i == 5 || i == 7 || i == 10 || i == 12){
                        ans -= 31;
                    }
                    else{
                        ans -= 30;
                    }
                }
                ans -= m;
            }
            else{
                ans += 366;
                for(int i=1; i<n; i++){
                    if(i == 2){
                        ans -= 29;
                    } 
                    else if(i == 1 || i == 3 || i == 5 || i == 7 || i == 10 || i == 12){
                        ans -= 31;
                    }
                    else{
                        ans -= 30;
                    }
                }
                ans -= m;
            }
        }
        else{
            ans += 365;
            for(int i=1; i<n; i++){
                if(i == 2){
                    ans -= 28;
                } 
                else if(i == 1 || i == 3 || i == 5 || i == 7 || i == 10 || i == 12){
                    ans -= 31;
                }
                else{
                    ans -= 30;
                }
            }
            ans -= m;
        }
        int d = (25 * 27)/gcd(25, 27);
        int d1 = (25 * 29)/gcd(25, 29);
        int d2 = (29 * 27)/gcd(29, 27);
        int k = (d * 29)/gcd(d, 29);
        cout << ans/k << " " << ans/d + ans/d1 + ans/d2 - 3 * (ans/k) << endl;
    }
}