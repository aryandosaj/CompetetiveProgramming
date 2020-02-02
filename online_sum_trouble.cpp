#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
using namespace __gnu_pbds; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set; 

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q,m1,m2;
    new_data_set p;
    ll last=0;
    cin>>q>>m1>>m2;
    while(q--)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            ll a,b;
            cin>>a>>b;
            a = (a+last)%m1+1;
            b = (b+last)%m2+1;
            p.erase(a);
            p.insert(b);
        }
    }

}