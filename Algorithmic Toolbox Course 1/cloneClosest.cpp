// the problem was you were returning value from bool which is always true
// ther might be a problem with sqrrt function to find sqrt of 18 digits numbers ,resolve that
// i have replaced sqrt with sqrtl but no help so problem is with using vector try it some time else
// another problem was nop-middle-1 was somewhere negative , can be resolved by making a condition

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

struct point
{
  int64_t xAxis,yAxis;
};
bool compareWithX(point p1, point p2){  
  return (p1.xAxis<p2.xAxis);
}
bool compareWithY(point p1,point p2){
  return (p1.yAxis<p2.yAxis);
}
long double leastFloat(long double a,long double b){
  return (a<b)?a:b;
}
long double distanceSquare(point p1,point p2){  
  return sqrtl(((p1.xAxis-p2.xAxis)*(p1.xAxis-p2.xAxis))+((p1.yAxis-p2.yAxis)*(p1.yAxis-p2.yAxis)));
}
long double leastDistance(point data[],int nop){
  long double least=numeric_limits<long double>::max();
  for(int64_t i=0;i<nop;i++){
    for(int64_t j=i+1;j<nop;j++){
      if(distanceSquare(data[i],data[j])<least){
        least=distanceSquare(data[i],data[j]);
      }
    }
  }
  return least;
}

long double closestWithD(point data[],int64_t nop,long double d){
  long double leastIn=d;
  for(int64_t i=0;i<nop;i++){
    for(int64_t j=i+1;j<nop && (data[j].yAxis-data[i].yAxis)<leastIn ;j++){
      if(distanceSquare(data[i],data[j])<leastIn){
        leastIn=distanceSquare(data[i],data[j]);
      }
    }
  }
  return leastIn;
}

long double recursiveLeast(point dataX[],point dataY[],int64_t nop){
  if(nop<=3){
    return leastDistance(dataX,nop);
  }
  int64_t middle=nop/2;
  point middlePoint=dataX[middle];

  // vector<point> dataYLeft;
  // dataYLeft.resize(middle+1);
  point dataYLeft[middle+1];
  // vector<point> dataYRight;
  // dataYRight.resize(nop-middle-1);
  if(nop-middle-1>=0){
    point dataYRight[nop-middle-1];
    int64_t lef=0,rig=0;
    for(int64_t i=0;i<nop;i++){
      if(dataY[i].xAxis <=middlePoint.xAxis){
        dataYLeft[lef++]=dataY[i];
      }
      else{
        dataYRight[rig++]=dataY[i];
      }
    }

    long double dLeft=recursiveLeast(dataX,dataYLeft,middle);
    long double dRight=recursiveLeast(dataX+middle,dataYRight,nop-middle);

    long double d=leastFloat(dLeft,dRight);

    // vector<point> finalStrip;
    // finalStrip.resize(nop);
    point finalStrip[nop];
    int64_t j=0;
    for(int64_t i=0;i<nop;i++){
      if(abs(dataY[i].xAxis-middlePoint.xAxis)<d){
        finalStrip[j]=dataY[i],j++;
      }
    }
    return leastFloat(d,closestWithD(finalStrip,j,d));
  }
  else{
    return 0;
  }  
}

long double finalLeast(vector<point>&data,int64_t nop){
  // vector<point> dataX;
  // dataX.resize(nop);
  point dataX[nop];
  // vector<point> dataY;
  // dataY.resize(nop);
  point dataY[nop];

  for(int64_t i=0;i<nop;i++){
    dataX[i]=data[i];
    dataY[i]=data[i];
  }

  // sort(dataX.begin(),dataX.end(),compareWithX);
  // sort(dataY.begin(),dataY.end(),compareWithY);
  sort(dataX,dataX+nop,compareWithX);
  sort(dataY,dataY+nop,compareWithY);

  return recursiveLeast(dataX,dataY,nop);
}

int main()
{
  int64_t n;
  cin >> n;
  vector<point>data;
  data.resize(n);
//   point data[n];
  for (int64_t i = 0; i < n; i++)
  {
    cin >> data[i].xAxis >> data[i].yAxis;
  }    
  cout << finalLeast(data,n) << endl;  
  
  return 0;
}