#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "conio.h"
using namespace std;

int opcion, player1[8][8], player2[8][8], ejex, ejey, vida, barco;
string nameP1 , nameP2, tableroprincipal[8][8], talberoP1[8][8], tableroP2[8][8];


void espaciado (){
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
}
void tableroDeJuego (){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout <<"\t\t\t\t"<< tableroprincipal [i][j];
        }
        cout << endl;
    }
    
}
void pantallaPrincipal (){

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tableroprincipal [i][j] ='-';
            talberoP1[i][j] = ' ';
            tableroP2[i][j] = ' ';
        }
        
    }
    espaciado ();

    cout << "\t\t\t-----------------"<< endl;
    cout << "\t\t\t| BAtalla Naval |" << endl;
    cout << "\t\t\t-----------------" << endl;
    cout << "\tElige una opcion:" << endl;
    cout << "\t1- JUGAR " << endl;
    cout << "\t2- SALIR" << endl;
    cin >> opcion;
    espaciado();

} 

void VerificaPosicionEjes (int x, int y){
    while (!(x>=1 && x<=8 && y>=1 && y<=8))
    {
        cout << "\t\t Error al colocar los ejes"<<endl;
        cout << "\t\t Por favor vuelva a colocar los ejes"<<endl;
        cout << "\t Eje X"<<endl;
        cin >> ejex;
        x = ejex;
        cout << "\t Eje Y"<<endl;
        cin >> ejey;
        y = ejey;
    }
    
}
void game (){

    cout << "\tIngresa el nombre del jugador 1 "<<endl;
    cin >> nameP1;
    cout << "\tIngresa el nombre del jugador 2 "<<endl;
    cin >> nameP2;
    cout << "\tIngrese la cantidad de barcos que tiene el jugador 1"<<endl;
    cin >> barco;
    cout << "\tIngrese la vida del que tiene el jugador 2"<<endl;
    cin >> vida;
    espaciado();
    for (int i = 0; i < barco; i++)
    {
        tableroDeJuego ();
        cout << "\t"<<nameP2<<" coloca el barco N. "<<i+1<<endl;
        cout << "\tEn el eje X"<<endl;
        cin >> ejex;
        cout << "\tEn el  eje y"<<endl;
        cin >> ejey;
        VerificaPosicionEjes (ejex, ejey);
        player1 [ejex-1][ejey-1]='0';
        tableroprincipal [ejex-1][ejey-1]='0';
        espaciado();
    }
    
    while (vida != 0 ) {
        tableroDeJuego ();
        cout <<"\t"<< nameP2<<" pocisiona el disparo"<<endl;
        cout << "\tEn el eje X"<<endl;
        cin >> ejex;
        cout << "\tEn el  eje y"<<endl;
        cin >> ejey;
        VerificaPosicionEjes(ejex, ejey);
        tableroprincipal[ejex-1][ejey-1]='0';

        espaciado();
        if (player1[ejex-1][ejey-1]=='0')
        {
            cout << "\t\tBien Destruiste un barco"<< endl;
                
        }else {
            cout << "\t\tNo Disparaste a ningun barco"<< endl;
            vida--;
            cout << "\t\tTe quedan "<<vida<<"vidas"<< endl;
        }
            
    }
    espaciado ();
    if (vida==0)
    {
        cout << "\t\t |Ganaste "<<player2<<"|"<<endl;
    }else{
        cout << "\t\t |Perdiste "<<player2<<"|"<<endl;
    }
    espaciado();
    pantallaPrincipal();
}

int main ()
{
    system ("color 03");
    pantallaPrincipal();
    while (opcion !=2){
        if (opcion==1)
        {
            game();
        }
        else if (opcion==2)
        {
            
            cout << "\t Gracias por jugar el juego" << endl;
            getche();
        }
        else {
            cout << "\tERROR" << endl;
            getche();
        }
          
    }
    return 0;
}