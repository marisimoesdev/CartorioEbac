#include <stdio.h> //Biblioteca de comunicação com o usuário, essa biblioteca deverá ser colocada até quando usa o printf
#include <stdlib.h> //Biblioteca de alocação de espaço na memória do computador
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável pelas strings

int cadastrar_usuario() //Função para cadastro do usuário
{
	setlocale(LC_ALL, "portuguese"); //Definindo o idioma
	
	char arquivo[40]; //Essa variável vai ser o nome do arquivo que ficarão guadados os dados cadastrados. É uma string, pois tem []
	char cpf[40]; // Variável do cpf. É uma string, pois tem [], essas variáveis precisam ser char, pois o usuário irá digitar vários caracteres, e precisa ser uma string para que possa armazenar esse conjunto de variáveis (caracteres/char)
	char nome[100]; //Variável do nomes. É uma string pois tem [], o valor dentro dos colchetes são o número máximo de caracteres que estarão dentro do conjunto criado pela string
	char sobrenome[100]; //Variável do sobrenome. É uma string pois tem []
	char cargo[100]; //Variável do cargo. É uma string pois tem []
	
	printf("Digite o CPF do usuário que deseja cadastrar: "); //Coletando informações do usuário. Esse printf vem antes do strcpy, pois primeiro você tem que definir o valor da string que terá o valor copiado, se você não fizer isso antes não dará certo
	scanf("%s", cpf); //Definindo o local de armazenamento do cpf, nesse caso é na variável “cpf char/string”. É %s, porque é uma string 
	
	strcpy(arquivo, cpf); //Essa função vai copiar o valor do cpf cadastrado para nomear o arquivo. Vai copiar a string cpf para a string arquivo
	//Iníco da inserção de dados
	FILE *file; //Criando o arquivo, você está falando para ele procurar nas nossas bibliotecas alguma estrutura chamada FILE, porque a gente vai criar um arquivo. Esse file em minúsculo dá pra mudar o nome, você pode usar qualquer outra palavra, ex: pasta.
	file = fopen(arquivo, "w"); //Aqui você está abrindo o arquivo. Esse w vem de write, para escrever. Dá pra colocar a variável CPF, pois tanto a variável "arquivo" quanto a variável "cpf" têm os valores igualados. Na verdade, poderia ser qualquer uma das variáveis, porém como o CPF é o identificador do usuário cadastrado, então tem que ser ele ou uma variável que tenha o valor igual ao dele, que no caso é a variável "arquivo"
	fprintf(file,"CPF: "); //Esse comando é para escrever o que vai aparecer no arquivo
	fclose(file); //Aqui está fechando o arquivo
		
	file = fopen(arquivo, "a"); //Atulizando o arquivo
	fprintf(file, cpf); //Aqui está salvando o o cpf do usuário na variável cpf
	fclose(file); //Aqui está fechando o arquivo
	
	printf("Digite o nome do usuário que deseja cadastrar: "); //Coletando informações do usuário
	scanf("%s", nome); //Definindo o local de armazenamento do nome, que nesse caso é na variável “nome char/string”

	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, ", Nome: "); //Escrevendo o que vai aparecer no arquivo
	fclose(file); //Fechando o arquivo
		
	file = fopen(arquivo, "a"); //Atulizando o arquivo
	fprintf(file, nome); //Salvando o nome do usuário, na variável nome
	fclose(file); //Fechando o arquivo
	
	printf("Digite o sobrenome do usuário que deseja cadastrar: "); //Coletando informações do usuário
	scanf("%s", sobrenome); //Defininfo o local de armazenamento do sobrenome do usuário, nesse caso é na variável “sobrenome char/string”
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, ", Sobrenome: "); //Escrevendo o que vai aparecer no arquivo
	fclose(file); //Fechando o arquivo
		
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, sobrenome); //Salvando o sobrenome do usuário, na variável sobrenome
	fclose(file); //Fechando o arquivo
	
	printf("Digite o cargo do usuário que deseja cadastrar: "); //Coletando informações do usuário
	scanf("%s", cargo); //Definindo o local de armazenamento do cargo do usuário, nesse caso é na variável “cargo char/string”
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, ", Cargo: "); //Escrevendo o que vai aparecer no arquivo
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, cargo); //Salvando o cargo do usuário, na variável cargo
	fclose(file); //Fechando o arquivo	
	//Final da inserção de dados
	system("pause"); //Pausando a página. Assim o usuário sós sairá dela quando quiser
}

