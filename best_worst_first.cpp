#include <bits/stdc++.h>
using namespace std;
int main()
{

    int mem[]={9500,7000,4500,8500,3000,9000,1000,5500,1500,500};
    int pro[]={5760,4190,3290,2030,2550,6990,8940,740,3930,6890,6580,3820,9140,420,220};
    cout<<"--------------------BEST FIT  --------------------\n";
    {
        map<int,int>asinged;
        map<int,int>mp;
        vector<int>v;
        int ifg=0,ef=0,a=0;
        for(int i=0;i<10;i++)a+=mem[i];
        string e="No";
        for(int i=0;i<15;i++)
        {
            int m=1000000;
            int p=-1;
            for(int j=0;j<10;j++)
            {
                if((mp[j]==0)&&(mem[j]>=pro[i])){
                if(m>(mem[j]-pro[i]))
                    {
                        m = mem[j]-pro[i];p=j;
                    }
                }
            }
                if(p==-1){
                    if(a>pro[i])
                        ef+=pro[i],e="Yes";
                        v.push_back(i);
                }
                else{
                    mp[p] = 1;
                    ifg+=mem[p]-pro[i];
                    a-=pro[i];
                    asinged[p]=i+1;
                    //cout<<"Process Allocated  : "<<i+1<<"\nMemory block : "<<p+1<<"\nInternal Fragmentation : "<<ifg<<"\n\n";
                }

            }


    cout<<"Internal Fragmentation : "<<ifg<<"\nExternal Fragmentation : "<<e<<"\nProcess Unallocated : ";
    for(int i=0;i<v.size();i++)cout<<v[i]+1<<" ";
    cout<<"\nMemory\tProcess\tFree\n";
    for(int i=0;i<10;i++)
    {
        if(asinged[i]!=0)
        cout<<mem[i]<<"\t"<<pro[asinged[i]-1]<<"\t"<<mem[i]-pro[asinged[i]-1]<<"\n";
        else
        cout<<mem[i]<<"\t"<<"Free"<<"\t"<<mem[i]-pro[asinged[i]-1]<<"\n";
    }

    }
    cout<<"\n\n---------------------------FIRST FIT------------------------\n";
    {
        map<int,int>asinged;
          map<int,int>mp;
        vector<int>v;
        int ifg=0,ef=0,a=0;
        for(int i=0;i<10;i++)a+=mem[i];
        string e="No";
        for(int i=0;i<15;i++)
        {
            int m=1000000;
            int p=-1;
            for(int j=0;j<10;j++)
            {
                if((mp[j]==0)&&(mem[j]>=pro[i]))
                {
                        p=j;break;
                }
            }
                if(p==-1){
                    if(a>pro[i])
                        ef+=pro[i],e="Yes";
                        v.push_back(i);
                }
                else{
                    mp[p] = 1;
                    ifg+=mem[p]-pro[i];
                    a-=pro[i];
                    asinged[p]=i+1;
                    //cout<<"Process Allocated  : "<<pro[i]<<"\nMemory block : "<<mem[p]<<"\nInternal Fragmentation : "<<ifg<<"\n\n";
                }

            }


    cout<<"Internal Fragmentation : "<<ifg<<"\nExternal Fragmentation : "<<e<<"\nProcess Unallocated : ";
    for(int i=0;i<v.size();i++)cout<<v[i]+1<<" ";
    cout<<"\nMemory\tProcess\tFree\n";
    for(int i=0;i<10;i++)
    {
        if(asinged[i]!=0)
        cout<<mem[i]<<"\t"<<pro[asinged[i]-1]<<"\t"<<mem[i]-pro[asinged[i]-1]<<"\n";
        else
        cout<<mem[i]<<"\t"<<"Free"<<"\t"<<mem[i]-pro[asinged[i]-1]<<"\n";
    }

    }

    cout<<"\n\n-----------------------WORST FIT--------------------\n";
    {
        map<int,int>asinged;
        map<int,int>mp;
        vector<int>v;
        int ifg=0,ef=0,a=0;
        for(int i=0;i<10;i++)a+=mem[i];
        string e="No";
        for(int i=0;i<15;i++)
        {
            int m=0;
            int p=-1;
            for(int j=0;j<10;j++)
            {
                if((mp[j]==0)&&(mem[j]>=pro[i])){
                if(m<(mem[j]-pro[i]))
                    {
                        m = mem[j]-pro[i];p=j;
                    }
                }
            }
                if(p==-1){
                    if(a>pro[i])
                        ef+=pro[i],e="Yes";
                        v.push_back(i);
                }
                else{
                    mp[p] = 1;
                    ifg+=mem[p]-pro[i];
                    a-=pro[i];
                    asinged[p]=i+1;
                    //cout<<"Process Allocated  : "<<i+1<<"\nMemory block : "<<p+1<<"\nInternal Fragmentation : "<<ifg<<"\n\n";
                }

            }


    cout<<"Internal Fragmentation : "<<ifg<<"\nExternal Fragmentation : "<<e<<"\nProcess Unallocated : ";
    for(int i=0;i<v.size();i++)cout<<v[i]+1<<" ";
    cout<<"\nMemory\tProcess\tFree\n";
    for(int i=0;i<10;i++)
    {
        if(asinged[i]!=0)
        cout<<mem[i]<<"\t"<<pro[asinged[i]-1]<<"\t"<<mem[i]-pro[asinged[i]-1]<<"\n";
        else
        cout<<mem[i]<<"\t"<<"Free"<<"\t"<<mem[i]-pro[asinged[i]-1]<<"\n";
    }
    }

    cout<<"\n\n---------------------------NEXT FIT------------------------\n";
    {
        map<int,int>asinged;
          map<int,int>mp;
        vector<int>v;
        int ifg=0,ef=0,a=0;
        for(int i=0;i<10;i++)a+=mem[i];
        string e="No";
        int jj=0;
        for(int i=0;i<15;i++)
        {
            int p=-1;
            for(int k=0;k<10;k++)
            {
                int j = (k+jj)%10;
                if((mp[j]==0)&&(mem[j]>=pro[i]))
                {
                        jj = j+1;
                        p=j;
                        break;
                }
            }
                if(p==-1){
                    if(a>pro[i])
                        ef+=pro[i],e="Yes";
                        v.push_back(i);
                }
                else{
                    mp[p] = 1;
                    ifg+=mem[p]-pro[i];
                    a-=pro[i];
                    asinged[p]=i+1;
                    //cout<<"Process Allocated  : "<<pro[i]<<"\nMemory block : "<<mem[p]<<"\nInternal Fragmentation : "<<ifg<<"\n\n";
                }

            }


    cout<<"Internal Fragmentation : "<<ifg<<"\nExternal Fragmentation : "<<e<<"\nProcess Unallocated : ";
    for(int i=0;i<v.size();i++)cout<<v[i]+1<<" ";
    cout<<"\nMemory\tProcess\tFree\n";
    for(int i=0;i<10;i++)
    {
        if(asinged[i]!=0)
        cout<<mem[i]<<"\t"<<pro[asinged[i]-1]<<"\t"<<mem[i]-pro[asinged[i]-1]<<"\n";
        else
        cout<<mem[i]<<"\t"<<"Free"<<"\t"<<mem[i]-pro[asinged[i]-1]<<"\n";
    }

    }


}


