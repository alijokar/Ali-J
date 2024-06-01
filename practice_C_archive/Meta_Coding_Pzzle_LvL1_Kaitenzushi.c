/*
There are N dishes in a row on a kaiten belt, with the ith dish being of type D_i. Some dishes may be of 
the same type as one another. You're very hungry, but you'd also like to keep things interesting. The N
dishes will arrive in front of you, one after another in order, and for each one you'll eat it as long as
it isn't the same type as any of the previous K dishes you've eaten. You eat very fast, so you can consume
a dish before the next one gets to you. Any dishes you choose not to eat as they pass will be eaten by others.
Determine how many dishes you'll end up eating.
Please take care to write a solution which runs within the time limit.

Constraints:
1 <= N <= 500000
1 <= K <= N
1 <= Di <= 1000000

Sample test case #1: 
    N = 6, K = 1, D = [1, 2, 3, 3, 2, 1] ----> Expected Return Value = 5
*/
int getMaximumEatenDishCount(int N, int* D, int K);

#include <stdio.h>

long long getMaxAdditionalDinersCount(long long N, long long K, int M, long long* S);

int main(){
    int N=6, K=1;
    int D[]={1, 2, 3, 3, 2, 1};

    printf("%d dishes will be eaten!", getMaximumEatenDishCount(N, D, K));
}


int getMaximumEatenDishCount(int N, int* D, int K) {
  // Write your code here
  int Dish_Eaten=1;
  
  if (N==0){
    Dish_Eaten=0;
  }
  
  int temp_value=0, temp_value_1=0, temp_value_2=0, Last_Dish=0;;
 
  for (int i=1; i < N; i++){
    
    temp_value=0;
    temp_value_1 = D[i];
    
    for (int j=0; j < K; j++){    
      
      if ((Last_Dish-j) > -1){
        
        temp_value_2 = D[Last_Dish-j];
        
        if (temp_value_1 == temp_value_2){
          temp_value +=1;
        }
      }
    }
    
    if (temp_value == 0){
      Dish_Eaten += 1;
      Last_Dish = i;
    }
  }
  return Dish_Eaten;
}