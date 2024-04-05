// How to make Weather App using Openweathermap API | Javascript - Responsive Website
// https://youtu.be/6trGQWzg2AI?si=Kb3GmmcHD8dZnstd
// This video is donde with html, CSS and JS. We will use C++ an python in this project

/*The objetctive of this project is to make an application in C++ and Python which takes data 
from Openweathermap API and presents it to the user*/
#include <iostream>
#include <cstring>
#include "include/weather.h"

int main()
{
/*
    Lo que está actualmente escrito en este main es una prueba para corroborar que se parsea
    el fichero JSON que llegue, se introducen los datos en una estructura, y se imprime
    por pantalla
*/

    //Creamos el objeto de la clase Weather, y lo inicializamos para pruebas
    weather weatherCity(10., 10., 0., "Madrid");
    
    // Ejemplo de JSON de respuesta de la API
    std::string jsonResponse = R"({"current": {"dt": 25}, "weather": [{"description": "Cielo despejado"}]})";

    // Parsear el JSON y almacenar los datos en la estructura We
    weatherCity.get_API_current_data(jsonResponse);

    //Copiamos los datos de la estructura que ha venido de la API a una estructura local
    Current currentData_;
    currentData_ = weatherCity.get_current_data();
    
    // Imprimir los datos del clima
    std::cout << "Dt: " <<  currentData_.dt << std::endl;

    return 0;
}