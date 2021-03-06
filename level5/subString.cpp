class Solution {
 public:
  int strStr(char *haystack, char *needle) {
    if (!haystack || !needle) return -1;
    for (int i = 0;; ++i) {
      for (int j = 0;; ++j) {
        if (needle[j] == 0) return i;
        if (haystack[i + j] == 0) return -1;
        if (haystack[i + j] != needle[j]) break;
      }
    }
  }
};