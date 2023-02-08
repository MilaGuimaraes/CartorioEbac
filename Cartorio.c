#include <stdio.h> //bibliteca de comunicacao com o usuario
#include <stdlib.h> //bliblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função repsonsável por cadastrar os usuários no sistema

{
	// início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);  // Responsavel por copiar os valores das strings
	
	FILE *file;  //chamando uma funcao que ja foi criada pelo sistema
	file = fopen(arquivo, "w");  // cria o arquivo e o "w" é escrever
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
		printf("Não foi possível abrir o arquivo, não localizado!.\n");		
		}	
		
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n Essas são as informações do usuário: ");
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
		printf("O usuário não se encontrar no sistema!.\n");
		system("pause");		
	}	 
	
}

int main()
{
	int opcao=0;	// Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // respossavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");  //Definindo a Linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do Menu
		printf("Escolher a opçao desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");	
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: "); // Fim do Menu
		
		scanf("%d", &opcao);  //Armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao) //Inicio da Seleção
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
			
			case 4:
			printf("Obrigada por usar o sistema");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		} //Fim da Seleção
	
	
	}

}
