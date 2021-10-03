class Solution {
 public:
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, 1, 0, -1};

  int orangesRotting(vector<vector<int>>& grid) {
    int fresh_orange{0};
    queue<pair<int, int>> q;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1)
          fresh_orange++;
        else if (grid[i][j] == 2)
          q.push({i, j});
      }
    }
    // if there is no fresh_orange
    if (fresh_orange == 0) return 0;
    // if there is no rotten orange
    if (q.empty()) return -1;

    // BFS
    int minutes{0};

    while (!q.empty()) {
      // store prev number of rotten oranges
      int n = q.size();
      while (n > 0) {
        auto rotten = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
          int x = rotten.first + dx[i];
          int y = rotten.second + dy[i];

          // if there is fresh orange within the grid
          if (x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and
              grid[x][y] == 1) {
            fresh_orange--;
            // fresh orange becomes rotten orange
            grid[x][y] = 2;
            q.push({x, y});
          }
        }
        n--;
      }
      // there is new rotten oranges
      if (!q.empty()) minutes++;
    }
    // there is fresh fresh_orange that never rots
    if (fresh_orange > 0)
      return -1;
    else
      return minutes;
  }
};