#include<bits/stdc++.h>
#define ll long long int
#define fl(i,x,y) for( ll i=x;i<y;i++)
#define w(t) while(t--)
#define vi vector<ll>
#define vvi vector< vi >
#define si set<ll>
#define msi multiset<ll>
#define si_d set<ll, greater<ll> >
#define mii map<ll,ll>
#define pb push_back
#define msi_it  multiset<ll> :: iterator
#define si_it set<ll> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
using namespace std;
int main()
{
	int t;
	string s;
    cin>>t;
	w(t)
	{
		cin>>s;
		int count=0;
		for(int i=0;i<s.length()-3;i++)
		{
		    map<char,ll> chef;
			chef[s[i]]++;chef[s[i+1]]++;
			chef[s[i+2]]++;chef[s[i+3]]++;
			if(chef['c']==1 && chef['h']==1 && chef['e']==1 && chef['f']==1) count++;
		}
		if(count==0) cout<<"normal\n";
        else cout<<"lovely"<<" "<<count<<"\n";
	}
}
 