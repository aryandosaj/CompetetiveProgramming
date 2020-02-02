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
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,m,q;
   cin>>n>>m>>q;
   string s,t;
   cin>>s>>t;
    ll arr[n];
    
    for(ll i = 0; i < n; i++)
    {
        arr[i]=0;
    }
    
    ll c=0;
    for(ll i = 0; i <= n-m; i++)
    {
        
        ll flag=0;
        for(ll k = 0; k < m; k++)
        {
            if(s[i+k]!=t[k])
            {
                flag=1;
                break;
            }
            
        }
        if(flag==0)
        {
            c++;
            if(i>0)
            arr[i+m-1]=arr[i-1+m-1]+1;
            else
            arr[i+m-1]++;
        }
        else if(i>0)
        arr[i+m-1]=arr[i-1+m-1];        
    }
    
    // for(int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }cout<<"\n";
    
    for(ll i = 0; i < q; i++)
    {
        ll l,r;
        cin>>l>>r;
        l--;r--;
        if(r-l+1<m)
        {cout<<"0\n";continue;}
        if(l!=0)
        cout<<(arr[r]-arr[l-1+m-1])<<"\n";
        else
        cout<<arr[r]<<" "<<"\n";
    }
    
    
}