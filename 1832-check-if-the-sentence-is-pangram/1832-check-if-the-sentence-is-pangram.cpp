class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool> freq(26, 0);
        int count=0;

        for(auto c: s)
        {
            if(!freq[c-'a'])
            {
                freq[c-'a']=1;
                count++;
            }
            if(count==26)
                return 1;
        }

        return 0;
    }
};