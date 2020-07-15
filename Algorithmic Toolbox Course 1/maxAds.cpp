#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int profit[n], avg[n];
  for (int i = 0; i < n; i++)
  {
    cin >> profit[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> avg[i];
  }
  sort(profit, profit + n);
  sort(avg, avg + n);
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += (long long)profit[i] * avg[i];
  }
  cout << sum << endl;
  return 0;
}