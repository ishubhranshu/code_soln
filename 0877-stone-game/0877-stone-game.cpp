class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int left=0, right=n-1;
        int a=0, b=0;
        while(left<right)
        {
            if(piles[left]>piles[right])
            {
                a+=piles[left++];
                b+=piles[right--];
            }
            else
            {
                
                b+=piles[left++];
                a+=piles[right--];
            }
        }
        return a>b;
    }
};