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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, p;
        cin >> n >> k >> p;
        ll mx = 0, mn = MAX;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }
        if (k & 1)
        {
            if (p == 0)
                cout << mx << "\n";
            else
                cout << mn << "\n";
        }
        else
        {
            ll jm=0;
            if(p==0)
            {
                for(int i=0;i<n;i++)
                {
                    if(i==0)
                    {
                        ll temp = arr[i+1];
                        jm = max(jm,temp);
                    }
                    else if(i==n-1)
                    {
                        ll temp = arr[i-1];
                        jm = max(jm,temp);
                    }
                    else
                    {
                        ll temp = min(arr[i-1],arr[i+1]);
                        jm = max(temp,jm);
                    }
                    
                }
                cout<<jm<<"\n";
            }
            else
            {
                jm=MAX;
                for(int i=0;i<n;i++)
                {
                    if(i==0)
                    {
                        ll temp = arr[i+1];
                        jm = min(jm,temp);
                    }
                    else if(i==n-1)
                    {
                        ll temp = arr[i-1];
                        jm = min(jm,temp);
                    }
                    else
                    {
                        ll temp = max(arr[i-1],arr[i+1]);
                        jm = min(temp,jm);
                    }
                    
                }
                cout<<jm<<"\n";
            }
            
        }
    }
}