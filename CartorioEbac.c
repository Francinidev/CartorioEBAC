#include <stdio.h> //biblioteca de cominica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloa��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
  //in�cio cria��o de vari�veis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //final da cria��o de vari�eis/string
  
  printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
  scanf("%s", cpf); //%s refere-se a string
  
  strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
  
  FILE *file; //cria o arquivo no banco de dados 
  file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
  fprintf(file,cpf); //salva o valor da vari�vel
  fclose(file); //fecha o arquivo
  
  file = fopen(arquivo,"a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
  scanf("%s",nome); //%s refere-se a string
  
  file = fopen(arquivo,"a"); //cria o arquivo e o "a" append que significa "Inserir" inserir novos dados
  fprintf(file,nome); //salva o valor da vari�vel
  fclose(file); //fecha o arquivo
  
  file = fopen(arquivo,"a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
  scanf("%s", sobrenome); //%s refere-se a string
  
  file= fopen(arquivo,"a"); //cria o arquivo e o "a" � o arquivo a ser aberto
  fprintf(file, sobrenome); //salva o valor da vari�vel
  fclose(file); // fecha o arquivo
  
  file = fopen(arquivo,"a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
  scanf("%s", cargo); //%s refere-se a string
  
  file= fopen(arquivo,"a"); //cria o arquivo e o "a" � o arquivo a ser aberto
  fprintf(file,cargo); //salva o valor da vari�vel
  fclose(file); //fecha o arquivo
  
  system("pause");
     
}

int consulta()
{
   setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
   
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado: ");
   scanf("%s", cpf);
   
   FILE *file;
   file = fopen (cpf,"r");
   
   if(file==NULL)
{  
   printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
}
   while(fgets(conteudo,200,file) != NULL)
{
   printf("\nEssas s�o as informa��es do usu�rio: ");
   printf("%s",conteudo);
   printf("\n\n");
}
   system("pause");
   
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
{
	printf("Foi deletado com sucesso! \n\n  O usu�rio n�o se encontra no sistema!.\n");
	system("pause");
}	
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;

    for(laco=1;laco=1;)
	{

        system("cls"); //respons�vel por limpar a tela
		
	
	    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
     	printf("### Cart�rio da EBAC ###\n\n"); //In�cio da sele��o do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
     	printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
	    printf("\t4 - Sair do sistema \n\n");
		printf("Op��o:");//Fim do menu
	
        scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
        system("cls");
    
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
	    
	        case 4:
	    	printf("Obrigado por utilizar o sistema!\n");
	    	return 0;
	    	break;
	        
			default:
         	printf("Essa op��o n�o est� dispon�vel!\n");
            system("pause");
            break;
            //fim da sele��o
        }
    }
}

