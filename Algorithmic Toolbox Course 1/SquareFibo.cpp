#include <iostream>
using namespace std;
uint64_t fibo(uint64_t n, uint64_t m);
uint64_t pisano(uint64_t m);
int main()
{
  uint64_t n, m;
  cin >> n;
  m = 10;
  cout << (fibo(n, m) * fibo(n + 1, m)) % m << endl;
  return 0;
}
uint64_t fibo(uint64_t n, uint64_t m)
{
  uint64_t one, two, result;
  uint64_t final = n % pisano(m);
  one = 0;
  two = 1;
  result = final;
  for (uint64_t i = 1; i < final; i++)
  {
    result = (one + two) % m;
    one = two;
    two = result;
  }
  return result % m;
}
uint64_t pisano(uint64_t m)
{
  uint64_t one = 0, two = 1, three = one + two;
  for (uint64_t i = 0; i < m * m; i++)
  {
    three = (one + two) % m;
    one = two;
    two = three;
    if (one == 0 && two == 1)
    {
      return i + 1;
    }
  }
}