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
    ll n;string s;
    cin>>n>>s;
    int z=0,o=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='z')z++;
        if(s[i]=='n')o++;
    }
    for(int i=0;i<o;i++)cout<<"1 ";
    for(int i=0;i<z;i++)cout<<"0 ";
}   