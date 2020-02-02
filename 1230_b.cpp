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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    if (k == 0)
    {
        cout << s << "\n";
        return 0;
    }
    if(s.size()==1)
    {
        cout<<"0";
        return 0;   
    }
    else
    {
        if (s[0] != '1')
        {
            s[0] = '1';
            k--;
        }

        for (int i = 1; i < s.length(); i++)
        {
            if (k == 0)
                break;
            if (s[i] == '0')
                continue;
            else
            {
                s[i] = '0';
                k--;
            }
        }

        cout << s << "\n";
    }
}