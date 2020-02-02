#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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


ll n, m, k;
string s[301];
struct dt{
    ll i,j,s;
};
vector<dt>star;
bool comp(dt a,dt b)
{
    if(a.s!=b.s)return a.s<b.s;
    else if(a.i!=b.i)return a.i<b.i;
    else return a.j<b.j;
}
void fun(ll i, ll j)
{
    if (s[i][j] != '*')
        return;
    for (ll x = 1; x < min(n, m); x++)
    {
        if ((i + x >= n) || (i - x < 0) || (j + x >= m) || (j - x < 0))
            return;
        if ((s[i + x][j] == '*') && (s[i - x][j] == '*') && (s[i][j + x] == '*') && (s[i][j - x] == '*'))
            {
                dt temp;temp.i = i+1;temp.j = j+1;temp.s=x;star.push_back(temp);
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            fun(i, j);
    sort(star.begin(),star.end(),comp);
    if (k > star.size())
        cout << "-1\n";
    else
    {
        k--;
        cout << star[k].i  << " " << star[k].j  << "\n";
        cout << star[k].i  - star[k].s << " " << star[k].j  << "\n";
        cout << star[k].i  + star[k].s << " " << star[k].j  << "\n";
        cout << star[k].i  << " " << star[k].j - star[k].s  << "\n";
        cout << star[k].i  << " " << star[k].j + star[k].s  << "\n";
    }
    // for(ll i=0;i<star.size();i++)
    // cout<<star_i[i]+1<<" "<<star_j[i]+1<<"\n";
}