#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int MAXA = 1e6+2;
int open[4*MAXA],close[4*MAXA], correct[4*MAXA], query, curr, ans;
string s;

void buildTree(int i, int l, int r){
	if(l > r) return;
	if(l == r){
		correct[i] = 0;
		if(s[l] == '(') open[i] = 1;
		else close[i] = 1;
		//cout << i << " " << l << " " << r << " " << correct[i] << " " << open[i] << " " << close[i] << endl;
		return ;
	}
	int m = (l+r)>>1;
	buildTree(i*2,l,m);
	buildTree(i*2+1,m+1,r);
	int commnon = min(open[i*2],close[i*2+1]);
	correct[i] = correct[i*2+1]+correct[i*2] + commnon*2;
	open[i] = open[i*2+1] + open[i*2] - commnon;
	close[i] = close[i*2+1] + close[i*2] - commnon;
//	cout << i << " " << l << " " << r << " " << correct[i] << " " << open[i] << " " << close[i] << endl;
}

int getS(int i, int l, int r, int tarL, int tarR) {
	if(r < tarL || tarR < l || r < l) return 0;
	if(tarL <= l && r <= tarR) {
		ans += (min(curr, close[i])*2);
		curr = curr - min(curr, close[i]);
		curr += open[i];
		// cout << i << " " << l << " " << r << " " << correct[i] << " " << open[i] << " " << close[i] << endl;
		// cout << curr << endl;
		return correct[i];
	}
	int m = (l+r) >> 1;
	return getS(i*2,l,m,tarL,tarR) + getS(i*2+1,m+1,r,tarL,tarR);
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("in.in","r",stdin);
	cin >> s;
	s = "0" + s;
	buildTree(1,1,s.length()-1);
	cin >> query;
	while(query --){
		int l, r;
		cin >> l >> r;
		curr = 0; ans = 0;
		cout << getS(1,1,s.length()-1,l,r) + ans<<endl;
	}
	return 0;
}