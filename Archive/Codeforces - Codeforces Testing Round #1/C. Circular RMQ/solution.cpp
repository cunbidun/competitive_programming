//simple segment tree

#include<stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

#define INF 1000000007
const int MAXA = 2e5+1;
using namespace std;

int segment[MAXA*4], lazy[MAXA*4],a[MAXA];
int n,m;

void buildTree(int node, int l, int r){
    if (l > r) return;
    if(l == r){
        segment[node] = a[l];
        return;
    }
    int m = (l+r) >> 1;
    buildTree(node*2, l, m);
    buildTree(node*2+1, m + 1, r);
    segment[node] = min(segment[node*2], segment[node*2 + 1]);
}

void lazyUpdate(int node, int l, int r){
    if (lazy[node] == 0) return;
    segment[node] += lazy[node];
    if(l != r){
        lazy[node*2] += lazy[node];
        lazy[node*2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int l, int r, int tar_L, int tar_R, int val){
    lazyUpdate(node, l, r);
    int m = (l+r)/2;
    if(l > tar_R || tar_L> r || l > r) return;
    if(tar_L <= l && r <= tar_R) {
        segment[node]  += val;
        if(l != r){
            lazy[node*2] += val;
            lazy[node*2 + 1] += val;
        }
        return;
    }
    update(node*2, l , m, tar_L, tar_R, val);
    update(node*2 + 1, m+1, r, tar_L, tar_R,val);
    segment[node] = min(segment[node*2], segment[node*2+1]);
}

int getMin(int node, int l, int r, int tar_L, int tar_R){
    lazyUpdate(node, l, r);
    if(l > tar_R || tar_L > r || l > r) return INF;
    if(tar_L <= l && r <= tar_R) return segment[node];
    int m = (l+r)/2;
    return min(getMin(node*2, l, m, tar_L, tar_R) , getMin(node*2 + 1, m+1, r, tar_L, tar_R));
}

int main(){
    //freopen("inp.inp","r", stdin);
    cin >> n;
    for(int i = 1 ;i <= MAXA*4 ; i ++) segment[i] = INF;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    buildTree(1,1,n);
    cin >> m;
    while (m--) {
        int s, e, v;
        int c;
        cin >> s >> e;
        s ++ ;
        e ++ ; 
        c = getchar();
        if(c != ' '){
            if(s <= e){
                cout << getMin(1, 1, n, s, e) << endl;
            }
            else{
                cout << min( getMin(1, 1, n, s, n), getMin(1, 1, n, 1, e)) << endl; 
            }
        }
        else{
            cin >> v;
            
            if(s <= e){
                update(1, 1, n, s, e, v);
            }
            else{
                update(1, 1, n, s, n, v);
                update(1, 1, n, 1, e, v); 
            }
        }
    }
}