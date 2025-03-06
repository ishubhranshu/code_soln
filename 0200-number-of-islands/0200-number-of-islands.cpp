class Solution {
public:
    void exploreLand(int row, int col, vector<vector<char>>& grid)
    {
        int rowSize=grid.size();
        int colSize=grid[0].size();
        if(row<0 || col<0 || row==rowSize || col==colSize || grid[row][col]!='1')
            return;

        grid[row][col]='0';

        int possDirs[]={0,1,0,-1,0};
        for(int currDir=0; currDir<4; currDir++)
        {
            int newRow=row+possDirs[currDir];
            int newCol=col+possDirs[currDir+1];

            exploreLand(newRow, newCol, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rowSize=grid.size();
        int colSize=grid[0].size();
        int islandCount=0;
        for(int row=0; row<rowSize; row++)
        {
            for(int col=0; col<colSize; col++)
            {
                if(grid[row][col]=='1')
                {
                    islandCount++;
                    exploreLand(row, col, grid);
                }
            }
        }

        return islandCount;
    }
};