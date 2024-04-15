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


    //Pedimos al usuario que introduzca manualmente la ciudad de la cual quiere obtener el tiempo
    std::string City;
    std::cout << "Introducir el nombre de la ciudad: " << std::endl;
    std::getline(std::cin, City);

    //Creamos el objeto de la clase Weather, y lo inicializamos por defecto 
    weather weatherCity(City);

    //Construimos la URL para la peticion a la API que nos devolverá la geolocalizacion
    std::string URL_GEO = "https://api.openweathermap.org/geo/1.0/direct?q=" + City + "&limit=1&appid=" + API_KEY;

    //Creamos el objeto de la clase API para realizar peticiones
    ApiClient geoAPI(API_KEY, URL_GEO);
    geoAPI.ApiHandler();

    // Guardo la respuesta de la API Geo en un string, y despues parseo el JSON y copio los datos de la API
    // en estructura local
    std::string geoResponse = geoAPI.get_ResponseData();
    weatherCity.get_API_location_Data(geoResponse);
    Location location = weatherCity.get_location_data();

    // Para la ciudad en cuestion, guardamos la respuesta de la API en su estructura
    weatherCity.set_latitude(location.latitude);
    weatherCity.set_longitude(location.longitude);
    weatherCity.set_altitude(location.altitude);

    //Construimos la URL para la petición a la API que nos devolverá los datos del
    std::string URL_WEATHER = "https://api.openweathermap.org/data/3.0/onecall?lat=" + weatherCity.get_LatitudeString(weatherCity.get_Latitude()) + 
                      "&lon=" + weatherCity.get_LongitudeString(weatherCity.get_Longitude()) + 
                      "&appid=" + API_KEY;

    //Creamos el objeto de la clase API para realizar peticiones
    ApiClient weatherAPI(API_KEY, URL_WEATHER);
    weatherAPI.ApiHandler();
    
    // Guardamos el JSON respuesta de la API en un string, parseo el JSON y copio los datos de la API en 
    // estructura local
    std::string jsonResponse = weatherAPI.get_ResponseData(); 
    weatherCity.get_API_current_data(jsonResponse);
    Current currentData_ = weatherCity.get_current_data();
    
    // Imprimir los datos del clima
    std::cout << "Dt: " <<  currentData_.dt << std::endl;

    return 0;
}