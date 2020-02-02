#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
vector<int>arr;
int t;
int fun(vector<vector<int>> &dp,int mask,int i,int n,int last)
{
    
    if(i==n)
    return 0;
    if(dp[mask][last]!=-1)return dp[mask][last];
    int sum=10000000;
    for(int j=0;j<n;j++)
    {
    
        if((abs(last-arr[j])<=t) &&((mask&(1<<j))==0))
        sum = min(sum,fun(dp,mask|(1<<j),i+1,n,arr[j])+abs(arr[i]-arr[j]));
        
    }
    cout<<mask<<" "<<last<<" "<<sum<<"\n";
    return dp[mask][last]=sum;
}
int MinAdjustmentCost(vector<int> &A, int target) {
    // write your code here
    arr=A;
    t=target;
    int n = A.size();
    int m = (1<<n);
    int mm = *max_element(A.begin(),A.end());
    vector<int>temp2(mm+1,-1);
    vector<vector<int>> dp(m,temp2);
    int mask=0;
    int sum=10000000;
    for(int j=0;j<n;j++)
    {
        sum = min(sum,fun(dp,mask|(1<<j),1,n,arr[j])+abs(arr[0]-arr[j]));
    }
    return sum/2;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   vector<int>v;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
   int target;
   cin>>target;
   cout<<MinAdjustmentCost(v,target);
   
}
