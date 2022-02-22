
#include<climits>
#include<vector>
using namespace std;
typedef long long ll;

class BIT {
public:
  BIT(ll s) {
    size = 1;
    while (size < s)
      size *= 2;
    bit.assign(size, 0); // def unit
  }

  void update(ll k, ll var) {
    k += 1;
    while (k <= size) {
      bit[k - 1] += var;  // def func
      k += k & -k;
    }
  }

  ll query(ll a) {
    ll s = 0;
    a++;
    while (a > 0) {
      s += bit[a - 1];  // def func
      a -= a & -a;
    }
    return s;
  }

  ll size;
  vector<ll> bit;
};
