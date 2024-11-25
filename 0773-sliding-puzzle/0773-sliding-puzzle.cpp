class Solution {
public:
    // 0 1 2
    // 3 4 5
    int find(string &s)
    {
        for(int i=0; i<6; i++)
            if(s[i]=='0')
                return i;
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int, vector<int>> ump;
        ump[0]={1, 3};
        ump[1]={0, 2, 4};
        ump[2]={1, 5};
        ump[3]={0, 4};
        ump[4]={1, 3, 5};
        ump[5]={2, 4};
        
        string s="";
        for(int i=0; i<2; i++)
            for(int j=0; j<3; j++)
                s.push_back(board[i][j]+'0');
        // cout<<s<<endl;

        queue<pair<string, int>> q;
        q.push({s, 0});
        unordered_set<string> st;
        st.insert(s);

        while(!q.empty())
        {
            string cs=q.front().first;
            int moves=q.front().second;
            q.pop();
            
            // cout<<cs<<endl;

            if(cs=="123450")
                return moves;

            int ind=find(cs);
            for(auto neigh: ump[ind])
            {
                swap(cs[ind], cs[neigh]);
                if(st.find(cs)==st.end())
                {
                    st.insert(cs);
                    q.push({cs, moves+1});
                }
                swap(cs[ind], cs[neigh]);
            }          
        }

        return -1;
    }
};