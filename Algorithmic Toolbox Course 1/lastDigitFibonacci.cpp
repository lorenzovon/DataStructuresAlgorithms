#include <iostream>
using namespace std;
int fibonacciArray(uint64_t n);
int main()
{
  uint64_t n;
  cin >> n;
  cout << fibonacciArray(n) << endl;
  return 0;
}
int fibonacciArray(uint64_t n)
{
  int F[n];
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    F[i] = (F[i - 1] + F[i - 2]) % 10;
  }
  return F[n];
}