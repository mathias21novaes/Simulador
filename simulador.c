#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char linha[20];
  char caracter[3][20];
  int i = 0;

  FILE *arquivo;
  arquivo = fopen("dados.txt", "r");

  if (arquivo == NULL)
  {
    printf ("ARQUIVO NAO ENCONTRADO E/OU NAO PODE SE ABERTO\n");
    getchar();
    exit(0);
  }

  while(fgets(linha, 20, arquivo) != NULL)
  {
    caracter[0][i] = linha[0];
    caracter[1][i] = linha[1];
    caracter[2][i] = linha[2];
    i++;
  }

  fclose(arquivo);

  for(i = 0; i<11; i++)
  {
    printf("%c%c%c\n", caracter[0][i], caracter[1][i], caracter[2][i]);
  }

  return 0;

}
