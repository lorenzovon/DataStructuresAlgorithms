#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int64_t n;
  cin >> n;
  int64_t a[n];
  for (int64_t i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a, a + n);
  cout << a[n - 2] * a[n - 1] << endl;
  return 0;
}