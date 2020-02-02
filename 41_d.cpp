#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
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
ll dp[101][101][11];
string path[101][101][11];
string arr[101];
ll n, m, k;
ll fun(ll i, ll j, ll x)
{
    if (j >= m || j < 0)
        return -1;
    if (dp[i][j][x] != -2)
    {

        return dp[i][j][x];
    }
    ll num = arr[i][j] - '0';
    ll c = 0;
    if (i == 0)
    {
        if (num % k == x)
            return num;
        else
            return -1;
    }
    if (num > x)
        c = (k - (num - x) % k) % k;
    else
        c = x - num;
    ll ans;
    ll left = fun(i - 1, j - 1, c);
    ll right = fun(i - 1, j + 1, c);
    if (left > right)
        path[i][j][x] = path[i - 1][j - 1][c] + 'L';
    else if (right > left)
        path[i][j][x] = path[i - 1][j + 1][c] + 'R';
    else if (right >= 0)
        path[i][j][x] = path[i - 1][j + 1][c] + 'R';

    ans = max(left, right);
    if (ans == -1)
        return dp[i][j][x]=-1;
    ans += num;
    return dp[i][j][x] = ans;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            for (ll g = 0; g < 11; g++)
                dp[i][j][g] = -2;
    k++;
    ll ans = -1;
    ll col = 0;
    for (ll i = 0; i < m; i++)
    {
        ll temp = fun(n - 1, i, 0);
        if ((ans < temp) && (temp % k == 0))
        {
            ans = temp;
            col = i + 1;
        }
    }
    if (ans == -1)
    {
        cout << "-1";
        return 0;
    }
    reverse(path[n - 1][col - 1][0].begin(),path[n - 1][col - 1][0].end());
    cout << ans << "\n"
         << col << "\n"<<path[n - 1][col - 1][0];
    // for (ll i = 0; i < path[n - 1][col - 1][0].length(); i++)
    //     cout << path[n - 1][col - 1][0][i];
}