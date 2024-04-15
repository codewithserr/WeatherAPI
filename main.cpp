// How to make Weather App using Openweathermap API | Javascript - Responsive Website
// https://youtu.be/6trGQWzg2AI?si=Kb3GmmcHD8dZnstd
// This video is donde with html, CSS and JS. We will use C++ an python in this project

/*The objetctive of this project is to make an application in C++ and Python which takes data 
from Openweathermap API and presents it to the user

*/
#include <iostream>
#include <cstring>
#include "include/weather.h"
#include "include/APIclient.h"
#include "include/utils.h"

int main()
{
/*
    Lo que está actualmente escrito en este main es una prueba para corroborar que se parsea
    el fichero JSON que llegue, se introducen los datos en una estructura, y se imprime
    por pantalla.
*/
 
    //Leemos la API KEY del fichero separado.
    std::string API_KEY = readAPIkeyFromFile("API_KEY");
    
    //Creamos el objeto de la clase Weather, y lo inicializamos para pruebas
    weather weatherCity(40.416775, -3.703790, 600., "Madrid");

    //Construimos la URL para la petición a la API
    std::string URL = "https://api.openweathermap.org/data/3.0/onecall?lat=" + weatherCity.get_LatitudeString(weatherCity.get_Latitude()) + 
                      "&lon=" + weatherCity.get_LongitudeString(weatherCity.get_Longitude()) + 
                      "&appid=" + API_KEY;

    //Creamos el objeto de la clase API para realizar peticiones
    ApiClient weatherAPI(API_KEY, URL);
    weatherAPI.ApiHandler();
    
    // Guardamos el JSON respuesta de la API en un string
    std::string jsonResponse = weatherAPI.get_ResponseData(); 
 
    // Parsear el JSON y almacenar los datos en la estructura We
    weatherCity.get_API_current_data(jsonResponse);
 
    //Copiamos los datos de la estructura que ha venido de la API a una estructura local
    Current currentData_ = weatherCity.get_current_data();
    
    // Imprimir los datos del clima
    std::cout << "Dt: " <<  currentData_.dt << std::endl;

    return 0;
}