#include <iostream>
#include <math.h>
using namespace std;

class Ponto{
    private:
        float x, y;
    public:
        Ponto(){
            this->x = 0;
            this->y = 0;
        }
        Ponto(float _x, float _y){
            this->x = _x;
            this->y = _y;
        }
        float getX(){
            return this->x;
        }
        float getY(){
            return this->y;
        }
        void setX(float _x){
            this->x = _x;
        }
        void setY(float _y){
            this->y = _y;
        }
        double calcDistancia(){
            return sqrt(pow(this->x, 2) + pow(this->y, 2));
        }
        void setCoordenadas(double _x, double _y){
            this->x = _x;
            this->y = _y;
        }

};