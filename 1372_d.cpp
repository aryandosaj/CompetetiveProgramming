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
    ll s1 = 0, s2 = 0;
    f(0, n)
    {
        cin >> arr[i];
        if (i & 1)
            s2 += arr[i];
        else
            s1 += arr[i];
    }
    ll ans=max(s1,s2);
    ll p1 = 0, p2 = 0, q1 = s1, q2 = s2;
    f(0, n)
    {
        if (i&1)
        {
            p2+=arr[i];
            s2-=arr[i];
            ans = max(ans,p2+s1);
        }
        else
        {
            p1+=arr[i];
            s1-=arr[i];
            ans = max(ans,p1+s2);
            
        }
        
    }
    cout<<ans<<"\n";
}