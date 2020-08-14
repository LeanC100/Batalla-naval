#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "conio.h"
using namespace std;

int opcion, ejex, ejey, vida, barco, x;
string nameP1, nameP2, tableroprincipal[8][8], tableroP1[8][8], tableroP2[8][8], gano;

void espaciado()
{
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
}
void tableroDeJuego()
{
    for (int i = 0; i < 8; i++)
    {
        cout << "\t\t\t\t";
        for (int j = 0; j < 8; j++)
        {
            cout << " " << tableroprincipal[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void pantallaPrincipal()
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tableroprincipal[i][j] = "-";
            tableroP1[i][j] = "-";
            tableroP2[i][j] = "-";
        }
    }
    espaciado();

    cout << "\t\t\t-----------------" << endl;
    cout << "\t\t\t| BAtalla Naval |" << endl;
    cout << "\t\t\t-----------------" << endl;
    cout << "\tElige una opcion:" << endl;
    cout << "\t1- JUGAR " << endl;
    cout << "\t2- SALIR" << endl;
    cin >> opcion;
    espaciado();
}

void VerificaPosicionEjes(int x, int y)
{
    while (!(x >= 1 && x <= 8 && y >= 1 && y <= 8))
    {
        cout << "\t\t Error al colocar los ejes" << endl;
        cout << "\t\t Por favor vuelva a colocar los ejes" << endl;
        cout << "\t Eje X: ";
        cin >> ejex;
        x = ejex;
        cout << "\t Eje Y: ";
        cin >> ejey;
        y = ejey;
    }
}
void game()
{

    cout << "\tIngresa el nombre del jugador 1 " << endl;
    cin >> nameP1;
    cout << "\tIngresa el nombre del jugador 2 " << endl;
    cin >> nameP2;
    cout << "\tIngrese la cantidad de barcos que tiene el jugador 1" << endl;
    cin >> barco;
    cout << "\tIngrese la vida del que tiene el jugador 2" << endl;
    cin >> vida;
    espaciado();
    tableroDeJuego();
    for (int i = 0; i < barco; i++)
    {
        cout << "\t" << nameP1 << " coloca el barco N. " << i + 1 << endl;
        cout << "\tEn el eje X: ";
        cin >> ejex;
        cout << "\tEn el  eje Y: ";
        cin >> ejey;
        VerificaPosicionEjes(ejex, ejey);
        tableroP1[ejex - 1][ejey - 1] = "0";
        tableroprincipal[ejex - 1][ejey - 1] = "0";
        espaciado();
        tableroDeJuego();
    }
    cout << endl;
    system("pause");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tableroprincipal[i][j] = "-";
        }
    }
    cout << endl;
    while (vida != 0 && x != 64)
    {
        tableroDeJuego();
        cout << "\t" << nameP2 << " pocisiona el disparo" << endl;
        cout << "\tEn el eje X: ";
        cin >> ejex;
        cout << "\tEn el  eje Y: ";
        cin >> ejey;
        VerificaPosicionEjes(ejex, ejey);
        tableroP2[ejex - 1][ejey - 1] = "0";
        tableroprincipal[ejex - 1][ejey - 1] = "+";
        espaciado();
        if (tableroP1[ejex - 1][ejey - 1] == "0")
        {
            cout << "\t\t\t\tt ------------------------- " << endl;
            cout << "\t\t\t\tt ------------------------- " << endl;
            cout << "\t\t\t\tt Bien Destruiste un barco" << endl;
            cout << "\t\t\t\tt ------------------------- " << endl;
            cout << "\t\t\t\tt ------------------------- " << endl;
            tableroprincipal[ejex - 1][ejey - 1] = "*";
            tableroP1[ejex - 1][ejey - 1] = "-";
        }
        else
        {

            cout << "\t\t\t\t| No le diste a ningun barco |" << endl;
            vida--;
            cout << "\t\t\t\t      Te quedan " << vida << " vidas" << endl;
        }
        cout << endl;
        x = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (tableroP1[i][j] == "-")
                {
                    x++;
                }
            }
        }
        if (x == 64)
        {
            gano = "SI";
            tableroDeJuego();
        }
    }

    if (vida == 0)
    {
        cout << "\t\t |Ganaste " << nameP1 << "|" << endl;
    }
    else if (gano == "SI")
    {
        cout << "\t\t |Ganaste " << nameP2 << "|" << endl;
    }
    espaciado();
    system("pause");
    espaciado();
    espaciado();
    pantallaPrincipal();
}

int main()
{
    system("color 03");
    pantallaPrincipal();
    while (opcion != 2)
    {
        if (opcion == 1)
        {
            game();
        }
        else if (opcion == 2)
        {

            cout << "\t Gracias por jugar el juego" << endl;
            getche();
        }
        else
        {
            cout << "\tERROR" << endl;
            getche();
        }
    }
    return 0;
}