#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)

ll n,d;
bool rec(ll num,ll val,ll dep)
{
    if(val==0||val==dep)
        return 1;
    if(val<dep)return 0;
    val-=dep;
    bool ans=0;
    num--;
    f(0,val)
    {
        bool v = (rec(num,i,dep+1)&rec(num,val-i,dep+1);
        if(v)
            cout<<num<<i<<
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        if(rec(n,d,0))cout<<"YES\n";else cout<<"No\n";
    }
}