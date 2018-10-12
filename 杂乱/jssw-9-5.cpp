// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <cstdio>
// #include <math.h>
// #include <queue>
// using namespace std;
// const int maxn=105;
// int main(){

// 	return 0;
// }

#include <stdio.h>  
  
int main(void)  
{  
    int m, k, i, j, n, min, temp, sum, count = 1;  
    int F[100][100];  
  
    while (1) {  
        scanf("%d%d", &m, &k);  
        for (i = 0; i < m; i++)  
            scanf("%d", &F[0][i]);  
        F[1][0] = F[0][0];  
        for (i = 1; i < m; i++)  
            F[1][i] = F[1][i - 1] + F[0][i];  
        for (i = 2; i <= k; i++) {  
            for (j = 0; j < m; j++) {  
                if (i > j + 1)  
                    F[i][j] = F[i - 1][j];  
                else {  
                    min = F[1][j];  
                    sum = 0;  
                    for (n = j; n >= 0; n--) {  
                        sum += F[0][n];  
                        temp = sum < F[i - 1][n - 1] ? F[i - 1][n - 1] : sum;  
                        if (min >= temp)  
                            min = temp;  
                        else  
                            break;  
                    }  
                    F[i][j] = min;  
                }  
            }  
        }  
        for (i = 1; i <= k ; i++)  
            if (!F[i][m- 1])  
                break;  
        if (m < 1)  
            temp = 0;  
        else  
            temp = F[i - 1][m - 1];  
        printf("Case %d:%d\n", count++, temp);  
    }  
  
    return 0;  
} 