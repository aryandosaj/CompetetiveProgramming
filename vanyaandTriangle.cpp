#include <bits/stdc++.h>
using namespace std;


 int main()
{
  ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long c=0;
   long long n;
   cin>>n;
   long long x[n];long long y[n];
   for(long long i = 0; i < n; i++)
   {
       cin>>x[i]>>y[i];
   }
   
   for(long long i = 0; i < n; i++)
   {
       
       for(long long j = i+1; j < n; j++)
       {
           
           for(long long k = j+1; k < n; k++)
           {
               if((x[j]*y[k]-x[k]*y[j]-x[i]*y[k]+x[k]*y[i]+x[i]*y[j]-x[j]*y[i]))
               c++;
           }
           
       }
       
   }
   cout<<c;
   
   
}