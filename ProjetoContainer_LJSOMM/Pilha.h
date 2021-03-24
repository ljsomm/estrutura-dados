#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
template <typename Tipo>
class Pilha{
private:
    int topo;
    Tipo *v;
    unsigned tamanho;
public:
    Pilha(unsigned tam){
        tamanho = tam;
        topo = -1;
        v = new Tipo[tamanho];
    }
    ~Pilha(){
        delete []v;
    }

    void empilha(Tipo x){
        topo++;
        v[topo]=x;
    }

    Tipo desempilha(){
        Tipo temp = v[topo];
        topo--;
        return temp;
    }

    Tipo elementodotopo(){
        return v[topo];
    }

    bool pilhacheia(){
        return topo == tamanho-1;
    }

    bool pilhavazia(){
        return topo == -1;
    }

    unsigned getTamanho(){
        return tamanho;
    }
    int getTopo(){
        return topo;
    }

    Tipo getValor(int posicao){
        return v[posicao];
    }
};



#endif // PILHA_H_INCLUDED
