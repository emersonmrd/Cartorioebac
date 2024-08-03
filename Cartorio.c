#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função responsavel por cadastrar os usuários no sistema
{
	//definindo as variaveis locais de registro
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim da definição de variaveis locais de registro
	
	printf("Digite o CPF a ser cadastrado: "); //pergunta ao usuário o cpf 
	scanf("%s", cpf); //armazena o cpf informado
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //consulta o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" é para escrita no arquivo
	fprintf(file,cpf); //salva o valor da variavel cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo e o "a" é para atualizar o arquivo
	fprintf(file, ","); //coloca uma virgula para separar
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //pergunta ao usuário o nome 
	scanf("%s", nome); //armazena o nome informado
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,nome); //salva o valor da variavel nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //coloca uma virgula para separar
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //pergunta ao usuário o nome
	scanf("%s",sobrenome); //armazena o sobrenome informado
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,sobrenome); //salva o valor da variavel sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //coloca uma virgula para separar
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //pergunta ao usuário o cargo
	scanf("%s",cargo); //armazena o cargo informado
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,cargo); //salva o valor da variavel cargo
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema
	
	
}

int consulta() //função responsavel por realizar a consulta no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//definindo as variaveis locais de consulta
	char cpf[40];
	char conteudo[200];
	const char delimitador[] = ",";
	char *chave;
	int contador=0;
	// fim da definição de variaveis locais de consulta
	
	printf("Digite o CPF a ser consultado: "); //pergunta ao usuário o cpf
	scanf("%s", cpf); //armazena o cpf  informado
	
	FILE *file; //consulta o arquivo
	file = fopen(cpf, "r"); //leitura do arquivo e o "r" é para leitura do arquivo
	
	if(file == NULL) //verifica se o arquivo existe
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //informa que o arquivo não foi localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //laço para puxar as informações do registro
	{
		//mostra as informações do usuário 
		printf("\nEssas são as informações do usuário: ");
		printf("\n\n");
		
		chave = strtok(conteudo, delimitador); //salva o primeiro valor da chave 
		contador = 1; // Reinicia o contador para cada nova linha
		
		 while (chave != NULL) //laço para fatiar a string
		{
			switch(contador) //switch para separação dos valores chaves
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
        	contador++; //adiciona +1 no valor do contador a cada iteração
    	}
		
	}
	
	fclose(file); // fecha o arquivo
	system("pause"); // pausa o sistema para que seja possivel ler
	
}

int deletar() // função responsavel por deletar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//definindo as variaveis locais de consulta
	char cpf[40]; 
	
	printf("Digite o CPF do usuário a ser deletado: "); //pergunta ao usuário o cpf
	scanf("%s", cpf); //armazena o cpf informado
	
	
	FILE *file; //consulta o arquivo
	file = fopen(cpf, "r"); //leitura do arquivo e o "r" é para leitura do arquivo
	
	if(file == NULL) //verifica se o usuário existe no sistema
	{
		printf("O usuário não se encontra no sistema!. \n"); // informa que o usuário não se encontra no sistema
		system("pause"); // pausa o sistema
	}
	
	// Fecha o arquivo antes de tentar removê-lo
    fclose(file);
	
	
	if (remove(cpf) == 0) //faz a verifica o sucesso da remoção do arquivo
	{
        printf("CPF %s deletado com sucesso!\n", cpf); // informa que o usuário foi deletado com sucesso
    } 
	else 
	{
        printf("Erro ao tentar deletar o arquivo.\n"); // informa que ocorreu um erro ao deletar o arquivo
    }

	system("pause"); //pausa o sistema
	
}

int main() // função principal do programa
{

	//Definindo variáveis	
	int opcao=0; //opcao do menu
	int laco=1; //contador
	char senhadigitada[10];// variável para senha
	char resp='S'; // variável de resposta
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	while (resp != 'N' && resp != 'n') // loop da solicitação de senha
	{
		system("cls"); //limpa a tela
		
		// menu de login
		printf("### Cartório da EBAC ###\n\n"); // titulo
		printf("Login de administrador\n\n"); // login de adm
		printf("Digite a sua senha: "); // solicita a senha
		scanf("%s", senhadigitada); // armazena a senha
		// fim do menu login
		
		if(strcmp(senhadigitada, "admin") == 0) // verifica se a senha esta correta
		{
			
			while(laco == 1) //laço do menu
			{
			
				system("cls"); //limpa a tela
				
				//inicio do menu
				printf("### Cartório da EBAC ###\n\n"); 
				printf("Escolha a opção desejada do menu:\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n");
				printf("\t4 - Sair do sistema\n\n");
				printf("Opção: ");
				//fim do menu
				
				scanf("%d", &opcao); //armazenando a escolha do usuário
				
				system("cls"); //limpa a tela
				
				//inicio da seleção 
				switch(opcao)
				{
					case 1: //opcao de registro de nomes
						registro(); //chama a função de registro
						break;
						
					case 2: //opcao de consulta de nomes
						consulta(); //chama a função de consulta
						break;
						
					case 3: //opcao de exclusao de nomes
						deletar(); //chama a função de delete
						break;	
					
					case 4: //opcao de sair do programa
						printf("### Cartório da EBAC ###\n\n");
		                printf("Você escolheu sair, esperamos que volte em breve!\n");
		                exit(0);
						
					default: //opcao default 
						printf("Essa opção não está disponivel!\n");
						system("pause"); //pausa o sistema
						break;		
				}
				// fim da seleção
				
				 // printf("Software de livre uso, desenvolvido por Emerson Martins\n");
			}
		
		}
		else
		{
	
			printf("Senha incorreta!\n"); // informa que a senha esta incorreta
			printf("Deseja tentar novamente? [S/N]\n"); //pergunta ao usuário se deseja tentar novamente
			fflush(stdin); //limpa o buffer de entrada
			
			scanf(" %c", &resp); // adicione um espaço antes de %c para ignorar espaços em branco
			if (resp != 'S' && resp != 's') //laço para verificar se o usuario deseja continuar
			{
                printf("Esperamos que volte em breve!\n"); //saudação
                exit(0);
            }
		}			
	}

}
