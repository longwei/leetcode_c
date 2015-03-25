#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

vector<int> dp;
vector<bool> vis;
// unordered_map<int, int> dp; //have slighter poor performace
bool inline consumeOne(string s, int cur) {
  // cur at least ptr to a int
  if (s[cur] == '0') return false;
  return true;
}

bool inline consumeTwo(string s, int cur) {
  if (cur >= s.size() - 1) return false;
  if (s[cur] == '1') return true;
  if (s[cur] == '2' && s[cur + 1] < '7') return true;
  return false;
}

int numDecodingsRec(string s, int cur) {
  if (cur == s.size()) return 1;
  if (vis[cur]) {
    return dp[cur];
  }
  bool one = consumeOne(s, cur);
  bool two = consumeTwo(s, cur);
  int num;
  if (!one && !two) {
    num = 0;
  }
  if (one && !two) {
    num = numDecodingsRec(s, cur + 1);
  }
  if (!one && two) {
    num = numDecodingsRec(s, cur + 2);
  }
  if (one && two) {
    num = numDecodingsRec(s, cur + 1) + numDecodingsRec(s, cur + 2);
  }
  vis[cur] = true;
  dp[cur] = num;
  return num;
}

int numDecodings(string s) {
  if (s.empty()) return 0;
  dp = vector<int>(s.size());
  vis = vector<bool>(s.size(), false);
  return numDecodingsRec(s, 0);
}

// o(1) space
int numDecodings(string s) {
  if (s.empty() || s[0] == '0') return 0;
  // Fibonacci rocks!
  int a = 1;
  int b = 1;
  for (int i = 1; i < s.length(); i++) {
    int n = 0;
    if (s[i] != '0') n += b;  // walk from the previous step
    if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
      n += a;  // jump from the step before the previous step
    }
    a = b;
    b = n;
    // if (a == 0 && b == 0) break;
  }
  return b;
}