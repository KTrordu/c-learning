#include <stdio.h>
#include <stdbool.h>

#define N 4

int maze[N][N] = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};

// Recursive fonksiyon: (i, j)'den (N-1, N-1)'e yol var mı?
bool isPathExists(int i, int j) {
    // Sınırların dışına çıktıysan veya duvara çarptıysan
    if (i >= N || j >= N || maze[i][j] == 0)
        return false;

    // Hedefe ulaştıysan
    if (i == N - 1 && j == N - 1)
        return true;

    // Sağ veya Aşağı doğru dene
    return isPathExists(i + 1, j) || isPathExists(i, j + 1);
}

int main() {
    if (isPathExists(0, 0))
        printf("Path exists: YES\n");
    else
        printf("Path exists: NO\n");

    return 0;
}