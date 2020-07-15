#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) ((a) < (b)) ? (a) : (b)
#define NO_OP 0
#define SUB_1 1
#define DIV_2 2
#define DIV_3 3

int main(void) {
        int num=10;
        int i;
        int *out;
        int *res;

        printf("Enter the number: ");
        scanf("%d", &num);

        out = (int*)malloc(sizeof(int) * (num+1));
        res = (int*)malloc(sizeof(int) * (num+1));

        out[1] = 0;
        res[1] = NO_OP;
        for(i=2; i <= num; i++) {
                out[i] = out[i-1] + 1;
                res[i] = SUB_1;
                
                
                if (i%2 == 0) {
                    if ((out[i/2] + 1) < out[i]) {
                        res[i] = DIV_2;
                        
                    }
                    out[i] = MIN(1 + out[i/2], out[i]);
                }
                if (i%3 == 0) {
                    if ((out[i/3] + 1) < out[i]) {
                        res[i] = DIV_3;
                        
                    }
                    out[i] = MIN(1 + out[i/3], out[i]);
                }
        }

        printf("The minimum number of steps to go down to 1 is: %d\n", out[num]);
        
        printf("\n");
        // Print the sequence, we already know the number of steps to print
        for (i = out[num]; i > 0; i--) {
            printf("%d,", res[num]);
            
            if (res[num] == SUB_1) {
                num = num - 1;
            } else if (res[num] == DIV_2) {
                num = num / 2;
            } else {
                num = num / 3;
            }
        }
        printf("\n");
        
        return 0;
}