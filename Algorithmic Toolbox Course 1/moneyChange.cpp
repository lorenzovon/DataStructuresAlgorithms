#include <iostream>
using namespace std;
int minCoins(int m);
int main()
{
  int m;
  cin >> m;
  cout << minCoins(m) << endl;
  return 0;
}
int minCoins(int m)
{
  int coins = 0;
  int a[3] = {1, 5, 10};
  for (int i = 2; i >= 0; i--)
  {
    if (m >= a[i])
    {
      coins += (m / a[i]);
      m %= a[i];
    }
  }
  return coins;
}