#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
string s;
string k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll num;
    k = "";
    cin >> num;
    cin >> s;
    while (num > 0)
    {
        k.push_back('0' + (num % 2));
        num /= 2;
    }
    reverse(k.begin(), k.end());
    cout << k << "\n"
         << s << "\n";
    if (k.length() > s.length())
    {
        cout << "0\n";
    }
    else if (s.length() > k.length())
    {
        // ll ind = 0;
        // ll flag = 0;
        // for (int i = 0; i < k.length(); i++)
        // {
        //     int f = 0;
        //     for (int j = ind; j < s.length(); j++)
        //     {
        //         if (s[j] == k[i])
        //         {
        //             ind = j + 1, f = 1;
        //             break;
        //         }
        //     }
        //     if (f == 0)
        //     {
        //         flag = 1;
        //         break;
        //     }
        // }
        // if (flag == 1)
        // {
        //     ll solve = 0;
        //     ll not_possible = 0;
        //     int ind = 0;
        //     for (int i = 1; i < k.length(); i++)
        //     {
        //         for (int j = 1; j < s.length(); j++)
        //         {
        //             if ((s.length() - j ) < (k.length() - i ))
        //             {
        //                 not_possible = 1;
        //                 break;
        //             }
                    

        //             if (k[i] == '1')
        //             {
        //                 if (s[j] == '0')
        //                 {
        //                     if ((s.length() - j - 1) >= (k.length() - i - 1))
        //                     {
        //                         solve = 1;
        //                         break;
        //                     }
        //                     else
        //                     {
        //                         not_possible = 1;
        //                         break;
        //                     }
        //                 }
        //                 else
        //                 {
                            
        //                     ind = j + 1;
        //                     break;
        //                 }
        //             }
        //             else
        //             {
        //                 if (s[j] == '0')
        //                 {
        //                     ind = j + 1;
        //                     break;
        //                 }
        //                 else
        //                 {
        //                 }
        //             }
        //         }
        //         if (solve)
        //             break;
        //         if (not_possible)
        //             break;
        //     }
        //     if (not_possible)
        //         cout << s.length() - k.length() + 1;
        //     else
        //         cout << s.length() - k.length();
        // }
        // else
        //     cout << "0\n";
        



    }
    else
    {
        // cout<<k<<"\n"<<s<<"\n";
        if (k.compare(s) == 0)
        {
            cout << "0\n";
        }
        else if (k.compare(s) > 0)
        {
            cout << "0\n";
        }
        else
        {
            cout << "1\n";
        }
    }
}