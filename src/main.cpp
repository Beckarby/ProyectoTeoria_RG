#include <iostream>
#include<string>
#include <fstream>
#include <sstream>
using namespace std;

struct datos{
    string id;
    string movie;
    string genders;
    string duration;
    string director;
    string release_on;
    string rent_to;
    string rent_on;
    string status;
};

int main(){
    datos peliculas[2000];

    int resp = 0;
    int count = 0;
    int nline = 0;
    string line,word;

    ifstream infile("../datos/movies.csv", istream :: in);
    ofstream outfile("../datos/movies.csv", ofstream :: out | ios_base :: app);

    if(!outfile.is_open()  || !infile.is_open()){
        cout <<"No se encontro el archivo" << endl;
        return 0;

    }else{
        cout << "Se encontro el archivo" << endl;
    }

    while (getline(infile,line)){
        stringstream str(line);

        while(getline (str,word,',')){
            switch (count){
                case 0:
                peliculas[nline].id =  word;
                break;

                case 1:
                peliculas[nline].movie = word;
                break;

                case 2:
                peliculas[nline].genders = word;
                break;

                case 3:
                peliculas[nline].duration = word;
                break;

                case 4:
                peliculas[nline].director = word;
                break;

                case 5:
                peliculas[nline].release_on = word;
                break;

                case 6:
                peliculas[nline].rent_to = word;
                break;

                case 7:
                peliculas[nline].rent_on = word;
                break;

                case 8:
                peliculas[nline].status = word;
            }
            count ++;
        }
        nline ++;
        count = 0;
    }

    cout << "              *****BIENVENIDO*****" << endl;
    cout << "                    1-Buscar " << endl;
    cout << "                    2-agregar pelicula" << endl;
    cout << "                    3-visualizar la data " << endl;
    cin >> resp;

    switch(resp){
        case 1:

        break;

        case 2:
        break;

        case 3:

         for (int i = 0; i < 1000; i ++){
           cout << "|"<< peliculas[i].id << " | " << peliculas[i].movie << "|";
           cout << peliculas[i].director << " | " ;
           cout << peliculas[i].rent_to << " | " << peliculas[i].rent_on << "|";
           cout << peliculas[i].status << " | "  << endl;  


         }


        break;
    }

}