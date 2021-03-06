#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int, int>
const int maxn = 1e5 + 5;

using namespace std;

int T, n, m, kase, res; 
int a[maxn];

int solve(){
    int res = INT_MIN;
    // pb the original gap value and split count (init as 1)
    priority_queue<pair<int, pii>, vector<pair<int, pii>>>pq;
    for(int i = 0; i < n - 1; i ++){
        pq.push({a[i + 1] - a[i], {a[i + 1] - a[i], 1}});
    }

    while(m--){
        auto top_ele = pq.top();
        pq.pop();
        int gap_ori = top_ele.se.fi; 
        int split = top_ele.se.se;
        // int gap_new = ceil((float)gap_ori / (float)(split + 1)); WA
        // int gap_new = ceil((double)gap_ori / (double)(split + 1)); // AC
        // non-casting version below
        split++;
        int gap_new = gap_ori / (split);
        if(gap_ori % split){
            gap_new++;
        }
        pq.push({gap_new, {gap_ori, split}});
    }

    return max(1, pq.top().first);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> n >> m;
        memset(a, 0 , sizeof(a));
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << "Case #" << ++kase << ": " << solve() << '\n';
    }

    return 0;
}
