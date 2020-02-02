#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
#define vpll vector<pll>

ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
int main()
{
    ll n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    ll l = s.size();
    ll flag=0,t=0;
    for(ll i = 0; i < l; i++)
    {
        if((flag==0)&&(s[i]=='0'))
        {
            t++;
            flag=1;

        }
        if((flag==1)&&(s[i]=='1'))
        {
            flag=0;
        }

    }
    if(x>y)
    {
        cout<<(t*y);
    }
    else
    {
        if(t>0)
        cout<<((t-1)*x+y);
        else
        cout<<"0";
    }
    
}