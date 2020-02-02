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

struct dt
{
    char a;
    ll ind;
};
struct d
{
    ll s;
    ll e;
};
bool comp(d a, d b)
{
    return a.s < b.s;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    string s;
    cin >> s;
    stack<dt> st;
    ll count = 0, flag = 0;
    ll m = 0;
    map<ll, ll> mp;
    vector<d> v;
    // map<ll, ll> start;
    // map<ll, ll> end;
    for (ll i = 0; i < s.length(); i++)
    {
        if (st.empty())
        {
            if (s[i] == '(')
                st.push({s[i], i});
            continue;
        }
        if (s[i] == ')')
        {
            v.push_back({st.top().ind, i});
            st.pop();
        }
        else
        {
            st.push({s[i], i});
        }
    }
    ll arr[s.length()+2];
    sort(v.begin(),v.end(),comp);
    for(ll i = 0; i <= s.length()+1; i++)
    {
        arr[i]=-1; 
    }
    for (ll i = 0; i < v.size(); i++)
    {
        arr[v[i].s]=v[i].e+1;
    }
    ll sta=-1;
    for(ll i = 0; i <= s.length(); i++)
    {
        if((arr[i]!=-1)&&(flag==0))
        {
            sta=i;flag=1;
            i = arr[i]-1;
            continue;
        }
        if((arr[i]!=-1)&&(flag==1))
        {
            i = arr[i]-1;
            continue;
        }
        if((arr[i]==-1)&&(sta!=-1))
        {
            if(m<=(i-sta))
            mp[(i-sta)]++;
            m = max(m,i-sta);flag=0;sta=-1;
        }
    }
    if (m)
        cout << m << " " << mp[m];
    else
        cout << "0 1";
}