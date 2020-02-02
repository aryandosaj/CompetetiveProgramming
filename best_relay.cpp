#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
struct dt{
    double a,b,i;string s;
};
bool comp(dt a,dt b){return a.b<b.b;}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    dt s[n];
    for(int i=0;i<n;i++)cin>>s[i].s>>s[i].a>>s[i].b,s[i].i=i;
    sort(s,s+n,comp);
    dt best[4];
    for(int i=0;i<4;i++)best[i]=s[i];
    double tim=MAX;
    string b[4];
    string ans[4];
    
    for(int i=0;i<n;i++)
    {
        double t = s[i].a;
        ll c=1;
        b[0]=s[i].s;
        for(int j=0;j<4;j++)
        {
            if(best[j].i!=s[i].i)
            {
                t+=best[j].b;
                b[c]=best[j].s;
                c++;
            }
            if(c==4)break;
        }
        if(tim>t)
        {
            tim=t;
            for(int k=0;k<4;k++)ans[k]=b[k];
        }

    }
    cout<<tim<<"\n";
    for(int i=0;i<4;i++)cout<<ans[i]<<"\n";
}