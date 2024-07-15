class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int row=0; row<9; row++)
        {
            for(int col=0; col<9; col++)
            {
                if(board[row][col]!='.')
                {
                    char num=board[row][col];
                    string rhash="", chash="", bhash="";
                    rhash+=num;
                    rhash+='0'+row;
                    rhash+='r';

                    chash+=num;
                    chash+='0'+col;
                    chash+='c';
                    
                    bhash+=num;
                    bhash+='0'+row/3;
                    bhash+='0'+col/3;
                    
                    // cout<<rhash<<" "<<chash<<" "<<bhash<<endl;
                    // cout<<row<<" "<<col<<endl;
                    if(st.find(rhash)!=st.end() ||
                        st.find(chash)!=st.end() ||
                        st.find(bhash)!=st.end())
                        return 0;
                    
                    st.insert(rhash);
                    st.insert(chash);
                    st.insert(bhash);
                }
            }
        }
        return 1;
    }
};