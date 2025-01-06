class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> left(n, 0), right(n, 0);

        int count= boxes[0]=='1'?1:0;
        for(int i=1; i<n; i++)
        {
            left[i]=count+left[i-1];
            if(boxes[i]=='1')
                count++;
        }
        count=boxes.back()=='1'?1:0;
        for(int i=n-2; i>=0; i--)
        {
            right[i]=count+right[i+1];
            if(boxes[i]=='1')
                count++;
        }
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++)
            ans[i]=left[i]+right[i];

        return ans;
        
    }
};