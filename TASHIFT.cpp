#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int lps[3000006];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
    int n;
    cin>>n;
    string a,b,s;
    cin>>a>>b;
    s = a+" "+b+b;
    int ind,val;
    ind=0,val=0;
    for(int i=1;i<3*n+1;i++)
    {
        int x = lps[i-1];
        while(x>0&&s[x]!=s[i])
            x = lps[x-1];
        if(s[x]==s[i])
        lps[i] = x+1;
        else
        lps[i]=0;
        if(val<lps[i]&&i>n)
        {
            val = lps[i];
            ind = i-n;
        }
        // cout<<lps[i]<<" ";
    }
    // cout<<ind<<" "<<val<<"\n";
    if(val>=n){
        cout<<"0";return 0;
    }
    int ans = ind-val;
    cout<<ans;

    

}