#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int j;
  int l = 0;
  for(int i = 0; i < n; i++){
    j = A[i] / x;
    l += j;
  }
  return l >= k;
}


int main(){
  int i, lb, ub;
  int max;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    if (max < A[i]){
      max = A[i];
    }
  }
  lb = 0;
  ub = max;
  while (ub-lb>1){
    int m = (ub + lb)/2;
    if (p(m)){
      lb = m;
    }
    else {
      ub = m;
    }
  }
  printf("%d\n", lb);
  return 0;
}