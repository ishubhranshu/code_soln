class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1=0, i2=0, j1=0, j2=0;
        int n1=word1.size(), m1=word2.size();

        while(i1<n1 && i2<m1)
        {
            int n2=word1[i1].length();
            int m2=word2[i2].length();

            while(j1<n2 && j2<m2)
            {
                if(word1[i1][j1] != word2[i2][j2])
                    return 0;
                j1++;
                j2++;
            }
            if(j1==n2)
            {
                j1=0;
                i1++;
            }
            if(j2==m2)
            {
                j2=0;
                i2++;
            }
        }

        return i1==n1 && i2==m1;
    }
};