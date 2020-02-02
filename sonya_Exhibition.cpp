#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n,m;
    cin>>n>>m;
    ll a,b;
    
    for(ll i = 0; i < m; i++)
    {
        cin>>a>>b;
    }
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        cout<<"1";
        else
        cout<<"0";
    }
    
}