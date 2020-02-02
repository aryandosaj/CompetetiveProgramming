vector<int> Solution::solve(int A) {
    int x=0;int sum=100000000;
    for(int i=0;i<=A;i++)
    {
        long long f = A*A - A*(4*i+1)+4*i*i;
        if(f>0)
        {
            // cout<<f<<" " <<i<<"\n";
            if(f<=sum)
            {
                sum=f;
                x=i;
            }
        }
    }
    vector<int>v;
    for(int i=0;i<A;i++){if(i<x) v.push_back(1);else v.push_back(-1);}
    return v;
}
