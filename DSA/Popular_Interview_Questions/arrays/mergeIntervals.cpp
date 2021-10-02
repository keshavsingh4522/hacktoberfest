vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    res.push_back({intervals[0][0], intervals[0][1]});

    for(int i=1; i<intervals.size(), i++){
        if(res[res.size() -1][1] >= intervals[i][0]){
            int minm = min(res[res.size()-1][0], intervals[i][0]);
            int maxm = max(res[res.size()][1], intervals[i][1]);

            res[res.size() - 1][0] = minm;
            res[res.size() - 1][1] = maxm;
        }

        else{
            res.push_back(intervals[i]);
        }
    }

    return res;
}