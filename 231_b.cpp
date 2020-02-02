#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, d, l;
    cin >> n >> d >> l;
    if (n % 2 == 0)
    {
        if ((d < ((n / 2) * (1 - l))) || (d > ((n / 2) * (l - 1))))
        {
            cout << -1;
            return 0;
        }
        else
        {
            ll arr[n];
            
            for(ll i = 0; i < n; i++)
            {
                arr[i]=1;
            }
            ll j=0;
            while(d>0)
            {
                arr[j]+=(min(d,l-1));
                d-=min(d,l-1);
                j+=2;
            }
            j=1;
            while(d<0)
            {
                arr[j]+=(min(-d,l-1));
                d+=min(-d,l-1);
                j+=2;
            }
            
            for(ll i = 0; i < n; i++)
            {
                cout<<arr[i]<<" ";
            }
            
        }
    }
    else
    {
        if ((d < ((n / 2) * (1 - l)+1)) || (d > ((n / 2) * (l - 1)+l)))
        {
            cout << -1;
            return 0;
        }
        else
        {
            ll arr[n];
            d--;
            for(ll i = 0; i < n; i++)
            {
                arr[i]=1;
            }
            ll j=0;
            while(d>0)
            {
                arr[j]+=(min(d,l-1));
                d-=min(d,l-1);
                j+=2;
            }
            j=1;
            while(d<0)
            {
                arr[j]+=(min(-d,l-1));
                d+=min(-d,l-1);
                j+=2;
            }
            
            for(ll i = 0; i < n; i++)
            {
                cout<<arr[i]<<" ";
            }

        }


    }
}