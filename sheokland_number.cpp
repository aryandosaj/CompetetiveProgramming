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
#define MAX 100000000000007
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[40];
        ll num = n;
        for (ll i = 0; i < 40; i++)
        {
            arr[i] = 0;
        }

        ll j = 0;
        ll c = 0;
        while (n > 0)
        {
            arr[j++] = n % 2;
            c += n % 2;
            n /= 2;
        }
        if(c==2)
        {
            cout << "0\n";
            continue;
        }
        ll flag = 0;
        for (ll i = 0; i < j; i++)
        {
            if (arr[i] == 0)
            {
                flag = 1;
                break;
            }
        }
        if ((flag == 0) && (num != 0))
        {
            cout << "2\n";
            continue;
        }

        if (c > 2)
        {
            ll num1 = 0, num2 = MAX;
            ll cc = 0;
            for (ll i = 39; i >= 0; i--)
            {
                /* code */
                if (arr[i] == 1)
                {
                    num1 += power(2, i, MAX);
                    cc++;
                }
                if (cc == 2)
                {
                    break;
                }
            }
            // for (ll i = 39; i >= 0; i--)
            // {
            //     /* code */
            //     if (arr[i] == 1)
            //     {
            //         num2 += power(2, i, MAX);
            //         num2 += power(2, i + 1, MAX);
            //         break;
            //     }
            // }
            ll num3 = 0;
            ll k = 0;
            for (ll i = 39; i >= 0; i--)
            {
                if ((arr[i] == 1) && (k == 0))
                {
                    k++;
                    num3 += power(2, i, MAX);
                }
                else if (k == 1)
                {
                    if (arr[i] == 1)
                    {
                        if (arr[i + 1] == 0)
                            num3 += power(2, i + 1, MAX);
                        else
                            num3 += MAX;
                        k++;
                    }
                }
                // cout<<num3<<"\n";
                if (k == 2)
                {
                    break;
                }
            }
            ll num4 = power(2, j, MAX) + 1;

            cout<<num2<<" "<<num1<<"-"<<num3<<" =";
            cout << min(min(min((num2 - num), (num - num1)), num3 - num), num4 - num) << "\n";
        }
        else if (c < 2)
        {
            // cout<<"here";
            ll step = 0;
            for (ll i = 0; i < 40; i++)
            {
                if (arr[i] == 0)
                {
                    step += power(2, i, MAX);
                    c++;
                }
                if (c == 2)
                    break;
            }
            cout << step << "\n";
        }
        
    }
}