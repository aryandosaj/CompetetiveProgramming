#include <bits/stdc++.h>
using namespace std;
struct dt{
int ar_t;
int end_t;
int wait_t;
int cpu_time;
int jn;
int js;
int bn;
int start_time;
};
queue <dt>rd;
int fj[1000];
int fm[1000];
int cnt[1000];
int wl=0;
int main()
{
    int m[] = {9500,7000,4500,8500,3000,9000,1000,5500,1500,500};
    int t=0;
    int n;
    int x=0;
    int w=0;
    int in_f=0;
    cin>>n;
    dt job[n];
    int nj=0;
    int temp=0;
    vector<dt>table;
    int i_f[10];
    for(int i=0;i<n;i++)
    {
        cin>>job[i].jn>>job[i].cpu_time>>job[i].js;
    }
    dt cur ;int flag=0;
    while(1)
    {

        for(int i=0;i<10;i++)
        {
            if(fm[i]==0)
            i_f[i]=m[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<10;j++)
            {
                if((fj[i]==0)&&(fm[j]==0)&&(job[i].js<=m[j]))
                {

                    job[i].ar_t = t;
                    job[i].bn = j;
                    rd.push(job[i]);
                    fj[i]=1;
                    fm[j]=i+1;
                    in_f+=m[j]-job[i].js;
                    cnt[j]++;
                    temp++;
                    i_f[j] = m[j] - job[i].js;
                }
            }

        }
        if(temp>0)
        {
        temp=0;
        cout<<"Partition Status \n";
        for(int i=0;i<10;i++)
            cout<<m[i]<<"\t";
        for(int i=0;i<10;i++)
            cout<<fm[i]<<"\t";cout<<"\n";

        }
        if(t%10==0)
        {
        for(int i=0;i<n;i++)
        {
            if(fj[i]==0)
                wl++;
        }
        w+=wl;x++;
        cout<<"waiting queue length = "<<wl<<"\n";wl=0;
        cout<<"Internal Fragmentation\n";
        for(int i=0;i<10;i++)
        {
            cout<<i_f[i]<<" ";
        }
        cout<<"\n\n";
        }

        t++;
       if(flag==0){
        cur = rd.front();cur.start_time=t;flag=1;
        }
        if((t-cur.start_time)==cur.cpu_time)
            {
                cout<<t<<" "<<cur.start_time<<" "<<cur.cpu_time<<"\n";
                rd.pop();
                cur.wait_t = t-cur.start_time;
                cur.end_t = t;
                table.push_back(cur);
                fm[cur.bn]=0;
                cur = rd.front();
                cur.start_time=t;
            }

       if(rd.empty())
            break;


    }
    cout<<"JNO\tWT_M\tST\tET\tTAT\tWT\n";
    for(int i=0;i<table.size();i++)
        cout<<table[i].jn<<"\t"<<table[i].ar_t<<"\t"<<table[i].start_time<<"\t"<<table[i].end_t<<"\t" <<table[i].end_t-table[i].ar_t<<"\t"<<table[i].end_t-table[i].ar_t-table[i].cpu_time<<"\n";
    cout<<"Avg waiting length : "<<(w/(x*1.0))<<"\n";
    cout<<"throughput : "<<(n/(t*1.0))<<"\n";
    cout<<"Total internal fragmentation  : "<<in_f<<"\n";
    int tt=0;
    double avg=0;
    int nvr=0;
    for(int i=0;i<10;i++)
    {
        tt+=cnt[i];
        if(cnt[i]==0)nvr++;
    }
    avg = tt/10.0;
    int b=0;
    for(int i=0;i<10;i++)
        if(cnt[i]>avg)b++;
    double hv = b*10;
    cout<<"%Heavy utilization : "<<hv<<"\n";
    cout<<"%Never utilization : "<<nvr*10<<"\n";
}