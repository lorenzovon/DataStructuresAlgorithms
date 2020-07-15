#include <iostream>
#include <algorithm>
using namespace std;
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
  for (uint64_t i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}