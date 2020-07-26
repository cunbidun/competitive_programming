/*input
12 3
101111100101
*/
#include <iostream>
#include <string>
using namespace std;
int n, d, cnt, cur;
string S;
int main()
{
//	freopen("inp.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	cin >> n >> d;
	cin >> S;
	cnt = 0; 
	for(int i = 0; i < S.length(); i){
		bool check = 0;
		for(int j = 1; j <= d; j++){
			if(S[i+j] == '1'){
				if(!check) check = 1;
				cur = i + j;
				if (cur >= n - 1){
				//	cout<< i << " " <<j<<endl;
					cout << cnt + 1;
					return 0;
				}
			}
		}
		if(!check){
				cout << "-1";
				return 0;
			}
		i = cur;
		//cout << "i = " << i << endl;
		cnt++;
	}
	return 0;
}