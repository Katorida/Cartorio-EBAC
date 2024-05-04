#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //alocação de espaço no disco
#include <locale.h> //alocação de linguagem regional
#include <string.h> //da vida pra strings

int main() // int = variavel "inteiro"
{
	int opcao=0; // definição de uma variável
	char erro=0; // definição de uma variável
	int laco=1; // definição de uma variável
	
	for(laco=1;laco=1;) // definição de um loop, toda vez que o processo for concluido ele volta pro começo
	{
	
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); //falando pro computador que vai ter acentos
	
		printf("~~~ Cartório da EBAC ~~~ \n\n"); // caso queira, não precisa fazer em "printf" cada linha, pode fazer em apenas uma linha de código utilizando o \n e \t
		printf("Escolha a opção desejada do menu abaixo: \n\n"); // \n = vai pra linha de baixo
		printf("\t1. Registrar nomes \n"); // \t = parágrafo
		printf("\t2. Consultar nomes \n");
		printf("\t3. Deletar nomes \n");
		printf("\t4. Fechar aplicativo \n\n\n\n");
		printf("Opção:	"); // fim do menu
	
		scanf("%d", &opcao); // escaneando a escolha do usuário
		scanf("%c", &erro);
	
		system("cls"); // limpa a tela
		
		
		switch(opcao) // escolher opção de acordo com a resposta do usuário
		{
			case 1:
				registro(); //chamada de função
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
				printf("Essa opção não existe!\n"); // fim da seleção
				system("pause");
				break;
			
		}
	}
	
}

int registro() // responsável por cadastros
{
	char arquivo[14];
	char cpf[14];
	char nome[50];
	char sobrenome[50];
	char cargo[40];
	
	
	printf("\n===__---\\REGISTRANDO UM EMPREGADO//---__===\n\n\n\t"); //coletando informação do usuário
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
	char conteudo[200]; // a string onde está os dados do empregado
	
	printf("\n===__---\\CONSULTANDO UM EMPREGADO//---__===\n\n\n\t");
	printf("Digite o cpf a ser consultado:	");
	scanf("%s", cpf);
	
	FILE *dados;
	dados = fopen(cpf, "r"); // abre e lê o arquivo que deve conter o cpf do empregado
	
	if(dados == NULL)
	{ 
		system("cls");
		printf("\n\n\t---Não foi possivel achar o arquivo.\n\n");
	}
	
	while(fgets(conteudo, 200, dados)  != NULL) //enquanto ele ta lendo o conteudo de até 200 caracteres que está dentro do "dados" e não encontrar nada diferente de NULL...
	{
		printf("\n\tAqui estão as informações:\n\n");
		printf("%s", conteudo); // printf : a string "conteudo"
		printf("\n\n\n\n");
	}
	
	system ("pause");
	
	
}

int deletar()
{
	char cpf[14];
	
	printf("\n\n\t--Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *dados;
	dados = fopen(cpf, "r");
	
	if(dados == NULL)
{
    system("cls");
    printf("\n\n\tO usuário não está no sistema.\n\n ");
    system("pause");
}
else
{
    remove(cpf);
    system("cls");
    printf("\n\n\tUsuário excluído com sucesso.\n\n");
    system("pause");
}

	
}
