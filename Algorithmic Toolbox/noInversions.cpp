#include <iostream>

using namespace std;
uint64_t naiveCount(uint64_t data[], uint64_t n);
int main()
{
  uint64_t n;
  cin >> n;
  uint64_t data[n];
  for (uint64_t i = 0; i < n; i++)
  {
    cin >> data[i];
  }
  uint64_t total = naiveCount(data, n);
  cout << total << endl;
  return 0;
}
uint64_t naiveCount(uint64_t data[], uint64_t n)
{
  uint64_t total = 0;
  for (uint64_t i = 0; i < n - 1; i++)
  {
    for (uint64_t j = i + 1; j < n; j++)
    {
      if (data[i] > data[j])
      {
        total += 1;
      }
    }
  }
  return total;
}