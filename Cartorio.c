#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//definindo as variaveis locais de registro
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim da defini��o de variaveis locais de registro
	
	printf("Digite o CPF a ser cadastrado: "); //pergunta ao usu�rio o cpf 
	scanf("%s", cpf); //armazena o cpf informado
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //consulta o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" � para escrita no arquivo
	fprintf(file,cpf); //salva o valor da variavel cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo e o "a" � para atualizar o arquivo
	fprintf(file, ","); //coloca uma virgula para separar
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //pergunta ao usu�rio o nome 
	scanf("%s", nome); //armazena o nome informado
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,nome); //salva o valor da variavel nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //coloca uma virgula para separar
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //pergunta ao usu�rio o nome
	scanf("%s",sobrenome); //armazena o sobrenome informado
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,sobrenome); //salva o valor da variavel sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //coloca uma virgula para separar
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //pergunta ao usu�rio o cargo
	scanf("%s",cargo); //armazena o cargo informado
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,cargo); //salva o valor da variavel cargo
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema
	
	
}

int consulta() //fun��o responsavel por realizar a consulta no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//definindo as variaveis locais de consulta
	char cpf[40];
	char conteudo[200];
	const char delimitador[] = ",";
	char *chave;
	int contador=0;
	// fim da defini��o de variaveis locais de consulta
	
	printf("Digite o CPF a ser consultado: "); //pergunta ao usu�rio o cpf
	scanf("%s", cpf); //armazena o cpf  informado
	
	FILE *file; //consulta o arquivo
	file = fopen(cpf, "r"); //leitura do arquivo e o "r" � para leitura do arquivo
	
	if(file == NULL) //verifica se o arquivo existe
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //informa que o arquivo n�o foi localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //la�o para puxar as informa��es do registro
	{
		//mostra as informa��es do usu�rio 
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("\n\n");
		
		chave = strtok(conteudo, delimitador); //salva o primeiro valor da chave 
		contador = 1; // Reinicia o contador para cada nova linha
		
		 while (chave != NULL) //la�o para fatiar a string
		{
			switch(contador) //switch para separa��o dos valores chaves
			{
				case 1:
        			printf("CPF: %s\n", chave); //mostra o cpf
        			break;
        			
        		case 2:
        			printf("Nome: %s\n", chave); //mostra o nome
        			break;
        		
        		case 3:
        			printf("Sobrenome: %s\n", chave); //mostra o sobrenome
        			break;
        			
        		case 4:
        			printf("Cargo: %s\n", chave); //mostra o cargo
        			break;
        			
        		default: //opcao default
        			break;
        	}
        	
        	chave = strtok(NULL, delimitador); // salva a proxima chave da linha
        	contador++; //adiciona +1 no valor do contador a cada itera��o
    	}
		
	}
	
	fclose(file); // fecha o arquivo
	system("pause"); // pausa o sistema para que seja possivel ler
	
}

int deletar() // fun��o responsavel por deletar os usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//definindo as variaveis locais de consulta
	char cpf[40]; 
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //pergunta ao usu�rio o cpf
	scanf("%s", cpf); //armazena o cpf informado
	
	
	FILE *file; //consulta o arquivo
	file = fopen(cpf, "r"); //leitura do arquivo e o "r" � para leitura do arquivo
	
	if(file == NULL) //verifica se o usu�rio existe no sistema
	{
		printf("O usu�rio n�o se encontra no sistema!. \n"); // informa que o usu�rio n�o se encontra no sistema
		system("pause"); // pausa o sistema
	}
	
	// Fecha o arquivo antes de tentar remov�-lo
    fclose(file);
	
	
	if (remove(cpf) == 0) //faz a verifica o sucesso da remo��o do arquivo
	{
        printf("CPF %s deletado com sucesso!\n", cpf); // informa que o usu�rio foi deletado com sucesso
    } 
	else 
	{
        printf("Erro ao tentar deletar o arquivo.\n"); // informa que ocorreu um erro ao deletar o arquivo
    }

	system("pause"); //pausa o sistema
	
}

int main() // fun��o principal do programa
{

	//Definindo vari�veis	
	int opcao=0; //opcao do menu
	int laco=1; //contador
	char senhadigitada[10];// vari�vel para senha
	char resp='S'; // vari�vel de resposta
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	while (resp != 'N' && resp != 'n') // loop da solicita��o de senha
	{
		system("cls"); //limpa a tela
		
		// menu de login
		printf("### Cart�rio da EBAC ###\n\n"); // titulo
		printf("Login de administrador\n\n"); // login de adm
		printf("Digite a sua senha: "); // solicita a senha
		scanf("%s", senhadigitada); // armazena a senha
		// fim do menu login
		
		if(strcmp(senhadigitada, "admin") == 0) // verifica se a senha esta correta
		{
			
			while(laco == 1) //la�o do menu
			{
			
				system("cls"); //limpa a tela
				
				//inicio do menu
				printf("### Cart�rio da EBAC ###\n\n"); 
				printf("Escolha a op��o desejada do menu:\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n");
				printf("\t4 - Sair do sistema\n\n");
				printf("Op��o: ");
				//fim do menu
				
				scanf("%d", &opcao); //armazenando a escolha do usu�rio
				
				system("cls"); //limpa a tela
				
				//inicio da sele��o 
				switch(opcao)
				{
					case 1: //opcao de registro de nomes
						registro(); //chama a fun��o de registro
						break;
						
					case 2: //opcao de consulta de nomes
						consulta(); //chama a fun��o de consulta
						break;
						
					case 3: //opcao de exclusao de nomes
						deletar(); //chama a fun��o de delete
						break;	
					
					case 4: //opcao de sair do programa
						printf("### Cart�rio da EBAC ###\n\n");
		                printf("Voc� escolheu sair, esperamos que volte em breve!\n");
		                exit(0);
						
					default: //opcao default 
						printf("Essa op��o n�o est� disponivel!\n");
						system("pause"); //pausa o sistema
						break;		
				}
				// fim da sele��o
				
				 // printf("Software de livre uso, desenvolvido por Emerson Martins\n");
			}
		
		}
		else
		{
	
			printf("Senha incorreta!\n"); // informa que a senha esta incorreta
			printf("Deseja tentar novamente? [S/N]\n"); //pergunta ao usu�rio se deseja tentar novamente
			fflush(stdin); //limpa o buffer de entrada
			
			scanf(" %c", &resp); // adicione um espa�o antes de %c para ignorar espa�os em branco
			if (resp != 'S' && resp != 's') //la�o para verificar se o usuario deseja continuar
			{
                printf("Esperamos que volte em breve!\n"); //sauda��o
                exit(0);
            }
		}			
	}

}
