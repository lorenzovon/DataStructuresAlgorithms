#include <iostream>
using namespace std;
int gcd(long int a, long int b);
int main()
{
  long int a = 0, b = 0;
  cin >> a >> b;
  cout << gcd(a, b) << endl;
  return 0;
}
int gcd(long int a, long int b)
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