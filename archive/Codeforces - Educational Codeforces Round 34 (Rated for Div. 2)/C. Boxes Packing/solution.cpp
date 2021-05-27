#include<iostream>
#include<algorithm>

using namespace std;

int n, a[5001], cur, ans;
bool check[5001];
int main(){
    cin>>n;
    for(int i = 1;i <= n; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    //for(int i = 1; i <= n; i++ ) cout<< a[i] << " "; cout<< endl;
    ans = 0;
    for(int i = 1; i <= n; i++){
        if (check[i] == true) continue;

        cur = a[i];
        check[i] = true;
        for(int j = i+1; j <= n; j++){
            if (check[j] == true) continue;
            if (a[j] > cur){
                cur = a[j];
                check[j] = true;
            }
        }
        ans ++;
    }
    cout<< ans;
}