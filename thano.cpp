#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n], pre[n];
        pre[0] = 0;
        unordered_map<ll,vll>mp;
        mp[0].push_back(0);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i != 0)
                pre[i] = pre[i - 1] ^ arr[i];
            else
                pre[i] = arr[i];
            mp[pre[i]].push_back(i+1);
        }
    ll ans=0;
    ll temp=0;
        for(auto i:mp)
        {
            //  cout<<i.first<<" "<<i.second.size()<<"\n";
             temp=0;
            for(ll j=1;j<i.second.size();j++)
            {
                temp+=abs(i.second[j]-i.second[0]);
            }
            ans+=temp;
            ll last=temp;
            for(ll j=1;j<i.second.size()-1;j++)
            {
                last=(last-abs(i.second[j]-i.second[j-1])*(i.second.size()-j));
                ans+=last;
            }
            ll nn=i.second.size();
            ans-=((nn)*(nn-1))/2;
        }
        cout<<ans<<"\n";
    }
}