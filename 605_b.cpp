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
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
struct ab
{
    ll a,u,v,i;
    bool b;

};
bool comp(ab a,ab b)
{
    if(a.a!=b.a)
    return a.a<b.a;
    else
    return a.b>b.b;
}
bool comp2(ab a,ab b)
{
    return a.i<b.i;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,m;
   cin>>n>>m;
   ab edge[m];
   for(ll i = 0; i < m; i++)
   {
       cin>>edge[i].a>>edge[i].b;
       edge[i].i=i;
   }
   sort(edge,edge+m,comp);
    if((edge[0].b==0)||(edge[1].b==0))
    {cout<<"-1";return 0;}
    edge[0].u=1;
    edge[0].v=2;
    edge[1].u=2;
    edge[1].v=3;
    ll cy=0;
    ll p=3;
    ll cy_i=1,cy_j=3;
    ll arr[n+1];
    
    for(ll i = 0; i < n+1; i++)
    {
        arr[i]=i+1;
    }
    
    arr[1]=2;
    for(ll i = 2; i <m; i++)
    {
        if(edge[i].b==0)
        {
            if(cy+1<=(p*(p-1)/2)-(p-1))
            {
                ll j=1;
                while(arr[j]>=p)
                {
                    j++;
                }
                edge[i].u=j;
                edge[i].v=++arr[j];
                // if(cy_j<=p)
                // {
                //     edge[i].u=cy_i;
                //     edge[i].v=cy_j;
                //     cy_j++;
                //     if(cy_j>p)
                //     {
                //         cy_i=1;
                //     }
                // }
                // else
                // {
                //     cy_i++;
                //     cy_j=cy_i+2;
                //     edge[i].u=cy_i;
                //     edge[i].v=cy_j++;
                // }
                cy++;
            }
            else
            {
                cout<<"-1";return 0;
            }
        }
        else
        {
            edge[i].u=p;
            edge[i].v=++p;
        }
    }
    
    
    
    sort(edge,edge+m,comp2);
    
    for(ll i = 0; i < m; i++)
    {
        cout<<edge[i].u<<" "<<edge[i].v<<"\n";
    }
    

}