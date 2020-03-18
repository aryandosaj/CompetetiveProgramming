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
ll arr[1000006];
double val[1000006];
ll m_avg[1000006];
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
    f(0, n) cin >> arr[i];
    ll sum = 0;
    f(0, n)
    {
        sum += arr[i];
        val[i] = (sum / (i + 1.0));
    }
    sum = 0;
    double c = 0;
    double m = MOD;
    ll ind = n - 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        c++;
        sum += arr[i];
        double avg = sum / (c);
        if (avg < m)
        {
            m = avg;
            ind = i;
        }
        m_avg[i] = ind;
    }
    sum=0;
    f(0,n)
    {
        double 



        sum+=arr[i];
    }



}