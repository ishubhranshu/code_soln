class TrieNode{
public: 
    vector<TrieNode *> children;
    bool end;

    TrieNode()
    {
        children.resize(26, NULL);
        end=0;
    }

};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *node=root;
        for(auto c: word)
        {
            if(node->children[c-'a']==NULL)
                node->children[c-'a']=new TrieNode();
            node=node->children[c-'a'];
        }
        node->end=1;
    }
    
    bool search(string word, TrieNode* node, int ind) {
        if (ind == word.size()) {
            return node->end;
        }

        char c = word[ind];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != NULL) {
                    if (search(word, node->children[i], ind + 1)) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            if (node->children[c - 'a'] == NULL) {
                return false;
            }
            return search(word, node->children[c - 'a'], ind + 1);
        }
    }

    bool search(string word) {
        return search(word, root, 0);
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */