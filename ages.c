#include <stdio.h>

int main() {

    int age;
    int diff;
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);
    printf("How old are you ?, %s ", name);
    scanf("%d", &age);
    if(age > 21){
      printf("You are %d years older than me\n",(age-21));
    }
    else if (age < 21){
      printf("You are %d years younger than me\n", (21-age));
    }
    else{
      printf("You are as old as me\n");
    }
    return 0;

}
