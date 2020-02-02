#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll l = s.length();
        if (s[0] == '1')
        {
            ll flag = 0;
            for (ll i = 1; i < l; i++)
            {
                if (s[i] != '0')
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0) 
            {
                
                for(ll i = 0; i < l-1; i++)
                {
                    cout<<"9";
                }
                cout<<"\n";
                continue;
            }
        }
        for (ll i = 0; i < l / 2; i++)
        {
            if (s[i] == s[l - i - 1])
                continue;
            else
            {

                if (s[i] > s[l - i - 1])
                {

                    for (ll j = l - i - 2; j >= 0; j--)
                    {
                        if (s[j] != '0')
                        {
                            s[j]--;
                            break;
                        }
                        else
                        {
                            s[j] = '9';
                        }
                    }
                }
                s[l - i - 1] = s[i];
            }
        }
        cout << s << "\n";
    }
}