#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;       
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define deb(x) cout << #x << "  " << x << endl;

//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    os << "[ ";
    for (auto v : V)
        os << v << " ";
    os << "]";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S)
{
    os << "{ ";
    for (auto s : S)
        os << s << " ";
    return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M)
{
    os << "{ ";
    for (auto m : M)
        os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}
string arr[100005][5];
ll a[200005];
struct dt{
    string name,number;
    ll id,l,r,ind;
};
vector<dt>v;
vector<dt>adj1[200005];
vector<dt>adj2[200005];
ll pnum[200005];
ll conv(string s)
{
    ll ans=0;
    ans = ((s[0]-'0')*10 + (s[1]-'0'))*3600 +((s[3]-'0')*10 + (s[4]-'0'))*60 + ((s[6]-'0')*10 + (s[7]-'0')); 
    return ans;
}
bool comp(dt a,dt b)
{
    return a.r<b.r;
}
ll fun(ll ind)
{
    dt temp;
    temp.l = conv(arr[ind][2]);
    temp.r = conv(arr[ind][3]) + conv(arr[ind][4]);
    temp.number = arr[ind][1];
    temp.name = arr[ind][0];
    temp.ind = ind;
    adj1[temp.l].pb(temp);
    adj2[temp.r].pb(temp);

    v.pb(temp);

}
dt fun2(ll ind)
{
    dt temp;
    temp.l = conv(arr[ind][2]);
    temp.r = conv(arr[ind][3]) + conv(arr[ind][4]);
    temp.number = arr[ind][1];
    temp.name = arr[ind][0];
    temp.ind = ind;
    return temp;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        v.clear();
        f(0,100005){
            adj1[i].clear();
            adj2[i].clear();
        }
        cin>>n;
        f(0,n)
        {
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3]>>arr[i][4];
            fun(i);
        }
        sort(v.begin(),v.end(),comp);
        ll c=0;
        set<ll>free;
        f(0,160005)
        {
            // cout<<c<<"\n";
            // return 0;
            for(auto j:adj2[i])
            {   
                free.insert(pnum[j.ind]);
            }
            for(auto j:adj1[i])
            {   
                if(free.size()>0)
                {
                    ll x = *free.begin();
                    pnum[j.ind]=x;
                    free.erase(x);
                    
                }
                else
                {
                    c++;
                    pnum[j.ind]=c;
                }
            }
            
        }
        
        cout<<c<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<pnum[i]<<"\n";
        }
    }
}