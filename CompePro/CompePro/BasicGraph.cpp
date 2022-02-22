// 基本グラフ環境
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

class DirectedGraph {
public:
  struct edge { ll to; };  // 行先,容量,逆容量,コスト

  DirectedGraph(ll n) {
    edges.resize(n);
  }
  void addEdge(ll from, ll to) {
    edge eF = { to };
    edges[from].push_back(eF);
  }

  void FindConnect(ll v, vector<bool>& out) {
    out.assign(edges.size(), false);
    vector<ll> stack;
    stack.push_back(v);
    out[v] = true;
    while (!stack.empty()) {
      v = stack.back(); stack.pop_back();
      for (int i = 0; i < edges[v].size(); i++) {
        ll t = edges[v][i].to;
        if (!out[t]) {
          out[t] = true;
          stack.push_back(t);
        }
      }
    }
  }

  vector<vector<edge>> edges;
};

class Tree {
public:
  Tree(ll n) {
    ll length = n - 1;
    maxLog = 0;
    while (length > 0) {
      length /= 2;
      maxLog++;
    }
    parent.resize(maxLog);
    for (ll i = 0; i < maxLog; i++) {
      parent[i].assign(n, -1);
    }
    child.resize(n);
    dist.assign(n, 0);
  }
  bool Add(ll p, ll c) {
    if (parent[0][c] != -1)
      return false;
    child[p].push_back(c);
    parent[0][c] = p;
    dist[c] = dist[p] + 1;
    return true;
  }


  void Remove(ll p) {
    vector<ll> stack;
    stack.push_back(p);
    while (!stack.empty()) {
      ll v = stack.back(); stack.pop_back();
      for (int i = 0; i < child[v].size(); i++) {
        dist[child[v][i]]--;
        stack.push_back(child[v][i]);
      }
    }
    for (int i = 0; i < child[p].size(); i++) {
      if (parent[0][p] == -1) {
        parent[0][child[p][i]] = child[p][i];
      }
      else {
        child[parent[0][p]].push_back(child[p][i]);
        parent[0][child[p][i]] = parent[0][p];
      }
    }
    parent[0][p] = -1;
  }

  void Doubling() {
    for (int k = 0; k < maxLog - 1; k++) {
      for (int v = 0; v < parent[k].size(); v++) {
        if (parent[k][v] < 0)parent[k + 1][v] = -1;
        else parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }

  ll LCA(ll a, ll b) {
    ll ans = 0;
    if (dist[a] > dist[b])
      swap(a, b);
    for (int k = 0; k < maxLog; k++) {
      if ((dist[b] - dist[a]) >> k & 1) {
        b = parent[k][b];
      }
    }
    if (a == b)return a;
    for (int k = maxLog - 1; k >= 0; k--) {
      if (parent[k][a] != parent[k][b]) {
        a = parent[k][a];
        b = parent[k][b];
      }
    }
    return parent[0][a];
  }

  ll maxLog;
  vector<vector<ll>> parent;  //2^i乗個上の親
  vector<ll> dist;
  vector<vector<ll>> child;
};

class UndirectedGraph {
public:
  struct edge { ll to; };  // 行先,容量,逆容量,コスト

  UndirectedGraph(ll n) {
    edges.resize(n);
  }
  void addEdge(ll from, ll to) {
    edge eF = { to };
    edges[from].push_back(eF);
    edge eT = { from };
    edges[to].push_back(eT);
  }

  void FindConnect(ll v, vector<bool>& out) {
    out.assign(edges.size(), false);
    vector<ll> stack;
    stack.push_back(v);
    out[v] = true;
    while (!stack.empty()) {
      v = stack.back(); stack.pop_back();
      for (int i = 0; i < edges[v].size(); i++) {
        ll t = edges[v][i].to;
        if (!out[t]) {
          out[t] = true;
          stack.push_back(t);
        }
      }
    }
  }

  // todo : TransTree
  Tree TransTree(ll root) {
    Tree tree(edges.size());
    queue<ll> que;
    que.push(root);
    while (!que.empty()) {
      ll v = que.front(); que.pop();
      for (int i = 0; i < edges[v].size(); i++) {
        ll t = edges[v][i].to;
        if (tree.Add(v, t)) {
          que.push(t);
        }
      }
    }
    return tree;
  }

  vector<vector<edge>> edges;
};