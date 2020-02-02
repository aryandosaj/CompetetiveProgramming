#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
struct st
{
    ll n, i;
};

struct kk
{
    ll sc,ns,i;
};

bool comp(st a, st b)
{
    if (a.n == b.n)
        return a.i < b.i;
    return a.n < b.n;
}
bool com(kk a,kk b)
{
    return a.sc<b.sc;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll p, s;
    cin >> p >> s;
    st arr[p];
    ll tp, ts;
    kk score[s];
    map<ll,vector<int>>mp;
    for (ll i = 0; i < p; i++)
    {

        for (ll j = 0; j < s; j++)
        {
            cin >> score[j].sc;
        }
        // cin >> tp;
        ll cur;
        ll c = 0;
        for (ll j = 0; j < s; j++)
        {
            cin >> score[j].ns;            
        }
        sort(score,score+s,com);
        for(ll j = 1; j < s; j++)
        {
            if(score[j-1].ns>score[j].ns)
            c++;
        }
        
        mp[c].push_back(i+1);
        arr[i].n = c;
        arr[i].i = i + 1;
    }
    for(auto i:mp)
    {
        sort(i.second.begin(),i.second.end());
        for(auto j:i.second)
        {
            cout<<j<<"\n";
        }
    }
    return 0;
    sort(arr, arr + p, comp);

    for (ll i = 0; i < p; i++)
    {
        cout << arr[i].i << "\n";
    }
}