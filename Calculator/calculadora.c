#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

#define CLS system("cls")

// CORES ANSI
#define PRETO "\x1b[30m"
#define VERMELHO "\x1b[31m"
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

bool _continue = true;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Archive manager functions

void verify_archive_open(FILE *archive)
{
    if (archive == NULL)
    {
        printf(VERMELHO "Erro ao abrir o arquivo." RESET);
        return;
    }
}

void write_history(char *address, char *text)
{
    FILE *archive = fopen(address, "a");

    verify_archive_open(archive);

    fputs(text, archive);
    fputs("\n", archive);

    fclose(archive);
}

void show_history(char *address)
{
    FILE *archive = fopen(address, "r");

    if (archive == NULL)
    {
        printf(VERMELHO "Erro ao abrir o arquivo." RESET);
        return;
    }

    char line[1024];

    while (fgets(line, sizeof(line), archive) != NULL)
    {
        printf("%s", line);
    }

    getch();

    fclose(archive);
}

// Menu images

void menucalculadora()
{

    CLS;

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
}

void back_menu()
{
    char *back_menu_image[6] = {
        "███╗   ███╗███████╗███╗   ██╗██╗   ██╗        ██╗ ██╗██╗ ",
        "████╗ ████║██╔════╝████╗  ██║██║   ██║██╗    ██╔╝███║╚██╗",
        "██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║╚═╝    ██║ ╚██║ ██║",
        "██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║██╗    ██║  ██║ ██║",
        "██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝╚═╝    ╚██╗ ██║██╔╝",
        "╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝         ╚═╝ ╚═╝╚═╝ "};

    for (int i = 0; i < 3; i++)
    {
        printf("\n");
    }

    for (int i = 0; i < 6; i++)
    {
        printf("\n%s", back_menu_image[i]);
    }
}

void history_choose()
{
    char *show_history_image[6] = {
        "███╗   ███╗ ██████╗ ███████╗████████╗██████╗  █████╗ ██████╗     ██╗  ██╗██╗███████╗████████╗ ██████╗ ██████╗ ██╗ ██████╗ ██████╗     ██╗██████╗ ██╗ ",
        "████╗ ████║██╔═══██╗██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗    ██║  ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗██║██╔════╝██╔═══██╗   ██╔╝╚════██╗╚██╗",
        "██╔████╔██║██║   ██║███████╗   ██║   ██████╔╝███████║██████╔╝    ███████║██║███████╗   ██║   ██║   ██║██████╔╝██║██║     ██║   ██║   ██║  █████╔╝ ██║",
        "██║╚██╔╝██║██║   ██║╚════██║   ██║   ██╔══██╗██╔══██║██╔══██╗    ██╔══██║██║╚════██║   ██║   ██║   ██║██╔══██╗██║██║     ██║   ██║   ██║ ██╔═══╝  ██║",
        "██║ ╚═╝ ██║╚██████╔╝███████║   ██║   ██║  ██║██║  ██║██║  ██║    ██║  ██║██║███████║   ██║   ╚██████╔╝██║  ██║██║╚██████╗╚██████╔╝   ╚██╗███████╗██╔╝",
        "╚═╝     ╚═╝ ╚═════╝ ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝    ╚═╝  ╚═╝╚═╝╚══════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═════╝     ╚═╝╚══════╝╚═╝ "};

    for (int i = 0; i < 3; i++)
    {
        printf("\n");
    }

    for (int i = 0; i < 6; i++)
    {
        printf("\n%s", show_history_image[i]);
    }

    printf("\n");
}

