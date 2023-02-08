#include <stdio.h> //bibliteca de comunicacao com o usuario
#include <stdlib.h> //bliblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o repsons�vel por cadastrar os usu�rios no sistema

{
	// in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);  // Responsavel por copiar os valores das strings
	
	FILE *file;  //chamando uma funcao que ja foi criada pelo sistema
	file = fopen(arquivo, "w");  // cria o arquivo e o "w" � escrever
	fprintf(file,cpf);  //salvo o valos da variavel
	fclose(file);  //fecha o arquivo
	
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
	
	printf("Digite o sobremone a ser cadastrado: ");
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
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");		
		}	
		
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
		system("pause");
		
		
}

int deletar()
{	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontrar no sistema!.\n");
		system("pause");		
	}	 
	
}

int main()
{
	int opcao=0;	// Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // respossavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");  //Definindo a Linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do Menu
		printf("Escolher a op�ao desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");	
		printf("Op��o: "); // Fim do Menu
		
		scanf("%d", &opcao);  //Armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao) //Inicio da Sele��o
		{
			case 1: 
			registro(); //chamada de funcoes
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		} //Fim da Sele��o
	
	
	}

}
