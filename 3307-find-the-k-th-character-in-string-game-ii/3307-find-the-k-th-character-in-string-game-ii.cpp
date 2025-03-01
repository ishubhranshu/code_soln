class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1)
            return 'a';

        long long len=1;
        long long oper=0;
        long long newK;
        for(long long i=0; i<operations.size(); i++)
        {
            len=len*2;
            if(len>=k)
            {
                oper=operations[i];
                newK=k-len/2;
                break;
            }
        }

        char ch=kthCharacter(newK, operations);
        if(oper==0)
            return ch;

        return ch=='z'? 'a':ch+1;
    }
};