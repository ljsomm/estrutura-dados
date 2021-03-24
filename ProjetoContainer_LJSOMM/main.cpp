#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "Pilha.h"
#include "Container.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    short opt, qt_quadra, num_quadra, num_cc;
    Container c;
    cout << "Insira a quantidade de quadras do seu pátio de containers: ";
    cin >> qt_quadra;
    cout << "Insira a quantidade de containers por quadra: ";
    cin >> num_cc;
    Pilha<Container> *p[qt_quadra];
    for(int i = 0; i < qt_quadra; i++){
        p[i] = new Pilha<Container>(num_cc);
    }
    do{
       system("cls");
       cout << "=== MENU ===\n\n1 - Empilhar um Container em uma quadra do pátio\n2 - Desempilha um Container de uma quadra do pátio\n3 - Exibir a situação do pátio\n4 - finalizar a aplicação\n\nOpção--> ";
       cin >> opt;
       system("cls");
       switch(opt){
            case 1:
                cout << "=== EMPILHA ===\n\nCódigo do Container: ";
                cin >> c.codigo;
                cout << "Dimensão do Container: ";
                cin >> c.dimensao;
                cout << "Peso do Container: ";
                cin >> c.peso;
                cout << "Quadra (De 1 até " << qt_quadra << "): ";
                cin >> num_quadra;
                if(!p[num_quadra-1]->pilhacheia()){
                    p[num_quadra-1]->empilha(c);
                }
                else{
                   cout << "\nERRO: Pilha cheia!";
                }
                cout << "\n\n-- Tecle algo para retornar o menu --";
                getch();
                break;
            case 2:
                cout << "=== DESEMPILHA ===\n\nQuadra (De 1 até " << qt_quadra << "): ";
                cin >> num_quadra;
                if(!p[num_quadra-1]->pilhavazia()){
                    p[num_quadra-1]->desempilha();
                }
                else{
                    cout << "\nNão foi desempilhado, pois a fila já está vazia!";
                }
                cout << "\n\n-- Tecle algo para retornar o menu --";
                getch();
                break;
            case 3:
                cout << "=== SITUAÇÃO DO PÁTIO ===\n\nMapa: \n\n";
                for(int i = 0; i < qt_quadra; i++){
                    cout << "-- Quadra " << i+1 << " --" << endl;
                    cout << "\n\tQuantia de Containers: " << p[i]->getTopo()+1 << " de " << p[i]->getTamanho();
                    cout << "\n\tStatus: ";
                    if(!(p[i]->pilhacheia()) && !(p[i]->pilhavazia())){
                        cout << "Ainda é possível inserir ou remover Containers;";
                    }
                    else{
                        if(p[i]->pilhacheia()){
                            cout << "A pilha de Containers está cheia;";
                        }
                        else if(p[i]->pilhavazia()){
                            cout << "A pilha de Containers está vazia;";
                        }
                    }
                    cout << "\n\n";
                }
                cout << "-- Tecle algo para retornar o menu --";
                getch();
                break;

       }
    }while(opt != 4);
    system("color a");
    printf("Obrigado por utilizar o nosso sistema de controle de containers!");
    return 0;
}
