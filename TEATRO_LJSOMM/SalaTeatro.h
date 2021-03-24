#ifndef SALATEATRO_H_INCLUDED
#define SALATEATRO_H_INCLUDED

class SalaTeatro{

    private:

        bool **ic_local; //considere: true = ocupada && false = desocupado
        int qt_contagem;

    public:

        SalaTeatro(int row, int col){
            ic_local = new bool *[row];
            for(int i = 0; i < row; i++){
                ic_local[i] = new bool[col];
            }
            //incializa todos os locais com cadeiras vazias (false)
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    ic_local[i][j] = false;
                }
            }
            qt_contagem = 0;
        }

        ~SalaTeatro(){
           delete [] ic_local;
        }

        bool reservarAssento(int row, int col){
            if(!(ic_local[row][col])){
                ic_local[row][col] = true;
                qt_contagem++;
                return true;
            }
        }

        bool alterarAssento(int r1, int r2, int c1, int c2){
            if(r1 != r2 || c1 != c2){
                excluirAssento(r1, c1);
                reservarAssento(r2, c2);
                return true;
            }
        }

        bool excluirAssento(int row, int col){
            if(ic_local[row][col]){
                ic_local[row][col] = false;
                qt_contagem--;
                return true;
            }
        }

        bool getLocal(int row, int col){
            return ic_local[row][col];
        }

        int getContagem(){
            return qt_contagem;
        }

};

#endif // SALATEATRO_H_INCLUDED
