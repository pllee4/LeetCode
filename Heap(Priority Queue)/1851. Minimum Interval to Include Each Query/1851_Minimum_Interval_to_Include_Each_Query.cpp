typedef pair<int, int> pi;

class Solution {
 public:
  vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    vector<int> res(queries.size(), -1);

    priority_queue<pi, vector<pi>, greater<pi> > queries_pq;
    // arrange queries in ascending order
    for (int i = 0; i < queries.size(); i++) {
      queries_pq.push({queries[i], i});
    }
    // arrange intervals in ascending order based on start time
    sort(intervals.begin(), intervals.end());

    priority_queue<pi, vector<pi>, greater<> > pq;
    int i = 0;
    while (!queries_pq.empty())
    {
      auto [time, idx] = queries_pq.top();
      // push while query time less than start time
      while (i < intervals.size() && intervals[i][0] <= time)
      {
        pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
        i++;
      }
      // pop all invalid values (end_time < time)
      while (!pq.empty() && pq.top().second < time)
        pq.pop();
      // if there is still valid values
      if (!pq.empty())
        res[idx] = pq.top().first;

      queries_pq.pop();
    }
    return res;
  }
};