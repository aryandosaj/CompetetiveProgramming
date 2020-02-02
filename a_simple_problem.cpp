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
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    scanf("%d",&n);
    int arr[n];
    map<int,bool>mp;
    map<int,int>mp2;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        // mp[arr[i]]++;
    }

    int sum[n];
    for(int i = 0; i < n; i++)
    {
        if(mp[arr[i]]==1)
        continue;
        mp[arr[i]]=1;
        mp2[arr[i]]++;
        for(int j = 2; j*arr[i] <=1000000 ; j++)
        {
            mp2[j*arr[i]]++;

        }
    }
    sum[0]=mp2[arr[0]];
    
    for(int i = 1; i < n; i++)
    {
        sum[i]=sum[i-1]+mp2[arr[i]];
    }
    int q;
    scanf("%d",&q);
    
    for(int i = 0; i < q; i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l!=0)
        printf("%d",(sum[r]-sum[l-1]));
        else
        printf("%d",(sum[r]));

    }
    
    
    
    
}