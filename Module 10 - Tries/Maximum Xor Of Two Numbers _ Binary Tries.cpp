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
    int maxXor(vector<int> &arr) {
        // code here
        Trie * obj = new Trie();
        int ans = -1;
        for(auto it:arr) obj->insert(it);
        for(auto it:arr) ans=max(ans,obj->maximumXorPair(it));
        return ans;
    }
};
