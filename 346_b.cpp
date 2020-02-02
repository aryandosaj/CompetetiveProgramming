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
// #define MAX 1000000007
string dp[101][101];
ll MAX = pow(2, 63) - 25;
ll p = 53;
vll uuu;
string v;
ll po[102];

ll vir(string s, string v)
{
    uuu.clear();
    ll hs[s.length() + 1];
    hs[0] = s[0];
    for (ll i = 1; i < s.length(); i++)
    {
        hs[i] = (hs[i - 1] + s[i] * po[i]) % MAX;
    }
    ll hv = 0;
    for (ll i = 0; i < v.length(); i++)
        hv = (hv + v[i] * po[i]) % MAX;
    ll num = 0;
    for (ll i = v.length() - 1; i < s.length(); i++)
    {
        ll temp, c;
        if (i == v.length() - 1)
            temp = hs[i], c = hv;
        else
            temp = hs[i] - hs[i - v.length()], c = (hv * po[i - v.length() + 1]) % MAX;
        if (c == temp)
            num++, uuu.push_back(i - v.length() + 1);
    }
    return num;
}
string comp(string s1, string s2, string s3)
{
    ll n1, n2, n3;
    n1 = s1.length();
    n2 = s2.length();
    n3 = s3.length();
    n1 = n1 - vir(s1, v);
    n2 = n2 - vir(s2, v);
    n3 = n3 - vir(s3, v);
    if (n3 >= n1 && n3 >= n2)
        return s3;
    if (n2 >= n1 && n2 >= n3)
        return s2;
    if (n1 >= n2 && n1 >= n3)
        return s1;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    po[0] = 1;
    for (ll i = 1; i < 101; i++)
        po[i] = (po[i - 1] * p) % MAX;
    string s1, s2;
    cin >> s1 >> s2 >> v;
    for (ll i = 0; i < s1.length(); i++)
        for (ll j = 0; j < s2.length(); j++)
            dp[i][j] = "";
    for (ll i = 0; i < s1.length(); i++)
    {
        for (ll j = 0; j < s2.length(); j++)
        {
            string temp = "";
            if (s1[i] == s2[j])
                temp = dp[i][j] + s1[i];
            dp[i + 1][j + 1] = comp(dp[i + 1][j], dp[i][j + 1], temp);
            // cout<<dp[i+1][j+1]<<"\n";
        }
    }
    ll a = 0;
    string s = "";
    for (ll i = 1; i <= s1.length(); i++)
    {
        for (ll j = 1; j <= s2.length(); j++)
        {
            ll x = (dp[i][j].length());
            if (a <= x)
            {
                a = x;
                s = dp[i][j];
            }
        }
    }
    if (s.size() == 0)
    {
        cout << "0";
        return 0;
    }
    string s5;
    s5 = s;
    // cout << s << s.size() << "\n";
    // cout << s5 << s5.size() << "\n";
    while (vir(s, v))
    {
        if (uuu.size() > 0)
        {
            s.replace(uuu[0] + v.length() - 1, 1, "");
            // cout << s << s.size() << "\n";
        }
    }

    while (vir(s5, v))
    {
        // cout<<s5<<"\n";
        if (uuu.size() > 0)
        {
            // cout << s5 << s5.size() << "\n";
            s5.replace(uuu[0], 1, "");
        }
    }
    // cout << "here";
    if ((s.size() == 0) && (s5.size() == 0))
    {
        cout << "0";
        return 0;
    }
    if (s.size() > s5.size())
        cout << s;
    else
        cout << s5;

    // cout<<s5<<s5.size();
    // ll hs[s.length() + 1];
    // hs[0] = s[0];
    // for (ll i = 1; i < s.length(); i++)
    // {
    //     hs[i] = (hs[i - 1] + s[i] * po[i]) % MAX;
    // }
    // ll hv = 0;
    // for (ll i = 0; i < v.length(); i++)
    //     hv = (hv + v[i] * po[i]) % MAX;
    // ll num = 0;
    // if(s==" "){cout<<"0";return 0;}
    // string fs1,fs2,temps;fs1="",fs2="";
    // temps=s;
    // for (ll i = v.length() - 1; i < s.length(); i++)
    // {
    //     ll temp, c;
    //     if (i == v.length() - 1)
    //         temp = hs[i], c = hv;
    //     else
    //         temp = hs[i] - hs[i - v.length()], c = (hv * po[i - v.length() + 1]) % MAX;
    //     if (c == temp)
    //     {
    //         // s[i - v.length() + 1] = ' ';
    //         char r =s[i - v.length() + 1];
    //         for (ll j = i - v.length() + 1; j >= 0; j--)
    //         {
    //             // cout<<s[j]<<"="<<r<<"\n";
    //             if (s[j] != r)
    //                 break;
    //             s[j] = ' ';
    //         }
    //     }
    // }
    // ll u1 = 0;
    // for (ll i = 0; i < s.length(); i++)
    //     if (s[i] != ' ')
    //         u1++, fs1+=s[i];
    // // cout << u;
    // // if (u == 0)
    // //     cout << "0";
    // // cout<<"herr";

    // s = temps;
    // // cout<<s;
    //  for (ll i = s.length() - 1; i >= v.length()-1; i--)
    // {
    //     ll temp, c;
    //     if (i == v.length() - 1)
    //         temp = hs[i], c = hv;
    //     else
    //         temp = hs[i] - hs[i - v.length()], c = (hv * po[i - v.length() + 1]) % MAX;
    //     if (c == temp)
    //     {
    //         // s[i - v.length() + 1] = ' ';
    //         char  r = s[i];
    //         for (ll j = i ; j < s.length() ; j++)
    //         {
    //             if (s[j] != r)
    //                 break;
    //             s[j] = ' ';
    //         }
    //     }
    // }
    // ll u2 = 0;
    // for (ll i = 0; i < s.length(); i++)
    //     if (s[i] != ' ')
    //         u2++, fs2+=s[i];
    // // if(u1>u2)cout<<fs1;
    // // if(u2>u1)cout<<fs2;
    // // if((u1==u2)&&(u1!=0))cout<<fs1;
    // // if((u1==u2)&&(u1==0))cout<<0;
    // cout<<fs1<<"\n"<<fs2;
}