int consultar_usuario() //Função para a consulta do usuário
{
	setlocale(LC_ALL, "portuguese"); //Definindo o idioma
	
	char cpf[40]; //Criando novamente uma variável cpf, por conta de estarmos em uma função diferente da anterior, para que seja possível a consulta. char/string
	char conteudo[200]; //Variável de armazenamento do conteúdo do arquivo, essa variável é uma char/string 
	
	printf("Digite o CPF que deseja consultar: "); //Coletando informações do usuário
	scanf("%s",cpf); //Definindo o local de armazenamento do cpf que o usuário irá digitar
	
	FILE *file;
	file = fopen(cpf,"r"); //O r vem de read, que é pra ler. Aqui é pra ele ler o arquivo cpf, ou seja, ele vai abrir e “ler” as informações
	//Início da validação
	if(file == NULL) //Operadores de decisão. Se a procura pelo cpf for nula, NULL=nulo
	{
		printf("\nEsse CPF não foi localizado.\n\n"); 
	}
	while(fgets(conteudo, 200, file) != NULL) //No caso o que o while faz é percorrer todo o arquivo e ler caractere por caractere e ir "imprimindo" na tela. É um repetidor pelo fato de ser uma string, ou seja, um conjunto de variáveis de caracteres, então ele irá rodar todo o arquivo para trazer todas as informações (variáveis) contidas dentro do arquivo. Por isso um repetidor, pois ele vai rodar até trazer tudo.O número 200 está se referindo ao while e não à variável "conteudo", isso quer dizer que ele está salvando na variável "conteudo" os 200 caracteresque estão dentro do file (arquivo).
	{
		printf("\nEssas são as informações do usuário: \n"); 
		printf("%s", conteudo); //Esse printf em questão não irá mostrar o “%s”, mas sim o o que está armazenada na variável char/string
		printf("\n\n");
	}
	fclose(file); //Fechando o arquivo
	//Final da validção
	system("pause"); //Pausando a tela, para que o usuário volte para o menu quando desejar
}

int deletar_usuario() //Função para deletar usuário
{
	char cpf[40]; //Criando novamente a variáel cpf char/string, pois estamos em uma função diferente, essa variável/string é para a alocação do cpf que será digitado pelo o usuário
	int escolha=0; //Variável para a alocação da escolha do usuário, no momento da escolha
	
	printf("Digite o CPF do usuário que deseja deletar do sistema: "); //Pedindo para o usuário digitar o cpf que desejar deletar
	scanf("%s", cpf); //Escaneando e alocando o cpf digitado pelo o usuário, que nesse caso foi alocado na variável cpf char/string dessa função
	
	FILE *file; //Chamando a a função “FILE” para acessar o “file” das nossas bibliotecas
	file = fopen(cpf, "r"); //Abrindo o arquivo, e usando o comando “r” (read) para que o mesmo leia a char/string “cpf”
	//Iníco da validção
	if(file == NULL) //Operador de decisão, caso o cpf digita estaja no sistema e seja deletado com sucesso 
	{ 
		printf("\nEsse CPF não foi localizado no nosso sistema.\n\n");
		system("pause"); //Pausando a tela para que a tela, para que assim o usuário volte para o menu quando desejar
	}
	if(file != NULL) //Operador de decisão, caso o cpf digitado NÃO seja encontrado no sistema
	{
		printf("\nTem certeza que deseja deletar o CPF "); //Coletando informações do usuário
		printf("%s", cpf); //Esse printf em questão não irá mostrar o “%s”, mas sim o o que está armazenada na variável char/string
		printf(" do nosso sistema?\n"); //Coletando informações do usuário
		printf("\nDigite “1” para DELETAR o CPF e “2” para VOLTAR ao menu do cartório: "); //Coletando informações do usuário
		scanf("%d", &escolha); //Escaneando e armazenando a resposta do usuário, no caso essa será alocada na variável tipo=int/nome=escolha. Por estar escaneando e armazenando a escolha do usuário não é obrigatório colocar o system(“pause”);
		fclose(file); //Fechando o arquivo
	
		switch (escolha) //Início da escolha
		{
			case 1:
				system("cls"); //Limpando a tela
				remove(cpf); //Chamando o comando “remove” nas bibliotecas, para que assim seja deletado o cpf desejado
				file = fopen(cpf, "r"); //Abrindo o arquivo, e pedindo para ler as informações continas nela com o comando “r”
				fclose(file); //Fechando o arquivo
				printf("CPF deletado com sucesso do nosso sistema.\n\n");
				system("pause"); //Pausando a tela para que a tela, para que assim o usuário volte para o menu quando desejar
				break; //Quando você terminar de colocar todas as instruções em um cenário no switch, você precisa colocar “break”, o break seria um ponto final. Se você não colocar não dará certo.
			case 2:
				system("cls");//Limpando a tela
				break; //Quando você terminar de colocar todas as instruções em um cenário no switch, você precisa colocar “break”, o break seria um ponto final. Se você não colocar não dará certo.
			default: //Esse default do switch VOCÊ PODE USAR quando a opção que o usuário escolheu não existe, aí você coloca o default em seguida coloca as instruções embaixo, NÃO PRECISA SER SÓ PRA OPÇÃO QUE NÃO EXISTE. Ele não é obrigatório
				system("cls"); //Limpando a tela
				printf("Essa opção não existe.\n\n");
				system("pause"); //Pausando a tela para que a mesma fique nessa, até o usuário desejar sair
				break;//Final da escolha
		}
	}
	//Final da validação
}

