#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // bilbioteca de aloca��o de espa�o em memoria
#include <locale.h> // bilbioteca de aloca��es de texto por regi�o
#include<string.h>  // biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios do sistema
{
	// Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digiste o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
}
	
int consulta()
	{
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
				printf("\nEssas s�o as informa��es do usuario: ");
				printf("%s", conteudo);
				printf("\n\n");
		}
		
		system("pause");
		
		
	}
	
int deletar()
	{
		char cpf[40];
		
		printf("Digite o CPF do usu�rio a ser consultado: ");
		scanf("%s",cpf);
		
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!. \n");
		system("pause");	
	}
	}
	
int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
		
		printf("### cart�rio da EBAC ###/\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("Op��o: "); // Fim da sele��o

	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio
			
		system("cls"); // respons�vel por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opc�o n�o est� disponivel!\n");
			system("pause");
			break;
		} //fim da sele��o
		
	
	}
}
