#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll arr[100];
ll n;
ll fun(vector<bool>v)
{
    ll smoke=MAX;
    ll sum=0;
    ll ind;
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)sum+=arr[i],c++;
    }
    if(c==1)
    return 0;
    vector<bool>temp;
    for(int i=0;i<n;i++)
    {
        temp=v;
        if(v[i]==0)
        {
            temp[i]=1;
            ll x = arr[i]*((sum-arr[i]+100)%100);
            smoke = min(smoke,x + fun(temp));
        }
    }
    
    return smoke;
    
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   for(int i=0;i<n;i++)
   cin>>arr[i];
   vector<bool>v(n,0);
   cout<<fun(v);


   
}