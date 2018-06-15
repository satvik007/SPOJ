#define BZ
// Warten auf das Licht, das nie kommt.
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

const int INF = 1 << 30;

#define maxn 100010

struct Data {
    int a, b;
    bool operator < (const Data &x) {
        return a < x.a;
    }
};

Data a[20010];
multiset <int> set1, set2;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int tc;
    cin >> tc;

    while(tc--) {
        set1.clear();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i].a >> a[i].b;
        }
        sort(a, a + n);
        set1.insert(INF);

        for(int i = n - 1; i >= 0; i--) {
            int last = a[i].a;
            set2.clear();
            for(; i >= 0 && a[i].a == last; i--) {
                auto it = set1.upper_bound(a[i].b);
                if(*it != INF) {
                    set1.erase(it);
                }
                set2.insert(a[i].b);
            }
            set1.insert(set2.begin(), set2.end());
            i++;
        }

        cout << set1.size() - 1 << "\n";
    }

}