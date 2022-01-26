/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/5/21
 */

#include <iostream>
#include "timer.h"

using namespace std;

extern "C" int threexplusone (int);

int main() {
    int x, n, res;
    float time;

    cout << "Enter a number: ";
    cin >> x;

    cout << "Enter iterations of subroutine: ";
    cin >> n;

    timer t;

    res = threexplusone(x);

    t.start();
    for (int i = 0; i < n; i++) {
        threexplusone(x);
    }
    t.stop();

    time = t.getTime() / n;

    cout << "Steps: " << res << endl;
    // cout << "Took " << time << " seconds" << endl;

    return 0;
}
