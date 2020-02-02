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
ll oper[10001];
ll num[10001];
ll pre[10001];
ll n;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        oper[0] = 1;

        cin >> n;

        for (int i = 0; i < 2 * n - 1; i++)
        {
            if (i % 2 == 0)
            {
                int nn;
                cin >> nn;
                num[i / 2] = nn;
            }
            else
            {
                char c;
                cin >> c;

                if (c == '-')
                    oper[(i + 1) / 2] = -1;
                else
                    oper[(i + 1) / 2] = 1;
            }
        }
        ll ans=0;
        for(ll i = 0; i < n; i++)
        {
            if(num[i]*oper[i]>0)
            ans+=num[i]*oper[i];
            else
            {
                ll mm=num[i],ii=i;
                ll t2=num[i];
                int j=i+1;
                for( j = i+1; j < n; j++)
                {
                    t2+=num[j]*oper[j];
                    if(t2<mm)
                    {
                        mm=t2;ii=j;
                        // cout<<t2<<" ";
                    }
                }
                if(mm<=num[i])
                {
                    ans+=oper[i]*mm;i=ii;

                }

            }
                    // cout<<ans<<" ";

        }
        cout<<ans<<"\n";
        
    }
}
