#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,x=0;
    cin>>t;
    while(t--)
    {x++;
        string s;ll n;
        cin>>n>>s;
        cout << "Case #" << x << ": ";
        for(ll i=0;i<s.length();i++)
        if(s[i]=='E')cout<<'S';else cout<<'E';
        cout<<"\n"; 
    }
}