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
    ll n;
    cin >> n;
    string s[n];
    unordered_map<ll, char> last;
    unordered_map<ll, vll> vowel;
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
        ll v = 0;
        char l;
        for (ll j = 0; j < s[i].length(); j++)
        {
            if (s[i][j] == 'a' || s[i][j] == 'e' || s[i][j] == 'i' || s[i][j] == 'o' || s[i][j] == 'u')
                v++, l = s[i][j];
        }
        vowel[v].push_back(i);
        last[i] = l;
    }
    unordered_map<ll, ll> vis;
    unordered_map<char, vll> lc;
    vll second,first;
    for (auto i : vowel)
    {
        vll left;
        for (auto j : i.second)
        {
            lc[last[j]].push_back(j);
        }
        for (auto j : lc)
        {
            if (j.second.size() >= 2)
            {
                ll temp = j.second.size();if(temp&1)temp--,left.push_back(j.second[j.second.size()-1]);
                for (ll k=0;k<temp;k++)
                {
                    second.push_back(j.second[k]);
                    vis[j.second[k]]=1;
                }
            }
            else
            {
                left.push_back(j.second[0]);
            }
            
        }
        if(left.size()>=2)
        {
            ll temp=left.size();if(temp&1)temp--;
            for(ll k=0;k<temp;k++)first.push_back(left[k]);
        }
        lc.clear();
        left.clear();
    }
    ll siz = second.size()-1;
    ll ans=second.size();
    if(first.size()<second.size())ans = (first.size()+second.size())/2;
    cout<<ans/2<<"\n";
    ll mm = min(first.size(),second.size());
    for(ll i=0;i<mm;i++)
    {
        cout<<s[first[i]]<<" "<<s[second[i]]<<"\n";
    }
    if(mm<second.size())
    {
        queue<ll>q;
        for(ll k=mm;k<second.size();k++)
        q.push(second[k]);
        while(1)
        {
            if(q.size()>=4)
            {
                ll ff[2];
                ff[0]=q.front();q.pop();ff[1]=q.front();q.pop();
                cout<<s[ff[0]]<<" "<<s[q.front()]<<"\n";
                q.pop();
                cout<<s[ff[1]]<<" "<<s[q.front()]<<"\n";
                q.pop();
            }
            else break;
        }
    }
}