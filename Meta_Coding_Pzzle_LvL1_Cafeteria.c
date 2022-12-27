/*
A cafeteria table consists of a row of N seats, numbered from 1 to N from left to right. Social distancing guidelines require that every diner be seated such that K seats to their left and K seats to their right (or all the remaining seats to that side if there are fewer than K) remain empty.
There are currently M diners seated at the table, the ith of whom is in seat S_i. No two diners are sitting in the same seat, and the social distancing guidelines are satisfied.
Determine the maximum number of additional diners who can potentially sit at the table without social distancing guidelines being violated for any new or existing diners, assuming that the existing diners cannot move and that the additional diners will cooperate to maximize how many of them can sit down.
Please take care to write a solution which runs within the time limit.

Constraints:
1 <= N <= 10^15
1 <= K <= N
1 <= M <= 500000
M <= N
1 <= S_i <= N

Sample test case #1: 
    N = 10, K = 1, M = 2, S = [6, 2] ----> Expected Return Value = 3

Sample test case #2: 
    N = 15, K = 2, M = 3, S = [11, 6, 14] ----> Expected Return Value = 1
*/


#include <stdio.h>
#include <time.h>

long long getMaxAdditionalDinersCount(long long N, long long K, int M, long long* S);

int main()
{
    long long N=1, K= 2, M=0, S[]={};
    // clock is being used to calculate process time and Time taken by a process
    clock_t t;
    double time_taken;
    
    t = clock();
    printf("%lld\n", getMaxAdditionalDinersCount(N, K, M, S));
    t = clock() - t;

    time_taken = ((double)t)/CLOCKS_PER_SEC; 

    printf("Time taken by f(): %f\n", time_taken);

}


long long getMaxAdditionalDinersCount(long long N, long long K, int M, long long* S) {
  // Arr is an array for table numbers from 1, ..., N
  long long Arr[N];
  
  long long sum=0;
  
  // First step is to set all values to 1 (Ready to be occupied)
  for (int i=0; i<N; i++){
    Arr[i]=1;
  }

  //Second step is to force -/+K tables next to occupied tables to not allowed to be accupied.
  for (int i=0; i<M; i++){
    int temp=S[i];   
    Arr[temp-1]=0;
    
    for (int j=1; j<(K+1); j++){
      if ((temp-j) > 0){
        Arr[temp-1-j]=0;
      }
      if ((temp+j) < (N+1)){
        Arr[temp-1+j]=0;
      }
    }    
  }

  //Third step is to force -/+K tables next to available tables to not allowed to be accupied. 
  for (int i=0; i<N; i++){
    if (Arr[i]==1){
      for (int j=1; j<(K+1); j++){
        if ((i-j) > 0){
          Arr[i-j]=0;
        }
        if ((i+j) < (N+1)){
          Arr[i+j]=0;
        }
      }
    }
  }
  
  for (int i=0; i<N; i++){
    sum+=Arr[i];
  }

  return sum;
}