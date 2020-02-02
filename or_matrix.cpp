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
// ll arr[1000][1000];
// int ans[1000][1000];
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll r[n];
        ll c[m];
        string arr[n];
        for (ll i = 0; i < n; i++)
        {
            r[i] = 0;
        }

        for (ll i = 0; i < m; i++)
        {
            c[i] = 0;
        }

        ll flag = 0;
        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
            for (ll j = 0; j < m; j++)
            {
                
                if (arr[i][j] == '1')
                {
                    flag = 1;
                    r[i] = 1;
                    c[j] = 1;
                }
                
            }
        }
        if (flag == 0)
        {
            for (ll i = 0; i < n; i++)
            {

                for (ll j = 0; j < m; j++)
                {
                    //    cin>>arr[i][j];
                    cout << "-1 ";
                }
                cout<<"\n";
            }
            continue;
        }
        for (ll i = 0; i < n; i++)
        {

            for (ll j = 0; j < m; j++)
            {
                //    cin>>arr[i][j];
                if (arr[i][j] == '1')
                {
                    // ans[i][j] = 0;
                    cout<<"0 ";
                }
                else
                {
                    int temp;
                    if (r[i] == 1)
                        temp = 1;
                    else if (c[j] == 1)
                        temp = 1;
                    else
                        temp = 2;
                        cout<<temp<<" ";
                }
            }
            cout<<"\n";
        }
    }
}