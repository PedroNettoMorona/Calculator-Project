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

#define PI 3.1415

// CORES ANSI
#define PRETO "\x1b[30m"
#define VERMELHO "\x1b[31m"
#define VERDE "\x1b[32m"
#define AMARELOFORTE "\x1b[33m"
#define AZUL "\x1b[34m"
#define AZUL_ESCURO "\x1b[38;5;17m"
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

int LinhaInicial = 0;
int LinhaFinal = 40;

int ColunaInicial = 0;
int ColunaFinal = 155;

void gotoXY(int x, int y)
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

void Moldura(char *cor, char *sEsquerdoM, char *sDireitoM, char *iEsquerdoM, char *iDireitoM, char *horizontalM, char *verticalM, int lInicialM, int lFinalM, int cInicialM, int cFinalM)
{
    int c, l;
    printf("%s", cor);
    for (l = lInicialM; l <= lFinalM; l++)
        for (c = cInicialM; c <= cFinalM; c++)
        {
            gotoXY(c, l);
            if (l == lInicialM && c == cInicialM)
                printf("%s", sEsquerdoM);
            else if (l == lInicialM && c == cFinalM)
                printf("%s", sDireitoM);
            else if (l == lFinalM && c == cInicialM)
                printf("%s", iEsquerdoM);
            else if (l == lFinalM && c == cFinalM)
                printf("%s", iDireitoM);
            else if (l == lInicialM || l == lFinalM)
                printf("%s", horizontalM);
            else if (c == cInicialM || c == cFinalM)
                printf("%s", verticalM);
        }
    printf(RESET);
}

void print_molduras()
{
    Moldura(AZUL_ESCURO, "\u2554", "\u2557", "\u255A", "\u255D", "\u2550", "\u2551", LinhaInicial, LinhaFinal, ColunaInicial, ColunaFinal);

    Moldura(AZUL_ESCURO, "\u250C", "\u2510", "\u2514", "\u2518", "\u2500", "\u2502", LinhaInicial + 7, LinhaFinal - 1, ColunaInicial + 1, ColunaFinal - 88);

    Moldura(AZUL_ESCURO, "\u250C", "\u2510", "\u2514", "\u2518", "\u2500", "\u2502", LinhaInicial + 7, LinhaFinal - 7, ColunaInicial + 68, ColunaFinal - 1);
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

    int counter = 8;
    while (fgets(line, sizeof(line), archive) != NULL)
    {
        gotoXY(ColunaInicial + 69, LinhaInicial + counter);
        printf("%s", line);
        counter++;
    }

    gotoXY(70, LinhaFinal - 1);
    getch();

    fclose(archive);
}

// Menu images

void menucalculadora()
{
    CLS;

    Moldura(AZUL_ESCURO, "\u2554", "\u2557", "\u255A", "\u255D", "\u2550", "\u2551", LinhaInicial, LinhaFinal, ColunaInicial, ColunaFinal);

    char *calculator_image[6] = {
        " ██████╗ █████╗ ██╗      ██████╗██╗   ██╗██╗      █████╗ ████████╗ ██████╗ ██████╗ ",
        "██╔════╝██╔══██╗██║     ██╔════╝██║   ██║██║     ██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗",
        "██║     ███████║██║     ██║     ██║   ██║██║     ███████║   ██║   ██║   ██║██████╔╝",
        "██║     ██╔══██║██║     ██║     ██║   ██║██║     ██╔══██║   ██║   ██║   ██║██╔══██╗",
        "╚██████╗██║  ██║███████╗╚██████╗╚██████╔╝███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║",
        " ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝"};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(35, i + 1);
        printf(AZUL_ESCURO "%s" RESET, calculator_image[i]);
    }

    gotoXY(35, 10);
    printf(" 1 - Soma\n");
    gotoXY(35, 11);
    printf(" 2 - Subtração\n");
    gotoXY(35, 12);
    printf(" 3 - Multiplicação\n");
    gotoXY(35, 13);
    printf(" 4 - Divisão\n");
    gotoXY(35, 14);
    printf(" 5 - Exponenciação\n");
    gotoXY(35, 15);
    printf(" 6 - Raiz Quadrada\n");
    gotoXY(35, 16);
    printf(" 7 - Soma de n Valores\n");
    gotoXY(35, 17);
    printf(" 8 - Cálculo da Sequencia de Fibonacci\n");
    gotoXY(35, 18);
    printf(" 9 - Área do circulo\n");
    gotoXY(85, 10);
    printf("10 - Área do retângulo\n");
    gotoXY(85, 11);
    printf("11 - Volume do Cubo\n");
    gotoXY(85, 12);
    printf("12 - Volume do Cilindro\n");
    gotoXY(85, 13);
    printf("14 - Mostrar histórico geral\n");
    gotoXY(70, 24);
    printf(VERMELHO " 0 - Sair\n" RESET);
    gotoXY(65, 26);
    printf(VERDE "Escolha uma opção:\n" RESET);
}

