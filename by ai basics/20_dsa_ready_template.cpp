/*
 * =============================================================
 * C++ DSA READY TEMPLATE
 * =============================================================
 * Use this as your starting point for DSA problems!
 * Copy and modify as needed.
 * =============================================================
 */

#include <bits/stdc++.h>  // Includes everything (use in CP only)
using namespace std;

// Type aliases for convenience
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vector<int>> vvi;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const double PI = acos(-1.0);

// Macros
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); i--)

// Debug macro (remove for submission)
#define dbg(x) cerr << #x << " = " << x << endl

// Fast I/O
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Common utility functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll power(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// Direction arrays for grid problems
int dx[] = {0, 0, 1, -1};      // 4 directions
int dy[] = {1, -1, 0, 0};
// int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};  // 8 directions
// int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// ============================================
// SOLVE FUNCTION - Write your solution here
// ============================================
void solve() {
    // Read input
    int n;
    cin >> n;
    
    vi arr(n);
    rep(i, 0, n) cin >> arr[i];
    
    // Your solution here
    ll sum = 0;
    for (int x : arr) sum += x;
    
    // Output
    cout << sum << "\n";
}

int main() {
    fastIO();
    
    int t = 1;
    // cin >> t;  // Uncomment for multiple test cases
    
    while (t--) {
        solve();
    }
    
    return 0;
}

/*
 * COMMON DSA PATTERNS:
 * ====================
 * 
 * ARRAY/VECTOR:
 * sort(all(arr));
 * sort(all(arr), greater<int>());
 * reverse(all(arr));
 * *max_element(all(arr));
 * accumulate(all(arr), 0LL);
 * 
 * MAP/SET:
 * map<int, int> mp; mp[key]++;
 * set<int> s; s.insert(x); s.count(x);
 * unordered_map for O(1) lookup
 * 
 * STRING:
 * s.substr(pos, len);
 * s.find(str);
 * sort(all(s));
 * 
 * BINARY SEARCH:
 * lower_bound(all(arr), x) - arr.begin();
 * upper_bound(all(arr), x) - arr.begin();
 * 
 * TWO POINTERS:
 * int l = 0, r = n - 1;
 * while (l < r) { ... }
 * 
 * SLIDING WINDOW:
 * for (int r = 0; r < n; r++) {
 *     // Add arr[r] to window
 *     while (condition) {
 *         // Remove arr[l] from window
 *         l++;
 *     }
 * }
 * 
 * BFS:
 * queue<int> q; q.push(start);
 * while (!q.empty()) {
 *     int u = q.front(); q.pop();
 *     for (int v : adj[u]) { ... }
 * }
 * 
 * DFS:
 * void dfs(int u) {
 *     vis[u] = true;
 *     for (int v : adj[u]) {
 *         if (!vis[v]) dfs(v);
 *     }
 * }
 */
