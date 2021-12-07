//C�digo feito por: Ana Dias al69691, Diana Alves al68557, Diana Ferreira al68938

#include <stdio.h>
#include <winsock2.h>
#include <string.h>

#pragma comment(lib,"ws2_32.lib") 
#pragma warning(disable : 4996)

int main(int argc, char* argv[])
{
	//Declara��o de vari�veis
	WSADATA wsa;							//armazena as informa��es do socket
	SOCKET s;								//Socket utilizada para a conex�o
	struct sockaddr_in server;				//armazenar os dados do servidor ao qual o cliente se vai conectar, como o IP e a porta
	char* mensagem = (char*)malloc(8192);	//armazenar a resposta do servidor para futura compara��o dos status codes
	char respostaServidor[8192];			//Vari�vel que armazena a resposta do servidor
	bool conectado = false;					//Estado da conex�o
	char* ip = (char*)malloc(20);			//mem�ria alocada para o IP 
	int recv_size;							//Tamanho da resposta do servidor, ir� ser tamb�m verificada para resolver problemas de troca de informa��es
	int ws_resultado = -1;					//por defeito n�o est� conectado inicialmente

	//Inicializar Winsock
	printf("\nInicializar Socket...");
	if(WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("ERRO! C�digo de Erro: %d", WSAGetLastError());
		return 1;
	}
	printf("Socket Inicializado.\n");

	//Criar o Socket
	s = socket(AF_INET, SOCK_STREAM, 0);
	if(s == INVALID_SOCKET)
	{
		printf("Nao foi possivel criar o Socket : %d", WSAGetLastError());
	}
	printf("Socket criado.\n");

	while(conectado == false) //Enquanto n�o estiver conectado, tenta conectar-se
	{
		while(ws_resultado < 0) //Enquanto o IP inserido n�o for v�lido
		{
			printf("Insira o IP (servidor) para se conectar:");
			fgets(ip, 20, stdin);

			//Criar o endere�o do Socket(IP address e porta)
			server.sin_addr.s_addr = inet_addr(ip);
			server.sin_family = AF_INET;
			server.sin_port = htons(68000); //porta
			//Conectar a um server remoto
			ws_resultado = connect(s, (struct sockaddr*)&server, sizeof(server));

			if(ws_resultado < 0)
			{
				printf("IP invalido! Tente novamente!!\n");
			}
		}
		
		//Recebe a resposta do servidor
		recv_size = recv(s, respostaServidor, 8192, 0);
		if(recv_size == SOCKET_ERROR) //Se der erro na liga��o ao servidor
		{
			puts("Falha ao receber.\n");
		}
		if(strcmp(respostaServidor, "100 OK") == 0) //Se n�o der erro apresenta os comandos poss�veis
		{
			printf("Conectado\n");
			conectado = true;
			printf("\n\tComandos Possiveis:\n");
			printf("\tPARA DETERMINAR AS CHAVES A CRIAR: CHAVE / Chave / chave + numero de chaves a criar \n");
			printf("\tPARA TERMINAR A CONEXAO: QUIT/ Quit / quit \n");
		}
	}

	while(1)//Ciclo infinito
	{
		//Apagar as mensagens vindas tanto do servidor como do cliente, para que possa receber novas mensagens
		ZeroMemory(mensagem, 8192);
		ZeroMemory(respostaServidor, 8192);

		fputs("\n\nEscreva o comando que deseja: ", stdout);
		fgets(mensagem, 8192, stdin);

		//Caso d� erro a enviar mensagens ao Servidor
		ws_resultado = send(s, mensagem, strlen(mensagem) - 1, 0);  // -1 para nao enviar "\n"
		if(ws_resultado < 0)
		{
			puts("Falha no envio.");
			return 1;
		}

		//Caso d� erro ao receber a mensagem do Servirdor
		recv_size = recv(s, respostaServidor, 8192, 0);
		if(recv_size == SOCKET_ERROR)
		{
			puts("Falha ao receber.");
		}

		//Vai buscar apenas o numero do codigo de erro � resposta do servidor
		char* cod_erro = strtok(respostaServidor, " ");
		int tent = atoi(cod_erro);
		//Compara o numero do erro com os numeros poss�veis
		switch (tent)
		{ 
			case 200: // 200 Sent
				ZeroMemory(respostaServidor, 8192);
				recv_size = recv(s, respostaServidor, 8192, 0);
				respostaServidor[recv_size] = '\0';
				printf("\nServidor: \n%s\n", respostaServidor);
			break;
			case 450: // 450 MalDirecionado
				printf("Servidor Erro: Comando desconhecido.\n");
			break;
			case 410: // 410 Perdido
				printf("Servidor Erro: Esta em falta o numero de chave para serem criadas.\n");
			break;
			case 404: // 404 NaoEncontrado
				printf("Servidor Erro: Numero de chaves invalido.\n");
			break;
			case 400: // 400 Bye
				printf("Servidor: Conexao terminada.\n");  
				system("pause");
				exit(-1);
			break;
		}
	}

	//Fechar o socket
	closesocket(s);
	//Limpar Winsock
	WSACleanup();

	system("pause");
	return 0;
}

