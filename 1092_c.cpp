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
    int n;
    cin >> n;
    map<string, int> mp;
    vector<string> v;
    vector<string> aa;

    for (int i = 0; i < 2 * n - 2; i++)
    {
        string s;
        cin >> s;
        aa.push_back(s);
        if (s.length() == n - 1)
        {
            v.push_back(s);
        }
        mp[s] = 1;
    }
    string s = v[0];
    string temp = "";
    string temp1 = "";
    int flag = 0;
    for (int i = 0; i < v[0].length()-1; i++)
    {

        temp += v[0][i];
        temp1+= v[1][i+1];
    }
    // cout<<s<<" ";
    for (int i = 0; i < s.length(); i++)
    {

        
        if (temp1[i]!=temp[i])
        {
            flag = 1;
            break;
        }
    }
    string ans;
    string h = "";
    string hh = "";
    hh+=v[1][0];
    if (n > 2)
    {
        h = h + v[1][0];
        h += v[1][1];
        if ((!flag) && (mp[(h)])&&(mp[hh]))
        {
            ans = v[1][0] + v[0];
        }
        else
            ans = v[0][0] + v[1];
    }
    else
    {cout<<"SP";return 0;}
    map<string, char> aaa;
    temp = "";
    map<string, int> g;
    for (int i = 0; i < ans.length() - 1; i++)
    {
        temp += ans[i];
        aaa[temp] = 'P';
    }
    temp = "";flag=0;

    for (auto i : aa)
    {
        flag=0;
        for(ll j = 0; j < i.length(); j++)
        {
            if(i[j]!=ans[j])
            {
                cout<<"S";flag=1;break;
            }
        }
        if(flag==0)
            if(g[i]==0)
                cout<<"P";
            else
                cout<<"S";
        g[i]=1;
        
    }
    // cout<<ans;
}