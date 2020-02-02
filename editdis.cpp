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
    string s;
    cin >> s;
    int c = 0;
    int l = s.length();
    for (int i = 0; i < l; i++)
        if (s[i] == '1')
            c++;
    if (l & 1)
    {
        if (c > (l / 2))
        {
            for (int i = 0; i < l; i++)
                cout << "0";
        }
        else
        {
            for (int i = 0; i < l; i++)
                cout << "1";
        }
    }
    else
    {
        if (c == (l / 2))
        {
            if(s[0]=='1')
            {
                cout<<"0";
                for(int i=1;i<l;i++)cout<<"1";
            }
            else
            {
                cout<<"1";
                for(int i=1;i<l;i++)cout<<"0";
            }
            
        }
        else
        {
            if (c > (l / 2))
            {
                for (int i = 0; i < l; i++)
                    cout << "0";
            }
            else
            {
                for (int i = 0; i < l; i++)
                    cout << "1";
            }
        }
    }
}