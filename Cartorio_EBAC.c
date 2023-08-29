#include <stdio.h> //Biblioteca de comunica��o com o usu�rio, essa biblioteca dever� ser colocada at� quando usa o printf
#include <stdlib.h> //Biblioteca de aloca��o de espa�o na mem�ria do computador
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel pelas strings

int cadastrar() //Fun��o para cadastro do usu�rio
{
	setlocale(LC_ALL, "portuguese"); //Definindo o idioma
	
	char arquivo[40]; //Essa vari�vel vai ser o nome do arquivo que ficar�o guadados os dados cadastrados. � uma string, pois tem []
	char cpf[40]; // Vari�vel do cpf. � uma string, pois tem [], essas vari�veis precisam ser char, pois o usu�rio ir� digitar v�rios caracteres, e precisa ser uma string para que possa armazenar esse conjunto de vari�veis (caracteres/char)
	char nome[100]; //Vari�vel do nomes. � uma string pois tem [], o valor dentro dos colchetes s�o o n�mero m�ximo de caracteres que estar�o dentro do conjunto criado pela string
	char sobrenome[100]; //Vari�vel do sobrenome. � uma string pois tem []
	char cargo[100]; //Vari�vel do cargo. � uma string pois tem []
	
	printf("Digite o CPF do usu�rio que deseja cadastrar: "); //Coletando informa��es do usu�rio. Esse printf vem antes do strcpy, pois primeiro voc� tem que definir o valor da string que ter� o valor copiado, se voc� n�o fizer isso antes n�o dar� certo
	scanf("%s", cpf); //Definindo o local de armazenamento do cpf, nesse caso � na vari�vel �cpf char/string�. � %s, porque � uma string 
	
	strcpy(arquivo, cpf); //Essa fun��o vai copiar o valor do cpf cadastrado para nomear o arquivo. Vai copiar a string cpf para a string arquivo
	//In�co da inser��o de dados
	FILE *file; //Criando o arquivo, voc� est� falando para ele procurar nas nossas bibliotecas alguma estrutura chamada FILE, porque a gente vai criar um arquivo. Esse file em min�sculo d� pra mudar o nome, voc� pode usar qualquer outra palavra, ex: pasta.
	file = fopen(arquivo, "w"); //Aqui voc� est� abrindo o arquivo. Esse w vem de write, para escrever. D� pra colocar a vari�vel CPF, pois tanto a vari�vel "arquivo" quanto a vari�vel "cpf" t�m os valores igualados. Na verdade, poderia ser qualquer uma das vari�veis, por�m como o CPF � o identificador do usu�rio cadastrado, ent�o tem que ser ele ou uma vari�vel que tenha o valor igual ao dele, que no caso � a vari�vel "arquivo"
	fprintf(file,"CPF: "); //Esse comando � para escrever o que vai aparecer no arquivo
	fclose(file); //Aqui est� fechando o arquivo
		
	file = fopen(arquivo, "a"); //Atulizando o arquivo
	fprintf(file, cpf); //Aqui est� salvando o o cpf do usu�rio na vari�vel cpf
	fclose(file); //Aqui est� fechando o arquivo
	
	printf("Digite o nome do usu�rio que deseja cadastrar: "); //Coletando informa��es do usu�rio
	scanf("%s", nome); //Definindo o local de armazenamento do nome, que nesse caso � na vari�vel �nome char/string�

	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, ", Nome: "); //Escrevendo o que vai aparecer no arquivo
	fclose(file); //Fechando o arquivo
		
	file = fopen(arquivo, "a"); //Atulizando o arquivo
	fprintf(file, nome); //Salvando o nome do usu�rio, na vari�vel nome
	fclose(file); //Fechando o arquivo
	
	printf("Digite o sobrenome do usu�rio que deseja cadastrar: "); //Coletando informa��es do usu�rio
	scanf("%s", sobrenome); //Defininfo o local de armazenamento do sobrenome do usu�rio, nesse caso � na vari�vel �sobrenome char/string�
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, ", Sobrenome: "); //Escrevendo o que vai aparecer no arquivo
	fclose(file); //Fechando o arquivo
		
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, sobrenome); //Salvando o sobrenome do usu�rio, na vari�vel sobrenome
	fclose(file); //Fechando o arquivo
	
	printf("Digite o cargo do usu�rio que deseja cadastrar: "); //Coletando informa��es do usu�rio
	scanf("%s", cargo); //Definindo o local de armazenamento do cargo do usu�rio, nesse caso � na vari�vel �cargo char/string�
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, ", Cargo: "); //Escrevendo o que vai aparecer no arquivo
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file, cargo); //Salvando o cargo do usu�rio, na vari�vel cargo
	fclose(file); //Fechando o arquivo	
	//Final da inser��o de dados
	system("pause"); //Pausando a p�gina. Assim o usu�rio s�s sair� dela quando quiser
}

