#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

// CORES ANSI
#define PRETO "\x1b[30m"
#define VERMELHO "\x1b[1;31m"
#define VERDE "\x1b[32m"
#define AMARELOFORTE "\x1b[33m"
#define AZUL "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CIANO "\x1b[36m"
#define BRANCO "\x1b[37m"
#define MARROM "\x1b[33m"
#define MARROMCLARO "\x1b[93m"
#define CINZA "\033[90m"
#define FUNDOCIANO "\033[46m"
#define FUNDOVERDE "\033[42m"
#define FUNDOMAGENTA "\033[45m"
#define BRANCO_FORTE "\033[97m"
#define RESET "\x1b[0m"
#define PISCAR "\033[5m"
#define AMARELO "\033[1;33m"
#define FUNDOAMARELO "\x1b[43m"
#define FUNDOVERMELHO "\033[41m"
#define FUNDOAZUL "\033[44;37m"
#define FUNDOCINZA "\033[100m"
#define FUNDOCINZA_ESC "\033[48;5;8m"
#define VERDE_ESCURO "\x1b[38;5;22m"
#define VERDE_MUSGO "\x1b[38;5;65m"
#define DOURADO "\x1b[38;5;178m"

void invalid_option()
{
    system("cls");

    char *invalid_option_image[23] = {
        VERMELHO "         ███             ███             ███             ███             ███             ███             ███       ",
        "       ███░            ███░            ███░            ███░            ███░            ███░            ███░        ",
        "     ███░            ███░            ███░            ███░            ███░            ███░            ███░          ",
        "   ███░            ███░            ███░            ███░            ███░            ███░            ███░            ",
        " ███░            ███░            ███░            ███░            ███░            ███░            ███░            ██",
        "██░            ███░            ███░            ███░            ███░            ███░            ███░            ███░",
        "░            ███░            ███░            ███░            ███░            ███░            ███░            ███░  ",
        "            ░░░             ░░░             ░░░             ░░░             ░░░             ░░░             ░░░    " RESET,
        VERMELHO "     ██" RESET "██████╗ ██████╗████████╗ █████╗████████╗     ██╗███╗   ██╗██╗ ████╗ █████╗ ██╗███  ██╗██████╗ ██████╗       ",
        VERMELHO "   ███" RESET "██╔═══██╗██╔══██╗██╔════╝██╔══██╗██╔═══██╗   ███║████╗  ██║██║██░██║██╔══██╗██║█░   ██║██╔══██╗██╔══██╗      ",
        VERMELHO " ███░ " RESET "██║   ██║██████╔╝██║     ███████║██║   ██║ █████║██╔██╗ ██║██║░  ██║███████║██║     ██║██║  ██║███████║" VERMELHO "    ██",
        VERMELHO "██░   " RESET "██║   ██║██╔═══╝ ██║     ██╔══██║██║   ██║██░ ██║██║╚██╗██║╚██╗ ██╔╝██╔══██║██║     ██║██║  ██║██╔══██║" VERMELHO "  ███░",
        VERMELHO "░     " RESET "╚██████╔╝██║     ╚██████╗██║  ██║╚██████╔╝░   ██║██║ ╚████║ ╚████╔╝ ██║████║███████╗██║██████╔╝██║  ██║" VERMELHO "███░  ",
        VERMELHO "      " RESET " ╚═════╝░╚═╝      ╚═════╝╚═╝  ╚═╝ ╚═════╝     ╚═╝╚═╝ █╚═══╝  ╚═══╝  ╚═╝█░╚═╝╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝" VERMELHO "█░    ",
        VERMELHO "         ███░            ███░            ███░            ███░            ███░            ███░            ███░      ",
        "        ░░░             ░░░             ░░░             ░░░             ░░░             ░░░             ░░░        ",
        " ███             ███             ███             ███             ███             ███             ███             ██",
        "██░            ███░            ███░            ███░            ███░            ███░            ███░            ███░",
        "░            ███░            ███░            ███░            ███░            ███░            ███░            ███░  ",
        "           ███░            ███░            ███░            ███░            ███░            ███░            ███░    ",
        "         ███░            ███░            ███░            ███░            ███░            ███░            ███░      ",
        "       ███░            ███░            ███░            ███░            ███░            ███░            ███░        ",
        "     ███░            ███░            ███░            ███░            ███░            ███░            ███░          " RESET};

    for (int i = 0; i < 23; i++)
    {
        printf("%s\n", invalid_option_image[i]);
    }
}

void Soma()
{
    system("cls");

    char *sum_image[6] = {
        "███████╗ ██████╗ ███╗   ███╗ █████╗ ",
        "██╔════╝██╔═══██╗████╗ ████║██╔══██╗",
        "███████╗██║   ██║██╔████╔██║███████║",
        "╚════██║██║   ██║██║╚██╔╝██║██╔══██║",
        "███████║╚██████╔╝██║ ╚═╝ ██║██║  ██║",
        "╚══════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝"};

    for (int i = 0; i < 6; i++)
    {
        printf("%s\n", sum_image[i]);
    }

    int quantidade = 0;
    float soma = 0, numero = 0;

    printf("Quantos valores deseja somar: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        printf("Quantidade invalida.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("Informe o valor %d: ", i + 1);
        scanf("%f", &numero);
        soma = soma + numero;
    }

    printf("A soma e: %.2f\n", soma);
}

