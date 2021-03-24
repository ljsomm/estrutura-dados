#ifndef FILAALOCACAOSEQUENCIAL_H_INCLUDED
#define FILAALOCACAOSEQUENCIAL_H_INCLUDED

template <typename Tipo>
//implementando uma dupla fila
class Fila{
private:
    Tipo *v;
    int fim;
    int inic;
    unsigned tamanho;
    unsigned qtde;
public:
    Fila(unsigned tam){
        tamanho = tam;
        fim=-1;
        inic = 0;
        qtde=0;
        v = new Tipo[tamanho];
    }
    void insereFim(Tipo x){
        fim++;
        if(fim == tamanho){
            fim=0;
        }
        v[fim]=x;
        qtde++;
    }

    void insereInicio(Tipo x){
        inic--;
        if (inic == -1){
            inic = tamanho-1;
        }
        v[inic]=x;
        qtde++;
    }


    Tipo removeInic(){
        Tipo temp=v[inic];
        inic++;
        if(inic==tamanho){
            inic=0;
        }
        qtde--;
        return temp;
    }

    Tipo removeFim(){
        Tipo temp = v[fim];
        fim--;
        if (fim == -1){
            fim=tamanho-1;
        }
        qtde--;
        return temp;
    }

    Tipo primeiro(){
        return v[inic];
    }

    Tipo ultimo(){
        return v[fim];
    }


    bool filavazia(){
        return qtde==0;
    }

    bool filacheia(){
        return qtde==tamanho;
    }
    unsigned getTamanho(){
        return tamanho;
    }
    int getFim(){
        return fim;
    }
    int getInic(){
        return inic;
    }
    unsigned getQtde(){
        return qtde;
    }

    Tipo getValor(unsigned posicao){
        return v[posicao];
    }

};

#endif // FILAALOCACAOSEQUENCIAL_H_INCLUDED
