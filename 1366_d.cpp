#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll int
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
ll arr[500005];
vll p;
ll pr[10000007];
void prime()
{
    for (ll i = 2; i * i < 10000007; i++)
    {
        if (pr[i] == i)
        {
            pr[i] = i;
            for (ll j = i * i; j < 10000007; j += i)
                if (pr[j] == j)
                    pr[j] = i;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f(0,10000007)pr[i]=i;
    ll n;
    cin >> n;
    f(0, n) cin >> arr[i];
    prime();
    vll a, b;
    f(0, n)
    {
        int f = 0;
        int num = arr[i];
        ll di = pr[arr[i]];
        while (num % di == 0)
            num /= di;
        if (num == 1)
            a.pb(-1),
                b.pb(-1);
        else
            a.pb(di),
                b.pb(num);
    }
    for (auto i : a)
        cout << i << " ";
    cout << "\n";
    for (auto i : b)
        cout << i << " ";
}