class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x=0;
        int n=derived.size();
        for(int i=0; i<n-1; i++)
        {
            if(derived[i])
                x^=1;
        }
        
        return x^0 == derived.back();
    }
};