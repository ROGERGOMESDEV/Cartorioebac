#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
   	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variaveis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informações
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

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

	printf("Digite o sobrenome a ser cadastrado: ");
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
	setlocale(LC_ALL, "Portuguese"); //Definidndo a linguagem

   char cpf[40];
   char conteudo[200];

   printf("Digite o CPF a ser consultado: ");
   scanf("%s",cpf);

   FILE *file;
   file = fopen(cpf,"r");

   if(file == NULL)
   {
   	 printf("Não foi possivel abrir o arquivo, não localizado!.\n");
   }

   while(fgets(conteudo, 200, file) != NULL)
   {
   	printf("\nEssas são as informações do usuário: ");
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

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");

	}
	else if (file != NULL)
	{
		fclose(file); //fecha o arquivo
		printf("Usuário deletado corretamente!.\n\n ");
		system("pause");
		remove (cpf);
	}

}



int main()
{
	int opcao=0; //Definindo variÃ¡veis
	int laco=1;

	for(laco=1; laco=1;)
	{

    system("cls");

	setlocale(LC_ALL, "Portuguese"); //Definidndo a linguagem

	printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
	printf("Escolha a operação desejada do menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opção: "); //fim do menu

	scanf("%d", &opcao); //armazenando a escolha do usuário

	system("cls"); //responsavel por limpar a tela


	switch(opcao) //inicio de seleção do menu
	{
		case 1:
		registro(); //chamada de funções de registro
		break;

		case 2:
        consulta(); //chamada de funções de consulta
		break;

		case 3:
        deletar(); //chamada de funções de deletar
        break;

        case 4:
        printf("Obrigado por utilizar o sistema!\n");
        return 0;
        break;

	    default:
        printf("Essa opção não está disponivel!\n");
		system("pause");
		break;
	  } //fim da seleção

   }
}
