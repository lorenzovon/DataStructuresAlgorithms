#include <iostream>
using namespace std;
uint64_t fibonacciArray(int n);
int main()
{
  int n;
  cin >> n;
  cout << fibonacciArray(n) << endl;
  return 0;
}
uint64_t fibonacciArray(int n)
{
  uint64_t F[n];
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    F[i] = F[i - 1] + F[i - 2];
  }
  return F[n];
}