#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct datos{
    int id;
    string movie;
    string genders;
    int duration;
    string director;
    float price;
    string release_on;
    string rent_to;
    string rent_on;
    string status;
    string rent_exp;
}peliculas[2000];

template <typename T>
int partition(T arr[], int start, int end);
template <typename T>
void quickSort(T arr[], int start, int end);
template <typename T>
int binarySearch(T arr[],int n,T x);
template <typename T>
int linearSearch(T arr[], int n, T x);

void agg_nuevas_pelis();
void eliminar_pelis();


ofstream outdata("data_renta.bin", std::ofstream::app );


int main(){
    int n = 0;
    int i = 0;
    int resp = 0;
    int count = 0;
    int nline = 0;
    long long int cont_pelis = 0;
    string line, word;
    string agg = " ";
    int filtro = 0; 
    int tipo_filtro_nombre = 0;
    int tipo_filtro_director = 0;
    int tipo_filtro_precio = 0; 
    string pelicula_search = " ";
    string gender_search = " "; 
    string director_search =  " ";
    float precio_search = 0;
    string fecha = " ";
    string nombre_cliente = " ";
    string fecha_rent = " ";
    string pelicula_rented = " ";
    string id_cliente = " ";  
    string OrderByMovies[1001];
    string UnOrderedMovies[1001];
    string OrderByGender[1001];
    string UnOrderedGender[1001];
    int OrderByDuration[1001];
    int UnOrderedDuration[1001];
    string OrderByDirector[1001];
    string UnOrderedDirector[1001];
    string OrderByDate[1001];
    string UnOrderedDate[1001];
    float OrderByPrice[1001];
    float UnOrderedPrice[1001];
    int size;
    int name_id = 0;
    int result;
   
    fstream infile("../movies.csv");

    if(!infile.is_open()){
        std::cout <<"ERROR - ARCHIVO NO ENCONTRADO" << endl;
        return 0;
    }
    while (getline(infile,line)){
        stringstream str(line);
        while(getline (str,word,';')){
            
            switch (count){
                case 0:
                    peliculas[nline].id = stoi(word);
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
                    peliculas[nline].price = stof(word);
                    break;

                case 6:
                    peliculas[nline].release_on = word;
                    break;

                case 7:
                    peliculas[nline].rent_to = word;
                    break;

                case 8:
                    peliculas[nline].rent_on = word;
                    break;

                case 9:
                    peliculas[nline].status = word;
                    break;
            }
            count ++;
        }
        nline ++;
        count = 0;
    }   
    for (int i = 0; i < nline; i++){
        OrderByMovies[i] = peliculas[i].movie;
        UnOrderedMovies[i] = peliculas[i].movie;
        OrderByGender[i] = peliculas[i].genders;
        UnOrderedGender[i] = peliculas[i].genders;
        OrderByDuration[i] = peliculas[i].duration;
        UnOrderedDuration[i] = peliculas[i].duration;
        OrderByDirector[i] = peliculas[i].director;
        UnOrderedDirector[i] = peliculas[i].director;
        OrderByDate[i] = peliculas[i].release_on;
        UnOrderedDate[i] = peliculas[i].release_on;
        OrderByPrice[i] = peliculas[i].price;
        UnOrderedPrice[i] = peliculas[i].price;

        
    }


    std::cout << "|| BIENVENIDO ||" << endl;
    std::cout << "1-Visualizar lista de peliculas " << endl;
    std::cout << "2-Visualizar el estado de la pelicula" << endl;
    std::cout << "3.-Agregar nueva peliculas" << endl;
    std::cout << "4.-Filtrado" << endl;
    std::cout << "5.-Rentar" << endl;
    std::cout << "6.-Busqueda de cliente" << endl;
    std::cout << "7.-Eliminar una pelicula" << endl;
    std::cin >> resp;

    switch (resp)
    {
    case 1:
         std::cout << "     ***Lista***" << endl;
         std::cout << " " << endl;
         for (int i = 0; i < 1001; i ++){
         std::cout << "|"<< peliculas[i ].id << " | " << peliculas[i ].movie << "|";
         std::cout << peliculas[i ].director << " | " << endl;
  
        }

        break;

        case 2:
        system("cls");

        do{
         std::cout << "Cual es la id de la pelicula a revisar??" << endl;   
         std::cin >> n;
         i = n - 1; 

        if (peliculas[i].status.empty()){

         peliculas[i].status =  "Disponible ";
         peliculas[i].rent_to = "Nadie";
         peliculas[i].rent_on = "Nadie";

            std::cout <<"     ***Estado de la pelicula****" << endl;
            std::cout <<" Nombre: " << peliculas[i].movie << endl;
            std::cout <<" Estado: " << peliculas[i].status << endl;
            std::cout <<" Rentada a " << peliculas[i].rent_to << endl;
          
        }else if(peliculas[i].status == "alquilado"){
            std::cout <<"     ***Estado de la pelicula****" << endl;
            std::cout <<" Nombre: " << peliculas[i].movie << endl;
            std::cout <<" Estado: " << peliculas[i].status << endl;
            std::cout <<" Rentada a " << peliculas[i].rent_to << endl;
            std::cout <<" fecha de renta " << peliculas[i].rent_on << endl;

        }else if(peliculas[i].status == "devuelto"){
            std::cout <<"     ***Estado de la pelicula****" << endl;
            std::cout <<" Nombre: " << peliculas[i].movie << endl;
            std::cout <<" Estado: " << peliculas[i].status << endl;
             
        }else if(peliculas[i].status == "caducado"){
            std::cout <<"     ***Estado de la pelicula****" << endl;
            std::cout <<" Nombre: " << peliculas[i].movie << endl;
            std::cout <<" Estado: " << peliculas[i].status << endl;
            std::cout <<" fecha que se rento: " << peliculas[i].rent_on << endl;
            std::cout <<" fecha que se expiro: " << peliculas[i].rent_exp << endl;
        } 
            std::cout << " " << endl;
            std::cout << "Quieres revisar otra ??:" << endl;
            std::cout << "1-para si " << endl;
            std::cout << "2-para no " << endl;

            do{
                std::cin >> resp;

               if(resp != 1 && resp != 2){
                 std::cout << "Error..." << endl;
                 std::cout << "Respuesta invalida seleccione una correcta:" << endl;
                }else{
                 std::cout << "Procesando.." << endl;
                 system("cls");
                }
            }while(resp != 1 && resp != 2);

        }while(n <= cont_pelis && resp != 2);

        break;

        case 3:

        agg_nuevas_pelis();
        
        break;    
    case 4: 
        std::cout << "Elige el tipo de filtro" << endl;
        std::cout << "1.- nombre" << endl;
        std::cout << "2.- genero" << endl;
        std::cout << "3.- duracion" << endl;        
        std::cout << "4.- director" << endl;
        std::cout << "5.- fecha de lanzamiento" << endl;
        std::cout << "6.- precio" << endl;
        std::cin >> filtro;

        switch (filtro)
        {
        case 1:              
            size = sizeof(OrderByMovies) / sizeof(OrderByMovies[0]);    
            quickSort(OrderByMovies, 0, size -1);

            std::cout << "A elegido filtrado por nombre" << endl;
            std::cout << "Ingrese 1 para ver las peliculas en orden alfabetico" << endl;
            std::cout << "Ingrese 2 para buscar una pelicula en especifico" << endl;
            std::cin >> tipo_filtro_nombre;
            while (tipo_filtro_nombre != 1 && tipo_filtro_nombre !=2)
            {
                std::cout << "ERROR - VALOR INVALIDO" << endl;
                std::cout << "Ingrese un valor valido" << endl;
                std::cout << "1 para filtrar alfabeticamente" << endl;
                std::cout << "2 para buscar una pelicula" << endl;
                cin.get();
                std::cin >> tipo_filtro_nombre;
            }
            if (tipo_filtro_nombre == 1){
                std::cout << "A continuacion se mostraran las peliculas en orden alfabetico" << endl;
                for (int i = 0; i < nline + 1; i++)
                {
                    std::cout << OrderByMovies[i] << " " << endl;
                    
                }
                std::cout << endl;
            } else if (tipo_filtro_nombre == 2) {
                std::cout << "Ingrese el nombre de la pelicula que quiera buscar" << endl;
                cin.get();
                getline(cin, pelicula_search);
                result = binarySearch(OrderByMovies, size, pelicula_search);
                if (result == -1){
                    std::cout << "La pelicula no se encuentra en la base de datos" << endl;
                    return 0;
                } else {
                    std::cout << "PELICULA ENCONTRADA" << endl;
                    result = linearSearch(UnOrderedMovies, size, pelicula_search);
                    std::cout << "Pelicula: " << peliculas[result].movie << endl;
                    std::cout << "Generos: " << peliculas[result].genders << endl;
                    std::cout << "Duracion: " << peliculas[result].duration << endl;
                    std::cout << "Director: " << peliculas[result].director << endl;
                    std::cout << "Estreno: " << peliculas[result].release_on << endl;
                    std::cout << "Precio: " << peliculas[result].price << endl; 
                    if(peliculas[result].status == ""){
                        std::cout << "Estado: Disponible" << endl; 
                    } else{
                        std::cout << "Estado: Ocupada" << endl;
                    }
                    
                }
            }
            
            break;
        case 2:

            std::cout << "A elegido el filtro por genero" << endl;
            std::cout << "Ingrese el genero que quiera buscar" << endl;
            std::cin.get();
            std::getline(cin, gender_search);

            for (int i = 0; i < nline; i++)
            {
                if(UnOrderedGender[i].find(gender_search) != std::string::npos){
                    std::cout << "Pelicula: " << peliculas[i].movie << endl;
                    std::cout << "Generos: " << peliculas[i].genders << endl;
                    std::cout << "Duracion: " << peliculas[i].duration << endl;
                    std::cout << "Director: " << peliculas[i].director << endl;
                    std::cout << "Precio: " << peliculas[i].price << endl;
                    if(peliculas[i].status == ""){
                        std::cout << "Estado: Disponible" << endl; 
                    } else{
                    std::cout << "Estado: Ocupada" << endl;
                    }
                }
                std::cout << endl;
            }
                    
            break;
        case 3:
            std::cout << "A elegido el filtro por duracion" << endl;
            std::cout << "A continuacion apareceran la duracion de las peliculas de menor a mayor" << endl;
            

            size = sizeof(OrderByDuration) / sizeof(OrderByDuration[0]);
            quickSort(OrderByDuration, 0, size -1);
            for (int i = 0; i < 1001; i++)
            {
                std::cout << "Duracion: " << OrderByDuration[i] << "min" << endl;
                result = linearSearch(UnOrderedDuration, size, OrderByDuration[i]);
                std::cout << "Pelicula: " << peliculas[result].movie << endl;
                std::cout << "Precio: " << peliculas[result].price << endl;
                if(peliculas[result].status == ""){
                    std::cout << "Estado: Disponible" << endl; 
                }else{
                    std::cout << "Estado: Ocupada" << endl;
                }
                std::cout << endl;
            }
            
            break;
        case 4:
            std::cout << "A elegido el filtro por director" <<endl;
            std::cout << "Presione 1 si quiere buscar por orden alfabetico" << endl;
            std::cout << "Presione 2 si quiere buscar directores especificos" << endl;
            std::cin >> tipo_filtro_director;

            while (tipo_filtro_director != 1 && tipo_filtro_director != 2)
            {
                std::cout << "ERROR - VALOR INVALIDO" << endl;
                std::cout << "Ingrese un valor valido" << endl;
                std::cout << "1 para filtrar por orden alfabetico" << endl;
                std::cout << "2 para filtrar por director especifico" << endl;
                std::cin >> tipo_filtro_director;
            }

            if (tipo_filtro_director == 1)
            {
                
                size = sizeof(OrderByDirector) / sizeof(OrderByDirector[0]);
                
                quickSort(OrderByDirector, 0, size -1);

                for (int i = 0; i < 1001; i++)
                {
                    std::cout << "Director: " << OrderByDirector[i] << " " << endl;
                    result = linearSearch(UnOrderedDirector, size, OrderByDirector[i]);
                    std::cout << "Pelicula: " << peliculas[result].movie << endl;
                    std::cout << "Precio: " << peliculas[result].price << endl;
                    if(peliculas[result].status == ""){
                        std::cout << "Estado: Disponible" << endl; 
                    } else{
                        std::cout << "Estado: Ocupada" << endl;
                    }
                }
                std::cout << endl;
            } 
            else
            {
                std::cout << "Ingrese el director que quiere buscar" << endl;
                std::cin.get();
                std::getline(std::cin, director_search);
                //se buscan las peliculas del director
                
                size = sizeof(OrderByDirector) / sizeof(OrderByDirector[0]);
                
                quickSort(OrderByDirector, 0, size -1);

                result = binarySearch(OrderByDirector, size, director_search);
                if(result == -1){
                    std::cout << "El director no se encuentra en la base de datos" << endl;
                    return 0;
                } else {
                    result = linearSearch(UnOrderedDirector, size, director_search);
                    std::cout << "el director se encontro en la base de datos" << endl;
                    std::cout << "Pelicula: " << peliculas[result].movie << endl;
                    std::cout << "Genero: " << peliculas[result].genders << endl;
                    std::cout << "Duracion: " << peliculas[result].duration << endl;
                    std::cout << "Precio: " << peliculas[result].price << endl;
                    if(peliculas[result].status == ""){
                        std::cout << "Estado: Disponible" << endl; 
                    } else{
                        std::cout << "Estado: Ocupada" << endl;
                    }

                    std::cout << endl;

                    
                }

            }
            break;
        case 5:
            size = sizeof(OrderByDate) / sizeof(OrderByDate[0]);
            quickSort(OrderByDate, 0, size -1);
            std::cout << "Ha elegido el filtro por fecha de lanzamiento" << endl;
            std::cout << "Ingrese la fecha con '-' de por medio " << endl;
            std::cout << "Ejemplo xxxx-xx-xx" << endl;
            std::cout << "year-month-day" << endl;
            std::cin.get();
            std::getline(std::cin, fecha);
            result = binarySearch(OrderByDate, size, fecha);
            if(result == -1){
                std::cout << "Ninguna pelicula en la base de datos se estreno en esa fecha" << endl;
                return 0;
            } else {
                result = linearSearch(UnOrderedDate, size, fecha);
                std::cout << "Pelicula: " << peliculas[result].movie << endl;
                std::cout << "Genero: " << peliculas[result].genders << endl;
                std::cout << "Duracion: " << peliculas[result].duration << endl;
                std::cout << "Precio: " << peliculas[result].price << endl;
                if(peliculas[result].status == ""){
                    std::cout << "Estado: Disponible" << endl; 
                } else{
                    std::cout << "Estado: Ocupada" << endl;
                }
                std::cout << endl;
            }            


            break;
        case 6:
            std::cout << "Ha elegido el filtro por precio" << endl;
            std::cout << "Presione 1 si quiere de orden ascendente" << endl;
            std::cout << "Presione 2 si quiere de orden descendiente" << endl;
            std::cout << "Presione 3 si quiere buscar un precio especifico" << endl;
            std::cin >> tipo_filtro_precio;

            while (tipo_filtro_precio != 1 && tipo_filtro_precio != 2 && tipo_filtro_precio != 3)
            {
                std::cout << "ERROR - VALOR INVALIDO" << endl;
                std::cout << "Ingrese un valor valido" << endl;
                std::cout << "1 para filtrar por orden ascendiente" << endl;
                std::cout << "2 para filtrar por genero descendiente" << endl;
                std::cout << "3 para filtrar por precio especifico" << endl;
                std::cin >> tipo_filtro_precio;
            }

            if (tipo_filtro_precio == 1)
            {
                std::cout << "A continuacion se mostraran los precios de menor a mayor" << endl;
                size = sizeof(OrderByPrice)/sizeof(OrderByPrice[0]);
                quickSort(OrderByPrice, 0, size -1);

                for (int i = 0; i < 1001; i++)
                {
                    std::cout << OrderByPrice[i] << endl;
                    result = linearSearch(UnOrderedPrice, size, OrderByPrice[i]);
                    std::cout << "Pelicula: " << peliculas[result].movie << endl;
                    std::cout << "Director: " << peliculas[result].director << endl;
                    if(peliculas[result].status == ""){
                        std::cout << "Estado: Disponible" << endl; 
                    } else{
                        std::cout << "Estado: Ocupada" << endl;
                    }

                }
                std::cout << endl;

            }
            else if (tipo_filtro_precio == 2)
            {
                std::cout << "A continuacion se mostraran los precios de mayor a menor" << endl;
                size = sizeof(OrderByPrice)/sizeof(OrderByPrice[0]);
                quickSort(OrderByPrice, 0, size -1);

                for(int i = nline; i > 0; i--){
                    std::cout << "Precio: " << OrderByPrice[i] << endl;
                    result = linearSearch(UnOrderedPrice, size, OrderByPrice[i]);
                    std::cout << "Peliculas: " << peliculas[result].movie << endl;
                    std::cout << "Director: " << peliculas[result].director << endl;
                    if(peliculas[result].status == ""){
                        std::cout << "Estado: Disponible" << endl; 
                    } else{
                        std::cout << "Estado: Ocupada" << endl;
                    }
                }
                std::cout << endl;
                
            }
            else
            {
                size = sizeof(OrderByPrice)/sizeof(OrderByPrice[0]);
                quickSort(OrderByPrice, 0, size -1);
                std::cout << "Ingrese el precio de la pelicula a buscar" << endl;
                std::cin >> precio_search;
                result = binarySearch(OrderByPrice, size, precio_search);
                if(result == -1){
                    std::cout << "Ninguna de las peliculas en la base de datos tiene ese precio" << endl;
                    return 0;
                } else {
                    std::cout << "Pelicula encontrada" << endl;
                    result = linearSearch(UnOrderedPrice, size, precio_search);
                    std::cout << "Pelicula: " << peliculas[result].movie << endl;
                    std::cout << "Genero: " << peliculas[result].genders << endl;
                    std::cout << "Duracion: " << peliculas[result].duration << endl;
                    std::cout << "Director: " << peliculas[result].director << endl;
                    std::cout << "Estreno: " << peliculas[result].release_on << endl;
                    std::cout << "Precio: " << peliculas[result].price << endl;
                    if(peliculas[result].status == ""){
                        std::cout << "Estado: Disponible" << endl; 
                    } else{
                        std::cout << "Estado: Ocupada" << endl;
                    } 
                }

            }
            
            break;        
        default:
            std::cout << "ERROR - VALOR INVALIDO" << endl;
            return 0;
            break;
        }
        break;
    case 5: 
        size = sizeof(OrderByMovies) / sizeof(OrderByMovies[0]);    
        quickSort(OrderByMovies, 0, size -1);

        if (!outdata) {
        std::cerr << "ERROR - EL ARCHIVO NO SE PUDO ABRIR.\n";
        return 1;
        }

        if (outdata.tellp() == 0) { 
            outdata << endl << "Pelicula - ID cliente - Nombre - Fecha";
        } else {
            outdata << "\n";
        }

        std::cout << "Ingrese la pelicula a rentar: ";
        std::cin >> pelicula_rented;
        outdata << " " << pelicula_rented;

        result = binarySearch(OrderByMovies, size, pelicula_rented);
        if (result == -1){
            std::cout << "La pelicula no se encuentra en la base de datos" << endl;
            return 0;
        } else {
            result = linearSearch(UnOrderedMovies, size, pelicula_search);
            peliculas[result].status = "Ocupada";
        }
        

        std::cout << "id del cliente: ";
        std::cin >> id_cliente;
        outdata << id_cliente;

        std::cout << "Ingrese el nombre del cliente: ";
        std::cin >> nombre_cliente;
        outdata << " " << nombre_cliente;
        peliculas[result].rent_to = nombre_cliente;


        std::cout << "Ingrese la fecha a rentar: " << endl;
        std::cout << "El formate a ingresar es." << endl;
        std::cout << "YEAR-MONTH-DAY" << endl;
        std::cout << "xxxx-xx-xx" << endl;
        std::cin >> fecha_rent;
        outdata << " " << fecha_rent;
        peliculas[result].rent_on = fecha_rent;

        std::cout << "Los datos han sido guardados.\n";
        std::cout << endl;
            
        break;
        
    case 6: //buscar por nombre o por id a un cliente
        std::cout << "Busqueda de clientes" << endl;    
        std::cout << "1.-Buscar por nombre" << endl;
        std::cout << "2.-Buscar por id" << endl;
        std::cin >> name_id;
        while (name_id !=1 && name_id != 2)
        {
            std::cout << "ERROR - VALOR INVALIDO" << endl;
            std::cout << "Ingrese un valor valido" << endl;
            std::cout << "1 para buscar por nombre" << endl;
            std::cout << "2 para buscar por id" << endl;
            std::cin >> name_id;
        }
        if (name_id == 1)
        {
            std::cout << "Ingrese el nombre a buscar" << endl;
            std::cin.get();
            std::getline(std::cin, nombre_cliente);
            for (int i = 0; i < nline; i++)
            {
                if(nombre_cliente == peliculas[i].rent_to){
                    std::cout << "Usuario Encontrado" << endl;
                    std::cout << "El usuario posee la pelicula: " << peliculas[i].movie << endl;
                }
            }
            
        }
        else
        {
            std::cout << "Ingrese el id a buscar" << endl;
            std::cin.get();
            std::getline(std::cin, id_cliente);
            for (int i = 0; i < nline; i++)
            {
                if(id_cliente == peliculas[i].rent_to){
                    std::cout << "Usuario Encontrado" << endl;
                    std::cout << "El usuario posee la pelicula: " << peliculas[i].movie << endl;
                }
            }
        }
        
        break;

    case 7:
       eliminar_pelis();

      break;    
    default:
        std::cout << "ERROR - VALOR INVALIDO" << endl;
        return 0;
        break;
    }

    infile.close();
    outdata.close();
}

