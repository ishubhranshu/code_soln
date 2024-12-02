class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        int n=searchWord.length();
        string word;
        int ind=1;
        while(ss >> word)
        {
            if(word.size()>=searchWord.length() && word.substr(0, n)==searchWord)
                return ind;
            ind++;
        }

        return -1;

    }
};