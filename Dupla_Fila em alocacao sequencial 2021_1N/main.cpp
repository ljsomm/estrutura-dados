#include <iostream>
#include <conio.h>
#include <locale.h>
#include "duplafila.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    cout << "Dupla Fila em Alocacao Sequencial" << endl;
    unsigned tamanho, fetch;
    int opc, valor;
    cout<<"Inserir o tamanho da Fila--> ";
    cin>>tamanho;
    system("cls");
    Fila<int> f(tamanho);
    do{
        cout<<"1-inserir (fim)"<<endl;
        cout<<"2-remover (inicio)"<<endl;
        cout<<"3-primeiro"<<endl;
        cout<<"4-exibir"<<endl;
        cout<<"5-inserir (inicio)"<<endl;
        cout<<"6-remover (fim)"<<endl;
        cout<<"7-ultimo"<<endl;
        cout<<"9-fim"<<endl;
        cout<<"Selecione: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            if(f.filacheia()){
                cout<<"fila cheia...."<<endl;
            }
            else{
                cout<<"Digite o valor: ";
                cin>>valor;
                f.insereFim(valor);
                cout<<"Sucesso"<<endl;
            }
            cout << "\n\n-- TECLE ALGO PARA RETORNAR AO MENU --";
            getch();
            break;
        case 2:
            if(f.filavazia()){
                cout<<"Fila vazia..."<<endl;
            }
            else{
                cout<<"Removido: "<<f.removeInic()<<endl;
            }
            cout << "\n\n-- TECLE ALGO PARA RETORNAR AO MENU --";
            getch();
            break;
        case 3:
            if(f.filavazia()){
                cout<<"fila vazia..."<<endl;
            }
            else{
                cout<<"Primeiro:"<<f.primeiro()<<endl;
            }
            cout << "\n\n-- TECLE ALGO PARA RETORNAR AO MENU --";
            getch();
            break;
        case 4:
            if(f.filavazia()){
                cout<<"Fila vazia..."<<endl;
            }
            else{
                fetch = f.getInic();
                cout<<"Elementos da Fila:" << endl;;
                for(int i = 0; i < f.getQtde(); i++){
                    if(fetch == tamanho){
                        fetch = 0;
                    }
                    cout << f.getValor(fetch) << endl;
                    fetch++;
                }

            }
            cout << "\n\n-- TECLE ALGO PARA RETORNAR AO MENU --";
            getch();
            break;
        case 5:
            if(f.filacheia()){
                cout<<"A fila já está cheia, não é possível inserir mais termos!"<<endl;
            }
            else{
                cout<<"Digite o valor: ";
                cin>>valor;
                f.insereInicio(valor);
                cout<<"Sucesso"<<endl;
            }
            cout << "-- TECLE ALGO PARA RETORNAR AO MENU --";
            getch();
            break;
        case 6:
            if(f.filavazia()){
                cout<<"Fila vazia..."<<endl;
            }
            else{
                cout<<"Removido: "<<f.removeFim()<<endl;
            }
            cout << "\n\n-- TECLE ALGO PARA RETORNAR AO MENU --";
            getch();
            break;
        case 7:
            if(f.filavazia()){
                cout<<"Fila vazia..."<<endl;
            }
            else{
                cout<< "Ultimo: " << f.ultimo();
            }
            cout << "\n\n-- TECLE ALGO PARA RETORNAR AO MENU --";
            getch();
            break;
        default:
            cout<<"opcao invalida..."<<endl;
            cout << "\n\n-- TECLE ALGO PARA RETORNAR AO MENU --";
            getch();
            break;
        }
        system("cls");
    }while (opc !=9);
    cout<<"Fim...."<<endl;
    return 0;
}
