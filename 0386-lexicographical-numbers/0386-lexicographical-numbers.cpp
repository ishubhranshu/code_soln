class Solution {
public:
        
    vector<int> nums;
    void lex(int num, int n)
    {
        if(num>n)
            return;

        nums.push_back(num);

        for(int i=0; i<=9; i++)
        {
            int temp=num*10+i;
            if(num>n)
                break;

            lex(temp, n);
        }    
    }
    vector<int> lexicalOrder(int n) {
        // nums.resize(n);
        for(int i=1; i<=9; i++)
            lex(i, n);
        return nums;
    }
};