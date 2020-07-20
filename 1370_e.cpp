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
    string s, t;
    cin >> s >> t;
    set<ll> s0, s1;
    f(0, n)
    {
        if (s[i] != t[i])
        {
            if (s[i] == '1')
                s1.insert(i);
            else
                s0.insert(i);
        }
    }
    if (s0.size() == 0 && s1.size() == 0)
    {
        cout << "0\n";
        return 0;
    }
    if (s0.size() != s1.size())
    {
        cout << "-1\n";
        return 0;
    }
    ll i0 = *s0.begin();
    ll i1 = *s1.begin();
    ll f = 2;
    int ans=0;
    while (!(s0.empty() && s1.empty()))
    {
        if (f == 2)
        {
            ans++;
            i0 = *s0.begin();
            i1 = *s1.begin();
            f=0;
        }
        if(i0<i1)
        {
            s0.erase(i0);
            s1.erase(i1);
            auto p =s0.upper_bound(i1); 
            if(p==s0.end()){
                f=2;
                continue;
            }
            i0 = *p;
        }
        else
        {
            s0.erase(i0);
            s1.erase(i1);
            auto p =s1.upper_bound(i0); 
            if(p==s1.end()){
                f=2;
                continue;
            }
            i1 = *p;
        }
    }
    cout<<ans<<"\n";
}