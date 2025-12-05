#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void printGrid(int rows, int cols, int grid[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int rows, int cols, int grid[MAX][MAX], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                count += grid[newX][newY];
            }
        }
    }
    return count;
}

void nextGeneration(int rows, int cols, int grid[MAX][MAX], int newGrid[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(rows, cols, grid, i, j);

            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3)
                    newGrid[i][j] = 0;
                else
                    newGrid[i][j] = 1;
            } else {
                if (neighbors == 3)
                    newGrid[i][j] = 1;
                else
                    newGrid[i][j] = 0;
            }
        }
    }
}

int main() {
    int rows, cols;
    char input[20];

    printf("Nhap so dong: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    int grid[MAX][MAX];
    int newGrid[MAX][MAX];

    printf("Nhap ma tran %d x %d (chi 0 hoac 1):\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            while (1) {
                printf("[%d][%d] = ", i, j);
                scanf("%s", input);

                // Không cho phép nhập số thực
                if (strchr(input, '.') != NULL) {
                    printf("Khong duoc nhap so thuc! Nhap lai.\n");
                    continue;
                }

                // Chỉ được nhập 0 hoặc 1
                if (strcmp(input, "0") == 0) {
                    grid[i][j] = 0;
                    break;
                } else if (strcmp(input, "1") == 0) {
                    grid[i][j] = 1;
                    break;
                } else {
                    printf("Chi duoc nhap 0 hoac 1! Nhap lai.\n");
                }
            }
        }
    }

    int generations;
    printf("Nhap so the he muon mo phong: ");
    scanf("%d", &generations);

    printf("\nThe he ban dau:\n");
    printGrid(rows, cols, grid);

    for (int gen = 1; gen <= generations; gen++) {
        nextGeneration(rows, cols, grid, newGrid);

        printf("The he %d:\n", gen);
        printGrid(rows, cols, newGrid);

        // Copy back
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }
    }

    return 0;
}
