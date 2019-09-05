#include <stdio.h>
void print_array(int (*pt)[], int size);
int count_zeros(int (*pt)[], int size);
void triple(int (*pt)[], int size);
int main() {
     int nums[] =  {1, 2, 3, 0, 5, -6, 0, -8, 0, 10};

    int size = sizeof(nums)/sizeof(int);

    print_array(&nums, size);
    printf("Number of 0’s: %d\n",count_zeros(&nums, size));
    triple(&nums, size);
    print_array(&nums, size);

    return 0;

}

void print_array(int (*pt)[], int size){
  printf("{ ");
  for(int i=0; i<size-1; i++){
    printf("%d, ",(*pt)[i]);
  }
  printf("%d", (*pt)[size-1]);
  printf("}\n");
}

int count_zeros(int (*pt)[], int size){
  int zero = 0;

  for (int i=0; i<size; i++){
    if((*pt)[i]==0){
      zero++;
    }
  }
  return zero;
}

void triple(int (*pt)[], int size){
  for (int i=0; i<size; i++){
    (*pt)[i] = (*pt)[i]*3;
  }
}
