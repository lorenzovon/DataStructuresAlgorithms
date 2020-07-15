// the problem was you were returning value from bool which is always true

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
float leastFloat(float a,float b){
  return (a<b)?a:b;
}
long double distanceSquare(point p1,point p2){
  // long double temp=((p1.xAxis-p2.xAxis)*(p1.xAxis-p2.xAxis))+((p1.yAxis-p2.yAxis)*(p1.yAxis-p2.yAxis));
  // return sqrt(temp);
  return sqrtl(((p1.xAxis-p2.xAxis)*(p1.xAxis-p2.xAxis))+((p1.yAxis-p2.yAxis)*(p1.yAxis-p2.yAxis)));
}
float leastDistance(point data[],int nop){
  long double least=numeric_limits<float>::max();
  for(int i=0;i<nop;++i){
    for(int j=i+1;j<nop;++j){
      if(distanceSquare(data[i],data[j])<least){
        least=distanceSquare(data[i],data[j]);
      }
    }
  }
  return least;
}

float closestWithD(vector<point> &data,int nop,float d){
  float leastIn=d;
  for(int i=0;i<nop;i++){
    for(int j=i+1;j<nop && (data[j].yAxis-data[i].yAxis)<leastIn ;j++){
      if(distanceSquare(data[i],data[j])<leastIn){
        leastIn=distanceSquare(data[i],data[j]);
      }
    }
  }
  return leastIn;
}

float recursiveLeast(point dataX[],point dataY[],int nop){
  if(nop<=3){
    return leastDistance(dataX,nop);
  }
  int middle=nop/2;
  point middlePoint=dataX[middle];

  // vector<point> dataYLeft;
  // dataYLeft.resize(middle+1);
  point dataYLeft[middle+1];
  // vector<point> dataYRight;
  // dataYRight.resize(nop-middle-1);
  point dataYRight[nop-middle-1];
  int lef=0,rig=0;
  for(int i=0;i<nop;i++){
    if(dataY[i].xAxis <=middlePoint.xAxis){
      dataYLeft[lef++]=dataY[i];
    }
    else{
      dataYRight[rig++]=dataY[i];
    }
  }
  
  // vector<point> tempo;
  // for(int i=middle;i<nop;i++){
  //   tempo.push_back(dataX[i]);
  // }
  float dLeft=recursiveLeast(dataX,dataYLeft,middle);
  float dRight=recursiveLeast(dataX+middle,dataYRight,nop-middle);

  float d=leastFloat(dLeft,dRight);

  vector<point> finalStrip;
  finalStrip.resize(nop);
  // point finalStrip[nop];
  int j=0;
  for(int i=0;i<nop;i++){
    if(abs(dataY[i].xAxis-middlePoint.xAxis)<d){
      finalStrip[j]=dataY[i],j++;
    }
  }
  return leastFloat(d,closestWithD(finalStrip,j,d));
}

float finalLeast(vector<point> &data,int nop){
  // vector<point> dataX;
  // dataX.resize(nop);
  point dataX[nop];
  // vector<point> dataY;
  // dataY.resize(nop);
  point dataY[nop];

  for(int i=0;i<nop;i++){
    dataX[i]=data[i];
    dataY[i]=data[i];
  }

  sort(dataX,dataX+nop,compareWithX);
  sort(dataY,dataY+nop,compareWithY);
  // sort(dataX.begin(),dataX.end(),compareWithX);
  // sort(dataY.begin(),dataY.end(),compareWithY);

  return recursiveLeast(dataX,dataY,nop);
}

int main()
{
  uint64_t n;
  cin >> n;
  vector<point>data;
  data.resize(n);
  for (uint64_t i = 0; i < n; i++)
  {
    cin >> data[i].xAxis >> data[i].yAxis;
  }    
  cout << finalLeast(data,n) << endl;  
  
  return 0;
}