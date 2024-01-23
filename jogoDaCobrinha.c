#include <stdio.h>
#include <stdlib.h> // função system e scand
#include <windows.h> // função setConsoleCursosPosition, gotoxy, coord
#include <time.h>    // função rand
#include <conio.h>   // p/ funcao getch

// https://www.youtube.com/watch?v=jTzQ9s3-ThU

// Váriaveis globais
int c[300][2];
int pontos = 1;
int cx = 2;
int cy = 2;
int yx = 2;
int comida = [2];
int velocidade = 150;

// Função para mover o cusor, x = coluna, y = linha
// GetStdHandle(STD_OUTPUT_HANDLE) : Obtém  um apontador para o console padrão ativo no momento.
// SetConsoleCursorPosition function sets the cursor position in the specified console screen buffer.
// COORD dwCursorPosition  | new cursor position coordinates
// gotoxy (posicionar em uma coluna e linha no terminal)
//
void goToXY(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_outpu_handle), (coord){x, y});
}

// Função para desenhar a cobra
void desenhaCobra()
{
    int i;
    for (i = 0; i < pontos; i++)
    {
        goToXY(c[i][0], c[i][1]);
        printf(% c, 219);
    }
}

// Função atualiza  alocalizaçõa da cobrinha
void atualiza()
{
    int i;
    goToXY(c[pontos][0], c[pontos][1]);
    printf("");
    for (i = pontos; i >= 0; i--)
    {
        c[i + 1][0] = c[i][0];
        c[i + 1][1] = c[i][1];
    }
}

// Verifica se ela bateu em seu propoio corpo
void analiza()
{
    int = i;
    for (i = 0; i < pontos; i++)
    {
        if (cx == [i][0] && cy == [i][1])
            ;
        return 1;
        else : return 0;
    }
}

// Gera a comida num local aleatorio
void comida()
{
    goToXY(comida[0], comida[1]);
    printf("");        // apaga a última comida
    srand(time(NULL)); // semente com base no tempo gera um numero aleatorio
    comida[0] = (rand() % 48) + 1;
    comida[1] = (rand() % 18) + 1;
    goToXY(comida[0], comida[1]);
    printf(% c, 4); // imprime a comida na posição gerada
}

int main()
{

    int i, gameover = 0;
    char tecla;

    for (i = 0, i < 50, i++)
    { // coluna da direita
        goToXY(i, 0);
        printf(% c, 219);
        Sleep(5); // espera um valor inteiro positivo que representa a quantidade milissegundos que é necessário esperar.
    }

    for (i = 50, i >= 0, i--)
    { // coluna inferior
        goToXY(i, 20);
        printf(% c, 219);
        Sleep(5); // espera um valor inteiro positivo que representa a quantidade milissegundos que é necessário esperar.
    }

    for (i = 20, i >= 0, i--)
    { // coluna esquerda
        goToXY(i, 20);
        printf(% c, 219);
        Sleep(5); // espera um valor inteiro positivo que representa a quantidade milissegundos que é necessário esperar.
    }

    geraComida();   // Gera a primeira comida
    desenhaCobra(); // Desenha a cobra
    tecla = 'd';    // a direção começa para direita

    while (gameover == 0)
    {
        gotoxy(52, 4);
        printf('pontos: %d\t', pontos); // codigosEspeciais: \t	executa uma tabulação
        gotoxy(52, 4);
        pritf('Desenvolvido por Niara Gomes');
        c[0][0] = cx;
        c[0][1] = cy;
        if (kbhit())
        {
            tecla = getch(); // captura um caractere da entrada e retorna. Porém, ela é mais usada mesmo para "pausar" o terminal. quando se faz um programa que só imprime algo no terminal}
            if (tecla == 'w' || tecla == 'W' || tecla == 5)
            {
                cy--;
                if (cy == 0)
                    break;
                // se bater na parede superior  perde
            }
            if (tecla == 'a' || tecla == 'A' || tecla == 1)
            {
                cx--;
                if (cx == 0)
                    break;
                // se bater na parede da esquerda  perde
            }
            if (tecla == 's' || tecla == 'S' || tecla == 2)
            {
                cy++;
                if (cx == 0)
                    break;
                // se bater na parede da inferior  perde
            }
            if (tecla == 'd' || tecla == 'D' || tecla == 3)
            {
                cx++;
                if (cx == 0)
                    break;
                // se bater na parede da direita  perde
            }

            gameover = analiza();
            atualiza();
            desenha();
            gotoXY(50, 20); // p/ o cursor não atrapalhar a visão da cobra
            Sleep(velocidade);
        }
        system("cls");
        printf("voceê perdeu! Sua pontuação foi de %d \n", pontos)
            system("pause")
    }

