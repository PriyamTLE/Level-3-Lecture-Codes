// User function Template for C++
#include<bits/stdc++.h>
using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    bool isSpecial;
    TrieNode *children[2];
    TrieNode() {
        isSpecial = false;
        for (int i = 0; i < 2; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(int num) {
        TrieNode *curr = root;
        for (int bit = 31; bit >=0 ; bit--)
        {            
            int bitValue = (num>>bit) & 1;
            if (curr->children[bitValue] == NULL)
                curr->children[bitValue] = new TrieNode();
            curr = curr->children[bitValue];
        }
        curr->isSpecial = true;
    }

    // Returns if the word is in the trie.
    int maximumXorPair(int num) {
        TrieNode *curr = root;
        int maxXorCand = 0;
        for (int bit = 31; bit >=0 ; bit--)
        {            
            int bitValue = (num>>bit) & 1;
            int oppoBitValue = bitValue ^ 1;
            if (curr->children[oppoBitValue] != NULL)
            {
                if(oppoBitValue == 1)
                {
                    maxXorCand |= (1<<bit);
                }
                curr = curr->children[oppoBitValue];
            }
            else
            {
                if(bitValue == 1)
                {
                    maxXorCand |= (1<<bit);
                }
                curr = curr->children[bitValue];
            }
        }
        return maxXorCand^num;
    }
};

class Solution {
  public:
    vector<long long> maximumXor(int n, int q, vector<int> &arr,
                                 vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(), arr.end()); //nlogn
        
        vector<pair<long long, pair<long long, long long>>> oq;  //offline query
        
        for(int i=0;i<q;i++) {
            oq.push_back({queries[i][1], {queries[i][0], i}});
        }
        
        sort(oq.begin(), oq.end()); // qlogq
        
        vector<long long> ans(q, 0);
        
        Trie * obj = new Trie();
        long long ind = 0;
        for(int i=0;i<q;i++) { // q
            
            long long mi = oq[i].first;
            long long xi = oq[i].second.first;
            long long qInd = oq[i].second.second;
            
            while(ind<n && arr[ind] <= mi) {
                obj->insert(arr[ind]); //. 31
                ind++;
            }
            if(ind!=0) ans[qInd] = obj->maximumXorPair(xi); // 31
            else ans[qInd] = -1;
        } // q * 31 + n* 31 = 31*(q+n)
        // tc -  O(max(QlogQ, NlogN))
        // sc - q+q+n*31*2 - O(q+n)
        return ans;
    }
};