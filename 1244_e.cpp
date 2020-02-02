#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll arr[100005];
ll post[100005];
ll pre[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    ll ans = MAX;
    {
        ll po = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            po += arr[i];
            post[i] = po - (n - i) * arr[i];
        }
        reverse(post, post + n);
        ll pre = 0;
        for (int i = 0; i < n; i++)
        {
            pre += arr[i];
            ll val = k - (arr[i] * (i + 1) - pre);
            ll p = (upper_bound(post, post + n, val) - post);
            p--;
            if (p < 0)
                continue;
            ll lef = val - post[p];
            ll num = lef / (p + 1);
            // cout << pre << " " << val << " " << p << " " << lef << " " << num << "\n";

            ans = min(ans, arr[n - p - 1] - arr[i] - num);
        }
    }
    {
        ll t=0;
        for(int i=0;i<n;i++)
        {
            t+=arr[i];
            pre[i] = arr[i]*(i+1)-t;
        }
        t=0;
        for(int i=n-1;i>=0;i--)
        {
            t+=arr[i];
            ll val = k - (t-arr[i]*(n-i));
            ll p = upper_bound(pre,pre+n,val)-pre;
            p--;
            if(p<0)continue;
            ll lef=(val-pre[p]);
            ll num = lef/(p+1);
            // cout <<arr[p]<< " "<< t << " " << val << " " << p << " " << lef << " " << num << "\n";

            ans = min(ans,arr[i]-arr[p]-num); 
        }
    }
    if (ans < 0)
        cout << "0";
    else
        cout << ans;
}