void invalid_option()
{
    CLS;

    char *invalid_option_image[24] = {
        VERMELHO "         ███             ███             ███             ███             ███             ███             ███       ",
        "       ███░            ███░            ███░            ███░            ███░            ███░            ███░        ",
        "     ███░            ███░            ███░            ███░            ███░            ███░            ███░          ",
        "   ███░            ███░            ███░            ███░            ███░            ███░            ███░            ",
        " ███░            ███░            ███░            ███░            ███░            ███░            ███░            ██",
        "██░            ███░            ███░            ███░            ███░            ███░            ███░            ███░",
        "░            ███░            ███░            ███░            ███░            ███░            ███░            ███░  ",
        "            ░░░             ░░░             ░░░             ░░░             ░░░             ░░░             ░░░    " RESET,
        VERMELHO "     ██" RESET "██████╗ ██████╗" VERMELHO "██" RESET "██████╗ █████╗" VERMELHO "██" RESET "██████╗     ██╗███╗   ██╗██╗ " VERMELHO "██" RESET "██╗ █████╗ ██╗" VERMELHO "███" RESET "  ██╗██████╗ " VERMELHO "█" RESET "█████╗       ",
        VERMELHO "   ███" RESET "██╔═══██╗██╔══██╗██╔════╝██╔══██╗██╔═══██╗   " VERMELHO "█" RESET "██║████╗  ██║██║" VERMELHO "██░" RESET "██║██╔══██╗██║" VERMELHO "█░" RESET "   ██║██╔══██╗██╔══██╗      ",
        VERMELHO " ███░ " RESET "██║   ██║██████╔╝██║     ███████║██║   ██║ " VERMELHO "███" RESET "██║██╔██╗ ██║██║" VERMELHO "░" RESET "  ██║███████║██║     ██║██║  ██║███████║" VERMELHO "    ██",
        VERMELHO "██░   " RESET "██║   ██║██╔═══╝ ██║     ██╔══██║██║   ██║" VERMELHO "██░" RESET " ██║██║╚██╗██║╚██╗ ██╔╝██╔══██║██║     ██║██║  ██║██╔══██║" VERMELHO "  ███░",
        VERMELHO "░     " RESET "╚██████╔╝██║     ╚██████╗██║  ██║╚██████╔╝" VERMELHO "░" RESET "   ██║██║ ╚████║ ╚████╔╝ ██║" VERMELHO "██" RESET "██║███████╗██║██████╔╝██║  ██║" VERMELHO "███░  ",
        VERMELHO "      " RESET " ╚═════╝" VERMELHO "░" RESET "╚═╝      ╚═════╝╚═╝  ╚═╝ ╚═════╝     ╚═╝╚═╝ " VERMELHO "█" RESET "╚═══╝  ╚═══╝  ╚═╝" VERMELHO "█░" RESET "╚═╝╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝" VERMELHO "█░    ",
        VERMELHO "         ███░            ███░            ███░            ███░            ███░            ███░            ███░      ",
        "        ░░░             ░░░             ░░░             ░░░             ░░░             ░░░             ░░░        ",
        " ███             ███             ███             ███             ███             ███             ███             ██",
        "██░            ███░            ███░            ███░            ███░            ███░            ███░            ███░",
        "░            ███░            ███░            ███░            ███░            ███░            ███░            ███░  ",
        "           ███░            ███░            ███░            ███░            ███░            ███░            ███░    ",
        "         ███░            ███░            ███░            ███░            ███░            ███░            ███░      ",
        "       ███░            ███░            ███░            ███░            ███░            ███░            ███░        ",
        "     ███░            ███░            ███░            ███░            ███░            ███░            ███░          " RESET};

    for (int i = 0; i < 24; i++)
    {
        printf("%s\n", invalid_option_image[i]);
    }
}

