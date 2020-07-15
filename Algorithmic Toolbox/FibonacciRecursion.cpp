#include <iostream>
using namespace std;

int fibonacciNaive(int n);
int main()
{
  int n;
  cin >> n;
  cout << fibonacciNaive(n) << endl;
  return 0;
}
int fibonacciNaive(int n)
{
  if (n <= 1)
  {
    return n;
  }
  else
  {
    return fibonacciNaive(n - 1) + fibonacciNaive(n - 2);
  }
}