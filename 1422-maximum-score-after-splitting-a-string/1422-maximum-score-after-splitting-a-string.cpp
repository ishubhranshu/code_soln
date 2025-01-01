class Solution {
public:
    int maxScore(string s) {
        int ones=0, zeroes=0, n=s.length();

        for(auto c: s)
            if(c=='1')
                ones++;
        zeroes=n-ones;
        int left=0, right=ones;
        int score=0;

        for(int i=0; i<n-1; i++)
        {
            if(s[i]=='0')
                left++;
            else if(s[i]=='1')
                right--;
            score=max(score, left+right);
        }

        return score;

        
    }
};