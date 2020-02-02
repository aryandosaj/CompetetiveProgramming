#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
string tostr(ll n)
{
    string ans="";
    while(n)
    {
        ans.push_back('0'+(n%10));
        n/=10;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int c=1;
    string ans="(";
    int f=0;
    stack<char>st;
    for(int i=s.length()-1;i>=0;i--)
    {
        st.push(s[i]);
    }
    ll b=0;
    ll f=0;
    while(!st.empty())
    {
        char c = st.top();
        st.pop();
        

    }
    
    cout<<ans;
}