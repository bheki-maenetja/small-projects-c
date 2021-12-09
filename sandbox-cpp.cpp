#include <iostream>
#include <set>
#include <queue>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

#define N 3

void printGrid(vector< vector<char> > array);
vector< vector<int> > getNeighbourCoords(int x, int y);
void printCoords(vector< vector<int> > coords);
vector<int> getEmptySpaceCoords(vector< vector<char> > array);
vector < vector<char> > generateNewGrid(int oldX, int oldY, int newX, int newY, vector< vector<char> > array);
void bfs_search();

vector< vector<char> > twoDArray = {{'1', '2', '3'}, {'4','5','6'}, {'7','8','0'}};

int main(int argc, char *argv[]) {
    // printGrid(twoDArray);
    // vector< vector<int> > neighbours = getNeighbourCoords(2,2);
    // printf("\n");
    // for (int i = 0; i < neighbours.size(); i++) {
    //     generateNewGrid(2,2, neighbours[i][0], neighbours[i][1], twoDArray);
    // }
    bfs_search();
}

void bfs_search() {
    set<vector< vector<char> >> explored;
    queue< vector< vector<char> >> frontier;
    frontier.push(twoDArray);
    explored.insert(twoDArray);

    while (!frontier.empty()) {
        vector< vector<char> > grid = frontier.front();
        frontier.pop();
        vector<int> emptySpaceCoords = getEmptySpaceCoords(grid);
        vector< vector<int> > neighbours = getNeighbourCoords(emptySpaceCoords[0], emptySpaceCoords[1]);

        printGrid(grid);
        printf("\n");
        for (int i = 0; i < neighbours.size(); i++) {
            vector < vector<char> > newGrid = generateNewGrid(emptySpaceCoords[0], emptySpaceCoords[1], neighbours[i][0], neighbours[i][1], grid);
            if (explored.find(newGrid) == explored.end()) {
                explored.insert(newGrid);
                frontier.push(newGrid);
            }
        }
    }
}

vector< vector<int> > getNeighbourCoords(int x, int y) {
    vector< vector<int> > neighbourCoords;
    if (x > 0)
        neighbourCoords.push_back({x-1, y});
    if (y > 0)
        neighbourCoords.push_back({x, y-1});
    if (y < N - 1)
        neighbourCoords.push_back({x, y+1});
    if (x < N - 1)
        neighbourCoords.push_back({x+1, y});
    
    return neighbourCoords;
}

vector < vector<char> > generateNewGrid(int oldX, int oldY, int newX, int newY, vector< vector<char> > array) {
    vector < vector<char> > newGrid;
    copy(array.begin(), array.end(), back_inserter(newGrid));

    char temp = newGrid[newX][newY];
    newGrid[newX][newY] = '0';
    newGrid[oldX][oldY] = temp;
    // printGrid(newGrid);
    
    return newGrid;
}

vector<int> getEmptySpaceCoords(vector< vector<char> > array) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (array[i][j] == '0') return {i,j};
    }
}

void printGrid(vector< vector<char> > array) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%c ", array[i][j]);
        printf("\n");
    }
}

void printCoords(vector< vector<int> > coords) {
    for (int i = 0; i < coords.size(); i++) {
        printf("(%d, %d)\n", coords[i][0], coords[i][1]);
    }
} 

