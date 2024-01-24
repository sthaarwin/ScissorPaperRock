#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
void loser(){
    system("halt");
}
void banner(){
    printf("____________________________________");
    printf("\n           SPR                   \n"); 
    printf("____________________________________\n"); 
}
int askUser(){
    printf("1. Scissors \n");
    printf("2. Paper\n");
    printf("3. Rock\n");
    printf("Choose your option: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}
int askComp(){
    int choice;
    srand(time(NULL));
    choice = rand() % 3;
    return choice;
}
void show(int user, int computer){
    switch(user){
        case 1:
            printf("Your choice : Scissors");
            break;
        case 2:
            printf("Your choice : Paper");
            break;
         case 3:
            printf("Your choice : Rock");
            break;
        default:
          break;
    }
    printf("\n");
    switch (computer)
    {
        case 0:
            printf("Comp choice : Scissors");
            break;
        case 1:
            printf("Comp choice : Paper");
            break;
        case 2:
            printf("Comp choice : Rock");
            break;
    }
}
void check(int user, int computer){
    /*
    if user =1 then scissors
    if user =2 then paper
    if user =3 then rock
    if computer =0 then scissors
    if computer =1 then paper
    if computer =2 then rock
    */
   switch (user)
   {
        case 1:
            if(computer == 0){
                printf("\n Result : Draw!!");
            }
            if(computer == 1){
                printf("\n Result : You win!!");
            }
            if(computer == 2){
                printf("\n Result : You lose!!");
                loser();
            }
            break;
        case 2:
            if(computer == 0){
                printf("\n Result : you lose!!");
                loser();
            }
            if(computer == 1){
                printf("\n Result : Draw!!");
            }
            if(computer == 2){
                printf("\n Result : You win!!");
            }
            break;
        case 3:
            if(computer == 0){
                printf("\n Result : You win!!");
            }
            if(computer == 1){
                printf("\n Result : You lose!!");
                loser();
            }
            if(computer == 2){
                printf("\n Result :Draw!!");
            }
   }

}
char askReplay(){
    printf("\nReplay?(y/n):");
    char c;
    c = getche();
    return c;
}
int user;
int comp;
int main(){
    char replay;
   do{
    system("cls");
    banner();
    user = askUser();
   while ( user > 3 || user < 1) {
     system("cls");
     banner();
     user = askUser();
   }
    comp = askComp();
    show(user, comp);
    check(user, comp);
    replay = askReplay();
   }
    while (replay == 'y' || replay =='Y');
    printf("\nThank you for trying.");
    return 0;
}