#include<bits/stdc++.h>
using namespace std;




class Solution {
  public:
    int findMaxAnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        int res = 0;
        for(int bit=31;bit>=0;bit--)
        {
            int match_pattern = 0;
            int pattern = res | (1<<bit);
            for(int i=0;i<n;i++)
            {
                if((pattern & arr[i]) == pattern)
                match_pattern++;
            }
            if(match_pattern>=2) res|=(1<<bit);
        }
        return res;
    }
};