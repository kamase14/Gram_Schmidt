#include<stdio.h>
#include <math.h>
#define size 3

double i_p(double *a,double *b){
  double sum=0;
  int i;
  for (i=0;i<=size-1;i++) sum=sum+a[i]*b[i]; 
  return sum;
}

double norm(double *a){
  double sum=0;
  int i;
  for (i=0;i<=size-1;i++) sum=sum+a[i]*a[i];
  return sqrt(sum);
}

double * v_sum(double *a,double *b){
  int i;
  for(i=0;i<=size-1;i++) a[i]=a[i]+b[i];
  return a;
}

double *scalar_p(double alpha, double *a){
  int i;
  for(i=0;i<=size-1;i++) a[i]=alpha*a[i];
  return a;
}

void show_vector(double *a){
  int i;
  printf("(");
  for (i=0;i<=size-1;i++) printf("%lf ",a[i]);
  printf(")");
  printf("\n");
}
void v_copy(double *a,double *b){
  int i;
  for(i=0;i<=size-1;i++) a[i]=b[i];
}

void calc_b_dash(double *a,double *b){
  
  double b_dash[size][size];
  double scalar_bai[size][size];
  double alpha;
  
  alpha = i_p(a[0],b[0]);
  printf("%d\n",alpha);
  // scalar_bai[0] = *scalar_p( alpha, a[0]);

  

}

int main(void){
  int i,k;
  double tmp[size];
  double a[size][size]=
  {
    {1.0,0.0,0.0},
    {1.0,1.0,0.0},
    {1.0,1.0,1.0}
  };

  calc_b_dash(a[0],a[1]);
  
  scalar_p(1/norm(a[0]),a[0]);
  show_vector(a[0]);

  return 0;
}
