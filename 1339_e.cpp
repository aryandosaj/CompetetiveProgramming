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
    set<ll> s;
    ll it = 1;
    vll v1;
    vll v2;
    vll v3;
    f(0, 50)
    {
        if (s.find(it) == s.end())
        {
            ll last = it;
            s.insert(it);
            v1.pb(it);
            while (it++)
            {
                if (s.find(it ^ last) == s.end() && s.find(it) == s.end())
                {
                    s.insert(it);
                    s.insert(it ^ last);
                    v2.pb(it);
                    v3.pb(it ^ last);
                    it = last;
                    break;
                }
            }
        }
        it++;
    }
    for (auto i : v1)
        cout << i << "\t";
    cout << "\n";
    for (auto i : v2)
        cout << i << "\t";
    cout << "\n";

    for (auto i : v3)
        cout << i << "\t";
        cout<<"\n"<<(33^18);
}
//