#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    long double n,m;
    cin>>n>>m;
    long double am=0;
    
    for(ll i = 0; i < m; i++)
    {
        long double x,d;
        cin>>x>>d;
        am+=x;
        if(((int)n)%2==1)
        {
            if(d>0)
            {
                if(n!=1)
                am+=d*(n-1)/2;
            }
            else
            {
                long double N = (n-1)/2;
                if(n!=1)
                am+=(N*(N+1.0)*d/n);
            }
        }
        else
        {
            if(d>0)
            {
                am+=((n-1.0)*d/2.0);
            }
            else
            {
                long double N = n/2.0-1.0;
                am+=((N+1.0)*(N+1.0)*d/n);
            }
        }
    }
    printf("%Lf",am);
    
}