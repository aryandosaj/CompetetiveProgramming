#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin>>q;
    while(q--)
    {
        ll c,m,n;
        cin>>c>>m>>n;
        ll s = c+n+m;
        ll h = min(c,m);
        if(h*3<=s)
        {
            cout<<h<<"\n";
        }
        else
        {
            cout<<s/3<<"\n";            
        }
        
    }
}    