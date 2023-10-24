//2.-Establecer un filtrado por genero, duracion, director, fecha de lanzamiento y precio
//4.-Realizar una renta de pelicula (agregar nombre en el campo rent_to de la data) y
//guardar la informacion del cliente en un archivo aparte(El archivo debe ser en binario, 
//para guardar la informacion del cliente en un archivo aparte
//6.-Buscar por id o por nombre a un cliente


#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct datos{
    int id;
    string movie;
    string genders;
    int duration;
    string director;
    string release_on;
    string rent_to;
    string rent_on;
    string status;
}peliculas[2000];


int main(){
    int resp = 0;
    int count = 0;
    int nline = 0;
    string line, word;

    ifstream infile("../datos/movies.csv", fstream::in);
    ofstream outdata("../datos/client_info.bin",fstream::in | fstream::out | fstream::binary);

    if(!outdata.is_open()  || !infile.is_open()){
        cout <<"ERROR - ARCHIVO NO ENCONTRADO" << endl;
        return 0;
    }else{
        cout << "ARCHIVO ENCONTRADO" << endl;
    }
    
    while (getline(infile,line)){
        stringstream str(line);

        while(getline (str,word,',')){
            switch (count){
                case 0:
                peliculas[nline].id = stoi (word);
                break;

                case 1:
                peliculas[nline].movie = word;
                break;

                case 2:
                peliculas[nline].genders = word;
                break;

                case 3:
                peliculas[nline].duration = stoi(word);
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

}