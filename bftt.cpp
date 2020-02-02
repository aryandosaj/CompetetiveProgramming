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
   ll t;
   cin>>t;
   while(t--)
   {
       ll n;
       string s="";
       cin>>n;
       if(n<100)
       n=100;
        n++;
        ll c=0;
        while(n>0)
        {
            if(n%10==3)
            c++;
            s+=48+n%10;
            n/=10;
        }
        if(c>=3)
        cout<<n<<"\n";
        else
        {
            ll flag=0;
            for(ll i = 0; i < s.length(); i++)
            {
                if(s[i]<'3')
                s[i]='3',c++;
                else if(s[i]>'3')
                {
                    if(flag==0)
                    {
                        flag=1;
                        s[i]='3';
                        c++;
                    }
                    else
                    {
                        s[i]='3';c++;
                    }
                }
                if(c==3)
                {
                    break;
                }
            }
            if(flag==1)
            {
            for(ll i = 0; i < s.length(); i++)
            {
                if(s[i]!='3')
                {
                    if(s[i]!='9')
                    {s[i]++;flag=0;break;}
                    else
                    {s[i]='0';continue;}
                }
            }
            if(flag==1)
            {
                s+='1';
            }
            }
            // cout<<s<<"\n";
            for(int i = s.length()-1; i >=0; i--)
            {
               cout<<s[i];
            }
            cout<<"\n";
            
            
        }
   }
}