class TrieNode {
public:
    vector<TrieNode *> children;
    bool end;

    TrieNode() {
        children.resize(26, nullptr);
        end = false;
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string &s) {
        TrieNode *node = root;
        for (char c : s) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->end = true;
    }
};

class Solution {
public:
    vector<string> ans;
    set<string> uniqueWords;  // To prevent duplicates

    void solve(int r, int c, vector<vector<char>>& board, TrieNode *node, string &s) {
        if (!node || !node->children[board[r][c] - 'a'])
            return;

        node = node->children[board[r][c] - 'a'];
        s += board[r][c];

        if (node->end) {
            uniqueWords.insert(s);
            node->end = false;  // Avoid duplicate entries for the same word
        }

        char temp = board[r][c];
        board[r][c] = '#';  // Mark the cell as visited

        int dirs[] = {0, 1, 0, -1, 0};  // Direction vectors for right, down, left, up

        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i];
            int nc = c + dirs[i + 1];
            if (nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size() && board[nr][nc] != '#') {
                solve(nr, nc, board, node, s);
            }
        }

        board[r][c] = temp;  // Restore the cell
        s.pop_back();  // Backtrack
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tr;
        for (const string &s : words)
            tr.insert(s);

        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tr.root->children[board[i][j] - 'a']) {
                    string s = "";
                    solve(i, j, board, tr.root, s);
                }
            }
        }

        return vector<string>(uniqueWords.begin(), uniqueWords.end());  // Convert set to vector
    }
};
