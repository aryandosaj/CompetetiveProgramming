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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    ll e=0,o=0;
    ll ea=0,oa=0;
    ll eb=0,ob=0;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='a')
        {
            if(i&1){oa++;o+=oa;e+=ea;}
            else {ea++;o+=ea;e+=oa;}
        }
        else
        {
            if(i&1){ob++;o+=ob;e+=eb;}
            else {eb++;o+=eb;e+=ob;}
        }
        
    }
    

    
    cout << e << " " << o;
}