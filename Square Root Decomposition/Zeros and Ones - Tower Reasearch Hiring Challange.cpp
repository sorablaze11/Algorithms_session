//Author - sorablaze_11
#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i,a,n) for(int i = a; i < n ; i++)
#define per(i,a,n) for(int i = n - 1; i >= a;i--)
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define mod 1000000007
#define inf 0x3f3f3f3f
#define pb push_back
#define em emplace_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ll long long int
#define ull unsigned ll
#define ld long double
 
inline ll gcd(ll a,ll b) { return b ? gcd(b, a % b): a;}
inline ll fast_pow(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for(;b;b >>= 1){ if(b & 1) res = res * a % mod; a = a * a % mod; } return res;}
inline bool isPrime(ll a){ for(ll i = 2; i * i <= a; i++) if(a % i == 0) return 0; return 1;}
 
const int N = 1e6, rootN = 1e3;
int n, q, I, k, lim_i, lim_j, dp[rootN][rootN], countArr[rootN];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    for(int i = 0; i < rootN; i++){
        for(int j = 0; j < rootN; j++){
            dp[i][j] = 1;
        }
        countArr[i] = rootN;
    }
    scanf("%d %d", &n, &q);
    lim_i = (n - 1) / rootN;
    lim_j = (n - 1) % rootN;
    for(int i = 0; i < q; i++){
        scanf("%d %d", &I, &k);
        if(I){
            int tempCount = 0, i = 0;
            while(tempCount + countArr[i] < k && i < lim_i){
                tempCount += countArr[i];
                i++;
            }
            for(int j = 0; j < rootN; j++){
                tempCount += dp[i][j];
                if(tempCount == k){
                    printf("%d\n", i * rootN + j + 1);
                    break;
                }
                if(i == lim_i && j == lim_j) break;
            }
            if(tempCount < k) printf("-1\n");
        }else{
            k--;
            int r = k / rootN, c = k % rootN;
            countArr[r] -= dp[r][c];
            dp[r][c] = 0;
        }
    }
    return 0;
}
