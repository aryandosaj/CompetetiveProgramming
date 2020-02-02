#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int n, k, s, pos=1;
int mindist, maxdist;
int main()
{
	// IOS;
	cin>>n>>k>>s;
	mindist=k;
	maxdist=(n-1)*k;
	if(s<mindist || s>maxdist)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=k-1;i>=0;i--)
	{
		int minleave=i;
		int cur=min(s-minleave, n-1);
		s-=cur;
		if(pos+cur<=n)
		{
			pos+=cur;
			cout<<pos<<" ";
		}
		else
		{
			pos-=cur;
			cout<<pos<<" ";
		}
	}
	return 0;
}