template <typename T>
int partition(T arr[], int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(arr[i]<arr[pivot]){
			swap(arr[i],arr[j]);
			++j;
		}
	}
	swap(arr[j],arr[pivot]);
	return j;
	
}

// template function to perform quick sort on array arr
template <typename T>
void quickSort(T arr[], int start, int end ){

	if(start<end){
		int p = partition(arr,start,end);
        quickSort(arr,start,p-1);
        quickSort(arr,p+1,end);
	}
	
}

template<typename T>
int binarySearch(T arr[],int n,T x)
{
	int start = 0;
	int end = n-1;
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(arr[mid]==x)	
			return mid;
		else if(arr[mid]<x)	
			start = mid + 1;
		else	
			end = mid - 1;
	}
	return -1;
}

template <typename T>
int linearSearch(T arr[], int n, T x) {

	for (int i = 0; i < n; ++i) {

		if (arr[i] == x)
			return i;

	}

	return -1;

}

void agg_nuevas_pelis(){
int cont_peli_agg = 1000;
int resp = 0;

ofstream infile;

infile.open("../datos/movies.csv", ios:: app);
        infile.seekp(1001);
        string agg;

        do{
         system("cls");
         
         cont_peli_agg = cont_peli_agg + 1;

         std::cout << "*** Vamos a agregar nuevas peliculas al menu ***" << endl;
         std::cout << " Ing. El nombre de la pelicula: " << endl;
         std::cin.get();
         getline (std::cin,agg);

         peliculas[cont_peli_agg].id = cont_peli_agg;
         peliculas[cont_peli_agg].movie = agg ;
        
         std::cout << " Ing. El genero: "<< endl;
         getline (std::cin,agg);

         peliculas[cont_peli_agg].genders = agg;

         std::cout << " Ing. la duracion: " << endl;
         std::cin>>agg;

         peliculas[cont_peli_agg].duration = stoi(agg);

         std::cout << " Ing. El nombre del director: " << endl;
         std::cin.get();
         getline (std::cin,agg);

         peliculas[cont_peli_agg].director = agg;

         std::cout << " Ing. La fecha de lanzamiento (escribalo con espacios; primero el dia,mes y year): " << endl;
         std::cin.get();
         getline (std::cin,agg);

         peliculas[cont_peli_agg].release_on = agg;

         std::cout << "Cual es su precio??:" << endl;
         cin >> agg;

         peliculas[cont_peli_agg].price = stof(agg);

         peliculas[cont_peli_agg].rent_to = "Nadie ";
         peliculas[cont_peli_agg].status = "Disponible";


         infile << peliculas[cont_peli_agg].id << ";" << peliculas[cont_peli_agg].movie << ";"
          << peliculas[cont_peli_agg].genders <<";" << peliculas[cont_peli_agg].duration <<";" 
          << peliculas[cont_peli_agg].director << ";" << peliculas[cont_peli_agg].price <<";" 
          << peliculas[cont_peli_agg].release_on + ";" << peliculas[cont_peli_agg].rent_to << ";" 
          << peliculas[cont_peli_agg].rent_on << ";" << peliculas[cont_peli_agg].status << endl;

          cout << peliculas[cont_peli_agg].id << ";" << peliculas[cont_peli_agg].movie + ";"
          << peliculas[cont_peli_agg].genders +";" << peliculas[cont_peli_agg].duration <<";" 
          << peliculas[cont_peli_agg].director + ";" << peliculas[cont_peli_agg].price <<";" 
          << peliculas[cont_peli_agg].release_on + ";" << peliculas[cont_peli_agg].rent_to + ";" 
          << peliculas[cont_peli_agg].rent_on << ";" << peliculas[cont_peli_agg].status << endl;

         std::cout << " Quieres agregar otras??:" << endl;
         std::cout << " 1 para si y 2 para no" << endl;

          std::cin.get();
         do{
             std::cin >> resp;

             if( resp != 1  && resp != 2){
                std::cout << "Error...." << endl;
                std::cout << "No pudo ser procesado por favor ingrese un numero valido" << endl;

             }else{
                std::cout << "Procesando.." << endl;
                system("cls");
             }
         }while (resp != 1 && resp != 2);
         
        }while(resp != 2);
}

