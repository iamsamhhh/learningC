//
//  main.c
//  Menu
//
//  Created by 谌宇轩 Sam on 2021/4/5.
//

#include <stdio.h>


int GetInt(void);
char GetFirst(void);
char GetChoice(void);
void Count(void);


int main(void) {
    int choice;
    
    while ((choice = GetChoice()) != 'q') {
        switch (choice) {
            case 'a':
                printf("Buy C primer plus!!!\n");
                break;
            case 'b':
                putchar('\a');
                break;
            case 'c':
                Count();
                break;
            default:
                printf("program error!\n");
                break;
        }
    }
    
    printf("Bye!\n");
    return 0;
}


char GetFirst(void){
    int ch;
    
    while ((ch = getchar()) == '\n')
        continue;
        
    while (getchar() != '\n')
        continue;
    
    return ch;
}

int GetInt(void){
    int input;
    char ch;
    
    while (scanf("%d", &input) != 1) {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a integer.\nPlease enter an integer"
               " value, such as 13, -278, 130: ");
    }
    
    return input;
}


char GetChoice(void){
    int ch;
    
    printf("Enter the letter of your choice:\n");
    printf("a. Advice        b. Bell\n"
           "c. Count         q. Quit\n");
    ch = GetFirst();
    while ((ch < 'a' || ch > 'c') && ch != 'q') {
        printf("Please responde with a, b, c or q.\n");
        ch = GetFirst();
    }
    
    
    return ch;
}


void Count(void){
    int n, i;
    
    printf("Count how far? Enter an integer:\n");
    n = GetInt();
    for (i = 1; i <= n; i++)
        printf("%d\n", i);
    
}
