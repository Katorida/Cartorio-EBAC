#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //aloca��o de espa�o no disco
#include <locale.h> //aloca��o de linguagem regional
#include <string.h> //da vida pra strings

int main() // int = variavel "inteiro"
{
	int opcao=0; // defini��o de uma vari�vel
	char erro=0; // defini��o de uma vari�vel
	int laco=1; // defini��o de uma vari�vel
	
	for(laco=1;laco=1;) // defini��o de um loop, toda vez que o processo for concluido ele volta pro come�o
	{
	
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); //falando pro computador que vai ter acentos
	
		printf("~~~ Cart�rio da EBAC ~~~ \n\n"); // caso queira, n�o precisa fazer em "printf" cada linha, pode fazer em apenas uma linha de c�digo utilizando o \n e \t
		printf("Escolha a op��o desejada do menu abaixo: \n\n"); // \n = vai pra linha de baixo
		printf("\t1. Registrar nomes \n"); // \t = par�grafo
		printf("\t2. Consultar nomes \n");
		printf("\t3. Deletar nomes \n");
		printf("\t4. Fechar aplicativo \n\n\n\n");
		printf("Op��o:	"); // fim do menu
	
		scanf("%d", &opcao); // escaneando a escolha do usu�rio
		scanf("%c", &erro);
	
		system("cls"); // limpa a tela
		
		
		switch(opcao) // escolher op��o de acordo com a resposta do usu�rio
		{
			case 1:
				registro(); //chamada de fun��o
				break;
				
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
			
			case 4:
				printf("\tObrigado por utilizar o sistema\n\n");
				return 0;
				break;
		
			default :
				printf("Essa op��o n�o existe!\n"); // fim da sele��o
				system("pause");
				break;
			
		}
	}
	
}

int registro() // respons�vel por cadastros
{
	char arquivo[14];
	char cpf[14];
	char nome[50];
	char sobrenome[50];
	char cargo[40];
	
	
	printf("\n===__---\\REGISTRANDO UM EMPREGADO//---__===\n\n\n\t"); //coletando informa��o do usu�rio
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf); //%s == 's'trings
	
	strcpy(arquivo, cpf); //vai copiar o valor da string cpf
	
		FILE *dados; //ele vai criar um FILE 
			dados = fopen(arquivo, "w"); // vai abrir o FILE
				fprintf(dados, "--CPF: "); // escreveu "--CPF:"
			fclose(dados); // fechou o arquivo
			
			dados = fopen(arquivo, "a"); // vai abrir o FILE (a = atualizar)
				fprintf(dados, cpf); // escreveu o cpf
			fclose(dados);
		
			dados = fopen(arquivo, "a"); 
				fprintf(dados,"    ");
			fclose(dados);
			
	system("cls");
	
	printf("\n===__---\\REGISTRANDO UM EMPREGADO//---__===\n\n\n\t");
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
		dados = fopen(arquivo, "a");
			fprintf(dados, "--NOME: ");
		fclose(dados);
		
		dados = fopen(arquivo, "a");
			fprintf(dados,nome);
		fclose(dados);
		
	system("cls");
	
	printf("\n===__---\\REGISTRANDO UM EMPREGADO//---__===\n\n\n\t");	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
		dados = fopen(arquivo, "a");
			fprintf(dados, " ");
		fclose(dados);
	
		dados = fopen(arquivo, "a");
			fprintf(dados,sobrenome);
		fclose(dados);
		
		dados = fopen(arquivo, "a"); // "a" = atualizar
			fprintf(dados,"    ");
		fclose(dados);
		
	system("cls");
	
	printf("\n===__---\\REGISTRANDO UM EMPREGADO//---__===\n\n\n\t");	
	printf("digite qual o cargo do empregado: ");
	scanf("%s", cargo);
	
		dados = fopen(arquivo, "a");
			fprintf(dados, "--CARGO: ");
		fclose(dados);
	
		dados = fopen(arquivo, "a");
			fprintf(dados,cargo);
			fclose(dados);
			
	system("cls");
			
	system("pause");	
	
}


int consulta()
{
		setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200]; // a string onde est� os dados do empregado
	
	printf("\n===__---\\CONSULTANDO UM EMPREGADO//---__===\n\n\n\t");
	printf("Digite o cpf a ser consultado:	");
	scanf("%s", cpf);
	
	FILE *dados;
	dados = fopen(cpf, "r"); // abre e l� o arquivo que deve conter o cpf do empregado
	
	if(dados == NULL)
	{ 
		system("cls");
		printf("\n\n\t---N�o foi possivel achar o arquivo.\n\n");
	}
	
	while(fgets(conteudo, 200, dados)  != NULL) //enquanto ele ta lendo o conteudo de at� 200 caracteres que est� dentro do "dados" e n�o encontrar nada diferente de NULL...
	{
		printf("\n\tAqui est�o as informa��es:\n\n");
		printf("%s", conteudo); // printf : a string "conteudo"
		printf("\n\n\n\n");
	}
	
	system ("pause");
	
	
}

int deletar()
{
	char cpf[14];
	
	printf("\n\n\t--Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *dados;
	dados = fopen(cpf, "r");
	
	if(dados == NULL)
{
    system("cls");
    printf("\n\n\tO usu�rio n�o est� no sistema.\n\n ");
    system("pause");
}
else
{
    remove(cpf);
    system("cls");
    printf("\n\n\tUsu�rio exclu�do com sucesso.\n\n");
    system("pause");
}

	
}
