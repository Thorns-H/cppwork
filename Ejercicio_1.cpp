#include <iostream>

using namespace std;

int main() {

  int n;
  int x=1;
  cout << "Dime un numero entero : ~"; cin >> n;

  for (int i=1;i<=n;i++) {
    for (int z=0;z<x;z++) {
      cout << "*";
    }
    cout << "\n";
    x++;
  }
  return 0;
}
