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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll oper[n];
        oper[0] = 1;
        ll num[n];
        ll sum = 0;
        ll pre[n];
        for(int i = 0; i < 2*n-1; i++)
        {
            if (i % 2 == 0)
            {
                int nn;
                cin>>nn;
                num[i / 2] = nn;
                sum += num[i / 2] * oper[i / 2];
                pre[i / 2] = sum;
            }
            else
            {
                char c;
                cin>>c;

                if (c == '-')
                    oper[(i + 1) / 2] = -1;
                else
                    oper[(i + 1) / 2] = 1;
            }
        }
        
        ll ans=0;
        sum=0;
        for (ll i = 0; i < n; i++)
        {
            sum=num[i];
            for (ll j = i + 1; j < n; j++)
            {
                for (ll k = j; k <=j; k++)
                {
                    sum+=num[k]*oper[k];
                }
                sum*=oper[i];
                if(i>0)
                sum+=pre[i-1]+pre[n-1]-pre[j];
                else
                sum+=pre[n-1]-pre[j];
                // cout<<sum<<" ";
                ans=max(ans,sum);
                sum=num[i];
            }
        }
        cout<<ans<<"\n";

    }
}