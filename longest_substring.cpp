#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n,k;
    string s;
    cin>>n>>k>>s;
    ll del=0,ans=0,a=0,b=0;
    
    for(ll i = 0; i < n; i++)
    {
        if(s[i]=='a')
        a++;
        else
        b++;
        if(min(a,b)<=k)
        ans=max(ans,a+b);
        else
        {
            del++;
            if(s[del-1]=='a')
            a--;
            else
            b--;
        }
    }
    cout<<ans;
    
}