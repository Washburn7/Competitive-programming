#include<bits/stdc++.h>
#define x first
#define y second
#define endl '\n'
#define LL long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=2000010,MOD=998244353;
int t,n,k,a[2100][2100];
int main()
{
	ios;
	cin>>t;
	while(t--){
		cin>>n>>k;
		LL num=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]!=a[n+1-i][n+1-j]){
					//cout<<i<<" "<<j<<endl;
					num++;
				}
			}
		}
		num=num/2;
        if(n & 1) {
            if(k >= num) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            if(k>=num && (k % 2 == num % 2)) cout<<"YES"<<endl;
		    else cout<<"NO"<<endl;
        }
		
	}
}