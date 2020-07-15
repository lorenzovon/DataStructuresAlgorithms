#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct segment
{
  uint64_t x;
  uint64_t y;
};

bool inAscending(segment a,segment b){
  return (a.y<b.y);
}

int main()
{
  int n;  
  cin >> n;  
  segment data[n];
  for (int i = 0; i < n; i++)
  {
    cin >> data[i].x >> data[i].y;
  }
  sort(data, data+n, inAscending);
  // for (int i = 0; i < n; i++)
  // {
  //   cout << data[i].x << " " << data[i].y;
  //   cout << endl;
  // }
  vector<int> minimumPoints ;
  int smallest = data[0].y ;
  minimumPoints.push_back(smallest);

  for(int i=1;i<n;++i){
    if(smallest < data[i].x || smallest > data[i].y){
      smallest = data[i].y;
      minimumPoints.push_back(smallest);
      // cout << smallest;
    }
  }

  cout << minimumPoints.size() << endl ;

  for (int i = 0; i < minimumPoints.size(); i++)
  {
    cout << minimumPoints[i];
    cout << " ";
  }
  cout << endl;
  
  return 0;
}