int criar_conta()
{
	char nome_conta[100]; //Variável string/char, que levará que será o nome do arquivo
	char celular_telefone[50]; //Variável string/char, que receberá o valor do telefone do usuário
	char senha[50]; //Variável string/char, que receberá o valor da senha do usuário
	
	printf("Insira seus dados abaixo para criar a sua conta.\n\n"); //Mensagem para o usuário
	printf("Telefone/celular: "); //Coletando informações do usuário
	scanf("%s", celular_telefone); //Escaneando e alocando a informação do usuário na string/char “celular_telefone”
	
	strcpy(nome_conta, celular_telefone); //Copiando o valor da string “celular_telefone” para a string “nome_conta”
	
	FILE *arq; //Criando o arquivo, você está falando para ele procurar nas nossas bibliotecas alguma estrutura chamada FILE, porque a gente vai criar um arquivo.
	arq = fopen(nome_conta, "w"); //Abrindo o arquivo chamado “nome_conta”. A letra “w” vêm de write, ou seja, é para escrever
	fprintf(arq, celular_telefone); //Esse comando você está falando para ele salvar o valor da string “celular_telefone” dentro do arquivo
	fclose(arq); //Fechando o arquivo
	
	printf("Senha: "); //Coletando informações do usuário
	scanf("%s", senha); //Escaneando e alocando a informação na string “senha”
	
	arq = fopen(nome_conta, "a"); //Abrindo o arquivo “nome_conta”, e a letra “a” para atulizar um arquivo já existente
	fprintf(arq, senha); //Pedindo para salvar o valor da string “senha” dentro do arquivo
	fclose(arq); //Fechando o arquivo
	
	system("pause"); //Pausando a tela para que assim o usuário consiga preencher os dados
}

