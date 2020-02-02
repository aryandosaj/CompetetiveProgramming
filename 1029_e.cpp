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
ll no_of_bit(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ans += n % 2;
        n /= 2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll arr[n+1];
    ll brr[n+1];
    ll sum=0;
    ll m_b=0;
    ll pre_sum[n+1];
    pre_sum[0]=0;
    ll e=1,o=0;

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        brr[i] = no_of_bit(arr[i]);
        sum+=brr[i];
        pre_sum[i]=sum;
        if(pre_sum[i]%2==0)
        {
            e++;
        }
        else
        {
            o++;
        }
    }
    
    // for(ll i = 1; i <= n; i++)
    // {
    //     cout<<brr[i]<<" ";
    // }
    // cout<<"\n"; 
   
    ll ans=e*(e-1)/2+o*(o-1)/2;
    
    for(ll i = 1; i <= n; i++)
    {
        
        ll mm=brr[i];
        ll su = brr[i];
        for(ll j=0;j<125;j++)
        {
            cout<<"here";
            if(i+j>n)
            break;
            mm = max(mm,brr[i+j]);
            su+=brr[i];
            if(mm>su/2)
            ans--;
        }
    }
    cout<<ans;    
}