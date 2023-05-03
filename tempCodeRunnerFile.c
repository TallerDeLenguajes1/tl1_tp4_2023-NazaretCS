#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>


//Valores aleatoreos Formula: [MAX-MIN]+MIN

int main(){

    srand(time(NULL));
    int aleatorio = rand() % 2 + 1;

    
    for (int i = 0; i < 100; i++)
    {
        printf("\n %d", aleatorio);
        aleatorio = rand() % 2 + 1;
    }

    return 0;
}