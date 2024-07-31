#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll C[1005][1005]; // C[i][j] = to hop chap j cua i
//cout << C[n][k]

int mod = 1e9 + 7;

void ktao(){
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                C[i][j] = 1;
            }
            else{
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                C[i][j] %= mod;
            }
        }
    }
}

int main(){
    ktao();
    int TC;
    cin >> TC;
    while(TC--){
        int n, k; cin >> n >> k;
        cout << C[n][k] << endl;
    }
}
