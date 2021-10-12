class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);
    bool source_present = false;
    for (auto value : times) {
      adj[value[0]].push_back({value[2], value[1]});
      if (value[0] == k) source_present = true;
    }
    // if source is not present
    if (!source_present) return -1;

    vector<int> dist(n + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, k});

    dist[k] = 0;
    dist[0] = 0;

    while (!pq.empty()) {
      int node = pq.top().second;
      pq.pop();
      for (auto child : adj[node]) {
        // for unvisited node
        if (dist[child.second] > dist[node] + child.first) {
          dist[child.second] = dist[node] + child.first;
          pq.push(child);
        }
      }
    }
    for (auto x : dist)
      if (x == INT_MAX) return -1;
    return *max_element(dist.begin(), dist.end());
  }
};