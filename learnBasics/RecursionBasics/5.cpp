#include <iostream>
using namespace std;
class Solution {
public:
  void reverse(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while (start != end) {
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++;
      end--;
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << endl;
    }
    return;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int arr[] = {2, 3, 6, 6, 66};
  s.reverse(arr, 5);
  return 0;
}