void clear_choose_option()
{
    for (int i = LinhaFinal - 6; i < LinhaFinal; i++)
    {
        gotoXY(70, i);
        printf("                                                                                     "); // 75 espaços (nao mudar)
    }
}

void back_menu()
{
    clear_choose_option();

    char *back_menu_image[6] = {
        "███╗   ███╗███████╗███╗   ██╗██╗   ██╗        ██╗ ██╗██╗ ",
        "████╗ ████║██╔════╝████╗  ██║██║   ██║██╗    ██╔╝███║╚██╗",
        "██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║╚═╝    ██║ ╚██║ ██║",
        "██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║██╗    ██║  ██║ ██║",
        "██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝╚═╝    ╚██╗ ██║██╔╝",
        "╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝         ╚═╝ ╚═╝╚═╝ "};

    for (int i = 0, cont = 6; i < 6; i++, cont--)
    {
        gotoXY(70, LinhaFinal - cont);
        printf("%s", back_menu_image[i]);
    }
}

void history_choose()
{
    clear_choose_option();

    char *show_history_image[6] = {
        "██╗  ██╗██╗███████╗████████╗ ██████╗ ██████╗ ██╗ ██████╗ ██████╗     ██╗██████╗ ██╗ ",
        "██║  ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗██║██╔════╝██╔═══██╗   ██╔╝╚════██╗╚██╗",
        "███████║██║███████╗   ██║   ██║   ██║██████╔╝██║██║     ██║   ██║   ██║  █████╔╝ ██║",
        "██╔══██║██║╚════██║   ██║   ██║   ██║██╔══██╗██║██║     ██║   ██║   ██║ ██╔═══╝  ██║",
        "██║  ██║██║███████║   ██║   ╚██████╔╝██║  ██║██║╚██████╗╚██████╔╝   ╚██╗███████╗██╔╝",
        "╚═╝  ╚═╝╚═╝╚══════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═════╝     ╚═╝╚══════╝╚═╝ "};

    for (int i = 0, cont = 6; i < 6; i++, cont--)
    {
        gotoXY(70, LinhaFinal - cont);
        printf("%s", show_history_image[i]);
    }
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

    print_molduras();

    char *sum_image[6] = {
        "███████╗ ██████╗ ███╗   ███╗ █████╗ ",
        "██╔════╝██╔═══██╗████╗ ████║██╔══██╗",
        "███████╗██║   ██║██╔████╔██║███████║",
        "╚════██║██║   ██║██║╚██╔╝██║██╔══██║",
        "███████║╚██████╔╝██║ ╚═╝ ██║██║  ██║",
        "╚══════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝"};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(60, i + 1);
        printf(AZUL_ESCURO "%s" RESET, sum_image[i]);
    }

    int quantidade = 0;
    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    int text_line = 8;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
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

        text_line++;
        gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
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

    text_line++;
    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf(VERDE "A soma é: %.2f" RESET, *soma);

    snprintf(temporary, sizeof(temporary), "%.2f", *soma);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    char geral_text[512] = "Soma: ";

    strcat(geral_text, calculo_str);

    write_history("../History/historico_soma.txt", calculo_str);
    write_history("../History/historico_geral.txt", geral_text);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        clear_choose_option();
        show_history("../History/historico_soma.txt");
    }

    free(soma);
    free(valores);
}
void Subtracao()
{
    CLS;

    print_molduras();

    char *subtraction_image[6] = {
        "███████╗██╗   ██╗██████╗ ████████╗██████╗  █████╗  ██████╗ █████╗  ██████╗ ",
        "██╔════╝██║   ██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔═══██╗",
        "███████╗██║   ██║██████╔╝   ██║   ██████╔╝███████║██║     ███████║██║   ██║",
        "╚════██║██║   ██║██╔══██╗   ██║   ██╔══██╗██╔══██║██║     ██╔══██║██║   ██║",
        "███████║╚██████╔╝██████╔╝   ██║   ██║  ██║██║  ██║╚██████╗██║  ██║╚██████╔╝",
        "╚══════╝ ╚═════╝ ╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(40, i + 1);
        printf(AZUL_ESCURO "%s" RESET, subtraction_image[i]);
    }

    int quantidade = 0;
    float subtracao = 0, numero = 0;

    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    int text_line = 8;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Quantos valores deseja subtrair: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        printf("Quantidade inválida.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++)
    {
        text_line++;
        gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
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

    text_line++;
    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf(VERDE "A subtração é: %.2f" RESET, subtracao);

    snprintf(temporary, sizeof(temporary), "%.2f", subtracao);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    char geral_text[512] = "Subtração: ";

    strcat(geral_text, calculo_str);

    write_history("../History/historico_subtracao.txt", calculo_str);
    write_history("../History/historico_geral.txt", geral_text);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        clear_choose_option();
        show_history("../History/historico_subtracao.txt");
    }
}

void Multiplicacao()
{
    CLS;

    print_molduras();

    char *multiplication_image[6] = {
        "███╗   ███╗██╗   ██╗██╗  ████████╗██╗██████╗ ██╗     ██╗ ██████╗ █████╗  ██████╗ █████╗  ██████╗ ",
        "████╗ ████║██║   ██║██║  ╚══██╔══╝██║██╔══██╗██║     ██║██╔════╝██╔══██╗██╔════╝██╔══██╗██╔═══██╗",
        "██╔████╔██║██║   ██║██║     ██║   ██║██████╔╝██║     ██║██║     ███████║██║     ███████║██║   ██║",
        "██║╚██╔╝██║██║   ██║██║     ██║   ██║██╔═══╝ ██║     ██║██║     ██╔══██║██║     ██╔══██║██║   ██║",
        "██║ ╚═╝ ██║╚██████╔╝███████╗██║   ██║██║     ███████╗██║╚██████╗██║  ██║╚██████╗██║  ██║╚██████╔╝",
        "╚═╝     ╚═╝ ╚═════╝ ╚══════╝╚═╝   ╚═╝╚═╝     ╚══════╝╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(35, i + 1);
        printf(AZUL_ESCURO "%s" RESET, multiplication_image[i]);
    }

    int quantidade = 0;
    float multiplicacao = 1, numero = 0;

    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    int text_line = 8;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Quantos valores deseja multiplicar: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
    {
        gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
        printf("Quantidade inválida.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++)
    {
        text_line++;
        gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
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

    text_line++;
    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf(VERDE "A multiplicação é: %.2f" RESET, multiplicacao);

    snprintf(temporary, sizeof(temporary), "%.2f", multiplicacao);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    char geral_text[512] = "Multiplicação: ";

    strcat(geral_text, calculo_str);

    write_history("../History/historico_multiplicacao.txt", calculo_str);
    write_history("../History/historico_geral.txt", geral_text);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        clear_choose_option();
        show_history("../History/historico_multiplicacao.txt");
    }
}

void Divisao()
{
    CLS;

    print_molduras();

    char *division_image[6] = {
        "██████╗ ██╗██╗   ██╗██╗███████╗ █████╗  ██████╗ ",
        "██╔══██╗██║██║   ██║██║██╔════╝██╔══██╗██╔═══██╗",
        "██║  ██║██║██║   ██║██║███████╗███████║██║   ██║",
        "██║  ██║██║╚██╗ ██╔╝██║╚════██║██╔══██║██║   ██║",
        "██████╔╝██║ ╚████╔╝ ██║███████║██║  ██║╚██████╔╝",
        "╚═════╝ ╚═╝  ╚═══╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(50, i + 1);
        printf(AZUL_ESCURO "%s" RESET, division_image[i]);
    }

    int quantidade = 0;

    int text_line = 8;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
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
        text_line++;
        gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
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

    text_line++;
    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf(VERDE "A divisão é: %.2f\n" RESET, divisao);

    snprintf(temporary, sizeof(temporary), "%.2f", divisao);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    char geral_text[512] = "Divisão: ";

    strcat(geral_text, calculo_str);

    write_history("../History/historico_divisao.txt", calculo_str);
    write_history("../History/historico_geral.txt", geral_text);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        clear_choose_option();
        show_history("../History/historico_divisao.txt");
    }
}

void Exponenciacao()
{
    CLS;

    print_molduras();

    char *exponentiation_image[6] = {
        "███████╗██╗  ██╗██████╗  ██████╗ ███╗   ██╗███████╗███╗   ██╗ ██████╗██╗ █████╗  ██████╗ █████╗  ██████╗ ",
        "██╔════╝╚██╗██╔╝██╔══██╗██╔═══██╗████╗  ██║██╔════╝████╗  ██║██╔════╝██║██╔══██╗██╔════╝██╔══██╗██╔═══██╗",
        "█████╗   ╚███╔╝ ██████╔╝██║   ██║██╔██╗ ██║█████╗  ██╔██╗ ██║██║     ██║███████║██║     ███████║██║   ██║",
        "██╔══╝   ██╔██╗ ██╔═══╝ ██║   ██║██║╚██╗██║██╔══╝  ██║╚██╗██║██║     ██║██╔══██║██║     ██╔══██║██║   ██║",
        "███████╗██╔╝ ██╗██║     ╚██████╔╝██║ ╚████║███████╗██║ ╚████║╚██████╗██║██║  ██║╚██████╗██║  ██║╚██████╔╝",
        "╚══════╝╚═╝  ╚═╝╚═╝      ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═══╝ ╚═════╝╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(30, i + 1);
        printf(AZUL_ESCURO "%s" RESET, exponentiation_image[i]);
    }

    int expoente;
    float base;
    float resultado;

    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    int text_line = 8;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Informe a base da exponenciação: ");
    scanf("%f", &base);

    text_line++;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Informe o expoente: ");
    scanf("%d", &expoente);

    resultado = base;
    for (int i = 1; i < expoente; i++)
    {
        resultado = resultado * base;
    }

    snprintf(temporary, sizeof(temporary), "%.2f ^ %d", base, expoente);

    strcat(calculo_str, temporary);

    text_line++;
    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf(VERDE "O resultado é: %.2f" RESET, resultado);

    snprintf(temporary, sizeof(temporary), "%.2f", resultado);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    char geral_text[512] = "Exponenciação: ";

    strcat(geral_text, calculo_str);

    write_history("../History/historico_exponenciacao.txt", calculo_str);
    write_history("../History/historico_geral.txt", geral_text);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        clear_choose_option();
        show_history("../History/historico_exponenciacao.txt");
    }
}

void Radiciacao()
{
    CLS;

    print_molduras();

    char *square_root_image[6] = {
        "██████╗  █████╗ ██╗███████╗     ██████╗ ██╗   ██╗ █████╗ ██████╗ ██████╗  █████╗ ██████╗  █████╗ ",
        "██╔══██╗██╔══██╗██║╚══███╔╝    ██╔═══██╗██║   ██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗",
        "██████╔╝███████║██║  ███╔╝     ██║   ██║██║   ██║███████║██║  ██║██████╔╝███████║██║  ██║███████║",
        "██╔══██╗██╔══██║██║ ███╔╝      ██║▄▄ ██║██║   ██║██╔══██║██║  ██║██╔══██╗██╔══██║██║  ██║██╔══██║",
        "██║  ██║██║  ██║██║███████╗    ╚██████╔╝╚██████╔╝██║  ██║██████╔╝██║  ██║██║  ██║██████╔╝██║  ██║",
        "╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚══════╝     ╚══▀▀═╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝"};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(30, i + 1);
        printf(AZUL_ESCURO "%s" RESET, square_root_image[i]);
    }

    float radicando;
    float resultado;

    char calculo_str[1024] = "";
    char *igualdade_str = " = ";
    char temporary[50];

    int text_line = 8;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Informe o radicando: ");
    scanf("%f", &radicando);

    resultado = sqrt(radicando);

    snprintf(temporary, sizeof(temporary), "sqrt(%.2f)", radicando);
    strcat(calculo_str, temporary);

    text_line++;
    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf(VERDE "O resultado é: %.2f" RESET, resultado);

    snprintf(temporary, sizeof(temporary), "%.2f", resultado);

    strcat(calculo_str, igualdade_str);
    strcat(calculo_str, temporary);

    char geral_text[512] = "Radiciação: ";

    strcat(geral_text, calculo_str);

    write_history("../History/historico_radiciacao.txt", calculo_str);
    write_history("../History/historico_geral.txt", geral_text);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        clear_choose_option();
        show_history("../History/historico_radiciacao.txt");
    }
}