// Operation functions
void Soma()
{
    CLS;

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
    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    printf("Quantos valores deseja somar: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        printf("Quantidade inválida.\n");
        return;
    }
    float *soma = calloc(1, sizeof(float)); // calloc
    float *valores = malloc(sizeof(float)); // malloc
    if (soma == NULL || valores == NULL)
    {
        printf("Sem memória.\n");
        free(soma);
        free(valores);
        return;
    }
    for (int i = 0; i < quantidade; i++)
    {
        if (i > 0)
        {
            // realloc
            float *tmp = realloc(valores, (i + 1) * sizeof(float));
            if (tmp == NULL)
            {
                printf("Sem memória.\n");
                free(soma);
                free(valores);
                return;
            }
            valores = tmp;
        }
        printf("Informe o valor %d: ", i + 1);
        scanf("%f", &valores[i]);
        *soma = *soma + valores[i];

        // Armazenamento de histórico
        if (i == quantidade - 1)
        {
            snprintf(temporary, sizeof(temporary), "%.2f", valores[i]);
        }
        else
        {
            snprintf(temporary, sizeof(temporary), "%.2f + ", valores[i]);
        }
        strcat(calculo_str, temporary);
    }
    printf("A soma é: %.2f\n", *soma);

    snprintf(temporary, sizeof(temporary), "%.2f", *soma);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    write_history("../History/historico_soma.txt", calculo_str);
    free(soma);
    free(valores);
    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        show_history("../History/historico_soma.txt");
    }
}
void Subtracao()
{
    CLS;

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

    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    printf("Quantos valores deseja subtrair: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        printf("Quantidade inválida.\n");
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

        if (i == quantidade - 1)
        {
            snprintf(temporary, sizeof(temporary), "%.2f", numero);
        }
        else
        {
            snprintf(temporary, sizeof(temporary), "%.2f - ", numero);
        }
        strcat(calculo_str, temporary);
    }

    printf("A subtração é: %.2f\n", subtracao);

    snprintf(temporary, sizeof(temporary), "%.2f", subtracao);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    write_history("../History/historico_subtracao.txt", calculo_str);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        show_history("../History/historico_subtracao.txt");
    }
}

void Multiplicacao()
{
    CLS;

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

    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    printf("Quantos valores deseja multiplicar: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        printf("Quantidade inválida.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("Informe o valor %d: ", i + 1);
        scanf("%f", &numero);
        multiplicacao = multiplicacao * numero;

        if (i == quantidade - 1)
        {
            snprintf(temporary, sizeof(temporary), "%.2f", numero);
        }
        else
        {
            snprintf(temporary, sizeof(temporary), "%.2f * ", numero);
        }
        strcat(calculo_str, temporary);
    }

    printf("A multiplicação é: %.2f\n", multiplicacao);

    snprintf(temporary, sizeof(temporary), "%.2f", multiplicacao);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    write_history("../History/historico_multiplicacao.txt", calculo_str);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        show_history("../History/historico_multiplicacao.txt");
    }
}

void Divisao()
{
    CLS;

    char *division_image[6] = {
        "██████╗ ██╗██╗   ██╗██╗███████╗ █████╗  ██████╗ ",
        "██╔══██╗██║██║   ██║██║██╔════╝██╔══██╗██╔═══██╗",
        "██║  ██║██║██║   ██║██║███████╗███████║██║   ██║",
        "██║  ██║██║╚██╗ ██╔╝██║╚════██║██╔══██║██║   ██║",
        "██████╔╝██║ ╚████╔╝ ██║███████║██║  ██║╚██████╔╝",
        "╚═════╝ ╚═╝  ╚═══╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        printf("%s\n", division_image[i]);
    }

    int quantidade = 0;

    printf("Quantos valores deseja dividir: ");
    scanf("%d", &quantidade);

    float divisao, numero[quantidade];

    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    if (quantidade <= 0)
    {
        printf("Quantidade inválida.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("Informe o valor %d: ", i + 1);
        scanf("%f", &numero[i]);

        if (i == quantidade - 1)
        {
            snprintf(temporary, sizeof(temporary), "%.2f", numero[i]);
        }
        else
        {
            snprintf(temporary, sizeof(temporary), "%.2f / ", numero[i]);
        }
        strcat(calculo_str, temporary);
    }

    divisao = numero[0];
    for (int i = 1; i < quantidade; i++)
    {
        divisao = divisao / numero[i];
    }

    printf("A divisão é: %.2f\n", divisao);

    snprintf(temporary, sizeof(temporary), "%.2f", divisao);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    write_history("../History/historico_divisao.txt", calculo_str);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        show_history("../History/historico_divisao.txt");
    }
}

