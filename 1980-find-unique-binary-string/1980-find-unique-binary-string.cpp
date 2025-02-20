class Solution {
public:

    int binaryToDecimal(string s)
    {
        int num=0;
        int n=s.length();

        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='1')
                num= num | 1<<(n-1-i);
        }
        cout<<s<<" "<<num<<endl;
        return num;
    }
    string decimalToBinary(int num, int n)
    {
        string binary="";

        while(num)
        {
            if(num & 1)
                binary="1"+binary;
            else
                binary="0"+binary;
            num>>=1;
            n--;
        }
        while(n--)
            binary='0'+binary;

        return binary;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> givenNums;
        for(auto &num: nums)
            givenNums.insert(binaryToDecimal(num));
        int n=nums.size();
        int upper_limit=(1<<n) - 1;
        cout<<upper_limit<<endl;

        for(int i=0; i<=upper_limit; i++)
        {
            cout<<i<<" "<<(givenNums.find(i) == givenNums.end())<<endl;
            if(givenNums.find(i) == givenNums.end())
                return decimalToBinary(i, n);
        }

        return "";
    }
};