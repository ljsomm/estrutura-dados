#include <iostream>
#include <stdlib.h>
#include "arCondicionado.h"

using namespace std;

int main()
{
    arCondicionado ac;
    short menu;
    do{
        cout << "Ar condicionado - Estado: " << ac.state << endl << "Temperatura: " << ac.temp << "C" <<   endl << "\n1 - Ligar/Desligar\n2 - Aumentar Temperatura\n3 - Diminuir Temperatura\n\nSelecionar--> ";
        cin >> menu;
        switch(menu){
            case 1:
                ac.changeState();
                break;
            case 2:
                ac.aTemp();
                break;
            case 3:
                ac.dTemp();
                break;
        }
        system("cls");
    }while(menu != 4);

    return 0;
}
