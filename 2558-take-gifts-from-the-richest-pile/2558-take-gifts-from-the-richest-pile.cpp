class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long initial=0;

        for(auto gift: gifts)
        {
            initial+=gift;
            pq.push(gift);
        }   

        for(k; k>0; k--)
        {
            int lar_ele=pq.top();
            pq.pop();
            int rem=floor(sqrt(lar_ele));
            // cout<<lar_ele-rem<<endl;
            initial-=(lar_ele-rem);
            pq.push(rem);
        }

        return initial;
    }
};