// Code mely
// Tìm dãy con tăng dài nhất bằng QHĐ cải tiến bằng fenwick tree + nén số
// ĐPT: O(N * log(n))

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int N = 1e5 + 9;
const int oo = 1e9 + 9;

int n, a[N], dp[N];

// dp[val] : Độ dài dãy con tăng dài nhất kết thúc tại phần tử có giá trị val    

// dp[val] = max(dp[x] + 1) với 0 <= x < val

// Ta có thể đặt phần tử có giá trị val vào sau phần tử có giá trị x (vì x < val) 

// và tạo thành dãy có độ dài dp[x] + 1

void update(int id, int x) {   // dp[id] = x (thao tác cập nhật trên fenwick tree)
  
    while (id <= n) 
      {  
        dp[id] = max(dp[id], x);
        id += id & (-id);
      }
  
}

int get(int id) {             // max(dp[0..id]) (thao tác lấy giá trị trên fenwick tree)
  
    int res = 0;
    while (id > 0) 
      {
        res = max(res, dp[id]);
        id -= id & (-id);
      }
  
    return res;
}
map <int, int> number;

void compress() {
  
    int cnt = 0;
    for (auto &xnew : number)
      xnew.second = ++cnt;
    for (int i = 1; i <= n; i++)
      a[i] = number[a[i]];
}

signed main() {
  
    cin >> n;
    for (int i = 1; i <= n; i++)
      {
        cin >> a[i]; 
        number[a[i]] = 0;  
      }  
       
    compress();   // nén giá trị của dãy a, sao cho 1 <= a[i] <= n 

    int res = 0;
    for (int i = 1; i <= n; i++) 
      {
        int len = get(a[i] - 1);  // Dãy con dài nhất mà phần tử kết thúc < a[i]. ie max(dp[x]) với x < a[i]
        res = max(res, len + 1);  
        update(a[i], len + 1);    // gán dp[len + 1] = a[i]
      }

    cout << res;
    return 0;
}
