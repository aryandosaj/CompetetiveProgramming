#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll dp[100005][10];
ll fff(string s)
{
    ll sum=0;
    sum=(sum+((s[0]-'0')*power(10,s.length()-1,MAX))%MAX)%MAX;
    for(ll i=1;i<s.length();i++)
    {
        if(s[i]!=s[i-1])
        sum=(sum+((s[i]-'0')*power(10,s.length()-1-i,MAX))%MAX)%MAX;
    }
    return sum;
}
ll rec(ll ind , ll last)
{
    if(ind<0)return 0;
    if(dp[ind][last]!=-1)return dp[ind][last];
    ll sum=0,mi = 0;
    for(ll i=9;i>=0;i--)
    {
        if(last!=i)
        sum =(sum + (i*power(10,2*ind,MAX))%MAX+rec(ind-1,i))%MAX;
        else
        sum=(sum+rec(ind-1,i))%MAX; 
    }
    return dp[ind][last] = sum;

}
string fun(string r)
{
    if(r.length()==1&&r[0]=='0')return r;
    ll i=0;
    while(1)
    {
        if(r[i]!='0'){r[i]--;return r;}
        else r[i]='9',i++;
    }
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   cin>>t;
   for(ll i=0;i<100005;i++)for(ll j=0;j<10;j++)dp[i][j]=-1;
   while(t--)
   {
       ll nl,nr;
       string l,r,z;
       cin>>nl>>z;
       
        cin>>nr>>r;
        reverse(z.begin(),z.end());
        reverse(r.begin(),r.end());
        ll a1 = 0;
        ll temp=0;
        ll num = 0;
        ll last=-1;
        l = fun(z);
        // cout<<l<<"\n";
        for(ll i=l.length()-1;i>=0;i--)
        {
            ll dig = l[i]-'0';
            
            for(ll j=dig-1;j>=0;j--)
            {
                if(last!=j)
                a1=(a1+(j*power(10,2*i,MAX))%MAX+rec(i-1,j)+(num*power(10,i,MAX))%MAX)%MAX;
                else
                a1=(a1+rec(i-1,j)+(num*power(10,i,MAX)%MAX))%MAX;
            }
            if(last!=dig)
                num=(num+(dig*power(10,i,MAX))%MAX)%MAX;
            last = dig;
        }
        
        ll ans1 = (a1+num)%MAX;
        // cout<<a1<<"\n";
        a1 = 0;
        temp=0;
        num = 0;
        last=-1;
        
        l=r;
        for(ll i=l.length()-1;i>=0;i--)
        {
            ll dig = l[i]-'0';
            
            for(ll j=dig-1;j>=0;j--)
            {
                if(last!=j)
                a1=(a1+(j*power(10,2*i,MAX))%MAX+rec(i-1,j)+(num*power(10,i,MAX))%MAX)%MAX;
                else
                a1=(a1+rec(i-1,j)+(num*power(10,i,MAX)%MAX))%MAX;
            }
            if(last!=dig)
                num=(num+(dig*power(10,i,MAX))%MAX)%MAX;
            last = dig;
        }
        // num = fff(l);
        ll ans2 = a1+num;
        cout<<(ans2-ans1+MAX)%MAX<<"\n";
        
        // cout<<a1<<"\n";
        
   }
}