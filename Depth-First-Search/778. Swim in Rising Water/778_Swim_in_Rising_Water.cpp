typedef pair<int, pair<int, int>> pii;

class Solution {
 public:
  int swimInWater(vector<vector<int>>& v) {
    int n = v.size();
    int least_time = v[0][0];

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // lower elevation has higher priority
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({v[0][0], {0, 0}});

    // Dijikstra
    while (!pq.empty()) {
      pii cur = pq.top();
      pq.pop();

      int x_val = cur.second.first;
      int y_val = cur.second.second;
      least_time = max(least_time, v[x_val][y_val]);

      // mark as visited
      visited[x_val][y_val] = true;
      // reach the bottom right square
      if (x_val == n - 1 && y_val == n - 1) return least_time;

      vector<int> dx = {-1, 0, 1, 0};
      vector<int> dy = {0, 1, 0, -1};

      for (int i = 0; i < 4; i++) {
        int x = x_val + dx[i];
        int y = y_val + dy[i];

        // exceed the boundary or visited before
        if (x >= n || y >= n || x < 0 || y < 0 || visited[x][y]) {
          continue;
        } else {
          visited[x][y] = true;
          pq.push({v[x][y], {x, y}});
        }
      }
    }
    return 0;
  }
};