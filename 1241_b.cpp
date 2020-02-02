#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin>>q;
    while(q--)
    {
        string s1,s2;
        cin>>s1>>s2;
        map<char,ll>mp;
        for(auto i:s1)mp[i]=1;
        ll f=0;
        for(auto i:s2)
        {
            if(mp[i])
            {
               cout<<"YES\n";
               f=1;break; 
            }
        }
        if(f==0)cout<<"NO\n";

    }
}