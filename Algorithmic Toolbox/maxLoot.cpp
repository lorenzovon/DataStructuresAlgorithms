#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct item
{
  uint64_t value;
  uint64_t weight;
};
bool comp(item i1, item i2)
{
  double d1 = (double)i1.value / i1.weight;
  double d2 = (double)i2.value / i2.weight;
  return d1 > d2;
}
double knapGreedy(uint64_t w, item data[], uint64_t n);

int main()
{
  uint64_t n, w;
  cin >> n >> w;
  item data[n];
  for (uint64_t i = 0; i < n; i++)
  {
    cin >> data[i].value;
    cin >> data[i].weight;
  }
  cout << setiosflags(ios::fixed)
       << setiosflags(ios::showpoint)
       << setprecision(4) << knapGreedy(w, data, n);
  return 0;
}
double knapGreedy(uint64_t w, item data[], uint64_t n)
{
  double presentW = 0;
  sort(data, data + n, comp);
  double maxValue = 0;
  for (uint64_t i = 0; i < n; i++)
  {
    if (presentW + data[i].weight <= w)
    {
      presentW += data[i].weight;
      maxValue += data[i].value;
    }
    else
    {
      double left = w - presentW;
      maxValue += data[i].value * ((double)(left / data[i].weight));
      break;
    }
  }
  return maxValue;
}