void Subtracao()
{
    system("cls");

    char *subtraction_image[6] = {
        "███████╗██╗   ██╗██████╗ ████████╗██████╗  █████╗  ██████╗ █████╗  ██████╗ ",
        "██╔════╝██║   ██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔═══██╗",
        "███████╗██║   ██║██████╔╝   ██║   ██████╔╝███████║██║     ███████║██║   ██║",
        "╚════██║██║   ██║██╔══██╗   ██║   ██╔══██╗██╔══██║██║     ██╔══██║██║   ██║",
        "███████║╚██████╔╝██████╔╝   ██║   ██║  ██║██║  ██║╚██████╗██║  ██║╚██████╔╝",
        "╚══════╝ ╚═════╝ ╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        printf("%s\n", subtraction_image[i]);
    }

    int quantidade = 0;
    float subtracao = 0, numero = 0;

    printf("Quantos valores deseja subtrair: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        printf("Quantidade invalida.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("Informe o valor %d: ", i + 1);
        scanf("%f", &numero);

        if (i == 0)
            subtracao = numero;
        else
            subtracao = subtracao - numero;
    }

    printf("A subtracao e: %.2f\n", subtracao);
}

void Multiplicacao()
{
    system("cls");

    char *multiplication_image[6] = {
        "███╗   ███╗██╗   ██╗██╗  ████████╗██╗██████╗ ██╗     ██╗ ██████╗ █████╗  ██████╗ █████╗  ██████╗ ",
        "████╗ ████║██║   ██║██║  ╚══██╔══╝██║██╔══██╗██║     ██║██╔════╝██╔══██╗██╔════╝██╔══██╗██╔═══██╗",
        "██╔████╔██║██║   ██║██║     ██║   ██║██████╔╝██║     ██║██║     ███████║██║     ███████║██║   ██║",
        "██║╚██╔╝██║██║   ██║██║     ██║   ██║██╔═══╝ ██║     ██║██║     ██╔══██║██║     ██╔══██║██║   ██║",
        "██║ ╚═╝ ██║╚██████╔╝███████╗██║   ██║██║     ███████╗██║╚██████╗██║  ██║╚██████╗██║  ██║╚██████╔╝",
        "╚═╝     ╚═╝ ╚═════╝ ╚══════╝╚═╝   ╚═╝╚═╝     ╚══════╝╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        printf("%s\n", multiplication_image[i]);
    }

    int quantidade = 0;
    float multiplicacao = 1, numero = 0;

    printf("Quantos valores deseja multiplicar: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        printf("Quantidade invalida.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("Informe o valor %d: ", i + 1);
        scanf("%f", &numero);
        multiplicacao = multiplicacao * numero;
    }

    printf("A multiplicacao e: %.2f\n", multiplicacao);
}

void limparTela()
{
    system("cls");
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void menucalculadora()
{
    char *calculator_image[6] = {
        " ██████╗ █████╗ ██╗      ██████╗██╗   ██╗██╗      █████╗ ████████╗ ██████╗ ██████╗ ",
        "██╔════╝██╔══██╗██║     ██╔════╝██║   ██║██║     ██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗",
        "██║     ███████║██║     ██║     ██║   ██║██║     ███████║   ██║   ██║   ██║██████╔╝",
        "██║     ██╔══██║██║     ██║     ██║   ██║██║     ██╔══██║   ██║   ██║   ██║██╔══██╗",
        "╚██████╗██║  ██║███████╗╚██████╗╚██████╔╝███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║",
        " ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝"};

    for (int i = 0; i < 6; i++)
    {
        printf("%s\n", calculator_image[i]);
    }
}
int main()
{
    setlocale(LC_ALL, "utf-8");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int continuar = 0;
    do
    {
        system("cls");
        menucalculadora();
        printf("1-Soma\n");
        printf("2-Subtração\n");
        printf("3-Multiplicação\n");
        printf("4-Divisão\n");
        printf("5-Exponenciação\n");
        printf("6-Raiz Quadrada\n");
        printf("7-Soma de n Valores\n");
        printf("8-Cálculo da Sequencia de Fibonacci\n");
        printf("9- Área do circulo\n");
        printf("10- Área do retângulo\n");
        printf("11- Volume do Cubo\n");
        printf("12- Volume do Cilindro\n");
        printf("0-Sair\n");
        printf(VERMELHO "Escolha uma opção:\n" RESET);
        int operacao;
        scanf("%d", &operacao);
        switch (operacao)
        {
        case 0:
            return 1;
        case 1:
            Soma();
            break;
        case 2:
            Subtracao();
            break;
        case 3:
            Multiplicacao();
            break;
        default:
            invalid_option();
        }
        printf("para voltar ao menu precione 1:");
        scanf("%d", &continuar);
        system("cls");
    } while (continuar == 1);

    printf("\nPressione qualquer tecla para sair...");
    getch();

    return 0;
}
