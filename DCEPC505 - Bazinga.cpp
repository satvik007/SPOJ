#define BZ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int INF = (int)1e9;

#define maxn 100010

bitset <11000010> bs;
vi primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for(int i = 2; i <= 11000000; i++) if(bs[i]) {
            primes.push_back(i);
            for(ll j = (ll) i * i; j <= 11000000; j += i) {
                bs[j] = 0;
            }
        }
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    sieve();

    int n = primes.size();
    vector <ll> ans;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ll v = (ll)primes[i] * primes[j];
            if(v >= 11000000) {
                break;
            }
            ans.push_back(v);
        }
    }

    sort(ans.begin(), ans.end());

    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;

        cout << ans[n - 1] << "\n";
    }


}