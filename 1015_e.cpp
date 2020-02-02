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
int from_left[1000][1000];
int from_right[1000][1000];
int from_bottom[1001][1001];
int from_top[1001][1001];

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m;
   cin>>n>>m;
   string s[n];
   vector <int> ii;
   vector <int> jj;
   for(int i = 0; i < n; i++)
   {
       cin>>s[i];
   }
   if((s[0][0]=='*')||(s[n-1][0]=='*')||(s[0][m-1]=='*')||(s[n-1][m-1]=='*'))
   {cout<<"-1";return 0;}
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(s[i][m-j-1]=='.')
                from_left[i][m-j-1]=0;
            else if(j!=0)
                from_left[i][m-j-1] = from_left[i][m-j]+1; 
            else
                from_left[i][m-j-1] = 1;
            if(s[i][j]=='.')
                from_right[i][j]=0;
            else if(j!=0)
                from_right[i][j] = from_right[i][j-1]+1; 
            else
                from_right[i][j]=1;
            if(s[i][j]=='.')
                from_bottom[i][j]=0;
            else if(i!=0)
                from_bottom[i][j] = from_bottom[i-1][j]+1; 
            else
                from_bottom[i][j]=1;
            if(s[n-i-1][j]=='.')
                from_top[n-i-1][j]=0;
            else if(i!=0)
                from_top[n-i-1][j] = from_top[n-i][j]+1; 
            else
                from_top[n-i-1][j]=1;
        }
        
        
        
    }
    int ans=0;
    vector <int> siz;
    for(int i = 1; i < n-1; i++)
    {
        for(int j = 1; j < m-1; j++)
        {
            
            int temp=min(from_bottom[i][j],min(from_left[i][j],min(from_right[i][j],from_top[i][j])));
            temp--;
            if(temp>0)
            {ans++;ii.push_back(i+1);jj.push_back(j+1);siz.push_back(temp);}
        }
        
    }
    string ch[n];
    ch[0]=".";
    for(int i = 1; i < m; i++)
    {
        ch[0]+=".";
    }
    
    for(int i = 0; i < n; i++)
    {
        ch[i]=ch[0];
    }
    for(int i = 0; i < ans; i++)
    {
        int sss=siz[i];
        while(sss>0)
        {
            ch[ii[i]+sss-1][jj[i]-1]='*';
            ch[ii[i]-sss-1][jj[i]-1]='*';
            ch[ii[i]-1][jj[i]+sss-1]='*';
            ch[ii[i]-1][jj[i]-sss-1]='*';
            sss--;
        }
        ch[ii[i]-1][jj[i]-1]='*';
    }
    for(int i = 0; i < n; i++)
    {
        if(ch[i].compare(s[i])!=0)
        {
            cout<<"-1";return 0;
        }
    }
    
    cout<<ans<<"\n";
    for(int i = 0; i < ans; i++)
    {
        cout<<ii[i]<<" "<<jj[i]<<" "<<siz[i]<<"\n";
    }
    
    
    
}