#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pint pair<int, int>
#define pb push_back
#define F first
#define S second
#define I insert
#define vint vector<int>
int power(int a, int b, int mod)
{
    int c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int n;
int dp[5001];
int w[5001];
int h[5001];
int nex[5001];
vector <int> v;
int rec(int ind)
{
    if (dp[ind])
    {
        return dp[ind];
    }
    else
    {
        
        for(int i = 1; i <= n; i++)
        {
            if((h[i]>h[ind])&&(w[i]>w[ind])&&(rec(i)>=dp[ind]))
            {
                dp[ind]=dp[i]+1;
                nex[ind]=i;
            }
        }
        return dp[ind];
        
        
    }
}
int main()
{

    cin >> n;
    
    for(int i = 0; i < 5001; i++)
    {
        dp[i]=0;
        nex[i]=-1;
    }
    
    for (int i = 0; i <= n; i++)
    {
        cin >>w[i]>>h[i];
    }
    cout<<rec(0)<<"\n";
    int i = nex[0];
    while(i!=-1)
    {
        cout<<i<<" ";
        i=nex[i];
    }
}