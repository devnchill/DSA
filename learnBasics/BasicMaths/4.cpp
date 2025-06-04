class Solution {
public:
  int GCD(int n1, int n2) {
    while (n1 > 0 && n2 > 0) {
      if (n1 > n2) {
        n1 = n1 % n2;
      } else {
        n2 = n2 % n1;
      }
    }
    if (n2 == 0) {
      return n1;
    }
    return n2;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  s.GCD(26, 36);
  return 0;
}
