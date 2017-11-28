#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char linha[20];
  char instrucoes[9][20];
  int memoria[200],acumulador,IR,PC;
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
    instrucoes[0][i] = linha[0];
    instrucoes[1][i] = linha[1];
    instrucoes[2][i] = linha[2];
    instrucoes[3][i] = linha[3];
    instrucoes[4][i] = linha[4];
    instrucoes[5][i] = linha[5];
    instrucoes[6][i] = linha[6];
    instrucoes[7][i] = linha[7];
    instrucoes[8][i] = linha[8];
    i++;
  }

  fclose(arquivo);

  i = 0;

  while(1)
  {
      if(instrucoes[0][i] == 'N' && instrucoes[1][i] == 'O' && instrucoes[2][i] == 'P')
      {
          printf("nop\n");
      }
      if(instrucoes[0][i] == 'S' && instrucoes[1][i] == 'T' && instrucoes[2][i] == 'A')
      {
          printf("sta\n");
      }
      if(instrucoes[0][i] == 'L' && instrucoes[1][i] == 'D' && instrucoes[2][i] == 'A')
      {
          printf("lda\n");
      }
      if(instrucoes[0][i] == 'A' && instrucoes[1][i] == 'D' && instrucoes[2][i] == 'D')
      {
          printf("add\n");
      }
      if(instrucoes[0][i] == 'O' && instrucoes[1][i] == 'R')
      {
          printf("or\n");
      }
      if(instrucoes[0][i] == 'A' && instrucoes[1][i] == 'N' && instrucoes[2][i] == 'D')
      {
          printf("and\n");
      }
      if(instrucoes[0][i] == 'N' && instrucoes[1][i] == 'O' && instrucoes[2][i] == 'T')
      {
          printf("not\n");
      }
      if(instrucoes[0][i] == 'J' && instrucoes[1][i] == 'M' && instrucoes[2][i] == 'P')
      {
          printf("jmp\n");
      }
      if(instrucoes[0][i] == 'J' && instrucoes[1][i] == 'N')
      {
          printf("jn\n");
      }
      if(instrucoes[0][i] == 'J' && instrucoes[1][i] == 'Z')
      {
          printf("jz\n");
      }
      if(instrucoes[0][i] == 'H' && instrucoes[1][i] == 'L' && instrucoes[2][i] == 'T')
      {
         break;
      }
      i++;
  }


  return 0;

}
