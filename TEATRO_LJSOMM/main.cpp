#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "SalaTeatro.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    unsigned linha, coluna, l1, c1, l2, c2;
    short menu;
    system("color b");
    cout << "SEJA BEM-VINDO AO THEATER SYSTEM!\n\nInsira a quantia de fileiras da sua sala--> ";
    cin >> linha;
    cout << "Insira a quantia de colunas da sua sala--> ";
    cin >> coluna;
    system("color 7");
    SalaTeatro sala(linha, coluna);
    do{
        system("cls");
        cout << "Situação atual da sala (Considere [0] vázio e [X] preenchido): \n\n";
        for(int i = 0; i < linha; i++){
                cout << "\t\t";
            for(int j = 0; j < coluna; j++){
                if(sala.getLocal(i, j)){
                    cout << "[X]";
                }
                else{
                    cout << "[0]";
                }
            }
            cout << endl;
        }
        cout << "\nTOTAL DE LUGARES OCUPADOS: " << sala.getContagem() << endl;
        cout << "\nO que deseja fazer?\n\n1 - Reservar assento\n2 - Alterar assento\n3 - Devolver Assento\n4 - Sair do sistema\n\nOpção--> ";
        cin >> menu;
        system("cls");
        switch(menu){
            case 1:
                cout << "=== RESERVAR ASSENTO ===\n\nFileira: ";
                cin >> l1;
                cout << "Coluna: ";
                cin >> c1;
                if(sala.reservarAssento(l1, c1)){
                    cout << "\nAssento reservado com sucesso!" ;
                }
                else{
                    cout << "\nHouve um erro ao reservar o assento :c\nTente novamente!";
                }
                cout << "\n\n-- Tecle algo para retornar ao menu --";
                getch();
                break;
            case 2:
                cout << "=== ALTERAR ASSENTO ===\n\nFileira Antiga: ";
                cin >> l1;
                cout << "Coluna Antiga: ";
                cin >> c1;
                cout << "Fileira Nova: ";
                cin >> l2;
                cout << "Coluna Nova: ";
                cin >> c2;
                if(sala.alterarAssento(l1, l2, c1, c2)){
                    cout << "\nAlteração concluída com sucesso!";
                }
                else{
                    cout << "\nHouve um erro ao fazer alteração :c\nTente Novamente!";
                }
                cout << "\n\n-- Tecle algo para retornar ao menu --";
                getch();
                break;
            case 3:
                cout << "=== DEVOLVER ASSENTO ===\n\nFileira: ";
                cin >> l1;
                cout << "Coluna: ";
                cin >> c1;
                if(sala.excluirAssento(l1, c1)){
                    cout << "\nDevolução concluída com sucesso!";
                }
                else{
                    cout << "\nHouve um erro ao tentar devolver :c\nTente novamente!";
                }
                cout << "\n\n-- Tecle algo para retornar ao menu --";
                getch();
                break;
            case 4:
                system("color a");
                cout << "Obrigado por utilizar nosso sistema!" << endl;
                break;
        }
    }while(menu != 4);
}
