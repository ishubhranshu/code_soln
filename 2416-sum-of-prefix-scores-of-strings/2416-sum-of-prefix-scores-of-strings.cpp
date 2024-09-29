class TrieNode {
public:
    unordered_map<char, TrieNode *> child;
    int count;
    TrieNode()
    {
        count=0;
    }

};
class Trie {
public:
    TrieNode *root;
    Trie()
    {
        root=new TrieNode();
    }

    void insert(string s)
    {
        TrieNode * node=root;
        for(auto ch: s)
        {
            if(node->child[ch-'a']==NULL)
                node->child[ch-'a']=new TrieNode();
            node=node->child[ch-'a'];
            node->count++;
        }
    }
    int find(string s)
    {
        TrieNode * node=root;
        int count=0;
        for(auto ch: s)
        {
            if(node->child[ch-'a']==NULL)
                break;
            node=node->child[ch-'a'];
            count+=node->count;
        }
        return count;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        Trie tr;
        for(auto w:words)
            tr.insert(w);

        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            ans[i]=tr.find(words[i]);
        }

        return ans;
    }
};