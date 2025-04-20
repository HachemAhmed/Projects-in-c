#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *entrada, *saida;
    int linhas, colunas;
    int **matrix, **transposta;

    entrada = fopen("matriz.txt", "r");
    if (!entrada) 
    {
        printf("Erro ao abrir o arquivo matriz.txt\n");
        return 1;
    }

    fscanf(entrada, "%d %d", &linhas, &colunas);

    matrix = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) 
    {
        matrix[i] = (int *)malloc(colunas * sizeof(int));
    }

    transposta = (int **)malloc(colunas * sizeof(int *));
    for (int i = 0; i < colunas; i++) 
    {
        transposta[i] = (int *)malloc(linhas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            fscanf(entrada, "%d", &matrix[i][j]);
        }
    }
    fclose(entrada);


    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            transposta[j][i] = matrix[i][j];
        }
    }

    saida = fopen("transposta.txt", "w");
    if (!saida) 
    {
        printf("Erro ao abrir o arquivo transposta.txt\n");
        return 1;
    }

    fprintf(saida, "%d %d\n", colunas, linhas); 
    for (int i = 0; i < colunas; i++) 
    {
        for (int j = 0; j < linhas; j++) 
        {
            fprintf(saida, "%d ", transposta[i][j]);
        }
        fprintf(saida, "\n");  
    }
    fclose(saida);

    for (int i = 0; i < linhas; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < colunas; i++) 
    {
        free(transposta[i]);
    }
    free(transposta);

    return 0;
}
