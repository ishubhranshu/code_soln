class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end())
            return 0;

        unordered_set<string> forward;
        unordered_set<string> backward;
        int len=1;

        forward.insert(beginWord);
        backward.insert(endWord);

        while(!forward.empty() && !backward.empty())
        {
            if(forward.size() > backward.size())
                swap(forward, backward);

            unordered_set<string> tempForward;
            for(auto word: forward)
            {
                int strLen=word.size();
                for(int i=0; i<strLen; i++)
                {
                    string tempStr=word;
                    for(auto c='a'; c<='z'; c++)
                    {
                        tempStr[i]=c;

                        if(backward.find(tempStr) != backward.end())
                            return len+1;
                        if(words.find(tempStr) != words.end())
                        {
                            tempForward.insert(tempStr);
                            words.erase(tempStr);
                        }
                    }
                }
            }
            forward=tempForward;
            len++;
        }
        return 0;
    }
};