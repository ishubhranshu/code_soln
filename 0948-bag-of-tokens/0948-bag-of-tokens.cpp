class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n=tokens.size(), score=0, tscore=0;
        int left=0, right=n-1;
        while(left<=right)
        {
            cout<<left<<" "<<right<<endl;
            while(left<=right && tokens[left]<=power)
            {
                tscore++;
                power-=tokens[left++];
            }   
            score=max(score, tscore);
            if(left<=right && tscore)
            {
                tscore--;
                power+=tokens[right--];
            }
            else
                break;
        }
        return score;
    }
};