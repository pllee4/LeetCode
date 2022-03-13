/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
 public:
  Node *cloneGraph(Node *node) {
    if (node == NULL) return NULL;
    unordered_map<Node *, Node *> graph;
    graph[node] = new Node(node->val);

    queue<Node *> q;
    q.push(node);

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      for (const auto adj : curr->neighbors) {
        // not in the graph
        if (graph.find(adj) == graph.end()) {
          graph[adj] = new Node(adj->val);
          q.push(adj);
        }
        graph[curr]->neighbors.push_back(graph[adj]);
      }
    }
    return graph[node];
  }
};