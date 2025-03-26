#include <iostream>
using namespace std;
int main() {
  int ones = 0, twos = 0, zeros = 0;
  int n;
  cin >> n;
  for (int i = 0 ; i < n ; i++) {
    int x ; cin >> x;

    if (x == 0) zeros ++;
    else if (x == 1) ones++;
    else twos++;
  }

  while (zeros) {
    cout << 0 << " ";
    zeros--;
  }

  while (ones) {
    cout << 1 << " ";
    ones--;
  }

  while (twos) {
    cout << 2 << " ";
    twos--;
  }
}