int consultar() //Fun��o para a consulta do usu�rio
{
	setlocale(LC_ALL, "portuguese"); //Definindo o idioma
	
	char cpf[40]; //Criando novamente uma vari�vel cpf, por conta de estarmos em uma fun��o diferente da anterior, para que seja poss�vel a consulta. char/string
	char conteudo[200]; //Vari�vel de armazenamento do conte�do do arquivo, essa vari�vel � uma char/string 
	
	printf("Digite o CPF que deseja consultar: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //Definindo o local de armazenamento do cpf que o usu�rio ir� digitar
	
	FILE *file;
	file = fopen(cpf,"r"); //O r vem de read, que � pra ler. Aqui � pra ele ler o arquivo cpf, ou seja, ele vai abrir e �ler� as informa��es
	//In�cio da valida��o
	if(file == NULL) //Operadores de decis�o. Se a procura pelo cpf for nula, NULL=nulo
	{
		printf("\nEsse CPF n�o foi localizado.\n\n"); 
	}
	while(fgets(conteudo, 200, file) != NULL) //No caso o que o while faz � percorrer todo o arquivo e ler caractere por caractere e ir "imprimindo" na tela. � um repetidor pelo fato de ser uma string, ou seja, um conjunto de vari�veis de caracteres, ent�o ele ir� rodar todo o arquivo para trazer todas as informa��es (vari�veis) contidas dentro do arquivo. Por isso um repetidor, pois ele vai rodar at� trazer tudo.O n�mero 200 est� se referindo ao while e n�o � vari�vel "conteudo", isso quer dizer que ele est� salvando na vari�vel "conteudo" os 200 caracteresque est�o dentro do file (arquivo).
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n"); 
		printf("%s", conteudo); //Esse printf em quest�o n�o ir� mostrar o �%s�, mas sim o o que est� armazenada na vari�vel char/string
		printf("\n\n");
	}
	fclose(file); //Fechando o arquivo
	//Final da valid��o
	system("pause"); //Pausando a tela, para que o usu�rio volte para o menu quando desejar
}

