#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

struct data
{
    int a,b;
};
vector <data> v;
int main()
{
    // cout<<gcd(1,2);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    //code start here
    int n,m;
    cin>>n>>m;
    int c=0;
    int flag=0;
    for(int i = 1; i <= n; i++)
    {
        
        
        for(int j = i+1; j <= n; j++)
        {
            // cout<<i<<j;
            // cout<<gcd(i,j);
            if(gcd(i,j)==(int)1)
            {
                data t;
                t.a=i;t.b=j;
                v.push_back(t);
                c++;
                // cout<<c;
                if(c>=m)
                {flag=1;break;}
            }
        }
        if(flag==1)
        break;
        
    }
    if((c==m)&&(m>=n-1))
    {
        cout<<"Possible\n";
        for(int i = 0; i < m; i++)
        {
            cout<<v[i].a<<" "<<v[i].b<<"\n";
        }
        
    }
    else
    cout<<"Impossible";
    
    
}