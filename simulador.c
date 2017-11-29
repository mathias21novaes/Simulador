#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char linha[20];
  char instrucoes[3][1000];
  int memoria[100], acumulador, PC = 0, n, z;
  int end[15], temp;
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
          printf("Instrucao: NOP\n\nEXECUTANDO...\n");
          printf("Valor de PC = %d\n",PC);
          printf("Instrucao lida pelo IR = NOP\n");
          printf("No PC sera incrementado +1\n");
          PC++;
          printf("Valor atual de PC =  %d\n",PC);
          printf("\n");
          system("pause");
          printf("\n");
      }
      else if(instrucoes[0][PC] == 'S' && instrucoes[1][PC] == 'T' && instrucoes[2][PC] == 'A')
      {
          printf("Instrucao: STA\n\nEXECUTANDO...\n");
          printf("Valor atual de PC =  %d\n",PC);
          printf("Instrucao lida pelo IR = Armazenar #%d\n",end[PC]);
          printf("AC = %d\n",acumulador);
          printf("Memoria#%d = AC\n",end[PC]);
          memoria[end[PC]] = acumulador;
          printf("Memoria #%d = %d\n",end[PC],memoria[end[PC]]);
          printf("No PC sera incrementado +1\n");
          PC++;
          printf("Valor atual de PC =  %d\n",PC);
          memoria[end[PC]] = acumulador;
          printf("\n");
          system("pause");
          printf("\n");

      }
      else if(instrucoes[0][PC] == 'L' && instrucoes[1][PC] == 'D' && instrucoes[2][PC] == 'A')
      {
          printf("Instrucao: LDA\n\nEXECUTANDO...\n");
          printf("Valor de PC = %d\n",PC);
          printf("Instrucao lida pelo IR = Carregar #%d\n",end[PC]);
          printf("Memoria#%d = %d\n",end[PC],memoria[end[PC]]);
          printf("AC = %d\n",acumulador);
          printf("AC = Memoria#%d\n",end[PC]);
          printf("No PC sera incrementado +1\n");
          PC++;
          printf("Valor de PC = %d\n",PC);
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
          system("pause");
          printf("\n");
      }
      else if(instrucoes[0][PC] == 'A' && instrucoes[1][PC] == 'D' && instrucoes[2][PC] == 'D')
      {
          printf("Instrucao: ADD\n\nEXECUTANDO...\n");
          printf("Valor de PC = %d\n",PC);
          printf("Instrucao lida pelo IR = Somar #%d\n",end[PC]);
          printf("AC = %d\n",acumulador);
          printf("ULA = %d +\n",acumulador);
          printf("Memoria#%d = %d\n",end[PC],memoria[end[PC]]);
          printf("ULA = %d + %d\n",acumulador,memoria[end[PC]]);
          printf("AC = ULA\n");
          acumulador += memoria[end[PC]];
          printf("AC = %d\n",acumulador);
          printf("No PC sera incrementado +1\n");
          PC++;
          printf("Valor de PC = %d\n",PC);
          printf("\n");
          system("pause");
          printf("\n");
      }
      else if(instrucoes[0][PC] == 'J' && instrucoes[1][PC] == 'M' && instrucoes[2][PC] == 'P')
      {
          printf("Instrucao: JMP\n\nEXECUTANDO...\n");
          printf("Valor de PC = %d\n",PC);
          printf("Instrucao lida pelo IR = Pular #%d\n",end[PC]);
          PC = end[PC];
          printf("Valor de PC = %d\n",PC);
          printf("\n");
          system("pause");
          printf("\n");
      }
      else if(instrucoes[0][PC] == 'J' && instrucoes[1][PC] == 'N')
      {
          printf("Instrucao: JN\n\nEXECUTANDO...\n");
          printf("Valor de PC = %d\n",PC);
          if(n == 1)
          {
            printf("N = TRUE\n");
            printf("Instrucao lida pelo IR = Pular #%d",end[PC]);
            PC = end[PC];
            printf("Valor de PC = %d\n",PC);
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
              printf("No PC sera incrementado +1\n");
              PC++;
              printf("Valor de PC = %d\n",PC);
              printf("\n");
          }
          system("pause");
          printf("\n");
      }
      else if(instrucoes[0][PC] == 'J' && instrucoes[1][PC] == 'Z')
      {
          printf("Instrucao: JZ\n\nEXECUTANDO...\n");
          printf("Valor de PC = %d\n",PC);
          if(z == 1)
          {
            printf("Z = TRUE\n");
            printf("Instrucao lida pelo IR = Pular #%d\n",end[PC]);
            PC = end[PC];
            printf("Valor de PC = %d\n",PC);
            printf("\n");
            system("pause");
            printf("\n");
          }
          else
          {
            printf("Z = FALSE\n");
            printf("No PC sera incrementado +1\n");
            PC++;
            printf("Valor de PC = %d\n",PC);
            printf("\n");
            system("pause");
            printf("\n");
          }

      }
      else if(instrucoes[0][PC] == 'H' && instrucoes[1][PC] == 'L' && instrucoes[2][PC] == 'T')
      {
         printf("Instrucao: HLT\n\nEXECUTANDO...\n");
         break;
         system("pause");
         printf("\n");
      }
      else
      {
          printf("ERRO: comando nao identificado!\n");
          break;
          system("pause");
          printf("\n");
      }
  }


  return 0;

}
