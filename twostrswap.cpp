#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    ll c=0;
    for(ll i = 0; i < n/2; i++)
    {
        map <ll,ll> mp;
        mp[a[i]]++;
        mp[b[i]]++;
        mp[b[n-i-1]]++;
        mp[a[n-i-1]]++;
        // cout<<mp[b[i]]<<" "<<mp[b[n-i-1]];
        if(b[i]==b[n-i-1])
        {
            if(a[i]!=a[n-i-1])
            c++;
        }
        else
        {
            if((mp[b[i]]>=2)&&(mp[b[n-i-1]]>=2))
            {
                // cout<<"here";
                continue;
            }
            else
            {
                if((mp[b[i]]>=2))
                {
                    c++;
                }
                else if((mp[b[n-i-1]]>=2))
                {
                    c++;
                }
                else
                c+=2;
            }
        }

    }
    if(n%2==1)
    {
        if(a[n/2]!=b[n/2])
        {
            c++;
        }
    }
    cout<<c;
    
}