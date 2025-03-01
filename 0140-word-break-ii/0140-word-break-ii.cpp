class Solution {
public:
    vector<string> ans;
    void breakW(int ind, string s, unordered_set<string> &words, string &sentence)
    {
        int n=s.length();
        if(ind==n)
        {
            sentence.pop_back();
            ans.push_back(sentence);
            return;
        }

        for(int i=ind; i<n; i++)
        {
            string word=s.substr(ind, i-ind+1);
            if(words.find(word) == words.end())
                continue;
            int len=sentence.length();
            sentence+=word+" ";
            breakW(i+1, s, words, sentence);
            sentence=sentence.substr(0, len);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        string sentence="";
        breakW(0, s, words, sentence);

        return ans;

    }
};