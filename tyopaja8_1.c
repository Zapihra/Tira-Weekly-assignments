/*algorithm Kruskal(G) is
    F:= ∅
    for each v ∈ G.V do
        MAKE-SET(v)
    for each (u, v) in G.E ordered by weight(u, v), increasing do
        if FIND-SET(u) ≠ FIND-SET(v) then
            F:= F ∪ {(u, v)} ∪ {(v, u)}
            UNION(FIND-SET(u), FIND-SET(v))
return F*/

#include <stdio.h>
#define INF 9999

typedef struct edge
{
    int x,y,z; 
} edge;

typedef struct list {
    edge data[20];
} list;

list inList;


int matrix[4][4];


int kruskal() {
    int partof[20], n = 0, m = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(matrix[i][j] != 0) {
                inList.data[n].x = i;
                inList.data[n].y = j;
                inList.data[n].z = matrix[i][j];
                n++;
            }
        }
    }
    
    sort();

    for(int i = 0; i<5; i++) {
        partof[i] = i;
    }
    
    

}

void sort() {
    edge point;

    for(int i = 1; i<5; i++) {
        for (int j = 0; j<5; j++) {
            if(inList.data[j].z > inList.data[j+1].z) {
                point = inList.data[j];
                inList.data[j] =inList.data[j + 1];
                inList.data[j + 1] = point;
            }
        }
    }
 
}

int main(void) {
    for (int i = 0; i < 5; i++)
    {
       for (int j = 0; i < 5; i++)
       {
           matrix[i][j] = INF;
           if(i == j) {
               matrix[i][j] = 0;
           }
       }
        
    }
    matrix[0][1] = 4;
    matrix[1][0] = 4;

    matrix[0][2] = 5;
    matrix[2][0] = 5;

    matrix[1][2] = 6;
    matrix[2][1] = 6;

    matrix[1][3] = 9;
    matrix[3][1] = 9;

    matrix[2][3] = 6;
    matrix[3][2] = 6;

    matrix[2][4] = 12;
    matrix[4][2] = 12;

    matrix[3][4] = 5;
    matrix[4][3] = 5;

    kurskal();

}