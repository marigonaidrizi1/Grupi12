#include<iostream>
using namespace std;

struct Student{
    string emri;
    int mosha;
    double nota[3];
};
double llogaritMesataren(const double nota[],int numriNotave){
    double shuma=0;
    for(int i=0;i<numriNotave;i++){
        shuma+=nota[i];
    }
    return shuma/numriNotave;
}
bool kaKaluarProvimet(const double nota[],int numriNotave){
    for(int i=0;i<numriNotave;i++){
        if(nota[i]<5.0){
            return false;
        }
    }
    return true;
}