typedef struct Fibonacci
{
    int atual;
    struct Fibonacci *anterior;
    struct Fibonacci *proximo;
} Fibonacci;

Fibonacci *criarSequenciaFibonacci(int valor, Fibonacci *anterior)
{
    Fibonacci *novo = malloc(sizeof(Fibonacci));
    if (novo == NULL)
        return NULL;

    novo->atual = valor;
    novo->anterior = anterior;
    novo->proximo = NULL;

    return novo;
}

void exibirSequenciaFibonacci(Fibonacci *inicio)
{
    Fibonacci *atual = inicio;

    while (atual != NULL)
    {
        printf("%d ", atual->atual);
        atual = atual->proximo;
    }
}

char *stringSequenciaFibonacci(Fibonacci *inicio)
{
    Fibonacci *atual = inicio;

    char *calculo_str = calloc(4096, sizeof(char));

    while (atual != NULL)
    {
        char valor_sequencia[50];

        snprintf(valor_sequencia, sizeof(valor_sequencia), "%d ", atual->atual);

        strcat(calculo_str, valor_sequencia);

        atual = atual->proximo;
    }

    return calculo_str;
}

void SequenciaFibonacci()
{
    CLS;

    print_molduras();

    char *fibonacci_image[6] = {
        "███████╗██╗██████╗  ██████╗ ███╗   ██╗ █████╗  ██████╗ ██████╗██╗",
        "██╔════╝██║██╔══██╗██╔═══██╗████╗  ██║██╔══██╗██╔════╝██╔════╝██║",
        "█████╗  ██║██████╔╝██║   ██║██╔██╗ ██║███████║██║     ██║     ██║",
        "██╔══╝  ██║██╔══██╗██║   ██║██║╚██╗██║██╔══██║██║     ██║     ██║",
        "██║     ██║██████╔╝╚██████╔╝██║ ╚████║██║  ██║╚██████╗╚██████╗██║",
        "╚═╝     ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚═════╝╚═╝"};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(45, i + 1);
        printf(AZUL_ESCURO "%s" RESET, fibonacci_image[i]);
    }

    int quantidade;

    int text_line = 8;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Informe quantos números da sequência de fibonacci deseja ver: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0)
        return;

    Fibonacci *primeiro = criarSequenciaFibonacci(1, NULL);

    if (quantidade == 1)
    {
        exibirSequenciaFibonacci(primeiro);
        write_history("../History/historico_fibonacci.txt", "1");
        write_history("../History/historico_geral.txt", "Fibonacci: 1");

        history_choose();

        char choose = getch();
        if (choose == '2')
        {
            show_history("../History/historico_fibonacci.txt");
        }

        return;
    }

    Fibonacci *segundo = criarSequenciaFibonacci(1, primeiro);

    primeiro->proximo = segundo;

    Fibonacci *ultimo_valor = segundo;

    for (int i = 2; i < quantidade; i++)
    {
        Fibonacci *proximo = criarSequenciaFibonacci(0, ultimo_valor);

        proximo->anterior->proximo = proximo;

        proximo->atual = proximo->anterior->atual + proximo->anterior->anterior->atual;

        ultimo_valor = proximo;
    }

    text_line++;
    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf(VERDE);
    exibirSequenciaFibonacci(primeiro);
    printf(RESET);

    char geral_text[512] = "Fibonacci: ";
    char *text = stringSequenciaFibonacci(primeiro);

    strcat(geral_text, text);

    write_history("../History/historico_fibonacci.txt", text);
    write_history("../History/historico_geral.txt", geral_text);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        clear_choose_option();
        show_history("../History/historico_fibonacci.txt");
    }

    free(text);
}

