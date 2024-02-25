#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <iostream>

using namespace std;

#define N 5

double matrix_a[N][N], matrix_b[N][N], matrix_c[N][N];

int main()
{
    auto started_time = chrono::high_resolution_clock::now();

    srand(10);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix_a[i][j] = rand() % 10;
            matrix_b[i][j] = rand() % 10;
        }
    }
    // Print Matrix A
    printf("Matrix A\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%0.f\t", matrix_a[i][j]);
        printf("\n");
    }

    // Print Matrix B
    printf("\nMatrix B\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%0.f\t", matrix_b[i][j]);
        printf("\n");
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            matrix_c[i][k] = 0;
            for (int j = 0; j < N; j++)
            {
                matrix_c[i][k] = matrix_c[i][k] + matrix_a[i][j] * matrix_b[j][k];
            }
        }
    }

    // Print the result matrix
    printf("Matrix C - - - Simple Sequence Matrix Multiplication - - -\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%0.f\t", matrix_c[i][j]);
        printf("\n");
    }
    auto ended_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(ended_time - started_time);
    cout << "Done! Execution time = " << duration.count() << " (microseconds)" << endl;
}