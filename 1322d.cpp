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
    ll k;
    cin>>k;
    ll m = 1;
    while (m <= 3e5)
        m = m * 2;
    ll o = m / 2 - 1;
    m = m / 4;
    cout<<"3 3\n";
    cout<<o<<" "<<m<<" "<<m<<"\n";
    cout<<o<<" "<<k<<" "<<m<<"\n";
    cout<<m<<" "<<o<<" "<<k<<"\n";


}