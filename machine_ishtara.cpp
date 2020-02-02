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
    cin>>t;
    while(t--)
    {
        string s, s2,s3;
        cin >> s;
        s = "0" + s + "0";
        s3 = s;s2=s;
        ll p;
        cin >> p;
        ll mod = -1;
        ll flag=0;
        for (ll i = 1; i <= p; i++)
        {

            for (ll j = 1; j < 11; j++)
            {
                if (s[j - 1] == s[j + 1])
                    s2[j] = '0';
                else
                    s2[j] = '1';
                    if(i==p)
                   cout<<s2[j];
                //    cout<<s2[j];
            }
            if(i==p)
                {flag=1;cout<<"\n";break;}
            if (s3.compare(s2) == 0)
            {
                mod = i;
                break;
            }
            //    cout<<"\n";
            s = s2;
        }
        if(flag==1)
        continue;
        p = p % mod;
        s = s3;
        if(p==0)
        {
            
            for(ll i = 1; i < 11; i++)
            {
                cout<<s2[i];
            }
            cout<<"\n";
            continue;
            
        }
        // cout<<mod<<"\n";
        for (ll i = 0; i < p; i++)
        {

            for (ll j = 1; j < 11; j++)
            {
                if (s[j - 1] == s[j + 1])
                    s2[j] = '0';
                else
                    s2[j] = '1';
                    if(i==p-1)
                   cout<<s2[j];
            }

            //    cout<<"\n";
            s = s2;
        }
        cout<<"\n";
    }
}