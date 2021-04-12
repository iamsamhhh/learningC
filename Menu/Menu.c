#include <stdio.h>


int GetInt(void);
char GetFirst(void);
char GetChoice(void);
void Count(void);
void Swap(int *, int *);
void Swap_Main(void);

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
            case 's':
                Swap_Main();
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
           "c. Count         s. Swap\n"
           "q. Quit\n");
    ch = GetFirst();
    while (((ch < 'a' || ch > 'c') && ch != 'q') && ch != 's') {
        printf("Please responde with a, b, c, s, or q.\n");
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

void Swap(int * a, int * b){ // 声明指针
    printf("Before swap a = %3d, b = %3d\n"
           "And the address of a is %p, for b is %p\n",
           *a, *b, // 解指针
           a, b); // 指针
    int temp = *a; // 解指针
    *a = *b;
    *b = temp;
    
}

void Swap_Main(){
    int a, b;
    printf("enter a number for a: ");
    a = GetInt();
    printf("and then b: ");
    b = GetInt();
    
    Swap(&a, &b); // 把a和b的地址赋值给指针
    
    printf("After swap a = %4d, b = %4d\n"
           "And the address of a is %p, for b is %p\n",
           a, b,
           &a, &b); //获取a和b的地址
    
}
