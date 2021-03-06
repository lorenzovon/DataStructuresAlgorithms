#include <iostream>
#include <algorithm>
using namespace std;

struct point
{
  int64_t fi;
  int64_t la;
};

bool comp(point d1, point d2)
{
  return d1.la > d2.la;
}
bool compa(point d1, point d2)
{
  return d1.fi > d2.fi;
}
int binSearch(point data[], int left, int right, int key);
int Segments(point data[], int key, int s);
int naiveSegments(point data[], int key, int s);
int main()
{
  uint64_t s, p;
  cin >> s >> p;
  point data[s];
  for (uint64_t i = 0; i < s; i++)
  {
    cin >> data[i].fi >> data[i].la;
  }
  int64_t search[p];
  for (uint64_t i = 0; i < p; i++)
  {
    cin >> search[i];
  }
  sort(data, data + s, comp);
  for (uint64_t i = 0; i < p; i++)
  {
    cout << Segments(data, search[i], s) << " ";
  }

  cout << endl;
  return 0;
}
int Segments(point data[], int key, int s)
{
  int count = 0;
  for (int i = 0; i < s; i++)
  {
    if (key > data[i].la)
    {
    }
    else if (key >= data[i].fi)
    {
      count++;
    }
  }
  return count;
}
int binSearch(point data[], int left, int right, int key)
{
  while (left != right)
  {
    int mid = (left + right) / 2;
    if (data[mid].la < key)
    {
      left = mid + 1;
    }
    else
    {
      right = mid;
    }
    return mid;
  }
}
int naiveSegments(point data[], int key, int s)
{
  uint64_t count = 0;
  for (uint64_t i = 0; i < s; i++)
  {
    if (data[i].fi <= key && data[i].la >= key)
    {
      count++;
    }
  }
  return count;
}