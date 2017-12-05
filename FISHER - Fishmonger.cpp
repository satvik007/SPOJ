#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
#define mp(a, b) make_pair(a, b)
#define inf (int)1e9

int n, t, a[105][105], b[105][105];
ii memo[105][1005];

ii solve(int current, int left){
    if(left < 0) return {inf, -inf};
    if(current == n-1) return {0, left};
    if(memo[current][left].first != -1) return memo[current][left];
    int max1 = inf;
    ii ans(inf, inf);
    for(int i=0; i<n; i++){
        if(i == current) continue;
        ii temp = solve(i, left - a[current][i]);
        temp.first += b[current][i];
        if(temp.first < max1) {
            max1 = temp.first;
            ans = temp;
        }
    }
    return (memo[current][left] = ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> t, n||t){
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> a[i][j]; // time
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> b[i][j]; // toll
        memset(memo, -1, sizeof memo);
        ii ans = solve(0, t);
        cout << ans.first << " " << (t - ans.second) << "\n";
    }
    return 0;
}