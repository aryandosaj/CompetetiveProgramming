#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int ii=1, jj=1;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            swap(s[i], s[j]);
            int st=0,c=0,start=0;
            for(int k=0;k<n;k++)
            {
                if(s[k]=='(')st++;
                if(s[k]==')')st--;
                if(st==start)c++;
                if(st<start)c=1,start=st;
            }
            swap(s[i], s[j]);   
            if(st==0&&ans<c)ans=c,ii=i+1,jj=j+1;
        }
    }
  
        cout << ans << "\n"
             << ii  << " " << jj ;
  
}