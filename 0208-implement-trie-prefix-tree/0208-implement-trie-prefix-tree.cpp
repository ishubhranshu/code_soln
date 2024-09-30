class TrieNode{
public:
    vector<TrieNode *> children;
    bool end;
    TrieNode()
    {
        children.resize(26, NULL);\
        end=0;
    }
};
class Trie {
public:
    TrieNode * root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node=root;
        for(auto c: word)
        {
            if(node->children[c-'a']==NULL)
                node->children[c-'a']=new TrieNode();
            node=node->children[c-'a'];
        }
        node->end=1;
    }
    
    bool search(string word) {
        TrieNode *node=root;
        for(auto c: word)
        {
            if(node->children[c-'a']==NULL)
                return 0;
            node=node->children[c-'a'];
        }
        return node->end==1;
    }
    
    bool startsWith(string word) {
        TrieNode *node=root;
        for(auto c: word)
        {
            if(node->children[c-'a']==NULL)
                return 0;
            node=node->children[c-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */