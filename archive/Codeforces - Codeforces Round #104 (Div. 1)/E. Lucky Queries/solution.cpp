//simple segment tree

#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

#define INF 1000000007f
const int MAXA = 1e6+1;
using namespace std;

string s;
int n,m;
int a[MAXA];

struct node{
    int n4, n7, n47, n74;
    node(){
        n4 = 0, n7 = 0, n47 = 0, n74 = 0;
    }
};

node segment[MAXA*4];
bool lazy[MAXA*4];
string S, temp;

void buildTree(int node, int l, int r){
    if (l > r) return;

    if (l == r){
        if(S[l] == '4') {
            segment[node].n4 = 1;
            segment[node].n7 = 0;
        }
        else{
            segment[node].n4 = 0;
            segment[node].n7 = 1;
        }
        segment[node].n47 = 1;
        segment[node].n74 = 1;
        return;
    }
    int m = (l + r) >> 1;
    buildTree((node << 1), l, m);
    buildTree((node << 1) + 1, m + 1, r);
    segment[node].n7 = segment[(node << 1)].n7 + segment[(node << 1) + 1].n7;
    segment[node].n4 = segment[(node << 1)].n4 + segment[(node << 1) + 1].n4;
    segment[node].n47 = max(max((segment[(node << 1)].n4 + segment[(node << 1) + 1].n7),
        (segment[(node << 1)].n4 + segment[(node << 1) + 1].n47)),
        (segment[(node << 1)].n47 + segment[(node << 1) + 1].n7));
    segment[node].n74 = max(max((segment[(node << 1)].n7 + segment[(node << 1) + 1].n4),
        (segment[(node << 1)].n74 + segment[(node << 1) + 1].n4)),
        (segment[(node << 1)].n7 + segment[(node << 1) + 1].n74));
}

void lazyUpdate(int node, int l, int r){
    if(lazy[node]){
        swap(segment[node].n4, segment[node].n7);
        swap(segment[node].n47, segment[node].n74);
        if (l != r){ 
            lazy[(node << 1)] = !lazy[(node << 1)];
            lazy[(node << 1) + 1] = !lazy[(node << 1) + 1];
        }
    }
    lazy[node] = 0;
}

void update(int node, int l, int r, int tar_L, int tar_R){
    lazyUpdate(node, l, r);
    if(l > tar_R || r < tar_L || l > r) return;
    if(tar_L <= l && r <= tar_R){
        swap(segment[node].n4, segment[node].n7);
        swap(segment[node].n47, segment[node].n74);
        if(l != r){    
            lazy[(node << 1)] = !lazy[(node << 1)];
            lazy[(node << 1) + 1] = !lazy[(node << 1) + 1];
        }
        return;
    }
    int m = (l + r) >> 1;
    update((node << 1), l, m, tar_L, tar_R);
    update((node << 1) + 1, m + 1, r, tar_L, tar_R);
    segment[node].n7 = segment[(node << 1)].n7 + segment[(node << 1) + 1].n7;
    segment[node].n4 = segment[(node << 1)].n4 + segment[(node << 1) + 1].n4;
    segment[node].n47 = max(max((segment[(node << 1)].n4 + segment[(node << 1) + 1].n7),
        (segment[(node << 1)].n4 + segment[(node << 1) + 1].n47)),
        (segment[(node << 1)].n47 + segment[(node << 1) + 1].n7));
    segment[node].n74 = max(max((segment[(node << 1)].n7 + segment[(node << 1) + 1].n4),
        (segment[(node << 1)].n74 + segment[(node << 1) + 1].n4)),
        (segment[(node << 1)].n7 + segment[(node << 1) + 1].n74));
}   

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("inp.inp","r", stdin);
    cin >> n >> m;
    cin >> S;
    S = 'X' + S;
    buildTree(1, 1, n);
    while (m--) {
        cin >> temp;
        if (temp == "count") {
            cout << segment[1].n47 << endl;
        }
        else {
            int s, e;
            cin >> s >> e;
            update(1, 1, n, s, e);
        }
    }
}