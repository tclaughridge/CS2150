#include <iostream>

using namespace std;


int main() {
   int n = 2;
   int *p = &n;
   *p = 5;
   n += 1;
   cout << n << endl;
   return 0;
}