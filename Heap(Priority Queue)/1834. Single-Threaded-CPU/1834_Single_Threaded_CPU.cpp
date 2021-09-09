typedef pair<int, int> pi;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        for (int i=0; i<tasks.size(); i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(), tasks.end());
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        
        int cur = 0;
        vector<int>res;
        res.reserve(tasks.size());
        for (int i=0; i<tasks.size(); i++)
        {
            while (cur < tasks[i][0] && !pq.empty())
            {
                res.push_back(pq.top().second);
                cur += pq.top().first;
                pq.pop();
            }            
            
            pq.push({tasks[i][1], tasks[i][2]});
            cur = max(cur, tasks[i][0]);
        }
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;        
    }
};