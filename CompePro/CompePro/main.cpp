#define ATCODER
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
#include <cassert>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <math.h>
#include <climits>
#include <set>
#include <map>
#include <list>
#include <random>
#include <iterator>
#include <bitset>

using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;

//template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for(ll i=(a); i<(b);i++)
#define REP(i, n) for(ll i=0; i<(n);i++)
#define ROF(i, a, b) for(ll i=(b-1); i>=(a);i--)
#define PER(i, n) for(ll i=n-1; i>=0;i--)
#define REPREP(i,j,a,b) for(ll i=0;i<a;i++)for(ll j=0;j<b;j++)
#define VV(type) vector< vector<type> >
#define VV2(type,n,m,val) vector< vector<type> > val;val.resize(n);for(ll i;i<n;i++)val[i].resize(m)
#define vec(type) vector<type>
#define VEC(type,n,val) vector<type> val;val.resize(n)
#define VL vector<ll>
#define VVL vector< vector<ll> >
#define VP vector< pair<ll,ll> >
#define SZ size()
#define all(i) begin(i),end(i)
#define SORT(i) sort(all(i))
#define BITI(i) (1<<i)
#define BITSET(x,i) x | (ll(1)<<i)
#define BITCUT(x,i) x & ~(ll(1)<<i)
#define EXISTBIT(x,i) (((x>>i) & 1) != 0)
#define ALLBIT(n) (ll(1)<<n-1)
#define TOMAX(n,v) n=n<v?v:n
#define TOMIN(n,v) n=n>v?v:n
#define MP(a,b) make_pair(a,b)
#define DET2(x1,y1,x2,y2) x1*y2-x2*y1
#define DET3(x1,y1,z1,x2,y2,z2,x3,y3,z3) x1*y2*z3+x2*y3*z1+x3*y1*z2-z1*y2*x3-z2*y3*x1-z3*y1*x2
#define SQU(x) (x)*(x)
#define L0 ll(0)
#ifdef ATCODER
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using mint2 = modint998244353;
#endif
template<typename T = ll>
vector<T> read(size_t n) {
  vector<T> ts(n);
  for (size_t i = 0; i < n; i++) cin >> ts[i];
  return ts;
}

template<typename TV, const ll N> void read_tuple_impl(TV&) {}
template<typename TV, const ll N, typename Head, typename... Tail>
void read_tuple_impl(TV& ts) {
  get<N>(ts).emplace_back(*(istream_iterator<Head>(cin)));
  read_tuple_impl<TV, N + 1, Tail...>(ts);
}
template<typename... Ts> decltype(auto) read_tuple(size_t n) {
  tuple<vector<Ts>...> ts;
  for (size_t i = 0; i < n; i++) read_tuple_impl<decltype(ts), 0, Ts...>(ts);
  return ts;
}

using val = ll;
using func = pair<ll, ll>;

val op(val a, val b) { return a + b; }
val e() { return 0; }

//val op(val a, val b) { return make_pair(a.first + b.first, a.second + b.second); }
//val e() { return MP(0, 0); }
//val mp(func f, val x) { return make_pair(x.first + x.second * f, x.second); }
//func comp(func f, func g) { return f + g; }
//func id() { return 0; }

ll di[4] = { 1,0,-1,0 };
ll dj[4] = { 0,1,0,-1 };

int main() {

  return 0;
}
