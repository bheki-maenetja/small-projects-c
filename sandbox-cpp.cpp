#include <iostream>
#include <set>
#include <iterator>
#include <vector>
using namespace std;

#define N 3

void printGrid(char array[N][N]);
void getNeighbourCoords(int x, int y);

char twoDArray[N][N] = {{'1', '2', '3'}, {'4','5','6'}, {'7','8','0'}};

int main(int argc, char *argv[]) {
    printGrid(twoDArray);
    getNeighbourCoords(1,2);
}

void getNeighbourCoords(int x, int y) {
    // vector< vector<int> > neightbourCoords(4);
    if (x < N - 1)
        printf("(%d, %d)\n", x+1, y);
    if (x > 0)
        printf("(%d, %d)\n", x-1, y);
    if (y < N - 1)
        printf("(%d, %d)\n", x, y+1);
    if (y > 0)
        printf("(%d, %d)\n", x, y-1);
}

void printGrid(char array[N][N]) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%c ", array[i][j]);
        printf("\n");
    }
}

