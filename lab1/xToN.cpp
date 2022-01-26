#include <iostream>
using namespace std;

int xton(int x, int n) {
  if (n == 0) {
    return 1;
  } else {
    return x * xton(x, n - 1);
  }
}

int main() {
  int a, b;
  cin >> a;
  cin >> b;
  cout << xton(a, b) << endl;
  return 0;
}
