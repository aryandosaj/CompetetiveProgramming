#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll n;
string s;
ll dp[2001][2001];
bool vowel(char c)
{
    if((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'))
    return 1;
    return 0;
}
ll rec(ll i,ll pos)
{
    if(i==n)return 1;
    if(dp[i][pos]!=-1)return dp[i][pos];
    ll ans=0;
    if(pos&1)
    {
        if(vowel(s[i])){
            ans+=rec(i+1,pos+1);
        }
        ans+=rec(i+1,pos);
    }
    else
    {
        ans=rec(i+1,pos+1)+rec(i+1,pos);
    }
    ans = ans%MAX;
    return dp[i][pos]=ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<2001;i++)for(int j=0;j<2001;j++)dp[i][j]=-1;
        cin>>n>>s;
        cout<<(rec(0,0)-1+MAX)%MAX<<"\n";
        
    }
}