int deletar() //Fun��o para deletar usu�rio
{
	char cpf[40]; //Criando novamente a vari�el cpf char/string, pois estamos em uma fun��o diferente, essa vari�vel/string � para a aloca��o do cpf que ser� digitado pelo o usu�rio
	int escolha=0; //Vari�vel para a aloca��o da escolha do usu�rio, no momento da escolha
	
	printf("Digite o CPF do usu�rio que deseja deletar do sistema: "); //Pedindo para o usu�rio digitar o cpf que desejar deletar
	scanf("%s", cpf); //Escaneando e alocando o cpf digitado pelo o usu�rio, que nesse caso foi alocado na vari�vel cpf char/string dessa fun��o
	
	FILE *file; //Chamando a a fun��o �FILE� para acessar o �file� das nossas bibliotecas
	file = fopen(cpf, "r"); //Abrindo o arquivo, e usando o comando �r� (read) para que o mesmo leia a char/string �cpf�
	//In�co da valid��o
	if(file == NULL) //Operador de decis�o, caso o cpf digita estaja no sistema e seja deletado com sucesso 
	{ 
		printf("\nEsse CPF n�o foi localizado no nosso sistema.\n\n");
		system("pause"); //Pausando a tela para que a tela, para que assim o usu�rio volte para o menu quando desejar
	}
	if(file != NULL) //Operador de decis�o, caso o cpf digitado N�O seja encontrado no sistema
	{
		printf("\nTem certeza que deseja deletar o CPF "); //Coletando informa��es do usu�rio
		printf("%s", cpf); //Esse printf em quest�o n�o ir� mostrar o �%s�, mas sim o o que est� armazenada na vari�vel char/string
		printf(" do nosso sistema?\n"); //Coletando informa��es do usu�rio
		printf("\nDigite �1� para DELETAR o CPF e �2� para VOLTAR ao menu: "); //Coletando informa��es do usu�rio
		scanf("%d", &escolha); //Escaneando e armazenando a resposta do usu�rio, no caso essa ser� alocada na vari�vel tipo=int/nome=escolha. Por estar escaneando e armazenando a escolha do usu�rio n�o � obrigat�rio colocar o system(�pause�);
		fclose(file); //Fechando o arquivo
	
		switch (escolha) //In�cio da escolha
		{
			case 1:
				system("cls"); //Limpando a tela
				remove(cpf); //Chamando o comando �remove� nas bibliotecas, para que assim seja deletado o cpf desejado
				file = fopen(cpf, "r"); //Abrindo o arquivo, e pedindo para ler as informa��es continas nela com o comando �r�
				fclose(file); //Fechando o arquivo
				printf("CPF deletado com sucesso do nosso sistema.\n\n");
				system("pause"); //Pausando a tela para que a tela, para que assim o usu�rio volte para o menu quando desejar
				break; //Quando voc� terminar de colocar todas as instru��es em um cen�rio no switch, voc� precisa colocar �break�, o break seria um ponto final. Se voc� n�o colocar n�o dar� certo.
			case 2:
				system("cls");//Limpando a tela
				break; //Quando voc� terminar de colocar todas as instru��es em um cen�rio no switch, voc� precisa colocar �break�, o break seria um ponto final. Se voc� n�o colocar n�o dar� certo.
			default: //Esse default do switch VOC� PODE USAR quando a op��o que o usu�rio escolheu n�o existe, a� voc� coloca o default em seguida coloca as instru��es embaixo, N�O PRECISA SER S� PRA OP��O QUE N�O EXISTE. Ele n�o � obrigat�rio
				system("cls"); //Limpando a tela
				printf("Essa op��o n�o existe.\n\n");
				system("pause"); //Pausando a tela para que a mesma fique nessa, at� o usu�rio desejar sair
				break;//Final da escolha
		}
	}
	//Final da valida��o
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1; //Definindo a repeti��o
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Esse comando limpa a tela, vai apagar todas as mensagens que tinha antes
	
		setlocale(LC_ALL, "Portuguese"); //Defini��o do idioma
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha uma das op��es do menu:\n\n"); 
		printf("\t1 - Cadastrar usu�rios.\n");
		printf("\t2 - Consultar usus�rios.\n");
		printf("\t3 - Deletar usu�rios.\n\n"); //Final do menu 
		printf("Op��o: ");
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio na vari�vel op��o. � %d, pois � uma vari�vel do tipo inteira
	
		system("cls"); //Esse comando limpa a tela, vai apagar todas as mensagens que tinha antes
	
		switch(opcao) //In�cio da sele��o
		{
			case 1:
				cadastrar(); //Chamando a fun��o cadastrar
				break; //Quando voc� terminar de colocar todas as instru��es em um cen�rio no switch, voc� precisa colocar �break�, o break seria um ponto final. Se voc� n�o colocar n�o dar� certo.
				
			case 2:
				consultar(); //Chamando a fun��o consultar
				break; //Quando voc� terminar de colocar todas as instru��es em um cen�rio no switch, voc� precisa colocar �break�, o break seria um ponto final. Se voc� n�o colocar n�o dar� certo.
				
			case 3:
				deletar(); //Chamando a fun��o deletar
				break; //Quando voc� terminar de colocar todas as instru��es em um cen�rio no switch, voc� precisa colocar �break�, o break seria um ponto final. Se voc� n�o colocar n�o dar� certo.
				
			default: //Esse default do switch VOC� PODE USAR quando a op��o que o usu�rio escolheu n�o existe, a� voc� coloca o default em seguida coloca as instru��es embaixo, N�O PRECISA SER S� PRA OP��O QUE N�O EXISTE. Ele n�o � obrigat�rio
				printf("Essa op��o n�o existe.\n\n");
				system("pause");
				break; //Final da sele��o
		}
	}
}
