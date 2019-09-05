#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_table(int, int);
void write_table(int, int, FILE*);
int read_files(int, int, char**);

int main(int argc, char* argv[]) {

  if (argc > 5 || argc%2 ==0) {
    printf("usage: progam name, option, file name, option, filename\n");
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
    if(!strcmp(argv[1], "-in")){
    read_files(2, 99, argv);
    }
    else if(!strcmp(argv[1], "-out")){
      FILE *fp;
      if((fp = fopen(argv[2], "w")) == NULL ) {
        printf("Output file not open\n");
        return -1;
      }
      scanf("%d", &row);
      scanf("%d",&col );
      write_table(row, col, fp);
      fclose(fp);
    }
    else{
      printf("usage: progam name, option, file name, option, file name\n");
    }
  }
  else if (argc == 5){
     if(!strcmp(argv[1], "-in") && !strcmp(argv[3], "-out")){
       read_files(2,4,argv);
    }
    else if(!strcmp(argv[3], "-in") && !strcmp(argv[1], "-out")){
      read_files(4,2,argv);
    }
    else{
      printf("usage: progam name, option, file name, option, file name\n");
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

int read_files(int infile, int outfile,char** argv){
  FILE *fpr;
  char line[256];
  if((fpr = fopen(argv[infile], "r")) == NULL ) {
    printf("Input file not open\n");
    return -1;
  }

  fgets(line, sizeof(int), fpr);
  char* endptr;
  int row = strtol(line,&endptr,10);
  if(row==0){
    printf("invalid format\n");
    return -1;
  }
  fgets(line, sizeof(int), fpr);
  int col = strtol(line,&endptr,10);
  if(col==0){
    printf("invalid format\n");
    return -1;
  }

  if(outfile!=99){
    FILE *fpw;
    if((fpw = fopen(argv[outfile], "w")) == NULL ) {
      printf("Input file not open\n");
      return -1;
    }
    printf("write table\n");
    write_table(row, col, fpw);
    fclose(fpw);
  }

  else{
    print_table(row,col);
  }

  fclose(fpr);


  return 0;
}
