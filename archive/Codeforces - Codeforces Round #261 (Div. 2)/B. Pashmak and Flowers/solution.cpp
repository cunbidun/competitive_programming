/*input
2
1 1
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXNUM (int)2e5+2
int n, a[MAXNUM], cntmax, cntmin;

int main()
{
//	freopen("inp.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cntmin = 0;
	cntmax = 0;
	for (int i = 1; i <= n; i++){
		if(a[i] == a[1]){
			cntmin++;
		}
		else break;
	}

	for (int i = n; i >= 1; i--){
		if(a[i] == a[n]){
			cntmax++;
		}
		else break;
	}
	if (cntmax == n)cout << "0"<< " " << (long long) (cntmax * (long long)(cntmax-1)/2)<<endl;
	else cout << a[n] - a[1] << " " << (long long) cntmax*cntmin;
	return 0;
}