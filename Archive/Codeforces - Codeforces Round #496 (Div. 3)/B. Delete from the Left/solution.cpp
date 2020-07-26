#include <iostream>	
#include <vector>	
#include <utility>
#include <cstdio>
#include <string>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int>	vi;

string a,b;
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("in.in","r",stdin);
	cin >> a >> b;
	int i = a.length()-1;
	int j = b.length()-1;         
	int ans = a.length() + b.length();                     
	while(a[i] == b[j]){
		ans-=2;                                             
		i--;
		j--;
		if(i < 0 || j < 0) break;
	}
	cout << ans;
	return 0;
}