void Exponenciacao()
{
    CLS;

    char *exponentiation_image[6] = {
        "███████╗██╗  ██╗██████╗  ██████╗ ███╗   ██╗███████╗███╗   ██╗ ██████╗██╗ █████╗  ██████╗ █████╗  ██████╗ ",
        "██╔════╝╚██╗██╔╝██╔══██╗██╔═══██╗████╗  ██║██╔════╝████╗  ██║██╔════╝██║██╔══██╗██╔════╝██╔══██╗██╔═══██╗",
        "█████╗   ╚███╔╝ ██████╔╝██║   ██║██╔██╗ ██║█████╗  ██╔██╗ ██║██║     ██║███████║██║     ███████║██║   ██║",
        "██╔══╝   ██╔██╗ ██╔═══╝ ██║   ██║██║╚██╗██║██╔══╝  ██║╚██╗██║██║     ██║██╔══██║██║     ██╔══██║██║   ██║",
        "███████╗██╔╝ ██╗██║     ╚██████╔╝██║ ╚████║███████╗██║ ╚████║╚██████╗██║██║  ██║╚██████╗██║  ██║╚██████╔╝",
        "╚══════╝╚═╝  ╚═╝╚═╝      ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═══╝ ╚═════╝╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        printf("%s\n", exponentiation_image[i]);
    }

    int expoente;
    float base;
    float resultado;

    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    printf("Informe a base da exponenciação: ");
    scanf("%f", &base);

    printf("Informe o expoente: ");
    scanf("%d", &expoente);

    resultado = base;
    for (int i = 1; i < expoente; i++)
    {
        resultado = resultado * base;
    }

    snprintf(temporary, sizeof(temporary), "%.2f ^ %d", base, expoente);

    strcat(calculo_str, temporary);

    printf("O resultado é: %.2f", resultado);

    snprintf(temporary, sizeof(temporary), "%.2f", resultado);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    write_history("../History/historico_exponenciacao.txt", calculo_str);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        show_history("../History/historico_exponenciacao.txt");
    }
}
void Radiciacao()
{
    CLS;

    char *square_root_image[6] = {
        "██████╗  █████╗ ██╗███████╗     ██████╗ ██╗   ██╗ █████╗ ██████╗ ██████╗  █████╗ ██████╗  █████╗ ",
        "██╔══██╗██╔══██╗██║╚══███╔╝    ██╔═══██╗██║   ██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗",
        "██████╔╝███████║██║  ███╔╝     ██║   ██║██║   ██║███████║██║  ██║██████╔╝███████║██║  ██║███████║",
        "██╔══██╗██╔══██║██║ ███╔╝      ██║▄▄ ██║██║   ██║██╔══██║██║  ██║██╔══██╗██╔══██║██║  ██║██╔══██║",
        "██║  ██║██║  ██║██║███████╗    ╚██████╔╝╚██████╔╝██║  ██║██████╔╝██║  ██║██║  ██║██████╔╝██║  ██║",
        "╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚══════╝     ╚══▀▀═╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝"};

    for (int i = 0; i < 6; i++)
    {
        printf("%s\n", square_root_image[i]);
    }

    float radicando;
    float resultado;

    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    printf("Informe o radicando: ");
    scanf("%f", &radicando);

    resultado = sqrt(radicando);

    snprintf(temporary, sizeof(temporary), "sqrt(%.2f)", radicando);
    strcat(calculo_str, temporary);

    printf("O resultado é: %.2f", resultado);

    snprintf(temporary, sizeof(temporary), "%.2f", resultado);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    write_history("../History/historico_radiciacao.txt", calculo_str);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        show_history("../History/historico_radiciacao.txt");
    }
}

// User Interface manipulation

void choose_option()
{
    int operacao;
    scanf("%d", &operacao);
    switch (operacao)
    {
    case 0:
        _continue = false;
        break;
    case 1:
        Soma();
        break;
    case 2:
        Subtracao();
        break;
    case 3:
        Multiplicacao();
        break;
    case 4:
        Divisao();
        break;
    case 5:
        Exponenciacao();
        break;
    case 6:
        Radiciacao();
        break;
    case 7:
        Soma();
        break;
    default:
        invalid_option();
    }

    if (_continue == true)
    {
        back_menu();

        char choose = getch();
        if (choose != '1' && choose != '2')
        {
            _continue = false;
        };
    }

    CLS;
}

// Main functions

int main()
{
    setlocale(LC_ALL, "utf-8");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    while (_continue == true)
    {
        menucalculadora();
        choose_option();
    }

    return 0;
};