int entrar_cartorio()
{
	char celular_telefone[50]="a"; //Chamando a variável que já foi criada anteriormente. Esse valor dessa variável será sobreposto ao que o usuário digitar.. então não faz diferença. Acho que por ser uma string tem que estar entre aspas o valor
	char senha[50]="a"; //Chamando a variável que já foi criada anteriormente. Esse valor dessa variável será sobreposto ao que o usuário digitar.. então não faz diferença. Acho que por ser uma string tem que estar entre aspas o valor
	char informacao_usuario[200]; //Essa variável irá receber as informações do usuário
	
	printf("Insira os seus dados abaixo para entrar no cartório EBAC.\n\n"); //Mensagem para o usuário
	printf("Telefone/celular: "); //Coletando informações do usuário
	scanf("%s", celular_telefone); //Escaneando e armazenando a informação do usuário na string “telefone_celular”
	
	printf("Senha: "); //Coletando informações do usuário
	scanf("%s", senha); //Escaneando e alocando a informação do usuário na string “senha”
		
	FILE *arq; //Com esse comando você está pedindo pra ele acessar na biblioteca e procurar uma estrutura de arquivo
	arq = fopen(celular_telefone, "r"); //Esse comando é pra ele abrir o arquivo “celualr_telefone” e a letra “r” é pra ele leia o que está dentro do arquivo
	while (fgets(informacao_usuario, 200, arq) != NULL) //Caso ele ache um arquivo com tenha o nome que bata com a informação dada pelo o usuário, que nessa situação seria a variável “celular_telefone”, já que a mesma que dá o nome ao arquivo. Nesse comando você está falando pra ele alocar o conteúdo do arquivo na variável “informacao_usuario”, ele vai gravar todos os caracteres na variável até que seja NULO, ou seja até acabar os caracteres dentro desse arquivo
	fclose(arq); //Fechando o arquivo
	
	strcat (celular_telefone, senha); //Esse comando faz a concatenação das strings, ou seja, ele liga o valor da 1º string com a 2º string
	
	if (strcmp(informacao_usuario, celular_telefone)==0) //Esse comando é para comparar o valor alocado nas strings, é “==0” porque se as informações nas strings forem iguais o esultado é 0
	{
		cartorio(); //Chamando a função “cartorio”, ou seja, se a comparação das strings der 0, ele terá acesso ao cartório da EBAC
	}
	else //Se caso as informações dada pelo o usuário não baterem na hora da comparação
	{
		system("cls"); //Limpando a tela
		printf("Telefone/celular ou senha incorretos.\n\n"); //Mensagem para o usuário
	}
	system("pause"); //Pausando a tela
}

int deletar_conta()
{
	char nome_conta[100]; //Chamando a variável que já foi criada anteriormente
	
	printf("Digite o telefone/celular da conta que você deseja deletar: "); //Coletando informações do usuário
	scanf("%s", nome_conta); //Escanaando e alocando a informação do usuário na string “nome_conta”
	
	FILE *arq; //Com esse comando você está pedindo pra ele acessar na biblioteca e procurar uma estrutura de arquivo
	arq = fopen(nome_conta, "r"); //Abrindo o arquivo correspondente com a informação dada pelo usuário. A letra “r” é para ler
	if (arq == NULL) //Se caso a informação dada pelo o usuário não exista
	{
		printf("\nEssa conta não existe.\n\n"); //Mensagem para o usuário
	}
	fclose(arq); //Fechando o arquivo
	if (arq != NULL) //Caso o informação do usuário exista
	{
		system("cls"); //Limpando a tela
		remove(nome_conta); //Chamando o comando “remove” nas bibliotecas, para que assim seja deletado a conta desejado
		arq = fopen(nome_conta, "r"); //Abrindo o arquivo correspondente com a informação dada pelo usuário. A letra “r” é para ler
		printf("Conta deletada com sucesso.\n\n"); //Mensagem para o usuário
		fclose(arq); //Fechando o arquivo
	}
	system("pause"); //Pausando a tela	
}

