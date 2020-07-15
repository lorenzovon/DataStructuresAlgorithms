// remember whenever u get segmentation fault core dumped try using vector and it will resolve 

#include <iostream>
#include <vector>
using namespace std;

uint64_t maxValue(uint64_t capacity,uint64_t bars,const vector<uint64_t> &weight);

uint64_t larger(uint64_t a,uint64_t b);

int main(){
    uint64_t capacity,bars;
    cin >> capacity >> bars;
    // uint64_t weight[bars];
    vector<uint64_t>weight(bars+1);
    for(uint64_t i=0;i<bars;i++){
        cin >> weight[i];
    }

    uint64_t k=maxValue(capacity,bars,weight);
    cout << k << endl;

    return 0;
}

uint64_t larger(uint64_t a,uint64_t b){
    return (a>b)?a:b;
}

uint64_t maxValue(uint64_t capacity,uint64_t bars,const vector<uint64_t> &weight){    


    vector<vector<uint64_t>>solved;
    solved.resize(bars+1,vector<uint64_t>(capacity+1,0));
    
    // uint64_t solved[bars+1][capacity+1];    
    for(uint64_t i=0;i<=bars;i++){
        for(uint64_t j=0;j<=capacity;j++){
            if(i==0 || j==0 ){
                solved[i][j]=0;
            }
            else if(weight[i-1]<=j){
                solved[i][j]=larger(weight[i-1]+solved[i-1][j-weight[i-1]],solved[i-1][j]);
            }
            else{
                solved[i][j]=solved[i-1][j];
            }
            // cout << "hello world " << i << " " << j << endl;
        }
    }
    return solved[bars][capacity];
}