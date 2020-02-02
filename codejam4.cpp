#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, f, b;
        cin >> n >> b >> f;
        string inp[5];
        vll num[5];
        ll arr[] = {16, 8, 4, 2, 1};
        vll brr;
        for (ll i = 0; i < 5; i++)
        {
            string s = "";
            ll flag = 0;
            for (ll j = 0; j < n; j++)
            {
                if ((j % arr[i] == 0) && (j != 0))
                    flag = 1 - flag;
                if (flag)
                    s.push_back('1');
                else
                    s.push_back('0');
            }
            cout << s << endl;
            cin >> inp[i];
            flag = 0;
            ll c = 0, p = 0, x = 0;
            if (i == 0)
            {
                for (ll j = 0; j < inp[i].length(); j++)
                {
                    if (flag == 0)
                    {
                        if (inp[i][j] == '0')
                            c++;
                        else
                            num[i].push_back(c), c = 0, flag = 1,j--;
                    }
                    else
                    {
                        if (inp[i][j] == '1')
                            c++;
                        else
                            num[i].push_back(c), c = 0, flag = 0,j--;
                    }
                }
                if (c)
                    num[i].push_back(c);
            }
            else
            {
                ll k = 0;
                ll o = 0, z = 0;
                for (ll j = 0; j < num[i - 1].size(); j++)
                {

                    if (num[i - 1][j] == 0)
                        num[i].push_back(0), num[i].push_back(0);
                    else
                    {
                        o = 0, z = 0;
                        ll h = 0;
                        while (h < num[i - 1][j])
                        {
                            if (inp[i][k + h] == '0')
                                z++;
                            else
                                o++;
                            h++;
                        }
                        k = k + h;
                        num[i].push_back(z);
                        num[i].push_back(o);
                    }
                }
            }
            //for(ll j=0;j<num[i].size();j++)cout<<num[i][j]<<" ";cout<<"\n";
        }
        for (ll i = 0; i < n; i++)
            if (num[4][i] == 0)
                cout << i << " ";
        cout << endl;
        ll ans;
        cin >> ans;
        if (ans == -1)
            return 0;
    }
}