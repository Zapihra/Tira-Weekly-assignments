//Tekijä: Iida Vaaja, opiskelijanro: 0606562


#include <stdlib.h>
#include <stdio.h>

void knownNumber(int numbers[5], int i, int n) {
    for (int j = 0; j < n; j++){
        if (numbers[j] == 0){
            numbers[j] = i;
            break;
        }
    }
}

void permutations(int k, int numbers[5], int inlist[5], int n) {
    if (k == 0) {
        for (int x = 0; x < 5; x++) {
            numbers[x] = 0;
            inlist[x] = 0;
        }
    }
    if (k == 1) {
        printf("%d: ", (numbers[0]-1)*24 + 1);
    }
    
    if (k == n) {
        printf("%d, %d, %d, %d, %d\n", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
    }
    else {
        for (int i = 1; i < n + 1; i++) {
            if (0 == inlist[i-1]){
                inlist[i-1] = 1;
                knownNumber(numbers, i, n);
                permutations(k+1, numbers, inlist, n);
                inlist[i-1] = 0;
                numbers[k] = 0;
            }   
        }   
    }
    return;
}

int main(){
    int k = 0, n = 5;
    int numbers[5], inlist[5];
    permutations(k, numbers, inlist, n);
}
