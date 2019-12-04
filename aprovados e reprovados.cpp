//Faça um programa com as seguintes opções:
//1-Incluir dados no arquivo:
//2-Listar Arquivo de Aprovados
//3-Listar Arquivo de Reprovados
//4-Fim
#include "conio.h"
#include "string.h"
#include "stdio.h"
#include "locale.h"
#include "math.h"
int main()
{
	setlocale(LC_ALL,"");
	struct registro
	{
		int id;
		char nome[50];
		float n1, n2, media;
	}aluno[3];
	
	FILE *aprovados;
	FILE *reprovados;
	char linha[100];
	int id_aluno,i, opcao;
	char nome_aluno[50];
	float n1_aluno,n2_aluno,media;
	
	do
	{
		printf("\n-------- MENU --------\n");	
		printf("\n1 - Incluir dados no arquivo");
		printf("\n2 - Listar Arquivo de Aprovados");
		printf("\n3 - Listar Arquivo de Reprovados");
		printf("\n4 - Sair");
		printf("\nEntre com a opção: ");
		scanf("%d",&opcao);
	
	switch (opcao)
	{
		case 1:
				aprovados = fopen("aprovados.txt", "a+");
				reprovados = fopen("reprovados.txt", "a+");
			for(i=0;i<3;i++)
			{
				printf("\nInforme o ID do %iª aluno: ",i+1);
				scanf("%d",&id_aluno);
				aluno[i].id = id_aluno;
				fflush(stdin);
				
				printf("\nInforme o nome do %iª aluno: ",i+1);
				gets(nome_aluno);
				strcpy(aluno[i].nome, nome_aluno);
				fflush(stdin);
				
				printf("\nInforme a primeira nota do %iª aluno: ",i+1);
				scanf("%f", &n1_aluno);
				aluno[i].n1 = n1_aluno;
				fflush(stdin);
				
				printf("\nInforme a segunda nota do %iª aluno: ",i+1);
				scanf("%f", &n2_aluno);
				aluno[i].n2 = n2_aluno;
				fflush(stdin);	
				
				media = (aluno[i].n1 + aluno[i].n2)/2;
				aluno[i].media = media;
				
			
		        if(media >= 7)
		        {
		        fprintf (aprovados, "ALUNOS APROVADOS: \n");
		        fprintf (aprovados, "ID: %d \t, NOME: %s \t, MEDIA: %.2f \n", aluno[i].id, aluno[i].nome, aluno[i].media);
		        }
		        else
		        {
		        fprintf (reprovados, "ALUNOS REPROVADOS: \n");
		        fprintf (reprovados, "ID: %d \t, NOME: %s \t, MEDIA: %.2f \n", aluno[i].id, aluno[i].nome, aluno[i].media); 
		        }
		    }
		        fclose (aprovados);
		        fclose (reprovados);
			
			break;	
	    case 2:
	    		aprovados = fopen("aprovados.txt","r");
					
   				while((!feof(aprovados)))
   				{
					if(fgets(linha, 100, aprovados)!=NULL)
						printf("%s", linha);
				}
				printf("\n Alunos aprovados Pressione qualquer tecla para continuar");
				getch();
				
				fclose(aprovados);
				
			break;
		case 3:
				reprovados = fopen("reprovados.txt","r");
					
   				while((!feof(reprovados)))
   				{
					if(fgets(linha, 100, reprovados)!=NULL)
						printf("%s", linha);
				}
				printf("\n Alunos aprovados Pressione qualquer tecla para continuar");
				getch();
				
				fclose(reprovados);	
	        break;
		case 4:
			break;
	}
	
	} while (opcao!=4);
	return 0;
}