void eliminar_pelis(){
    int resp = 0;
    bool existe = false ;
    ofstream infile;

    infile.open("../datos/movies.csv", ios:: out);

    std::cout << "Vamos a eliminar una pelicula " << endl;
    std::cout << "Ingrese el id de la pelicula a borrar" << endl;
    std::cin >> resp;

    for(int i = 0; i < 1003; i++){

        if(peliculas[i].id == resp){

            existe = true;
        }else if (existe == false ){
          infile << peliculas[i].id << ";" << peliculas[i].movie << ";"
          << peliculas[i].genders <<";" << peliculas[i].duration <<";" 
          << peliculas[i].director << ";" << peliculas[i].price <<";" 
          << peliculas[i].release_on + ";" << peliculas[i].rent_to << ";" 
          << peliculas[i].rent_on << ";" << peliculas[i].status << endl;
            
        }else{
            //esto es para cuando cuando ya encuentre la pelicula, reste una posicion a los ID
            infile << peliculas[i - 1].id << ";" << peliculas[i].movie << ";"
            << peliculas[i].genders <<";" << peliculas[i].duration <<";" 
            << peliculas[i].director << ";" << peliculas[i].price <<";" 
            << peliculas[i].release_on + ";" << peliculas[i].rent_to << ";" 
            << peliculas[i].rent_on << ";" << peliculas[i].status << endl;

        }
    
    
    }



}
