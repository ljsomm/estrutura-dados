#ifndef ARCONDICIONADO_H_INCLUDED
#define ARCONDICIONADO_H_INCLUDED

struct arCondicionado{
    bool state;
    float temp;

    arCondicionado(){
        temp = 18;
    }

    void changeState(){
        if(state){
            state = 0;
        }
        else{
            state = 1;
        }

    }

    void aTemp(){
        if(state && temp < 24){
            temp++;
        }
    }

    void dTemp(){
        if(state && temp > 16){
            temp--;
        }
    }


};;


#endif // ARCONDICIONADO_H_INCLUDED
