#include <iostream>
using namespace std;
int lastDigit(uint64_t n);

int fibonacciArray(int n);
int main()
{
  uint64_t n;
  cin >> n;
  cout << lastDigit(n) << endl;
  return 0;
}
int fibonacciArray(int n)
{
  int F[n];
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    F[i] = (F[i - 1] + F[i - 2]) % 10;
  }
  int sum = 0;
  for (int i = 0; i <= n; i++)
  {
    sum += F[i];
  }
  return sum;
}
int lastDigit(uint64_t n)
{
  uint64_t x = 0, y = 0, z = 0;
  x = n / 60;

  y = n % 60;

  if (n <= 60)
  {
    z = fibonacciArray(n);
  }
  else
  {
    z = ((x - 1) * fibonacciArray(59)) + fibonacciArray(y);
  }
  return z % 10;
}
