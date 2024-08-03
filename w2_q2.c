#include <stdio.h>
#include <stdlib.h>

void readMatrix(int *matrix, int rows, int cols)
{
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i * cols + j]);
        }
    }
}

void printMatrix(int *matrix, int rows, int cols)
{
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int *matrix, int *transposed, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transposed[j * rows + i] = matrix[i * cols + j];
        }
    }
}

int main()
{
    int *matrix, *transposed;
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    matrix = (int *)malloc(rows * cols * sizeof(int));
    transposed = (int *)malloc(cols * rows * sizeof(int));

    if (matrix == NULL || transposed == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    readMatrix(matrix, rows, cols);

    printf("Original matrix:\n");
    printMatrix(matrix, rows, cols);
    transposeMatrix(matrix, transposed, rows, cols);
    printf("Transposed matrix:\n");
    printMatrix(transposed, cols, rows);

    free(matrix);
    free(transposed);
    return 0;
}

