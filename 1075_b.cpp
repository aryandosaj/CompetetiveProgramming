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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll arr[n + m];
    ll brr[n + m];
    ll ans[n + m];

    for (ll i = 0; i < n + m; i++)
    {
        ans[i] = 0;
    }

    vll pos;
    for (ll i = 0; i < n + m; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n + m; i++)
    {
        cin >> brr[i];
        if (brr[i] == 1)
            pos.push_back(i);
    }
    
    ans[pos[0]]=pos[0];
    for (ll i = 1; i < pos.size(); i++)
    {
        //    ans[i-1]+=(((pos[i]-pos[i-1]-1)%2)==0)?(pos[i]-pos[i-1]-1)/2:(pos[i]-pos[i-1]-1)/2+1;
        //    ans[pos[i]]+=(pos[i]-pos[i-1]-1)/2;
        ll temp = arr[pos[i-1]];
        if(((arr[pos[i]]-arr[pos[i-1]]-1)%2)==0)
            temp+=(arr[pos[i]]-arr[pos[i-1]]-1)/2;
        else
            temp+=(arr[pos[i]]-arr[pos[i-1]]-1)/2+1;
        // cout<<temp<<"==";
        for (ll j = pos[i-1] + 1; j < pos[i]; j++)
        {
            if(arr[j]<=temp)
            ans[pos[i-1]]++;
            else
            ans[pos[i]]++;
        }
        
    }
    ans[pos[pos.size()-1]] += (n + m - pos[pos.size()-1] - 1);
    // cout<<ans[0]<<"==";


    for (ll i = 0; i < n + m; i++)
    {
        if (brr[i])
            cout << ans[i] << " ";
    }
}