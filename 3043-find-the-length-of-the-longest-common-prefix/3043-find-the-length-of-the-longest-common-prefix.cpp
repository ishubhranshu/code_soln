class TrieNode{
    public:
    vector<TrieNode*> child;

    TrieNode()
    {
        child.resize(10, NULL);
    }
};
class Trie{
    private:
        TrieNode* root;
    public:
        Trie()
        {
            root=new TrieNode();
        }

        void insert(int num)
        {
            string s=to_string(num);
            TrieNode* node=root;
            for(auto ch: s)
            {
                if(node->child[ch-'0'] == NULL)
                    node->child[ch-'0']=new TrieNode();
                node=node->child[ch-'0'];
            }
        }

        int match(int num)
        {
            string s=to_string(num);
            int ans=0;
            TrieNode* node=root;
            for(auto ch: s)
            {
                if(node->child[ch-'0'] == NULL)
                    break;
                ans++;
                node=node->child[ch-'0'];
            }
            return ans;
        }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie tr;
        for(auto num: arr1)
            tr.insert(num);

        int ans=0;
        for(auto num: arr2)
            ans=max(ans, tr.match(num));
        
        return ans;
    }
};