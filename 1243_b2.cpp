#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<pair<ll,ll>>v;
        ll f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i])continue;
            for(int j=i+1;j<n;j++)
            {
                if(s[j]==s[i])
                    {swap(t[i],s[j]);v.push_back({j,i});break;}
            }
            if(s[i]==t[i])continue;
            for(int j=i+1;j<n;j++)
            {
                if(t[j]==s[i])
                {
                    swap(s[j],t[j]);
                    v.push_back({j,j});
                    swap(s[j],t[i]);
                    v.push_back({j,i});
                    break;
                }
            }
            if(s[i]!=t[i]){
                cout<<"No\n";
                f=1;
                break;
            }


        }
        if(f)
        {
            continue;
        }
        else
        {
            if(v.size()>2*n){
                cout<<"No\n";continue;
            }
            cout<<"Yes\n";
            cout<<v.size()<<"\n";
            for(auto i:v)cout<<i.first+1<<" "<<i.second+1<<"\n";

        }
        

    }
}