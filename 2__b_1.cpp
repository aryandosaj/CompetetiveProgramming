#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
ll dp5[1005][1005];
ll dp2[1005][1005];
ll arr[1005][1005];
char path_2[1005][1005];
char path_5[1005][1005];
ll no_of_2(ll i)
{
    ll ans = 0;
    while ((i > 0) && ((i % 2) == 0))
    {
        ans++;
        i /= 2;
    }
    return ans;
}
ll no_of_5(ll i)
{
    ll ans = 0;
    while ((i > 0) && ((i % 5) == 0))
    {
        ans++;
        i /= 5;
    }
    return ans;
}
ll rec_2(ll i, ll j)
{
    if (dp2[i][j] != -1)
    {
        return dp2[i][j];
    }
    ll c = no_of_2(arr[i][j]);

    if ((i == 0) && (j == 0))
        return dp2[i][j] = c;
    ll d = MAX;
    ll r = MAX;
    if (i > 0)
        d = rec_2(i - 1, j);
    if (j > 0)
        r = rec_2(i, j - 1);
    if (d < r)
    {
        path_2[i][j] = 'D';
        return dp2[i][j] = d + c;
    }
    else
    {
        path_2[i][j] = 'R';
        return dp2[i][j] = r + c;
    }
}
ll rec_5(ll i, ll j)
{
    if (dp5[i][j] != -1)
    {
        return dp5[i][j];
    }
    ll c = no_of_5(arr[i][j]);

    if ((i == 0) && (j == 0))
        return dp5[i][j] = c;
    ll d = MAX;
    ll r = MAX;
    if (i > 0)
        d = rec_5(i - 1, j);
    if (j > 0)
        r = rec_5(i, j - 1);
    if (d < r)
    {
        path_5[i][j] = 'D';
        return dp5[i][j] = d + c;
    }
    else
    {
        path_5[i][j] = 'R';
        return dp5[i][j] = r + c;
    }
}
string t_2 = "";
string t_5 = "";
void trace_2(ll i, ll j)
{
    if ((i == 0) && (j == 0))
        return;
    else
    {
        if (path_2[i][j] == 'D')
        {
            trace_2(i - 1, j);
            t_2 = t_2 + 'D';
        }
        else
        {
            trace_2(i, j - 1);
            t_2 = t_2 + 'R';
        }
    }
}
void trace_5(ll i, ll j)
{
    if ((i == 0) && (j == 0))
        return;
    else
    {
        if (path_5[i][j] == 'D')
        {
            trace_5(i - 1, j);
            t_5 = t_5 + 'D';
        }
        else
        {
            trace_5(i, j - 1);
            t_5 = t_5 + 'R';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;

    for (ll i = 0; i < 1005; i++)
    {
        for (ll j = 0; j < 1005; j++)
        {
            dp2[i][j] = -1;
            dp5[i][j] = -1;
            arr[i][j] = -1;
        }
    }
    ll ii = -1, jj = -1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
            {
                ii = i;
                jj = j;
            }
        }
    }
    string p0;
    ll ans_0 = MAX;
    if ((ii != -1) && (jj != -1))
    {
        for (ll i = 0; i < ii; i++)
        {
            p0 += 'D';
        }
        for (ll i = 0; i < jj; i++)
        {
            p0 += 'R';
        }
        for (ll i = ii; i < n - 1; i++)
        {
            p0 += 'D';
        }
        for (ll i = jj; i < n - 1; i++)
        {
            p0 += 'R';
        }
    ans_0 = 1;

    }
    ll ans_2 = rec_2(n - 1, n - 1);
    ll ans_5 = rec_5(n - 1, n - 1);
    if (ans_0 < min(ans_2, ans_5))
    {
        cout << "1\n"
             << p0;
        return 0;
    }

    if (ans_2 < ans_5)
    {
        cout << ans_2 << "\n";
        trace_2(n - 1, n - 1);
        cout << t_2;
    }
    else
    {
        cout << ans_5 << "\n";
        trace_5(n - 1, n - 1);
        cout << t_5;
    }
}