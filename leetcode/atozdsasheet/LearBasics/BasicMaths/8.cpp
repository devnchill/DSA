#include <bits/stdc++.h>
using namespace std;
int anyBaseToDecimal(int base, string num) {
  int total = 0;
  // if the current character is more than 9 which means it would be uppercase
  // alphabet A...Z , so curr would store their value in decimal system
  int curr = 0;
  for (auto it : num) {
    // formula = total * base + current value
    if ('0' <= it && it <= '9') {
      total = (total * base) + (it - '0');
    } else {
      curr = it - 65 + 10;
      total = (total * base) + curr;
    }
  }
  return total;
}
int main(int argc, char *argv[]) {
  cout << anyBaseToDecimal(2, "1011") << endl;
  cout << anyBaseToDecimal(8, "4763") << endl;
  cout << anyBaseToDecimal(16, "1A81") << endl;
  return 0;
}
