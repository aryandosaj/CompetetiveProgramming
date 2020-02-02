#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,k;
   cin>>n>>k;
   ll arr[n];
   int sum=0;
   for(int i=0;i<n;i++)
   cin>>arr[i],sum+=arr[i];
   if(2*k>=n)return sum;
   int w=0;
   for(int i=0;i<k;i++)
   w+=arr[i];
   int temp=w;
   int start=0,end=k-1;
   for(int i=k;i<n;i++)
   {
       w-=arr[i-k];w+=arr[i];
       if(w>temp)
       {
           temp=w;
           start=i-k+1,end=i;
       }
   }
    // cout<<temp;
    end++;
   while(end<n)
        arr[start++] = arr[end];
        // cout<<start<<" "<<end;
    w=0;
    for(int i=0;i<k;i++)w+=arr[i];
    int temp2=w;
    for(int i=k;i<start;i++)
    {
        w-=arr[i-k];
        w+=arr[i];
        if(w>temp2)temp2=w;
    }    
    cout<<temp+temp2;

}