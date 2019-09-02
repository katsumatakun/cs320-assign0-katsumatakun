#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256

void print_table(int, int);
void write_table(int, int, FILE*);

int main(int argc, char* argv[]) {

  if (argc > 5 || argc%2 ==0) {
    printf("usage: progam name, option, file name\n");
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
