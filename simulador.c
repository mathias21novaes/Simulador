#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char linha[20];
  char instrucoes[3][20];
  int memoria[100],acumulador,PC = 0,n,z;
  int end[15],temp;
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
    temp = atoi(&linha[5]);
    end[i] = temp;
    i++;
  }

  fclose(arquivo);

  while(1)
  {
      if(instrucoes[0][PC] == 'N' && instrucoes[1][PC] == 'O' && instrucoes[2][PC] == 'P')
      {
          printf("nop");
          printf(" %d\n",PC);
          PC++;
      }
      else if(instrucoes[0][PC] == 'S' && instrucoes[1][PC] == 'T' && instrucoes[2][PC] == 'A')
      {
          printf("sta");
          printf(" %d\n",PC);
          memoria[end[PC]] = acumulador;
          PC++;
      }
      else if(instrucoes[0][PC] == 'L' && instrucoes[1][PC] == 'D' && instrucoes[2][PC] == 'A')
      {
          printf("lda");
          printf(" %d\n",PC);
          acumulador = memoria[end[PC]];
          if(acumulador < 0)
          {
              n = 1;
          }
          else
          {
              n = 0;
          }
          if(acumulador == 0)
          {
              z = 1;
          }
          else
          {
              z = 0;
          }
          PC++;
      }
      else if(instrucoes[0][PC] == 'A' && instrucoes[1][PC] == 'D' && instrucoes[2][PC] == 'D')
      {
          printf("add");
          printf(" %d\n",PC);
          acumulador += memoria[end[PC]];
          PC++;
      }
      else if(instrucoes[0][PC] == 'A' && instrucoes[1][PC] == 'D' && instrucoes[2][PC] == 'A')
      {
          printf("ada");
          printf(" %d\n",PC);
          acumulador = end[PC];
          PC++;
      }
      else if(instrucoes[0][PC] == 'N' && instrucoes[1][PC] == 'O' && instrucoes[2][PC] == 'T')
      {
          printf("not");
          printf(" %d\n",PC);
          PC++;
      }
      else if(instrucoes[0][PC] == 'J' && instrucoes[1][PC] == 'M' && instrucoes[2][PC] == 'P')
      {
          printf("jmp");
          PC = end[PC];
          printf(" %d\n",PC);
      }
      else if(instrucoes[0][PC] == 'J' && instrucoes[1][PC] == 'N')
      {
          printf("jn");
          printf(" %d\n",PC);
          if(n == 1)
          {
            PC = end[PC];
            if(end[PC] == NULL)
            {
                break;
            }
          }
          else
          {
            PC++;
          }
      }
      else if(instrucoes[0][PC] == 'J' && instrucoes[1][PC] == 'Z')
      {
          printf("jz");
          printf(" %d\n",PC);
          if(z == 1)
          {
            PC = end[PC];
          }
          else
          {
            PC++;
          }
      }
      else if(instrucoes[0][PC] == 'H' && instrucoes[1][PC] == 'L' && instrucoes[2][PC] == 'T')
      {
         break;
      }
  }


  return 0;

}
