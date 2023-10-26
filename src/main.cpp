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
    string id;
    string movie;
    string genders;
    string duration;
    string director;
    string release_on;
    string rent_to;
    string rent_on;
    string status;
}peliculas[2000];

void imprimir_bin(string);

fstream outdata("../datos/client_info.bin", fstream::in | fstream::out | fstream::binary);
ifstream infile("../datos/movies.csv", fstream::in);



int main(){
    int resp = 0;
    int count = 0;
    int nline = 0;
    string line, word;
    int filtro = 0; 
    int tipo_filtro_genero = 0;
    int tipo_filtro_director = 0;
    int tipo_filtro_precio = 0; 
    string gender_search = " "; 
    string director_search =  " ";
    string fecha = 0;
    string nombre_cliente = " ";
    string fecha_rent = " ";
    string pelicula_rented = " ";
    string id_cliente = " ";  

    int name_id = 0;
    
    
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
                peliculas[nline].id = word;
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

    cout << "|| BIENVENIDO ||" << endl;
    cout << "4.-Filtrado" << endl;
    cout << "5.-Rentar" << endl;
    cout << "6.-Busqueda de cliente" << endl;

    switch (resp)
    {
    case 4:  // Filtrado
        cout << "Elige el tipo de filtro" << endl;
        cout << "1.- genero" << endl;
        cout << "2.- duracion" << endl;        
        cout << "3.- director" << endl;
        cout << "4.- fecha de lanzamiento" << endl;
        cout << "5.- precio" << endl;

        switch (filtro)
        {
        case 1:
            cout << "A elegido el filtro por genero" << endl;
            cout << "Ingrese 1 para que sea por orden alfabetico" << endl;
            cout << "Ingrese 2 para elegir el genero que quiera buscar" << endl;
            cin >> tipo_filtro_genero;

            while (tipo_filtro_genero != 1 && tipo_filtro_genero != 2)
            {
                cout << "ERROR - VALOR INVALIDO" << endl;
                cout << "Ingrese un valor valido" << endl;
                cout << "1 para filtrar por orden alfabetico" << endl;
                cout << "2 para filtrar por genero especifico" << endl;
                cin >> tipo_filtro_genero;
            }
            if (tipo_filtro_genero == 1)
            {
                //se imprime las peliculas en orden alfabetico

            }
            else 
            {
                cout << "Ingrese el genero que quiera buscar" << endl;
                cin >> gender_search;
                //buscamos los generos

            }
            break;
        case 2:
            cout << "A elegido el filtro por duracion" << endl;
            cout << "A continuacion apareceran las peliculas de mayor a menor duracion" << endl;
            break;
        case 3:
            cout << "A elegido el filtro por director" <<endl;
            cout << "Presione 1 si quiere buscar por orden alfabetico" << endl;
            cout << "Presione 2 si quiere buscar directores especificos" << endl;
            cin >> tipo_filtro_director;

            while (tipo_filtro_director != 1 && tipo_filtro_director != 2)
            {
                cout << "ERROR - VALOR INVALIDO" << endl;
                cout << "Ingrese un valor valido" << endl;
                cout << "1 para filtrar por orden alfabetico" << endl;
                cout << "2 para filtrar por director especifico" << endl;
                cin >> tipo_filtro_director;
            }

            if (tipo_filtro_director == 1)
            {
                //se imprimen los directores en orden alfabetico
            } 
            else
            {
                cout << "Ingrese el director que quiere buscar" << endl;
                cin >> director_search;
                //se buscan las peliculas del director


            }
            break;
        case 4:
            cout << "Ha elegido el filtro por fecha de lanzamiento" << endl;
            cout << "Ingrese la fecha con '-' de por medio " << endl;
            cout << "Ejemplo xxxx-xx-xx" << endl;
            cout << "year-month-day" << endl;
            cin >> fecha;

            
            // quizas tambien elegir 


            break;
        case 5:
            cout << "Ha elegido el filtro por precio" << endl;
            cout << "Presione 1 si quiere de orden ascendente" << endl;
            cout << "Presione 2 si quiere de orden descendiente" << endl;
            cout << "Presione 3 si quiere buscar un precio especifico" << endl;
            cin >> tipo_filtro_precio;

            while (tipo_filtro_precio != 1 && tipo_filtro_precio != 2 && tipo_filtro_precio != 3)
            {
                cout << "ERROR - VALOR INVALIDO" << endl;
                cout << "Ingrese un valor valido" << endl;
                cout << "1 para filtrar por orden ascendiente" << endl;
                cout << "2 para filtrar por genero descendiente" << endl;
                cout << "3 para filtrar por precio especifico" << endl;
                cin >> tipo_filtro_precio;
            }

            if (tipo_filtro_precio == 1)
            {
                /* code */
            }
            else if (tipo_filtro_precio == 2)
            {
                /* code */
            }
            else
            {
                /* code */
            }
            
            break;        
        default:
            cout << "ERROR - VALOR INVALIDO" << endl;
            return 0;
            break;
        }
        break;
    case 5: // Rentar
        cout << "Ingrese el nombre del cliente" << endl;
        cin >> nombre_cliente;
        imprimir_bin(nombre_cliente);
        cout << "Ingrese la pelicula a rentar" << endl;
        cin >> pelicula_rented;
        imprimir_bin(pelicula_rented);
        cout << "Ingrese la fecha a rentar" << endl;
        cin >> fecha_rent;
        imprimir_bin(fecha_rent);
        cout << "id del cliente" << endl;
        cin >> id_cliente;
        imprimir_bin(id_cliente);

        break;


        
    case 6: //buscar por nombre o por id a un cliente
        cout << "1.-Buscar por nombre" << endl;
        cout << "2.-Buscar por id" << endl;
        cin >> name_id;
        while (name_id !=1 && name_id != 2)
        {
            cout << "ERROR - VALOR INVALIDO" << endl;
            cout << "Ingrese un valor valido" << endl;
            cout << "1 para buscar por nombre" << endl;
            cout << "2 para buscar por id" << endl;
            cin >> name_id;
        }
        if (name_id == 1)
        {
            cout << "Ingrese el nombre a buscar" << endl;
        }
        else
        {
            cout << "Ingrese el id a buscar" << endl;
        }
        
        break;
    default:
        cout << "ERROR - VALOR INVALIDO" << endl;
        return 0;
        break;
    }

}

void imprimir_bin(string oracion){

    do {
        outdata.write((char*) &oracion, sizeof(char));
    } while(oracion.length() < 100);     
}