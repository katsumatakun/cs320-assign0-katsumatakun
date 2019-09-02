#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256

void print_table(int, int);
void write_table(int, int, FILE*);

int main(int argc, char* argv[]) {

  if (argc > 5 || argc%2 ==0) {
    printf("usage: progam name, binary file name\n");
    return -1;
  }
  int row;
  int col;

  if (argc==1){
    scanf("%d", &row);
    scanf("%d",&col );
    print_table(row, col);
  }

  else if (argc==3){
    FILE *fp;
    char line[256];
    if(!strcmp(argv[1], "-in")){
      if((fp = fopen(argv[2], "r")) == NULL ) {
        printf("Input file not open\n");
        return -1;
      }
      while (fgets(line, sizeof(line), fp)){
        printf("%s",line);
        }

      fclose(fp);
    }
    else if(!strcmp(argv[1], "-out")){
      if((fp = fopen(argv[2], "w")) == NULL ) {
        printf("Output file not open\n");
        return -1;
      }
      scanf("%d", &row);
      scanf("%d",&col );
      write_table(row, col, fp);
      fclose(fp);
    }
  }

  else if (argc == 5){
    if(!strcmp(argv[1], "-in") && !strcmp(argv[3], "-out")){
      FILE *fpr;
      FILE *fpw;
      char line[256];
      if((fpr = fopen(argv[2], "r")) == NULL ) {
        printf("Input file not open\n");
        return -1;
      }
      if((fpw = fopen(argv[4], "w")) == NULL ) {
        printf("Input file not open\n");
        return -1;
      }
      while (fgets(line, sizeof(line), fpr)){
        fprintf(fpw, "%s", line);
      }

      fclose(fpr);
      fclose(fpw);
    }

    else if(!strcmp(argv[3], "-in") && !strcmp(argv[1], "-out")){
      FILE *fpr;
      FILE *fpw;
      char line[256];
      if((fpr = fopen(argv[4], "r")) == NULL ) {
        printf("Input file not open\n");
        return -1;
      }
      if((fpw = fopen(argv[2], "w")) == NULL ) {
        printf("Input file not open\n");
        return -1;
      }
      while (fgets(line, sizeof(line), fpr)){
        fprintf(fpw, "%s", line);
      }

      fclose(fpr);
      fclose(fpw);

    }
  }


/*
  FILE *fp;
  if((fp = fopen(argv[1], "b")) == NULL ) {
    printf("Input file not open\n");
    return -1;
  }

  nodePtr head_ptr = NULL;

  //Allocate space for the first record while checking if there
  //is memory space.
  EmpPtr q;
  q = (EmpPtr) malloc(sizeof(struct emp));
  if(q == NULL){
    printf("No more memory space available \n");
    return -1;
  }


  while(fread(q, sizeof(struct emp), 1, fp)){
    print_raw_data(q);

    //Insert data with dainamically allocation
    head_ptr = insertData(head_ptr, q);
    if(head_ptr == NULL){
      printf("No more memory space available \n");
      return -1;
    }

    q = (EmpPtr) malloc(sizeof(struct emp));
    if(q == NULL){
      printf("No more memory space available \n");
      return -1;
    }
}
  free(q);  //deallocation for extra memory

  if(head_ptr != NULL){
    printf("========================================\n");
    printf("Calculated Bi-weekly Pays in Order\n\n");
    printf("Last name, First name  bi-weekly pay  federal tax  state tax  insurance     net pay \n");
    print_emp_data(head_ptr);
  }
  else{
    printf("No data was read\n");
  }

*/
  return 0;
}

void print_table(int row, int col){
  for(int i=1; i<=row; i++){
    for(int j=1; j<=col; j++){
      if(i*j<=1000){
        printf("%-5d", i*j);
      }
      else
        break;
    }
    printf("\n");
  }
}


void write_table(int row, int col, FILE* fp){
  for(int i=1; i<=row; i++){
    for(int j=1; j<=col; j++){
      if(i*j<=1000){
        fprintf(fp, "%-5d", i*j);
      }
      else
        break;
    }
    fprintf(fp, "\n");
  }
}
