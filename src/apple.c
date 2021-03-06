#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int j;
  int l = 0;
  for(int i = 0; i < n; i++){
    j = ((A[i] -1) / x) + 1;
    l += j;
  }
  return l <= k;
}

int main(){
  int i, lb, ub;
  int max = 0;
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
      ub = m;
    }
    else {
      lb = m;
    }
  }
  printf("%d\n", ub);
  return 0;
}