#include <stdio.h>
#include <stdlib.h>


void mapafinal(char **mapa, int linha, int coluna) 
{
    for (int i = 0; i < linha; i++) 
    {
        for (int j = 0; j < coluna; j++) 
        {
            printf("| %c ", mapa[i][j]);
        }
        printf("\n");
    }
}


int seguro(char **mapa, int x, int y, int linha, int coluna) 
{
    return (x >= 0 && x < linha && y >= 0 && y < coluna && mapa[x][y] != 'R' && mapa[x][y] != '*');
}


int encontrarcaminho(char **mapa, int x, int y, int linha, int coluna) 
{
    
    if (mapa[x][y] == 'Z') 
    {
        return 1;
    }

    
    char temporario = mapa[x][y]; 
    mapa[x][y] = '*'; 

    
    if (seguro(mapa, x - 1, y, linha, coluna) && encontrarcaminho(mapa, x - 1, y, linha, coluna)) 
    {
        return 1;
    }
    
    if (seguro(mapa, x + 1, y, linha, coluna) && encontrarcaminho(mapa, x + 1, y, linha, coluna)) 
    {
        return 1;
    }
   
    if (seguro(mapa, x, y - 1, linha, coluna) && encontrarcaminho(mapa, x, y - 1, linha, coluna)) 
    {
        return 1;
    }
    
    if (seguro(mapa, x, y + 1, linha, coluna) && encontrarcaminho(mapa, x, y + 1, linha, coluna)) 
    {
        return 1;
    }

    
    mapa[x][y] = temporario;
    return 0;
}

int fuga_humana(char **mapa, int linha, int coluna) 
{
    int humano_I = -1, humano_J = -1;

    for (int i = 0; i < linha; i++) 
    {
        for (int j = 0; j < coluna; j++) 
        {
            if (mapa[i][j] == 'H') 
            {
                humano_I = i;
                humano_J = j;
                break;
            }
        }
        if (humano_I != -1) break;
    }


    if (humano_I == -1 || humano_J == -1) 
    {
        printf("Caminho nao encontrado\n");
        return 0;
    }

    
    if (encontrarcaminho(mapa, humano_I, humano_J, linha, coluna)) 
    {
        printf("Caminho encontrado:\n");
        mapafinal(mapa, linha, coluna);
        return 1;
    } 
    else 
    {
        printf("Nao existe um caminho seguro\n");
        return 0;
    }
}

int main() 
{
    FILE *arq = fopen("mapa.txt", "r");
    if (!arq) 
    {
        return 1;
    }

    int linha, coluna;
    fscanf(arq, "%d %d\n", &linha, &coluna);

    char **matriz = (char **)malloc(linha * sizeof(char *));
    for (int i = 0; i < linha; i++) 
    {
        matriz[i] = (char *)malloc(coluna * sizeof(char));
    }

    for (int i = 0; i < linha; i++) 
    {
        for (int j = 0; j < coluna; j++) 
        {
            matriz[i][j] = fgetc(arq);      //obs: o mapa não pode ter espaço entre as casas do mapa
        }
        fgetc(arq);
    }

    fclose(arq);

    fuga_humana(matriz, linha, coluna);
  
    for (int i = 0; i < linha; i++) 
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}