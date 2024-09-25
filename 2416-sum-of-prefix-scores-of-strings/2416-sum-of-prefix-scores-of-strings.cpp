class Solution {
public:
    struct TrieNode{
        TrieNode* children[26];
        int count;
        
        TrieNode() {
            count = 0;
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* getnode() {
        return new TrieNode();
    }
    
    void insert(TrieNode* root, const string& word) {
        TrieNode* ptr = root;
        
        for(auto c : word) {
            if(ptr->children[c - 'a'] == nullptr) {
                ptr->children[c - 'a'] = getnode();
            }
            ptr->children[c-'a']->count++;
            ptr = ptr->children[c - 'a'];
        }
    }
    
    int getPrefixScore(TrieNode* root, const string& word) {
        TrieNode* ptr = root;
        int score = 0;
        
        for(auto c : word) {
            ptr = ptr->children[c - 'a'];
            score += ptr->count;  // Add the number of words that pass through this prefix
        }
        
        return score;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = getnode();
        
        // Insert all words into the Trie
        for(const auto& word : words) {
            insert(root, word);
        }
        
        vector<int> ans(words.size(), 0);
        
        // For each word, calculate the sum of scores of all prefixes
        for(int i = 0; i < words.size(); i++) {
            ans[i] = getPrefixScore(root, words[i]);
        }
        
        return ans;
    }
};
