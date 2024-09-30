class TrieNode{
    public:
    vector<TrieNode *> children;
    int count;
    TrieNode()
    {
        children.resize(26, NULL);
        count=0;
    }
};
class Trie{
    public:
    TrieNode* root;

    Trie()
    {
        root=new TrieNode();
    }
    void insert(string s)
    {
        TrieNode *node=root;
        for(auto ch: s)
        {
            if(node->children[ch-'a']==NULL)
                node->children[ch-'a']=new TrieNode();
            node=node->children[ch-'a'];
            node->count++;
        }
    }
    string lpre(string s, int n)
    {
        TrieNode *node=root;
        string ans="";
        for(auto ch: s)
        {
            node=node->children[ch-'a'];
            if(node->count!=n)
                break;
            ans+=ch;
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie tr;
        for(auto s: strs)
            tr.insert(s);

        string ans=tr.lpre(strs[0], strs.size());

        return ans;
    }
};