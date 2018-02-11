// Author - sorablaze_11
#include "bits/stdc++.h"
using namespace std;

const int N = 1e5, rootN = ceil(sqrt(100000.0));
int n, m, x, y, arr[N], minArr[rootN];
char type;

void preprocess(){
    for(int i = 0; i < ceil(float(n) / rootN); i++){
        int min_ = INT_MAX;
        for(int j = 0; j < rootN && j + i * rootN < n; j++) min_ = min(min_, arr[j + i * rootN]);
        minArr[i] = min_;
    }
}

int query(int l, int r){
    int block_l = l / rootN, block_r = r / rootN, min_ = INT_MAX;
    if(block_l == block_r) for(int i = l; i <= r; i++) min_ = min(min_, arr[i]);
    else{
        for(int i = l; i < (block_l + 1) * rootN; i++) min_ = min(min_, arr[i]);
        for(int i = block_r * rootN; i <= r; i++) min_ = min(min_, arr[i]);
        for(int i = block_l + 1; i < block_r; i++) min_ = min(min_, minArr[i]);
    }
    return min_;
}

void update(int pos, int val){
    int block = pos / rootN, min_ = INT_MAX;
    arr[pos] = val;
    for(int i = 0; i < rootN && i + block * rootN < n; i++) min_ = min(min_, arr[i + block * rootN]);
    minArr[block] = min_;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    preprocess();
    //for(int i = 0; i < n / rootN + 1; i++) cout << minArr[i] << '\n';
    for(int i = 0; i < m; i++){
        cin >> type >> x >> y;
        if(type == 'q') cout << query(--x, --y) << '\n';
        else update(--x, y);
    }
    return 0;
}
