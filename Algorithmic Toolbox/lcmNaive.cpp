#include <iostream>
using namespace std;
long int gcd(long int a, long int b);
uint64_t lcm(long int a, long int b);
int main()
{
  long int a = 0, b = 0;
  cin >> a >> b;
  cout << lcm(a, b) << endl;
  return 0;
}
uint64_t lcm(long int a, long int b)
{
  uint64_t x = 0;
  x = a * b;
  return x / gcd(a, b);
}
long int gcd(long int a, long int b)
{
  while (a != 0 && b != 0)
  {
    if (a > b)
    {
      return gcd(b, a % b);
    }
    else
    {
      return gcd(b % a, a);
    }
  }
  if (a == 0 || b == 0)
  {
    if (a == 0)
    {
      return b;
    }
    else
    {
      return a;
    }
  }
}