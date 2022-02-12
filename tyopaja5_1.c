#include <stdio.h>
#include <stdlib.h>

int fibonacci(int fibonacciNumber) {
    if (fibonacciNumber == 1 || fibonacciNumber == 0) { //if the fibonacci is 0 or 1 it has reached the end and it should return itself 
        return fibonacciNumber;
    }
    fibonacciNumber = fibonacci(fibonacciNumber - 1) + fibonacci(fibonacciNumber - 2); 
    //next fibonacci is sum of the two previous ones and it is easier to count them using the same program
    return fibonacciNumber; 
    //it returns this number to the right place so if it is part of the next fibonacci number it goes to the code above
    //if it the wanted sum it returns it to the main program
}

int main() {
    int endFibonacci, finnished;
    printf("Give the number which fibonacci you want to count: ");
    scanf("%d", &endFibonacci);
    finnished = fibonacci(endFibonacci); //wanted fibonacci goes to the subprogram
    printf("This was your fibonacci counted: %d", finnished);
}