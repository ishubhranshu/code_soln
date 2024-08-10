class Solution {
public:
    class DisjointSet{
        public:
            vector<double> par, size;
            DisjointSet(int n)
            {
                par.resize(n);
                size.resize(n, 1);
                for(int i=0; i<n; i++)
                    par[i]=i;
            }

            int upar(int x)
            {
                if(par[x]==x)
                    return x;

                return par[x]=upar(par[x]);
            }

            void ubs(int x, int y)
            {
                int upx=upar(x);
                int upy=upar(y);

                if(size[upx]>size[upy])
                {
                    par[upy]=upx;
                    size[upx]+=size[upy];
                }
                else
                {
                    par[upx]=upy;
                    size[upy]+=size[upx];
                }
                
            }

    }; 
    int getcellno(int n, int r, int c)
    {
        return n*r+c;
    }
    vector<int> getgridno(int cellno)
    {
        vector<int> grid;
        for(int i=0; i<4; i++)
                grid.push_back(4*cellno+i);
                
        return grid;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        DisjointSet ds(4*n*n);

        // cout<<ds.par.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int cellno=getcellno(n, i, j);
                vector<int> gnos=getgridno(cellno);
                
                if(grid[i][j]==' ')
                {
                    ds.ubs(gnos[0],gnos[1]);
                    ds.ubs(gnos[1],gnos[2]);
                    ds.ubs(gnos[2],gnos[3]);
                }
                else if(grid[i][j]=='/')
                {
                    ds.ubs(gnos[0],gnos[1]);
                    ds.ubs(gnos[2],gnos[3]);
                }
                else
                {
                    ds.ubs(gnos[0],gnos[3]);
                    ds.ubs(gnos[2],gnos[1]);
                }
                if(i!=0)
                {
                    vector<int> temp=getgridno(getcellno(n, i-1, j));
                    ds.ubs(temp[2], gnos[0]);
                }
                if(j!=0)
                {
                    vector<int> temp=getgridno(getcellno(n, i, j-1));
                    ds.ubs(temp[3], gnos[1]);
                }
                if(i!=n-1)
                {
                    vector<int> temp=getgridno(getcellno(n, i+1, j));
                    ds.ubs(temp[0], gnos[2]);
                }
                if(j!=n-1)
                {
                    vector<int> temp=getgridno(getcellno(n, i, j+1));
                    ds.ubs(temp[1], gnos[3]);
                }
            }
        }
        int ans=0;
        for(int i=0; i<ds.par.size(); i++)
            if(i==ds.par[i])
                ans++;
        return ans;
    }
};