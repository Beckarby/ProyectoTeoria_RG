#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
 
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
    string rent_exp; 
};

int main(){
    datos peliculas[2000];
    int n = 0;
    int i = 0;
    int resp = 0;
    int count = 0;
    int nline = 0;
    int cont_pelis = 0;
    int cont_peli_agg = 0;
    string line,word;
    string agg = " "; // esta variable es para agregar los nombres y campos de las nuevas pelis

    ifstream infile("../datos/movies.csv", istream :: in);
    ofstream outfile("../datos/movies.csv", ofstream :: out | ios_base :: app);

    infile.open("../datos/movies.csv", ios :: app);

    if(!outfile.is_open()  || !infile.is_open()){
        std::cout <<"No se encontro el archivo" << endl;
        return 0;

    }else{
        std::cout << "Se encontro el archivo" << endl;
    }

    while (getline(infile,line)){
        stringstream str(line);
         cont_pelis = cont_pelis + 1;
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

    std::cout << "              *****BIENVENIDO*****" << endl;
    std::cout << "                    1-visualizar lista de peliculas " << endl;
    std::cout << "                    2-Ver el estado de la pelicula" << endl;
    std::cout << "                    3-agregar nueva peiculas" << endl;
    std::cin >> resp;


    switch(resp){
        case 1:
         std:: cout << "     ***Lista***" << endl;
         std:: cout << " " << endl;
         for (int i = 0; i < 1001; i ++){
         std::cout << "|"<< peliculas[i ].id << " | " << peliculas[i ].movie << "|";
         std::cout << peliculas[i ].director << " | " ;
  
        }

        break;

        case 2:
        system("clear");
        

        std::cout << "Cual es la id de la pelicula a revisar??" << endl;
        do{
        std::cin >> n;

        if (peliculas[i].status == " "){

         peliculas[i].status =  "Disponible ";
         peliculas[i].rent_to = "Nadie";
         peliculas[i].rent_on = "Nadie";
          
        }else if(peliculas[i].status == "alquilado "){
            std::cout <<"     ***Estado de la pelicula****" << endl;
            std::cout <<" Nombre: " << peliculas[i].movie << endl;
            std::cout <<" Estado: " << peliculas[i].status << endl;
            std::cout <<" Rentada a " << peliculas[i].rent_to << endl;
            std::cout <<" fecha de renta " << peliculas[i].rent_on << endl;

        }else if(peliculas[i].status == "devuelto "){
            std::cout <<"     ***Estado de la pelicula****" << endl;
            std::cout <<" Nombre: " << peliculas[i].movie << endl;
            std::cout <<" Estado: " << peliculas[i].status << endl;
             
        }else if(peliculas[i].status == "caducado "){
            std::cout <<"     ***Estado de la pelicula****" << endl;
            std::cout <<" Nombre: " << peliculas[i].movie << endl;
            std::cout <<" Estado: " << peliculas[i].status << endl;
            std::cout <<" fecha que se rento: " << peliculas[i].rent_on << endl;
            std::cout <<" fecha que se expiro: " << peliculas[i].rent_exp << endl;
        } ;
        }while(n <= cont_pelis);

        break;

        case 3:
        
        do{
         system("clear");
         cont_peli_agg = cont_pelis + 1 ;


         std::cout << "*** Vamos a agregar nuevas peliculas al menu ***" << endl;
         std::cout << " Ing. El nombre de la pelicula: " << endl;
         std::cin >>agg;

         peliculas[cont_peli_agg].id = cont_peli_agg;
         peliculas[cont_peli_agg].movie = agg ;
        
         std::cout << " Ing. El genero: "<< endl;
         std::cin >>agg;

         peliculas[cont_peli_agg].genders = agg;

         std::cout << " Ing. la duracion: " << endl;
         std::cin >>agg;

         peliculas[cont_peli_agg].duration = agg;

         std::cout << " Ing. El nombre del director: " << endl;
         std::cin >>agg;

         peliculas[cont_peli_agg].director = agg;

         std::cout << " Ing. La fecha de lanzamiento (escribalo con espacios; primero el dia,mes y año): " << endl;
         std::cin >>agg;

         peliculas[cont_peli_agg].release_on = agg;

         std::cout << " Quieres agregar otras??:" << endl;
         std::cout << " 1 para si y 2 para no" << endl;
         std::cin >> resp;

        }while(resp == 2);
        
        break;    

    }

    infile.close();
}