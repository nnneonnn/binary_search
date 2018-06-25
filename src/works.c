#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int j = 1;
  int l = 0;
  for(int i = 0; i < n; i++){
    if (A[i] > m) return 0;
    l += A[i];
    if (l > m){
      j++;
      l = A[i];
    }
  }
  return j <= k;
}


int main(){
  int i, lb, ub;
  int sum = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    sum += A[i];
  }
  lb = 0;
  ub = sum;
  while (ub-lb>1){
    int m = (ub + lb)/2;
    if (p(m)) ub = m;
    else lb = m;
  }
  printf("%d\n", ub);
  return 0;
}