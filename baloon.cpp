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
    ll n;
    cin>>n;
    ll arr[n];
    ll sum=0;
    for(ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(n==1)
    {cout<<"-1";return 0;}
    if(sum%2==1)
    {
        cout<<"1\n";
        cout<<"1";
        return 0;
    }
    if(n==2)
    {
        if(arr[0]==sum/2)
        {
            cout<<"-1";
            return 0;
        }
    }
    if(arr[0]==sum/2)
    {
        cout<<"1\n";
        cout<<"2";
    }
    else
    {
        cout<<"1\n";
        cout<<"1";
    }
}
