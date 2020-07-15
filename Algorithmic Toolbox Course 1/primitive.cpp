// submitted program

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

int leastOp(int input,int iter,int iterSet[]);

int main(){
    int iter,amount;    
    iter=3;    
    int iterSet[iter]={1,2,3};
    cin >> amount;
    // int k = leastOp(amount,iter,iterSet);
    // cout << k << endl ;
    leastOp(amount,iter,iterSet);
    return 0;
}

int leastOp(int input,int iter,int iterSet[]){
    int solved[input+1];
    solved[0]=0;
    solved[1]=0;

    int maximum = INT_MAX;
    // for(int i=2;i<=input;i++){
    //     solved[i]=maximum;
    // }

    int opSet[input+1];
    opSet[0]=0;
    opSet[1]=0;

    for(int i=2;i<=input;i++){
        int leftOver;
        int nextPoint;

        solved[i]=solved[i-1]+1;
        opSet[i]=1;

        if(i%2==0){
            if(solved[i/2]+1<solved[i]){
                opSet[i]=2;                
                solved[i]=solved[i/2]+1;
            }            
        }
        if(i%3==0){
            if(solved[i/3]+1<solved[i]){
                opSet[i]=3;
                solved[i]=solved[i/3]+1;
            }
        }                
    }    

    cout << solved[input] << endl ;        

    // for(int i=solved[input];i>=0;i--){
    //     // cout << opSet[input] << " " ;
    //     cout << input << " " ;
    //     if(opSet[input]==1){
    //         input=input-1;
    //     }
    //     else if(opSet[input]==2){
    //         input=input/2;
    //     }
    //     else{
    //         input=input/3;
    //     }
    // }

    int output[solved[input]];

    int temp= solved[input];

    for(int i=solved[input];i>=0;i--){
        // cout << opSet[input] << " " ;
        output[i]=input;
        // cout << input << " " ;
        if(opSet[input]==1){
            input=input-1;
        }
        else if(opSet[input]==2){
            input=input/2;
        }
        else{
            input=input/3;
        }
    }

    for(int i=0;i<=temp;i++){
        cout << output[i] << " ";
    }

    // cout << input;

    // for (auto ir = solutionSet.begin(); ir != solutionSet.end(); ++ir)
    // {
    //     cout << *ir << " ";
    // }
    cout << endl;
}
