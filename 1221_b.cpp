#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    cin>>s[i];
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&1){
            if(j&1)cout<<"W";
            else cout<<"B";
            }
            else
            {
                if(j&1)cout<<"B";
            else cout<<"W";    
            }
            // if(s[i][j]=='W')
            // {
            //     ll x=1,y=2;
            //     if((x+i<n&&y+j<n)&&s[i+x][j+y]=='B')ans++;
            //     if((i-x>=0&&j-y>=0)&&s[i-x][j-y]=='B')ans++;
            //     if((i+x<n&&j-y>=0)&&s[i+x][j-y]=='B')ans++;
            //     if((i-x>=0&&y+j<n)&&s[i-x][j+y]=='B')ans++;
            //     x=2;y=1;
            //     if((x+i<n&&y+j<n)&&s[i+x][j+y]=='B')ans++;
            //     if((i-x>=0&&j-y>=0)&&s[i-x][j-y]=='B')ans++;
            //     if((i+x<n&&j-y>=0)&&s[i+x][j-y]=='B')ans++;
            //     if((i-x>=0&&y+j<n)&&s[i-x][j+y]=='B')ans++;
            // }
        }
        cout<<"\n";
    }
    // cout<<ans;
}   