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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int c =0;
        if((a==0)||(b==0))
        {
            cout<<n+1<<"\n";continue;
        }
        for (int i = -n * b; i <= n * a; i++)
        {
            if (i < 0)
            {
                int x1 = abs(i) % b ;
                if(x1==0)
                {
                    cout<<i<<" ";

                    c++;continue;
                }
                int y1 = abs(i)/b+1;
                int x2 = (b-x1) % a;
                int y2 = (b-x1)/a;
                if(((x1==0)||(x2==0))&&(y1+y2)<=n)                
                {
                    cout<<i<<" ";
                    c++;continue;
                }
           }
           else 
           {
                int x1 = (i) % a ;
                if(x1==0)
                {
                    cout<<i<<" ";

                    c++;continue;
                }
                int y1 = i/a+1;
                int x2 = (a-x1) % b;
                int y2 = (a-x1)/b;
                if(((x1==0)||(x2==0))&&(y1+y2)<=n)
                {
                    cout<<i<<" ";
                    c++;continue;
                }
               
           }
        }
        // cout<<c<<"\n";
    }
}