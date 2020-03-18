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
pl score[100005];
ll d1[100005];
map<ll,vll>mp;
pair<pl,vll> lib[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll B,L,D;
    cin>>B>>L>>D;
    f(0,B)
    cin>>score[i].first,score[i].second=i;
    sort(score,score+B,greater<pl>());
    f(0,L)
    {
        ll n,t,m;

        cin>>n>>t>>m;
        lib[i].first={t,m};
        fi(0,n)
        {
            ll x;
            cin>>x;
            mp[x].pb(i);
            lib[i].second.pb(x);
        }
        
    }




}