#include <iostream>
#include <algorithm>
using namespace std;
int findMajority(uint64_t data[], uint64_t n);
int main()
{
  uint64_t n;
  cin >> n;
  uint64_t a[n];
  for (uint64_t i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a, a + n);
  cout << findMajority(a, n) << endl;
  return 0;
}
int findMajority(uint64_t data[], uint64_t n)
{
  uint64_t min = (n / 2) + 1;
  bool major = false;
  for (uint64_t i = 0; i < min; i++)
  {
    if (data[i] == data[i + min - 1])
    {
      major = true;
      return 1;
    }
    if (i == n / 2 && major == false)
    {
      return 0;
    }
  }
}
