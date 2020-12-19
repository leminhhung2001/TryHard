#include<bits/stdc++.h>

using namespace std;

int Binary_Search(int a[], int l, int r, int x){
    while(l <= r){
        int mid = l + (r-l)/2;
        
        if(a[mid] == x) return mid; //nếu mà tìm thấy thì sẽ trả về vị trí

        else if(a[mid] > x){
            r = mid - 1;    //cập nhật lại vị trí của right và tìm kiếm nửa bên trái
        }

        else{
            l = mid + 1;    //cập nhật lại vị trí của left và tìm kiếm nửa bên phải
        }
    }
    return -1;
}
int main(){
    int n;
    cout << "Nhap so phan tu n = "; cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
    
    cout << "Nhap so can tim k = ";
    int k; cin >> k;

    int ans = Binary_Search(a, 0, n-1, k);

    if(ans != -1) cout << "So " << k << " vt " << ans+1 << endl;
    else cout << "Khong ton tai " << k << " trong mang" << endl;

}