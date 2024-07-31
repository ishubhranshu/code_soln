class Solution {
public:
    int solve(int ind, vector<vector<int>>& books, int &shelfWidth, int ch, int rem, vector<vector<int>> &dp)
    {
        if(ind>=books.size())
            return ch;

        if(dp[ind][rem]!=-1)
            return dp[ind][rem];

        int keep=INT_MAX, skip=INT_MAX;
        int w=books[ind][0], h=books[ind][1];

        if(rem>=w)
            keep=solve(ind+1, books, shelfWidth, max(ch, h), rem-w, dp);

        skip=ch+solve(ind+1, books, shelfWidth, h, shelfWidth-w, dp);

        return dp[ind][rem]=min(skip, keep);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> dp(books.size(), vector<int>(shelfWidth+1, -1));
        return solve(0, books, shelfWidth, 0, shelfWidth, dp);
    }
};