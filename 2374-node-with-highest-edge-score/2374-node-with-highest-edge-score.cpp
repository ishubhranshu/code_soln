class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long> scores(n);

        for(int i=0; i<n; i++)
            scores[edges[i]]+=i;

        long long score=scores[0], ind=0;

        for(int i=0; i<n; i++)
            if(scores[i]>score)
            {
                score=scores[i];
                ind=i;
            }
        
        return ind;
        
    }
};