#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll arr[300005];
vector<int>bit[33];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>arr[i];
       for(int j=0;j<=30;j++)
       {
           if(arr[i]&(1<<j))
           bit[j].push_back(i);
       }
    }
    int flag=0;
    map<int,int>mp;
    int ans=0;
    for(int i=30;i>=0;i--)
    {
        if(bit[i].size()>=2){
            if(flag==0){
                for(auto j:bit[i])
                {
                    mp[j]=1;
                }
                flag=1;
                ans = (1<<i);
            }
            else 
            {
                map<int,int>temp;
                for(auto j:bit[i])
                {
                    if(mp[j])
                    {
                        temp[j]=1;
                    }
                }
                if(temp.size()>=2)
                {
                    mp=temp;
                    ans = ans|(1<<i);
                }
            }
        }
    }
    cout<<ans;

   
}