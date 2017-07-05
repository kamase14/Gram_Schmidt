#include<stdio.h>
#include <math.h>
#define size 3

// i_p() a to b no naiseki
// norm() a no zettaiti
// v_sum() vector no tasizan
// scalar_p() a no alpha bai
// show_vector() vector no hyouzi
// v_copy vector no kopi-

double i_p(double *a,double *b){
  double sum=0;
  int i;
  for (i=0;i<=size-1;i++) sum=sum+a[i]*b[i]; 
  return sum;
}

double norm(double *a){ // a no ookisa
  double sum=0;
  int i;
  for (i=0;i<=size-1;i++) sum=sum+a[i]*a[i];
  return sqrt(sum);
}

double * v_sum(double a[],double b[]){ // vector no tasizan
  int i;
  for(i=0;i<=size-1;i++) a[i]=a[i]+b[i]; // a + b wo a ni ireru
  return a; // vector a no sentou adoresu wo kaesu
}

double *scalar_p(double alpha, double *a){ // a no alpha bai (a no sukara- bai)
  int i;
  for(i=0;i<=size-1;i++) a[i]=alpha*a[i]; // alpha to a no seki wo a ni ireru
  return a;
}

void show_vector(double *a){  // bekutoru no seibun wo hyouzi suru 
  int i;
  printf("(");
  for (i=0;i<=size-1;i++) printf("%lf ",a[i]);
  printf(")");
  printf("\n");
}
void v_copy(double *a,double *b){  //  bekutoru wo kopi- suru 
  int i;
  for(i=0;i<=size-1;i++) a[i]=b[i]; // b wo a ni kopi- suru
}

void calc_b_vector(double *a,double *b){
  int i;
  double b_dash[size][size];

  v_copy( b_dash, b);

  for(i=0; i<=size-1; i++){
    b_dash[i] = b[i] - v_sum( i_p(a[i],b[i]), a[i]);
  }
  scalar_p(1/norm(b_dash[0]),b_dash[0]);
  show_vector(b_dash[0]);
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
  calc_b_vector(a[0],a[1]);

  scalar_p(1/norm(a[0]),a[0]);
  show_vector(a[0]);

  return 0;
}
