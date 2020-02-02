#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        if(s1+s2==s3 || s2+s1==s3)
            return true;
        // write your code here
        s1 = " "+ s1;
        s2=" " +s2;
        s3=" "+s3;
        int l1 = s1.length();
        int l2 = s2.length();
        
        bool mat[l2][l1];
        
        memset(mat, false, sizeof(mat));
        
        for(int i=0;i<l2;i++)
        {
            for(int j=0;j<l1;j++)
            {
                if(i==0 && j==0)
                    mat[i][j] = true;
                if(i==0 && s1[j] == s3[i+j])
                    mat[i][j] = true;
                if(j==0 && s2[j] == s3[i+j])
                    mat[i][j] = true;
                if(mat[i-1][j]==true && mat[i][j-1] == true && s2[i] == s3[i+j])
                    mat[i][j]==true;
                if(mat[i-1][j] == true && s2[i] == s3[i+j])
                    mat[i][j] = true;
                if(mat[i][j-1] == true && s1[j] == s3[i+j])
                    mat[i][j] = true;
            }
        }
        cout<<endl;
        for(int i=0;i<l2;i++)
        {
            for(int j=0;j<l1;j++)
            {
                if(mat[i][j] == true)
                cout<<" T ";
                else
                cout<<" F ";
            }
            cout<<endl;
        }
        return mat[l2-1][l1-1];
    }
};