int cartorio()
{
	int opcao=0; //Definindo as variáveis
	int laco=1; //Definindo a repetição

	for(laco=1;laco=1;)
	{
		
		system("cls"); //Esse comando limpa a tela, vai apagar todas as mensagens que tinha antes
	
		setlocale(LC_ALL, "Portuguese"); //Definição do idioma
	
		printf("****** Cartório da EBAC ******\n\n"); //Mensagem para o usuário
		printf("-------------xxxx-------------\n\n");
		printf("Escolha uma das opções do menu:\n\n"); //Início do menu
		printf("\t1 - Cadastrar usuários.\n");
		printf("\t2 - Consultar ususários.\n");
		printf("\t3 - Deletar usuários.\n"); 
		printf("\t4 - Sair do sistema.\n\n");//Final do menu 
		printf("Opção: ");
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário na variável opção. É %d, pois é uma variável do tipo inteira
	
		system("cls"); //Esse comando limpa a tela, vai apagar todas as mensagens que tinha antes

		switch(opcao) //Início da seleção
		{
			case 1:
				cadastrar_usuario(); //Chamando a função cadastrar
				break; //Quando você terminar de colocar todas as instruções em um cenário no switch, você precisa colocar “break”, o break seria um ponto final. Se você não colocar não dará certo.
			case 2:
				consultar_usuario(); //Chamando a função consultar
				break; //Quando você terminar de colocar todas as instruções em um cenário no switch, você precisa colocar “break”, o break seria um ponto final. Se você não colocar não dará certo.
			case 3:
				deletar_usuario(); //Chamando a função deletar
				break; //Quando você terminar de colocar todas as instruções em um cenário no switch, você precisa colocar “break”, o break seria um ponto final. Se você não colocar não dará certo.
			case 4:
				printf("Obrigado por ter utilizado o nosso sistema.\n"); //Mensagem para o usuário
				exit (0); //Esse comando além de quebrar o loop do “for” ele também fehca o programa, ou seja, ele não volta pra função main. Os comandos return 0; e break; não fechariam o programa, mas sim a função e em seguida retornaria para a função main. E também não foi necessário colocar o system(“pause”); 
				break; //Quando você terminar de colocar todas as instruções em um cenário no switch, você precisa colocar “break”, o break seria um ponto final. Se você não colocar não dará certo.
			default: //Esse default do switch VOCÊ PODE USAR quando a opção que o usuário escolheu não existe, aí você coloca o default em seguida coloca as instruções embaixo, NÃO PRECISA SER SÓ PRA OPÇÃO QUE NÃO EXISTE. Ele não é obrigatório
				printf("Essa opção não existe.\n\n");
				system("pause");
				break; //Final da seleção
		}
	}	
}

int main()
{
	int login=0; //Definindo a variável da escolha do usuário
	int rep=1; //Definindo a variável do repetidor “for”
	
	for(rep=1;rep=1;) //Comando do loop, para que ele fique repetindo incontáveis vezes
	{
		system("cls"); //Limpando a tela
		
		setlocale(LC_ALL, "portuguese"); //Definindo o idioma
		
		printf("**** Seja bem-vindo a área do administrador ****\n\n"); //Mensagem para o usuário
		printf("Escolha uma das opções abaixo:\n\n"); //Mensagem para o usuário
		printf("\t1 - Criar uma conta de administrador.\n"); //Início do menu
		printf("\t2 - Entrar na cartório EBAC.\n");
		printf("\t3 - Deletar sua conta de administrador.\n");
		printf("\t4 - Sair do sistema.\n\n"); //Final do menu
		printf("Opção: "); //Mensagem para o usuário
		
		scanf("%d", &login); //Escaneando e alocando a escolha do usuário na variável “login”
		
		system("cls"); //Limpando a tela
		
		switch(login) //Início da seleção
		{
			case 1:
				criar_conta(); //Chamando a função “criar_conta”
				break; //O ponto final do switch, se não colocar vai aparecer as instruções dos outros case
			case 2: 
				entrar_cartorio(); //Chamando a função “entrar_cartorio”
				break; //O ponto final do switch, se não colocar vai aparecer as instruções dos outros case	
			case 3:
				deletar_conta(); //Chamando a função “deletar_conta”
				break; //O ponto final do switch, se não colocar vai aparecer as instruções dos outros case
			case 4: 
				printf("Obrigado por ter utilizado o nosso sistema.\n"); //Mensagem para o usuário
				return 0; //Quebrando a repetição do repetidor “for”, e assim o programa é fechado, também não foi necessário colocar o system(“pause”);
				break; //O ponto final do switch, se não colocar vai aparecer as instruções dos outros case
			default: //Quando o usuário escolher uma opção que não existe
				printf("Essa opção não existe.\n\n"); //Mensagem para o usuário
				system("pause"); //Pausando a tela
				break; //O ponto final do switch, se não colocar vai aparecer as instruções dos outros case
		}
	}
}
