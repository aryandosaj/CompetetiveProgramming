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
ll arr[200005];
stack<ll> st[21];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    f(0, n)
    {
        cin >> arr[i];
        fi(0, 21)
        {
            if (arr[i] & (1 << j))
                st[j].push(arr[i]);
        }
    }
    vll ans;
    while (1)
    {
        ll a =0;
        ll f=0;
        for (ll i = 20; i >= 0; i--)
        {
            if(st[i].size()>0){
                f=1;
                a = a|(1<<i);
                st[i].pop();
            }
        }
        if(f==0)break;
        ans.pb(a);
        a=0;
    }
    ll aa = 0;
    for(auto i:ans)aa+=i*i;
    cout<<aa;
}