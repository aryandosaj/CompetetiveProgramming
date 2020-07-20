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
string arr[1003];
ll vis[1003][1003];
ll n, m;
ll a;
ll r[1003];
ll co[1003];
ll s[1003][1003];
ll rr[1003];
ll cc[1003];

void rec(ll ui, ll uj)
{

    if (ui < 0 || ui >= n || uj < 0 || uj > m)
        return;
    if (arr[ui][uj] == '.')
        return;
    vis[ui][uj] = 1;
    if (vis[ui + 1][uj] == 0)
        rec(ui + 1, uj);
    if (vis[ui][uj + 1] == 0)
        rec(ui, uj + 1);
    if (ui > 0 && vis[ui - 1][uj] == 0)
        rec(ui - 1, uj);
    if (uj > 0 && vis[ui][uj - 1] == 0)
        rec(ui, uj - 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    f(0, n)
            cin >>
        arr[i];
    ll flag = 0;
    ll g = 0;
    f(0, n) fi(0, m) if (arr[i][j] == '#')
    {
        g = 1;
        break;
    }
    if (g == 0)
    {
        cout << "0\n";
        return 0;
    }
    f(0, n)
    {
        ll c = 0;
        ll f = 0;
        fi(0, m)
        {

            if (f == 0 && arr[i][j] == '#')
                c++, f = 1;
            else if (f == 1 && arr[i][j] == '.')
                f = 0;
        }
        r[i] = c;
        if (c > 1)
        {
            flag = 1;
            break;
        }
    }
    f(0, m)
    {
        ll c = 0;
        ll f = 0;
        fi(0, n)
        {

            if (f == 0 && arr[j][i] == '#')
                c++, f = 1;
            else if (f == 1 && arr[j][i] == '.')
                f = 0;
        }
        co[i] = c;
        if (c > 1)
        {
            flag = 1;
            break;
        }
    }
    f(0, n)
    {
        if (r[i] == 0)
        {
            ll g = 0;
            fi(0, m)
            {
                if (co[j] == 0)
                {
                    g = 1;
                    break;
                }
            }
            if (g == 0)
            {
                flag = 1;
                break;
            }
        }
    }
    f(0, m)
    {
        if (co[i] == 0)
        {
            ll g = 0;
            fi(0, n)
            {
                if (r[j] == 0)
                {
                    g = 1;
                    break;
                }
            }
            if (g == 0)
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag)
    {
        cout << "-1\n";
        return 0;
    }
    ll x=0;
    ++x++;
    f(0, n) fi(0, m)
    {

        if (vis[i][j] == 0 && arr[i][j] == '#')
            // cout << i << " " << j << "\n",
            a++, rec(i, j);
    }
    cout << a << "\n";
}