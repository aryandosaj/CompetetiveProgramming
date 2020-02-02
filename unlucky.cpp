#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll bit[1000006];
ll p[1000006];
void insert(int s)
{
    if(s==0){bit[s]+=1;return;}
    for(;s<1000006;s+=s&-s)
        bit[s]+=1;
    return;
}
ll q(int x)
{
    if(x<0)return 0;
    ll ans=0;
    for(;x>0;x-=x&-x)ans+=bit[x];
    return ans+bit[0];
}
ll u(ll a)
{
    int x=0,y=0;int d=10;
    for(int i=0;i<3;i++){
        x+=a%d;
        a/=d;
    }
    for(int i=0;i<3;i++){
        y+=a%d;
        a/=d;
    }
    return abs(x-y);
}
int main()
{
    for(int i=0;i<1000006;i++)
    {
        int g = u(i);
        insert(g);
        p[i] = (q(g-1));
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<p[n]<<"\n";
    }
}