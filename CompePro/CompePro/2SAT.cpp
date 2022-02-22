// todo : all(ACLÇ…ç›ÇÈà◊ã}ÇÆïKóvÇ»ÇµÅj
/*
class Scc {
public:
  Scc(ll n) {
    cnt = n;
    g.resize(n);
    rg.resize(n);
    vs.resize(n);
    used.resize(n);
    cmp.resize(n);
  }

  void add_edge(ll from, ll to) {
    g[from].push_back(to);
    rg[to].push_back(from);
  }

  void dfs(ll v) {
    used[v] = true;
    REP(i, g[v].size()) {
      if (!used[g[v][i]])dfs(g[v][i]);
    }
    vs.push_back(v);
  }
  void rdfs(ll v, ll k) {
    used[v] = true;
    cmp[v] = k;
    REP(i, rg[v].size()) {
      if (!used[rg[v][i]])rdfs(rg[v][i], k);
    }
  }

  ll GetScc() {
    used.assign(cnt, false);
    vs.clear();
    REP(v, cnt) {
      if (!used[v])dfs(v);
    }
    used.assign(cnt, false);
    ll k = 0;
    PER(v, cnt) {
      if (!used[v])dfs(v, k++);
    }
  }

  ll cnt;
  vector<vector<ll>> g;
  vector<vector<ll>> rg;
  vector<ll> vs;
  vector<bool> used;
  vector<ll> cmp;
};
*/