void AreaCirculo()
{
    CLS;

    print_molduras();

    char *area_circulo_image[6] = {
        " █████╗ ██████╗ ███████╗ █████╗     ██████╗  ██████╗      ██████╗██╗██████╗  ██████╗██╗   ██╗██╗      ██████╗ ",
        "██╔══██╗██╔══██╗██╔════╝██╔══██╗    ██╔══██╗██╔═══██╗    ██╔════╝██║██╔══██╗██╔════╝██║   ██║██║     ██╔═══██╗",
        "███████║██████╔╝█████╗  ███████║    ██║  ██║██║   ██║    ██║     ██║██████╔╝██║     ██║   ██║██║     ██║   ██║",
        "██╔══██║██╔══██╗██╔══╝  ██╔══██║    ██║  ██║██║   ██║    ██║     ██║██╔══██╗██║     ██║   ██║██║     ██║   ██║",
        "██║  ██║██║  ██║███████╗██║  ██║    ██████╔╝╚██████╔╝    ╚██████╗██║██║  ██║╚██████╗╚██████╔╝███████╗╚██████╔╝",
        "╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝    ╚═════╝  ╚═════╝      ╚═════╝╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝ ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(25, i + 1);
        printf(AZUL_ESCURO "%s" RESET, area_circulo_image[i]);
    }

    float raio, area_circulo;

    int text_line = 8;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Informe o raio do circulo: ");
    scanf("%f", &raio);

    area_circulo = PI * (raio * raio);

    text_line++;
    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf(VERDE "O resultado é: %.2f" RESET, area_circulo);

    char calculo_str[1024] = "Raio: ";
    char *igualdade_str = " = ";
    char temporary[50];

    snprintf(temporary, sizeof(temporary), "%.2f", raio);
    strcat(calculo_str, temporary);

    strcat(calculo_str, igualdade_str);

    snprintf(temporary, sizeof(temporary), "%.2f", area_circulo);
    strcat(calculo_str, temporary);

    char geral_text[512] = "Área do Círculo: ";

    strcat(geral_text, calculo_str);

    write_history("../History/historico_area_do_circulo.txt", calculo_str);
    write_history("../History/historico_geral.txt", geral_text);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        clear_choose_option();
        show_history("../History/historico_area_do_circulo.txt");
    }
}

