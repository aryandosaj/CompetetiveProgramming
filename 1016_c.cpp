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
ll n;
ll arr[2][3 * 100000 + 1];
ll sum0[3 * 100000 + 1];
ll sum1[3 * 100000 + 1];
ll sum[2 * 3 * 100000 + 2];
ll pre_up[2 * 3 * 100000 + 2];
ll pre_down[2 * 3 * 100000 + 2];
ll rec(ll i, ll j,ll t)
{
    if(j==(n-1))
    {
        return (t+1)*arr[i^1][j]+t*arr[i][j];
    }
    if (i == 0)
    {
        ll a;
        if(j>0)a = pre_up[2*n-1-j]-pre_up[j-1] + (t-j)*(sum[2*n-1-j]-sum[j-1]);
        else a=pre_up[2*n-1-j] + (t-j)*(sum[2*n-1-j]-sum[j-1]);
        return max(a,t*arr[i][j]+(t+1)*arr[i^1][j]+rec(i^1,j+1,t+2));
    }
    else
    {
        ll a;
        a = pre_down[2*n-1-j]-pre_down[j-1] + (t-j)*(sum[2*n-1-j]-sum[j-1]);
        return max(a,arr[i][j]*t+(t+1)*arr[i^1][j]+rec(i^1,j+1,t+2));

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < 2; i++)
    {
        ll s = 0;
        ll ss = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            ss += arr[i][j];

            if (i == 0)
                sum[j] = ss, s += arr[i][j] * j, pre_up[j] = s, sum0[j] = ss;
            else
                s += arr[i][j] * j, sum1[j] = ss, pre_down[j] = s;
            //    s+=(2*n-1-j)*arr[i][j],pre_up[i]=;
        }
        ss = 0;
        s = 0;
    }

    for (ll i = n; i < 2 * n; i++)
    {
        pre_up[i] = pre_up[i - 1] + arr[1][2 * n - 1 - i] * i;
        pre_down[i] = pre_down[i - 1] + arr[0][2 * n - 1 - i] * i;
        sum[i] = sum[i - 1] + arr[1][2 * n - 1 - i];
    }
    cout<<rec(0,0,0);
}