class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double w_time = 0;
        int n=customers.size();
        int time = 0;
        for(int i=0; i<n; i++)
        {
            w_time+=customers[i][1];
            if(time>customers[i][0])
                w_time+=time-customers[i][0];
            if(time<customers[i][0])
                time=customers[i][0];
            time+=customers[i][1];

            cout<<w_time<<endl;
        }
        return w_time/n;
    }
};