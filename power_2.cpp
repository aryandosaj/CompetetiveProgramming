


#include <bits/stdc++.h> 
using namespace std;


void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
map<int,bool>mp;
int sum=0;
void permute(char *a, int l, int r) 
{ 
   int i; 
   if (l == r) 
     {
         
        string s = a;
        
        int num=0;
        for(int i = 0; i < s.length(); i++)
        {
            /* code */
            num=num*10 + s[i]-48;
            
        }
        // cout<<num<<"\n";
        if(mp[num]==1)
        return;
        mp[num]=1;
        if((num&(num-1))==0)
        sum+=num;
        
     } 
   else
   { 
       for (i = l; i <= r; i++) 
       { 
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i)); 
       } 
   } 
} 
  
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        char str[1001];
        cin>>str;
    // char str[] = "ABC"; 
    int n = strlen(str); 
    permute(str, 0, n-1); 
    if(sum!=0)
    cout<<sum<<"\n";
    else
    cout<<"-1\n";
    sum=0;
    mp.clear();
    }
} 