void AreaRetangulo()
{
    CLS;

    print_molduras();

    char *area_retangulo_image[6] = {
        " █████╗ ██████╗ ███████╗ █████╗     ██████╗  ██████╗     ██████╗ ███████╗████████╗ █████╗ ███╗   ██╗ ██████╗ ██╗   ██╗██╗      ██████╗ ",
        "██╔══██╗██╔══██╗██╔════╝██╔══██╗    ██╔══██╗██╔═══██╗    ██╔══██╗██╔════╝╚══██╔══╝██╔══██╗████╗  ██║██╔════╝ ██║   ██║██║     ██╔═══██╗",
        "███████║██████╔╝█████╗  ███████║    ██║  ██║██║   ██║    ██████╔╝█████╗     ██║   ███████║██╔██╗ ██║██║  ███╗██║   ██║██║     ██║   ██║",
        "██╔══██║██╔══██╗██╔══╝  ██╔══██║    ██║  ██║██║   ██║    ██╔══██╗██╔══╝     ██║   ██╔══██║██║╚██╗██║██║   ██║██║   ██║██║     ██║   ██║",
        "██║  ██║██║  ██║███████╗██║  ██║    ██████╔╝╚██████╔╝    ██║  ██║███████╗   ██║   ██║  ██║██║ ╚████║╚██████╔╝╚██████╔╝███████╗╚██████╔╝",
        "╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝    ╚═════╝  ╚═════╝     ╚═╝  ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝  ╚═════╝ ╚══════╝ ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(10, i + 1);
        printf(AZUL_ESCURO "%s" RESET, area_retangulo_image[i]);
    }

    float base, altura, area_retangulo;

    int text_line = 8;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Informe a base: ");
    scanf("%f", &base);

    text_line++;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Informe a altura: ");
    scanf("%f", &altura);

    area_retangulo = base * altura;

    text_line++;
    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf(VERDE "O resultado é: %.2f" RESET, area_retangulo);

    char calculo_str[1024] = "";
    char *multiplicador = " * ";
    char *igualdade = " = ";
    char temporary[50];

    snprintf(temporary, sizeof(temporary), "%.2f", base);
    strcat(calculo_str, temporary);

    strcat(calculo_str, multiplicador);

    snprintf(temporary, sizeof(temporary), "%.2f", altura);
    strcat(calculo_str, temporary);

    strcat(calculo_str, igualdade);

    snprintf(temporary, sizeof(temporary), "%.2f", area_retangulo);
    strcat(calculo_str, temporary);

    char geral_text[512] = "Área do Retângulo: ";

    strcat(geral_text, calculo_str);

    write_history("../History/historico_area_do_retangulo.txt", calculo_str);
    write_history("../History/historico_geral.txt", geral_text);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        clear_choose_option();
        show_history("../History/historico_area_do_retangulo.txt");
    }
}

