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

void merrStudent(Student& s) {
   cout << "Shkruani emrin e studentit: ";
   cin >> s.emri;
   cout << "Shkruani mosh\x89n e studentit: ";
   cin >> s.mosha;
   cout << "Shkruani 3 notat e studentit: ";
   for (int i = 0; i < 3; i++) {
       cin >> s.nota[i];
   }
   cout << endl;
}
 

void shfaqStudentin(const Student& s) {
   cout << "Emri: " << s.emri << endl;
   cout << "Mosha: " << s.mosha << endl;
   cout << "Notat: ";
   for (int i = 0; i < 3; i++) {
       cout << s.nota[i] << " ";
   }
   cout << endl;
   cout << "Mesatarja: " << llogaritMesataren(s.nota, 3) << endl;
 
   
   if (kaKaluarProvimet(s.nota, 3)) {
       cout << "Statusi: KA KALUAR provimet." << endl;
   } else {
       cout << "Statusi: NUK KA KALUAR provimet." << endl;
   }
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
        cout << "Futni t\x89 dh\x89nat p\x89r studentin " << i + 1 << ":" << endl;
        merrStudent(studentet[i]);
    }
cout<<"---------------"<<endl;
cout<<"Informacioni per te gjithe studentet:"<<endl;
for (int i=0;i<numriStudenteve;i++){
shfaqStudentin(studentet[i]);
cout<<"---------------"<<endl;
}


Student studentiMeMesT = gjejStudentinMeMesatarenMeTeLarte(studentet,numriStudenteve);
cout<<"Studenti me mesataren me te larte eshte : "<<endl;
shfaqStudentin(studentiMeMesT);
return 0 ;
}



