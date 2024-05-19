#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fun��o para limpar o buffer de entrada
void limparBuffer() {
    system ("color 0B");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Fun��o para limpar a tela
void limparTela() {
     system ("color 0B");
    system("cls || clear");
}

// Fun��o para verificar o nome de usu�rio e senha
int verificarCredenciais(char *usuario, char *senha) {

    // Verificar se o usu�rio e a senha s�o v�lidos
    //  "admin" como usu�rio e "senha123" como senha
     system ("color 0B");
    if (strcmp(usuario, "admin") == 0 && strcmp(senha, "senha123") == 0) {
        return 1; // Credenciais v�lidas
    } else {
        return 0; // Credenciais inv�lidas
    }
}

// Fun��o para a tela inicial de login

void telaInicial() {
     system ("color 0B");
    char usuario[20];
    char senha[20];

    // Solicitar nome de usu�rio

    printf("************************************** BEM VINDO - IMOBILIARIA TATOOINE *****************************************\n");
    printf("\n");
    printf("Por favor, insira seu nome de usuario: ");
    scanf("%s", usuario);
    limparBuffer(); // Limpa o buffer

    // Solicitar senha
    printf("Por favor, insira sua senha: ");
    scanf("%s", senha);
    limparBuffer(); // Limpa o buffer

    // Verificar as credenciais
    if (verificarCredenciais(usuario, senha)) {
        // Credenciais v�lidas, continuar com o programa
        printf("Credenciais validas. Pressione qualquer tecla para continuar...\n");
        getchar(); // Aguarda a entrada do usu�rio
        limparBuffer(); // Limpa o buffer
        limparTela(); // Limpa a tela
    } else {
        // Credenciais inv�lidas, encerrar o programa
        printf("Credenciais invalidas. Encerrando o programa...\n");
        exit(0);
    }
}

void cadastrarImovel(); // Declarando a fun��o antes do menu principal
void verCidades(); // Declarando a fun��o antes do menu principal

// Fun��o para o menu principal
void menuPrincipal() {
    system ("color 0B");
    while (1) {
        int escolha;

         printf("Deseja cadastrar um imovel, ver as cidades disponiveis ou consultar imoveis cadastrados?\n");
        printf(" 1 - Cadastrar imovel\n");
        printf(" 2 - Ver cidades disponiveis\n");
        printf(" 3 - Consultar imoveis cadastrados\n");
        printf(" 0 - Encerrar o programa\n");
        scanf("%d", &escolha);
        limparBuffer(); // Limpa o buffer

        limparTela(); // Limpa a tela

        switch (escolha) {
            case 0:
                printf("Encerrando o programa...\n");
                exit(0);
            case 1:
                cadastrarImovel();
                break;
            case 2:
                verCidades();
                break;
            case 3:
                // Consultar im�veis cadastrados
                consultarImoveisCadastrados();
                printf("Pressione qualquer tecla para continuar...\n");
                getchar(); // Aguarda a entrada do usu�rio
                limparBuffer(); // Limpa o buffer
                break;
            default:
                printf("Opcao invalida\n");
        }
    }
}

void cadastrarImovel() {
    system ("color 0B");
    int modelo;
    float tamanho, valor;

    printf("Por favor escolha o modelo do imovel:\n");
    printf(" 1 - Casa\n");
    printf(" 2 - Terreno\n");
    printf(" 3 - Apartamento\n");
    printf(" 0 - Voltar ao menu anterior\n");
    scanf("%d", &modelo);
    limparBuffer(); // Limpa o buffer

    limparTela(); // Limpa a tela

    // Menu Escolha do usuario
    switch (modelo) {
        case 0:
            // Retorna ao menu anterior
            return;
        case 1:
        case 2:
        case 3:
            break;
        default:
            // Caso a op��o n�o seja v�lida
            printf("Opcao invalida\n");
            cadastrarImovel(); // Chama novamente a fun��o
            return;
    }

    printf("Quantos metros quadrado o terro tem ? - Informe apenas o numero: ");
    scanf("%f", &tamanho);
    limparBuffer(); // Limpa o buffer

    printf("Informe o valor do imovel - Informe apenas numeros: ");
    scanf("%f", &valor);
    limparBuffer(); // Limpa o buffer

    // Informa��o de cadastro realizado
    printf("Imovel cadastrado com sucesso!\n");

    // Menu ap�s o cadastro para encerrar o programa ou retornar ao menu inicial
    int escolhaEncerrar;
    printf("Deseja encerrar o programa ou voltar ao menu inicial?\n");
    printf(" 1 - Encerrar o programa\n");
    printf(" 0 - Voltar ao menu inicial\n");
    scanf("%d", &escolhaEncerrar);
    limparBuffer(); // Limpa o buffer

    if (escolhaEncerrar == 1) {
        // Encerra o programa
        printf("Encerrando o programa...\n");
        exit(0);
    } else {
        // Retorna ao menu inicial
        return;
    }
}

// Fun��o para o menu de visualiza��o de cidades
void verCidades() {
    system ("color 0B");
    int cidade, opcao;


    printf("Por favor escolha uma das cidades \n");
    printf(" 1 - Curitiba (capital)\n");
    printf(" 2 - Londrina \n");
    printf(" 3 - Maringa \n");
    printf(" 0 - Voltar ao menu inicial\n");
    scanf("%d", &cidade);
    limparBuffer(); // Limpa o buffer

    limparTela(); // Limpa a tela

    // Loop para garantir que a cidade selecionada seja v�lida
    while (cidade < 0 || cidade > 3) {
        printf("Cidade invalida, por favor escolha novamente\n");
        scanf("%d", &cidade);
        limparBuffer(); // Limpa o buffer
    }

    if (cidade == 0) {
        // Retorna ao menu inicial
        return;
    }

    // Menu de escolha de op��o adicional
    printf("Seja bem vindo \n");
    printf("Por favor escolha a modalidade desejada:\n");
    printf(" 1 - Terrenos a venda\n");
    printf(" 2 - Casas a venda\n");
    printf(" 0 - Voltar ao menu inicial\n");
    scanf("%d", &opcao);
    limparBuffer(); // Limpa o buffer

    limparTela(); // Limpa a tela

    // Loop para garantir que a op��o selecionada seja v�lida
    while (opcao < 0 || opcao > 2) {
        printf("Opcao invalida, por favor selecione novamente\n");
        scanf("%d", &opcao);
        limparBuffer(); // Limpa o buffer
    }

    if (opcao == 0) {
        // Retorna ao menu inicial
        return;
    }

    // Processamento da op��o adicional
    switch (opcao) {
        case 1:
            printf("Selecionado - Terrenos a venda\n");
            // Exibir op��es de terrenos
            printf("Terrenos disponiveis:\n");
            printf("1. Terreno no centro - Valor: 100 mil\n");
            printf("2. Terreno no bairro Portao - Valor: 200 mil\n");
            printf("3. Terreno no bairro Reboucas - Valor: 150 mil\n");
            break;
        case 2:
            printf("Selecionado - Casas a venda\n");
            // Exibir op��es de casas
            printf("Casas disponiveis:\n");
            printf("1. Casa no centro - Valor: 300 mil\n");
            printf("2. Casa no bairro Portao - Valor: 400 mil\n");
            printf("3. Casa no bairro Reboucas - Valor: 350 mil\n");
            break;
    }

    printf("\nPressione qualquer tecla para continuar...");
    getchar(); // Aguarda a entrada do usu�rio
    limparBuffer(); // Limpa o buffer
    limparTela(); // Limpa a tela novamente

    // Perguntar se deseja simular um financiamento ou agendar uma visita
    int escolha;
    printf("\nVoce Deseja simular um financiamento ou agendar uma visita?\n");
    printf(" 1 - Simular financiamento\n");
    printf(" 2 - Agendar visita\n");
    printf(" 0 - Voltar ao menu inicial\n");
    printf("\n");
    scanf("%d", &escolha);
    limparBuffer(); // Limpa o buffer

    limparTela(); // Limpa a tela novamente

    // Loop para garantir que a escolha seja v�lida
    while (escolha < 0 || escolha > 2) {
        printf("Opcao invalida\n");
        scanf("%d", &escolha);
        limparBuffer(); // Limpa o buffer
    }

    if (escolha == 0) {
        // Retorna ao menu inicial
        return;
    }

    // Processamento da escolha
    switch (escolha) {
        case 1:
            printf("Simulacao de financiamento selecionada.\n");
            // Solicitar o valor de entrada
            float valorEntrada;
            printf("Informe o valor de entrada (minimo R$ 20.000): ");
            scanf("%f", &valorEntrada);
            limparBuffer(); // Limpa o buffer
            if (valorEntrada < 20000) {
                printf("Valor de entrada invalido. O valor minimo e de R$ 20.000\n");
                return;
            }
            // Calcula o valor financiado
            float valorFinanciado = (100 - (valorEntrada / 100)) * 300000 * -1; // Supondo que a casa custe R$ 300.000
            // Calcula o valor da parcela
            float valorParcela = valorFinanciado / (5 * 12); // 5 anos em meses
            printf("O valor da parcela sera de: R$ %.4f\n", valorParcela);
            break;
        case 2:
            printf("Agendamento de visita selecionado.\n");
            break;
    }

    // Menu para encerrar o programa ou retornar ao menu inicial
    int escolhaEncerrar;
    printf("\nDeseja encerrar o programa ou voltar ao menu inicial?\n");
    printf(" 1 - Encerrar o programa\n");
    printf(" 0 - Voltar ao menu inicial\n");
    scanf("%d", &escolhaEncerrar);
    limparBuffer(); // Limpa o buffer

    limparTela(); // Limpa a tela

    if (escolhaEncerrar == 1) {
        // Encerra o programa
        printf("Encerrando o programa...\n");
        exit(0);
    } else {
        // Retorna ao menu inicial
        return;
    }
}

// Fun��o para consultar im�veis cadastrados
void consultarImoveisCadastrados() {
    system ("color 0B");
    // Aqui voc� pode adicionar a implementa��o da fun��o para consultar os im�veis cadastrados
    // Exemplo:
    printf("Consulta de imoveis cadastrados...\n");
    printf("Imovel 1: Casa no centro - Valor: R$ 300.000\n");
    printf("Imovel 2: Terreno no bairro Portao - Valor: R$ 200.000\n");
    printf("Imovel 3: Apartamento no centro - Valor: R$ 500.000\n");
}

// C�digo Principal - Programa inteiro
int main(void) {
    system ("color 0B");
    // Tela inicial de login
    telaInicial();

    // Menu principal
    system ("color 0B");
    menuPrincipal();

    return 0;
}
