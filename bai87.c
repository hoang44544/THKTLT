// Bài 87.Viết chương trình cài đặt trò chơi Life mô phỏng cuộc sống của một quần thể? 
// Giải thích: 
// Xét một mảng hình chữ nhật chứa các ô con, mỗi ô có thể chứa một cơ thể. Nếu mảng 
// được xem như vô hạn cả hai chiều, thì mỗi ô có 8 ô đứng quanh nó. Trong mỗi thế hệ, 
// sự sinh ra và chết đi xảy ra theo qui luật sau: - Mỗi cơ thể được sinh ra trong một ô trống có đúng 3 cơ thể bên cạnh. - Mỗi cơ thể chết đi vì cô lập nếu nó có ít hơn 2 cơ thể bên cạnh. - Mỗi cơ thể chết đi vì quá đông nếu nó có nhiều hơn 3 cơ thể bên cạnh. 
// Tất cả các cơ thể khác sống sót. 
// Trò chơi Life hay còn gọi là "Conway's Game of Life" là một mô hình toán học thú 
// vị mô phỏng sự phát triển của quần thể. Đây là cách bạn có thể cài đặt trò chơi này 
// bằng ngôn ngữ lập trình C cùng với giải thích đầu vào và đầu ra. 
// Đầu vào: 
// Một ma trận hình chữ nhật (mảng 2 chiều) chứa các ô, mỗi ô có thể chứa một cơ 
// thể hoặc không. 
// Đầu vào có thể được nhập vào từ bàn phím hoặc từ một tệp tin. Mỗi ô được biểu 
// diễn bằng '1' (có cơ thể) hoặc '0' (không có cơ thể). 
// Kích thước của ma trận (số dòng và số cột). 
// Đầu ra: 
// Sau mỗi thế hệ, một ma trận mới sẽ được in ra trên màn hình, thể hiện trạng thái 
// của quần thể sau khi áp dụng các quy luật đã nêu. 
// Nếu có thể, các thông tin như số thế hệ đã chạy cũng có thể được hiển thị. 
#include <stdio.h>
#define ROWS 5
#define COLS 5
void printGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int countNeighbors(int grid[ROWS][COLS], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS) {
                count += grid[newX][newY];
            }
        }
    }
    return count;
}
void nextGeneration(int grid[ROWS][COLS], int newGrid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] == 1) {
                //tbao con song
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                // Cell is dead
                if (neighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
}
int main() {
    int grid[ROWS][COLS] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1}
    };
    int newGrid[ROWS][COLS];
    int generations = 5;

    printf("Initial Generation:\n");
    printGrid(grid);

    for (int gen = 0; gen < generations; gen++) {
        nextGeneration(grid, newGrid);
        printf("Generation %d:\n", gen + 1);
        printGrid(newGrid);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }
    }

    return 0;
}

