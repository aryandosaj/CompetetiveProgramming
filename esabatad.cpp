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
void complement(vll &v)
{
    f(0, v.size()) v[i] = 1 - v[i];
}
int main()
{
    ll t, b;
    cin >> t >> b;
    while (t--)
    {
        vll v1, v2;
        ll x1, x2;
        ll f1 = 0, f2 = 0, f = 0, val1 = 0, val2 = 0;
        ll last1 = 0, last2 = 0;
        ll i = 1, c = 0;
        while (1)
        {
            cout << i << endl;
            cin >> x1;
            v1.pb(x1);
            cout << (b + 1 - i) << endl;
            cin >> x2;
            v2.pb(x2);
            if (x1 == x2)
                f1 = i, val1 = x1;
            else
                f2 = i, val2 = x1;
            if (i == 1)
                last1 = x1, last2 = x2;
            else if (last1 != x1)
                f = i;

            if (v1.size() == b / 2)
                break;

            i++;
            c++;

            if (c % 5 == 0) //c++
            {
                c++;
                if (f1 && f2)
                {
                    cout << f1 << endl;
                    cin >> x1;
                    cout << f2 << endl;
                    cin >> x2;
                    if (x1 == val1) //rev or nothing
                    {
                        if (x2 != val2) //rev
                            swap(v1, v2),val2=x2;
                    }
                    else //complement or complement+rev
                    {
                        val1=x1;
                        if (x2 == val2) //complement+rev
                        {
                            complement(v1);
                            complement(v2);
                            swap(v1, v2);
                        }
                        else //complement
                        {
                            complement(v1);
                            complement(v2);
                            val2=x2;
                        }
                    }
                }
                else if (f1 || f2)
                {

                    if (f1)
                    {
                        cout << f1 << endl;
                        cin >> x1;
                        cout << f1 << endl;
                        cin >> x1;
                        if (x1 != val1)//complement or complement+rev
                            complement(v1), complement(v2),val1=x1;
                    }
                    else
                    {
                        cout << f2 << endl;
                        cin >> x2;
                        cout << f2 << endl;
                        cin >> x2;
                        if (x2 != val2)
                            complement(v1), complement(v2),val2=x2;
                    }
                }
            }
        }
        for (auto i : v1)
            cout << i;
        reverse(v2.begin(), v2.end());
        for (auto i : v2)
            cout << i;
        cout << endl;
        char ans;
        cin >> ans;
        if (ans == 'Y')
            continue;
        else
            break;
    }
}