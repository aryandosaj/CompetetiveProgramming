#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    string s;
    cin>>s;
    ll l = s.length();
    map<ll,ll> mp;
    for(ll i = 0; i < l; i++)
    {
        if(s[i]=='1')
        mp[s[i]]++;
    }
    for(ll i = 0; i < l; i++)
    {
        if(s[i]=='2')
        {
            
            for(ll i = 0; i < mp['0']; i++)
            {
                cout<<'0';
            }
            
            for(ll i = 0; i < mp['1']; i++)
            {
                cout<<'1';
            }
            mp['0']=0;
            mp['1']=0;
            cout<<'2';
            

        }
        else if(s[i]=='0')
        mp[s[i]]++;

    }
    while(mp['0']>0)
    {cout<<'0';mp['0']--;}
    while(mp['1']>0)
    {cout<<'1';mp['1']--;}
    
}