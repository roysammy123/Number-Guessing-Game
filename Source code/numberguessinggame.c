// Program for a number guessing game

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>

extern int i;


void welcomemessage()
{
    // Printing welcome message

    printf("\n\n\n===================================\n");
    printf("\n< WELCOME TO NUMBER GUESSING GAME >\n\n");
    printf("===================================\n\n\n\n");
}


void rulesdisplay()
{
    // Printing rules of the game

    printf("HOW TO PLAY\n");
    printf("________________________________________\n\n\n");
    printf("> You will have 10 tries to guess a number between 1 and 100\n\n");
    printf("> With each successive try, it will display either:\n");
    printf("\t>> 'Your number is BIGGER' if the number is still bigger\n");
    printf("\t>> 'Your number is SMALLER' if the number is still smaller\n\n");
    printf("> If can guess the number before the number of tries are exhausted, You WIN...else, you LOSE\n\n\n");
}



void understandrules()
{
    // Asking user whether he/she has read and understood the rules

    printf("Have you understood the rules of the game? (Type in 'yes' or 'no' as your answer)\n\n");

    char yesno[5];
    scanf("%s",yesno);

    // Actions based on if user has understood rules or not 

    if ((strcmp(yesno,"Yes") == 0) || (strcmp(yesno,"yes") == 0) || (strcmp(yesno,"YES") == 0))
    {
        system("cls"); // clears console output screen
        printf("Let's begin!\n\n");
    }

    else if ((strcmp(yesno,"No") == 0) || (strcmp(yesno,"no") == 0) || (strcmp(yesno,"NO") == 0))
    {
        printf("\n\nSince you haven't understood the rules, please take a look at them again below:\n\n");
        rulesdisplay();
        understandrules();
    }

    else
    {
        printf("Invalid Input...\n\nRestarting the game...");
        char restartgame[3];
        printf("\n\nPress any key...\n");
        scanf("%s",restartgame);
        system("cls"); // Clears console output screen
        main();
    }
}



void endgame()
{
    printf("\n\nPress 'x' to exit...\n\n");
    char exitpresskey;
    scanf(" %c",&exitpresskey);

    return;
}


void gameendmessage(int x)
{

        // Want to play again or not

        printf("Do you want to play the game again? (Type in 'yes' or 'no' as answer)\n\n");
        char continuegame[5];

        scanf(" %s",continuegame);

        if((strcmp(continuegame,"Yes") == 0) || (strcmp(continuegame,"yes") == 0) || (strcmp(continuegame,"YES") == 0))
        {
            printf("Restarting game...\n\nPress any key...\n\n");
            char presskey1;
            scanf("%c",&presskey1);
            system("cls");
            main();
        }

        else if((strcmp(continuegame,"No") == 0) || (strcmp(continuegame,"no") == 0) || (strcmp(continuegame,"NO") == 0))
        {
            printf("Thanks for playing!\n");

            endgame();
        }

        else
        {
            printf("Invalid input\n\nPress any key\n\n");
            char presskey2;
            scanf("%c",&presskey2);

            endgame();
        }
}


int machinepicksnumber()
{
    // Machine picking a random number

    srand(time(0));

    int i;
    i = (rand()%100); //rand()%num where num is the upper range

    int j=i;

    return j;
}



void randomguess1(int x)
{
    //  Taking first guess input 
    printf("\nGuess a number between 1 to 100:\n\n\n");

    printf("TRY 1:\n");

    int guessno;
    scanf("%d",&guessno);

    // Checking if number is bigger or smaller or equal

    if (guessno > x)
    {
        printf("\nYour number is BIGGER\n\n");
        randomguess2to10(x,guessno);
    }

    else if (guessno < x)
    {
        printf("\nYour number is SMALLER\n\n");
        randomguess2to10(x,guessno);
    }

    else if (guessno == x)
    {
        printf("\n\nVOILA! You have guessed it right! %d was the number!\n\n",x);
        printf("!!! WELL DONE !!!\n\n\n");

        gameendmessage(x);
    }

}


int i=2;


int randomguess2to10(int y,int guessno2)
{

    
    int m = guessno2;
    const int n = y;
    int inputno;

    printf("TRY %d:\n",i);
    scanf("%d",&inputno);


    if (i<10)
    {

        if (inputno > n)
        {
            printf("\nYour number is BIGGER\n\n");
            i++;
            randomguess2to10(n,inputno);
        }

        else if (inputno < n)
        {
            printf("\nYour number is SMALLER\n\n");
            i++;
            randomguess2to10(n,inputno);
        }

        else if (inputno == n)
        {
            printf("\n\nVOILA! You have guessed it right! %d was the number!\n\n",n);
            printf("!!! WELL DONE !!!\n\n\n");

            i=2;

            gameendmessage(n);
        }
    }


    else if (i==10)
    {
        if (inputno == n)
        {
            printf("\n\nVOILA! You have guessed it right! %d was the number!\n\n",n);
            printf("!!! WELL DONE !!!\n\n\n");

            i=2;

            gameendmessage(n);
        }

        else
        {
            printf("\n\nYOU LOSE :(\n\n");

            printf("%d was the number!\n\n",n);
            printf("!!! BETTER LUCK NEXT TIME !!!\n\n\n");

            i=2;

            gameendmessage(n);
        }
    }

    return 0;
}



int main()
{
    // calling welcome message function to display the welcome message

    welcomemessage();

    // calling rules display function to print rules for the first time

    rulesdisplay();

    // calling understandrules function to check if the user has understood the rules  

    understandrules();

    // calling machinepicksnumber function to let computer pick a number

    int machinenumber;

    machinenumber = machinepicksnumber();

    // calling randomguess1 to take first attemp input and compare the results  

    randomguess1(machinenumber);

    return 0;
}