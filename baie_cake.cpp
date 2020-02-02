#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
struct dt
{
    ll r, h, v;
    
};
map <ll,ll> mp;
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    //code start here
    // int brr[]={1,2,3,4,5,6,7,10};
    // cout<<((upper_bound(brr,brr+8,9)-brr));
      
    ll n;
    cin >> n;
    dt arr[n];
    mp[0]=0;
    ll m=0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].r >> arr[i].h;
        arr[i].v =  arr[i].r * arr[i].r * arr[i].h;
        
        map<ll,ll>::iterator p = mp.lower_bound(arr[i].v);
        // cout<<((--p)->second)<<" ";
        p--;
        mp[arr[i].v]=max(mp[arr[i].v],((p)->second+arr[i].v));
        m=max(m,mp[arr[i].v]);
        map<ll,ll>::iterator it = mp.upper_bound(arr[i].v);
		while(it!=mp.end()&&it->second<mp[arr[i].v])it=mp.erase(it);

    }
    printf("%0.10f",3.1415926535897*m);

    
}