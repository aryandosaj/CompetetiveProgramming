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
struct st
{
    ll val, i;
};
bool comp(st a, st b)
{
    return a.val < b.val;
}
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, s;
        cin >> n >> s;
        ll arr[n];
        ll brr[n];
        map<ll, ll> mp;
        vll v;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (mp[arr[i]] == 0)
            {
                mp[arr[i]]++;
                v.push_back(arr[i]);
            }
        }
        sort(v.begin(), v.end());

        for (ll i = 0; i < v.size(); i++)
        {
            mp[v[i]] = i + 1;
        }

        ll ans = 0;
        ll m = MAX;
        ll flag = 0;
        for (ll k = 0; k <= n; k++)
        {
            for (ll u = 0; u < n; u++)
            {
                brr[u] = 0;
            }
            ll sum = n;
            for (ll i = 0; i < n; i++)
            {
                // if(k==0) {brr[i]=0;continue;}
                vector<st> ss;
                ll pos = 0;
                ll pos2 = 0;
                for (ll j = i; j <= min(n - 1, i + k); j++)
                {
                    if (arr[i] > arr[j])
                    {
                        pos++;
                    }
                    if(k>0)
                    if (arr[i + 1] > arr[j])
                        pos2++;
                }
                ll dif = brr[i]-pos;
                // brr[i]+=dif;
                brr[i+1]=pos2+dif;
                m = min(m, brr[i]);
                sum += brr[i];
                // for(ll j = max((ll)0,i-k); j <= min(n-1,i+k); j++)
                // {
                //     if(arr[j]<arr[i])
                //     {
                //         if(brr[j]>=brr[i])
                //         {
                //             if(j<i)
                //             {
                //                 brr[i]=brr[j]+1;
                //             }
                //             else
                //             {
                //                 brr[j]=brr[i]-1;
                //                 if(brr[j]<=0)
                //                 {
                //                     flag=1;
                //                     m = min(brr[j],m);
                //                 }
                //             }
                //         }
                //     }
                // }
                // sum += brr[i];
                cout << brr[i] << " ";
            }

            // for(ll q = 0; q < n; q++)
            // {
            //     m=min(m,brr[q]);
            //     sum+=brr[q];
            // }

            if (m <= 0)
                sum += (-1 * m) * n;
            cout << sum << "\n";
            if (sum <= s)
                ans++;
            else
                break;
            m = MAX;
            flag = 0;
        }
        cout << ans << "\n";
    }
}