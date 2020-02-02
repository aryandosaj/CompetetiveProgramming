#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
struct dt
{
    ll start, mid, stop,mm;
};
dt a[51];
dt fun(vll v)
{
    dt temp;
    temp.mm=v[0];
    temp.start = v[0];
    ll x = 0,current_max=0,max_till_now = -MAX;
    ll mm=-MAX;
    for(ll i=0;i<v.size();i++)
    {
        mm = max(mm,v[i]);
        current_max=current_max+v[i];
        current_max = max(current_max,0ll);
        max_till_now = max(max_till_now,current_max);
    }
    if(mm<0)
    temp.mm = mm;
    else
    temp.mm = max_till_now;
    for (ll i = 0; i < v.size(); i++)
    {
        x += v[i];
        temp.start = max(temp.start, x);
    }
    reverse(v.begin(), v.end());
    temp.stop = v[0];
    x = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        x += v[i];
        temp.stop = max(temp.stop, x);
    }
    temp.mid = x;
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vll arr[n];
    
    for (ll i = 0; i < n; i++)
    {
        ll l;
        cin >> l;
        for (ll j = 0; j < l; j++)
        {
            ll x;
            cin >> x;
            arr[i].push_back(x);
        }
        a[i + 1] = fun(arr[i]);
        // cout<<i+1<<" "<<a[i+1].start<<" "<<a[i+1].mid<<" "<<a[i+1].stop<<" "<<a[i+1].mm<<"\n";
    }
    ll max_sum = -MAX, cur_sum = 0,f=0,mm=-MAX;
    for (ll i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        mm = max(a[x].mm,mm);
        // if (i == 0)
        // {
            
        //     cur_sum = a[x].stop;
        //     max_sum = max(max_sum,a[x].start);
        // }
        // else
        {
            max_sum = max(max_sum, cur_sum + a[x].start);
            // max_sum = max(max_sum,a[x].start);
            cur_sum += a[x].mid;
            if(cur_sum<a[x].stop){
                if(a[x].stop>=0)
                    cur_sum = a[x].stop,max_sum = max(max_sum, a[x].stop);
                    else
                    cur_sum = 0;
            }
            
        }

        
    }
    if(max_sum>mm)
    cout << max_sum;
    else
    cout << mm;
        
    
}