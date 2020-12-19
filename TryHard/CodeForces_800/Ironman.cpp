#include <bits/stdc++.h>
using namespace std;


int ans(int n, int sum, int a[]){
    
    if(n == 1 and sum - a[n]*n >= 0){
        return a[n]*n;
    }
    else if(sum - a[n] * n > 0){
        sum -= a[n] * n;
        //cout << "SUM: " << sum << "  n = " << n << "  a[] = " << a[n] << endl;
        return ans(n-1, sum, a);
    }
    else return INT_MIN;
    
}
bool cmp(int x, int y){
    return x > y;
}
int main()
{
	int n, sum;
    cin >> n >> sum;
    int a[n];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1, cmp);
    //cout << "ANS = " << ans(n, sum, a) << endl;
    if(ans(n, sum, a) < 0) cout << "YES";
    else cout << "NO";
    
}
