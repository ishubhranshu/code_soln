class Solution {
public:
    bool check(string &s, vector<int> &freq)
    {
        vector<int> reqFreq(26, 0);
        for(auto &c: s)
            reqFreq[c-'a']++;

        for(int i=0; i<26; i++)
            if(reqFreq[i]>freq[i])
                return false;

        return true;
    }
    int calScore(string &s, vector<int>& score)
    {
        int wScore=0;
        for(auto &c:s)
            wScore+=score[c-'a'];
        
        return wScore;
    }
    int solve(int ind, vector<string>& words, vector<int>& score, vector<int> &freq)
    {
        int n=words.size();
        if(ind==n)
            return 0;

        int ans=0;
        if(check(words[ind], freq))
        {
            for(auto &c: words[ind])
                freq[c-'a']--;
            ans=max(ans, calScore(words[ind], score)+solve(ind+1, words, score, freq));
            for(auto &c: words[ind])
                freq[c-'a']++;
        }
        ans=max(ans, solve(ind+1, words, score, freq));
    
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);

        for(auto c: letters)
            freq[c-'a']++;

        return solve(0, words, score, freq);
    }
};