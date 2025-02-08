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


Student gjejStudentinMeMesatarenMeTeLarte(const Student studentet[], int numriStudenteve) {
    int indeksMax = 0;
    double mesMax = llogaritMesataren(studentet[0].nota, 3);

    for (int i = 1; i < numriStudenteve; i++) {
        double mesatarja = llogaritMesataren(studentet[i].nota, 3);
        if (mesatarja > mesMax) {
            mesMax = mesatarja;
            indeksMax = i;
        }
    }

    return studentet[indeksMax];
}

int main() {
    const int numriStudenteve = 3; 
    Student studentet[numriStudenteve]; 


    for (int i = 0; i < numriStudenteve; i++) {
        cout << "Futni të dhënat për studentin " << i + 1 << ":" << endl;
        merrStudent(studentet[i]);
    }
}