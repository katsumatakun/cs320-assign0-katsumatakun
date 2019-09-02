#include <stdio.h>

int main() {

    int num;
    int finished = 0;
    char ans;
    while(!finished){
      printf("Give a number: ");
      scanf("%d", &num);
      for(int i=1; i<=num; i++){
        printf("%d\n", i);
        }
      printf("Run again (y/n)? ");
      scanf(" %c", &ans);
      if(ans=='n')
        finished = 1;
    }
    printf("Done...\n");
    return 0;

}
