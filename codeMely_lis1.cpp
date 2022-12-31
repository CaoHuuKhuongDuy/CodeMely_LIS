// Code mely
// Tìm dãy con tăng dài nhất bằng QHĐ
// ĐPT: O(N * N)

#include <iostream>

using namespace std;

const int N = 1e4 + 9;
const int oo = 1e9 + 9;

int n, a[N], dp[N];

// dp[i] : Dãy con tăng dài nhất kết thúc tại i

signed main() {
  
    cin >> n;
    for (int i = 1; i <= n; i++)
       cin >> a[i];
       
    a[0] = -oo;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < i; j++)
        if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);     
      
    int res = 0;
    for (int i = 1; i <= n; i++)
       res = max(res, dp[i]);
    cout << res;
  
	return 0;
}