void VolumeCubo()
{
    CLS;

    print_molduras();

    char *volume_cubo_image[6] = {
        "██╗   ██╗ ██████╗ ██╗     ██╗   ██╗███╗   ███╗███████╗    ██████╗  ██████╗      ██████╗██╗   ██╗██████╗  ██████╗ ",
        "██║   ██║██╔═══██╗██║     ██║   ██║████╗ ████║██╔════╝    ██╔══██╗██╔═══██╗    ██╔════╝██║   ██║██╔══██╗██╔═══██╗",
        "██║   ██║██║   ██║██║     ██║   ██║██╔████╔██║█████╗      ██║  ██║██║   ██║    ██║     ██║   ██║██████╔╝██║   ██║",
        "╚██╗ ██╔╝██║   ██║██║     ██║   ██║██║╚██╔╝██║██╔══╝      ██║  ██║██║   ██║    ██║     ██║   ██║██╔══██╗██║   ██║",
        " ╚████╔╝ ╚██████╔╝███████╗╚██████╔╝██║ ╚═╝ ██║███████╗    ██████╔╝╚██████╔╝    ╚██████╗╚██████╔╝██████╔╝╚██████╔╝",
        "  ╚═══╝   ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝    ╚═════╝  ╚═════╝      ╚═════╝ ╚═════╝ ╚═════╝  ╚═════╝ "};

    for (int i = 0; i < 6; i++)
    {
        gotoXY(25, i + 1);
        printf(AZUL_ESCURO "%s" RESET, volume_cubo_image[i]);
    }

    float altura, largura, comprimento, volume_cubo;

    int text_line = 8;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Informe a altura: ");
    scanf("%f", &altura);
    text_line++;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Informe a largura: ");
    scanf("%f", &largura);
    text_line++;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf("Informe o comprimento: ");
    scanf("%f", &comprimento);
    text_line++;

    volume_cubo = altura * largura * comprimento;

    gotoXY(ColunaInicial + 2, LinhaInicial + text_line);
    printf(VERDE "O resultado é: %.2f" RESET, volume_cubo);

    char calculo_str[1024] = "";
    char *multiplicador = " * ";
    char *igualdade = " = ";
    char temporary[50];

    snprintf(temporary, sizeof(temporary), "%.2f", altura);
    strcat(calculo_str, temporary);

    strcat(calculo_str, multiplicador);

    snprintf(temporary, sizeof(temporary), "%.2f", largura);
    strcat(calculo_str, temporary);

    strcat(calculo_str, multiplicador);

    snprintf(temporary, sizeof(temporary), "%.2f", comprimento);
    strcat(calculo_str, temporary);

    strcat(calculo_str, igualdade);

    snprintf(temporary, sizeof(temporary), "%.2f", volume_cubo);
    strcat(calculo_str, temporary);

    char geral_text[512] = "Área do Retângulo: ";

    strcat(geral_text, calculo_str);

    write_history("../History/historico_volume_cubo.txt", calculo_str);
    write_history("../History/historico_geral.txt", geral_text);

    history_choose();

    char choose = getch();
    if (choose == '2')
    {
        clear_choose_option();
        show_history("../History/historico_volume_cubo.txt");
    }
}

// User Interface manipulation

void choose_option()
{
    int operacao;
    gotoXY(85, 26);
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
    case 8:
        SequenciaFibonacci();
        break;
    case 9:
        AreaCirculo();
        break;
    case 10:
        AreaRetangulo();
        break;
    case 11:
        VolumeCubo();
        break;
    case 14:
        CLS;
        show_history("../History/historico_geral.txt");
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
