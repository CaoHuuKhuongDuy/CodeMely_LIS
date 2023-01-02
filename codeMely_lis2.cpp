// Code mely
// Tìm dãy con tăng dài nhất bằng QHĐ cải tiến bằng chặt nhị phân  
// ĐPT: O(N * log(n))

#include <iostream>

using namespace std;

const int N = 1e5 + 9;
const int oo = 1e9 + 9;

int n, a[N], dp[N];

// dp[len] : giá trị phần tử kết thúc nhỏ nhất với dãy con tăng độ dài len (tại thời điểm đang xét)    

int binarySearch(int l, int r, int x) {
  
    int res = 1;
    while (l <= r) { 
      int mid = (l + r) / 2;
      if (dp[mid] >= x) {
        res = mid;
        r = mid - 1;  
      } 
      else l = mid + 1;
    }
    return res;
  
}

signed main() {
  
    cin >> n;
    for (int i = 1; i <= n; i++)
       cin >> a[i];
       
    dp[0] = -oo;
    for (int i = 1; i <= n; i++)
      dp[i] = oo;
  
    int maxLen = 0;
    for (int i = 1; i <= n; i++)
      {
        int len = binarySearch(0, maxLen + 1, a[i]); // Vị trí đầu tiên mà dp[len] >= a[i] => dp[x] < a[i] (x < len)
        dp[len] = a[i];    // len chính là độ dài dãy con tăng dài nhất kết thúc tại a[i]
        maxLen = max(maxLen, len);  
      }
    cout << maxLen;
  
    return 0;
}
