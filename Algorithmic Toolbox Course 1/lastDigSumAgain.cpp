#include <iostream>
#include <cmath>
using namespace std;
int lastDigit(uint64_t m, uint64_t n);
uint64_t fibonacciSum(int a, int b);
int main()
{
  uint64_t n, m;
  cin >> m >> n;
  cout << lastDigit(m, n) << endl;
  return 0;
}
int lastDigit(uint64_t m, uint64_t n)
{
  uint64_t m1 = 0, n1 = 0, a = 0, b = 0;
  m1 = m / 60;
  n1 = n / 60;
  a = m % 60;
  b = n % 60;
  int sum = 0;
  if (m1 = n1)
  {
    return fibonacciSum(a, b) % 10;
  }
  else
  {
    return ((n1 - m1 - 1) * fibonacciSum(0, 59) + fibonacciSum(a, 59) + fibonacciSum(0, b)) % 10;
  }
}
uint64_t fibonacciSum(int a, int b)
{
  int F[60];
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i < 60; i++)
  {
    F[i] = (F[i - 1] + F[i - 2]) % 10;
  }
  uint64_t sum = 0;

  for (uint64_t i = a; i <= b; i++)
  {
    sum += F[i];
  }
  return sum;
}
