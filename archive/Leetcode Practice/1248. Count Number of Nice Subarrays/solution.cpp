#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    int l = 0, r = 0;
    int sl = 0, sr = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] & 1) {
        sl++;
        sr++;
      }
      while (sl > k) {
        if (nums[l] & 1) {
          sl--;
        }
        l++;
      }
      while (sr >= k) {
        if (nums[r] & 1) {
          sr--;
        }
        r++;
      }
      if (sl == k) {
        ans += r - l;
      }
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> v{1, 1, 2, 1, 1};
  cout << Solution().numberOfSubarrays(v, 3) << '\n';
}
