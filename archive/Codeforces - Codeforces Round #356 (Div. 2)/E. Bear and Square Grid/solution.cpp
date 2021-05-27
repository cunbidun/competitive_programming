#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define REP(i,a,b) for(int i = a; i <= b; i ++) 

const int MAXN = 505;
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
int n, k;
int ans = 0, curr = 0;
char a[MAXN][MAXN];
int dsu[MAXN*MAXN], level[MAXN*MAXN], size[MAXN*MAXN];
bool visited[MAXN][MAXN], used[MAXN*MAXN];
int convert(int x, int y){
    return n*(x-1)+y;
}

int findSet(int x){
    return (dsu[x] == x) ? x : (dsu[x] = findSet(dsu[x])); 
}

bool isSameSet(int x, int y){
    return (findSet(x) == findSet(y));
}

void mergeSet(int x, int y){
    if(!isSameSet(x,y)){
        x = findSet(x);
        y = findSet(y);
        if(level[x] > level[y]) {
            dsu[y] = x;
            size[x] += size[y];
        }
        else {
            dsu[x] = y;
            size[y] += size[x];
            if(level[x] == level[y]) level[y] ++ ;
            
        }
    }
}

int getSize(int x){
    return size[findSet(x)];
}

void dfs(int x, int y, int lastx, int lasty){
    if(x > n || y > n || x < 1 || y < 1) return;
    visited[x][y] = 1;
    //cout << x << " " << y <<" "<< lastx << " " << lasty << endl;
    mergeSet(convert(x,y), convert(lastx,lasty));
    for(int i = 0; i < 4; i++){
        int newx, newy;
        newx = x + dirx[i];
        newy = y + diry[i];
        if(!visited[newx][newy] && a[x][y] == '.') dfs(newx, newy, x, y);
    }
}

void disconnect(int x, int y){
    int temp = findSet(convert(x,y));
    curr -= getSize(temp);
    used[temp] = 0;
}

void connect(int x, int y){
    int temp = findSet(convert(x,y));
    curr += getSize(temp);
    used[temp] = 1;
}

bool inUse(int x, int y){
    return used[findSet(convert(x,y))];
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("inp.inp","r",stdin);
    cin >> n >> k;
    if(n == k) {
        cout << n*n;
        return 0;
    }

    REP(i,1,n){
        REP(j,1,n){ 
            cin >> a[i][j];
            if(a[i][j] == '.') {
                int temp = convert(i,j);
                dsu[temp] = temp;
                size[temp] = 1;
                level[temp] = 0;
            }
            else visited[i][j] = 1;
        }
    }

    REP(i,1,n)
        REP(j,1,n)
            if(!visited[i][j] && a[i][j] == '.') 
                dfs(i,j,i,j);

    
    REP(i,1,n-k+1){
        curr = 0;
        REP(ii,1,n)
            REP(jj,1,n) used[findSet(convert(ii,jj))] = 0;
        
        REP(ii,0,k-1)
            REP(jj,0,k-1){
                if(a[i+ii][1+jj] == 'X') curr ++;
                else{
                    if(!inUse(i+ii, 1+jj)) connect(i+ii, 1 + jj);  
                }
            }

        if (i > 1)  
            REP(ii,0,k-1)
                if(a[i-1][1+ii] == '.' && !inUse(i-1,1+ii))
                    connect(i-1,1+ii);
        
        if (i < n-k+1)  
            REP(ii,0,k-1)
                if(a[i+k][1+ii] == '.' && !inUse(i+k,1+ii))
                     connect(i+k,1+ii);

        REP(ii,0,k-1)
            if(a[i+ii][k+1] == '.' && !inUse(i+ii,1+k))
                 connect(i+ii,1+k);
        ans = max(ans, curr);
        REP(j,1,n-k+1){
            if(j == 1) continue;

            if(i > 1)
                if(a[i-1][j-1] == '.' && inUse(i-1,j-1))
                    disconnect(i-1,j-1);
            if (i < n-k+1)
                if(a[i+k][j-1] == '.' && inUse(i+k,j-1))
                    disconnect(i+k,j-1);
            
            REP(l,0,k-1) {
                if(a[i+l][j-1] == 'X') curr --;
                if(a[i+l][j+k-1] == 'X') curr ++;
                if(j>2)
                    if(a[i+l][j-2] == '.' && inUse(i+l,j-2)) 
                        disconnect(i+l,j-2);
            }

            if(i > 1)
                if(a[i-1][j+k-1] == '.' && !inUse(i-1,j+k-1))
                    connect(i-1,j+k-1);
            if (i < n-k+1)
                if(a[i+k][j+k-1] == '.' && !inUse(i-1,j+k-1))
                    connect(i-1,j+k-1);
            
            REP(l,0,k-1) {
                if(a[i+l][j-1] == '.' && !inUse(i+l,j-1)) 
                    connect(i+l, j-1);
                if(j < n-k+1)
                    if(a[i+l][j+k] == '.' && !inUse(i+l,j+k)) 
                        connect(i+l, j+k);
            }
            REP(l,0,k-1) {
                if(i > 1)
                if(a[i-1][j+l] == '.' && !inUse(i-1,j+l)) 
                    connect(i-1,j+l);
                if(i < n-k+1)
                    if(a[i+k][j+l] == '.' && !inUse(i+k,j+l)) 
                        connect(i+k,j+l);
            }

            //cout << i << " " << j << " " << curr << endl;
            ans = max(ans, curr);
        }
    }

    cout << ans;
    return(0);
}