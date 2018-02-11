//Author - sorablaze_11
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define mod 1000000007
#define inf 0x3f3f3f3f
#define INF 1e18
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long int
#define ld long double

inline ll gcd(ll a,ll b) { return b ? gcd(b, a % b): a;}
inline ll fast_pow(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for(;b;b >>= 1){ if(b & 1) res = res * a % mod; a = a * a % mod; } return res;}
inline bool isPrime(ll a){ for(ll i = 2; i * i <= a; i++) if(a % i == 0) return 0; return 1;}

const int N = 1e5+5, sqrtValue = 500;
int n, q, type, idx, val, arr[N], mat[sqrtValue][sqrtValue], dp[sqrtValue][sqrtValue];
unordered_map<int, int> cnt[sqrtValue];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int temp = 0;
    bool flag = false;
    for(int i = 0; i < sqrtValue; i++){
        for(int j = 0; j < sqrtValue; j++){
            dp[i][j] = mat[i][j] = arr[temp++];
            if(j > 0) dp[i][j] ^= dp[i][j - 1];
            cnt[i][dp[i][j]]++;
            if(temp >= n){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    while(q--){
        scanf("%d%d%d", &type, &idx, &val);
        idx--;
        if(type == 1){
            int t1 = idx / sqrtValue, t2 = idx % sqrtValue;
            temp = t1 * sqrtValue;
            mat[t1][t2] = val;
            for(int i = 0; i < sqrtValue; i++){
                cnt[t1][dp[t1][i]]--;
                dp[t1][i] = mat[t1][i];
                if(i > 0) dp[t1][i] ^= dp[t1][i - 1];
                cnt[t1][dp[t1][i]]++;
                temp++;
                if(temp >= n) break;
            }
        }else{
            temp = val;
            int t1 = idx / sqrtValue, t2 = idx % sqrtValue, ans = 0;
            for(int i = 0; i < t1; i++){
                if(cnt[i].find(temp) != cnt[i].end()) ans += cnt[i][temp];
                //cout << temp << ' ' << ans << '\n';
                temp ^= dp[i][sqrtValue - 1];
            }
            //cout << temp << '\n';
            for(int i = 0; i <= t2; i++) if(temp == dp[t1][i]) ans++;
            printf("%d\n", ans);
            //cout << '\n';
        }
    }
    return 0;
}
