# ConcursoEuromilhoes

  Com este projeto pretendeu-se criar um sistema cliente/servidor que permita registar e gerir apostas no jogo Euromilhões usando a framework gRPC. Foi implementado três programas
cliente e um programa servidor usando a linguagem C# e a framework gRPC. Foi também especificado o conjunto de serviços RPC implementados no servidor e usados pelos clientes.

Servidor:
  • Implementou-se as funcionalidades necessárias para os utilizadores registarem apostas, e disponibilizar essas funcionalidades sob a forma de serviço gRPC.
  • Implementou-se as funcionalidades necessárias para o administrador visualizar as apostas correntes e efetuar o seu arquivo, devendo disponibilizar essas funcionalidades 
    sob a forma de serviço gRPC.
  • Implementou-se as funcionalidades necessárias paras o diretor do sorteio efetuar a gestão do sorteio Euromilhões, recebendo a chave vencedora e identificando os vencedores.
    Foram disponibilizadas, essas funcionalidades sob a forma de serviço gRPC.
  • Identifica cada jogador e as chaves em que aposta.
  • Mantém um registo das apostas correntes e do arquivo de apostas de sorteios anteriores.
  • Cada aposta contém, pelo menos: a identificação do utilizador, a chave, a data da aposta.
  • O registo persistente de informação foi efetuado em base de dados: MS SQL Express
  
Cliente para utilizadores:
  • Têm configurado, receber como parâmetro, ou pedir ao utilizador o endereço IP do servidor a contactar.
  • Tem identificar o utilizador.
  • Permite a visualização da lista de chaves em que o utilizador já apostou anteriormente.
  • Permite  registar apostas.
  • Foi programado como uma aplicação com interface gráfica Windows (Windows forms).

Cliente para administração do sistema:
  • Tem configurado, receber como parâmetro, ou pedir ao utilizador o endereço IP do servidor a contactar.
  • Permite a visualização da lista de utilizadores e chaves registadas para sorteio.
  • Permite arquivar as apostas e iniciar um novo sorteio.
  • Foi programado como uma aplicação com interface gráfica Windows (Windows forms).
  
Cliente para gestão do sorteio:
  • Tem configurado, receber como parâmetro, ou pedir ao utilizador o endereço IP do servidor a contactar.
  • Permite o registo da chave vencedora e a obtenção das apostas vencedoras.
  • Foi programado como uma aplicação com interface gráfica Windows (Windows forms).
  
Implementação:
  • A implementação dos clientes e do servidor foram feitas em Visual Studio (Core 3 ou superior e C#) e gRPC.
 
