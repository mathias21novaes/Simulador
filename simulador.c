#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char linha[20];
  char instrucoes[3][1000];
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
          printf("PC = %d\n",PC);
          printf("IR = NOP\n");
          printf("PC +1\n");
          PC++;
          printf("PC =  %d\n",PC);
          printf("\n");
      }
      else if(instrucoes[0][PC] == 'S' && instrucoes[1][PC] == 'T' && instrucoes[2][PC] == 'A')
      {
          printf("PC =  %d\n",PC);
          printf("IR = Armazenar #%d\n",end[PC]);
          printf("AC = %d\n",acumulador);
          printf("Memoria#%d = AC\n",end[PC]);
          memoria[end[PC]] = acumulador;
          printf("Memoria #%d = %d\n",end[PC],memoria[end[PC]]);
          printf("PC +1\n");
          PC++;
          printf("PC =  %d\n",PC);
          memoria[end[PC]] = acumulador;
          printf("\n");

      }
      else if(instrucoes[0][PC] == 'L' && instrucoes[1][PC] == 'D' && instrucoes[2][PC] == 'A')
      {
          printf("PC = %d\n",PC);
          printf("IR = Carregar #%d\n",end[PC]);
          printf("Memoria#%d = %d\n",end[PC],memoria[end[PC]]);
          printf("AC = %d\n",acumulador);
          printf("AC = Memoria#%d\n",end[PC]);
          printf("PC +1\n");
          PC++;
          printf("PC = %d\n",PC);
          acumulador = memoria[end[PC]];
          printf("\n");
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
      }
      else if(instrucoes[0][PC] == 'A' && instrucoes[1][PC] == 'D' && instrucoes[2][PC] == 'D')
      {
          printf("PC = %d\n",PC);
          printf("IR = Somar #%d\n",end[PC]);
          printf("AC = %d\n",acumulador);
          printf("ULA = %d +\n",acumulador);
          printf("Memoria#%d = %d\n",end[PC],memoria[end[PC]]);
          printf("ULA = %d + %d\n",acumulador,memoria[end[PC]]);
          printf("AC = ULA\n");
          acumulador += memoria[end[PC]];
          printf("AC = %d\n",acumulador);
          printf("PC +1\n");
          PC++;
          printf("PC = %d\n",PC);
          printf("\n");
      }
      else if(instrucoes[0][PC] == 'J' && instrucoes[1][PC] == 'M' && instrucoes[2][PC] == 'P')
      {
          printf("PC = %d\n",PC);
          printf("IR = Pular #%d\n",end[PC]);
          PC = end[PC];
          printf("PC = %d\n",PC);
          printf("\n");
      }
      else if(instrucoes[0][PC] == 'J' && instrucoes[1][PC] == 'N')
      {
          printf("PC = %d\n",PC);
          printf(" %d\n",PC);
          if(n == 1)
          {
            printf("N = TRUE\n");
            printf("IR = Pular #%d",end[PC]);
            PC = end[PC];
            printf("PC = %d\n",PC);
            printf("\n");
            if(end[PC] == NULL)
            {
                printf("ERRO: Endereco nao existe!");
                break;
            }
          }
          else
          {
              printf("N = FALSE\n");
              printf("PC +1\n");
              PC++;
              printf("PC = %d\n",PC);
              printf("\n");
          }
      }
      else if(instrucoes[0][PC] == 'J' && instrucoes[1][PC] == 'Z')
      {
          printf("PC = %d\n",PC);
          if(z == 1)
          {
            printf("Z = TRUE\n");
            printf("IR = Pular #%d\n",end[PC]);
            PC = end[PC];
            printf("PC = %d\n",PC);
            printf("\n");
          }
          else
          {
            printf("Z = FALSE\n");
            printf("PC +1\n");
            PC++;
            printf("PC = %d\n",PC);
            printf("\n");
          }
      }
      else if(instrucoes[0][PC] == 'H' && instrucoes[1][PC] == 'L' && instrucoes[2][PC] == 'T')
      {
         break;
      }
      else
      {
          printf("ERRO: comando nao identificado!\n");
          break;

      }
  }


  return 0;

}
