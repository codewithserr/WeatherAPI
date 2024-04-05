#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include "API_struct.h"

// Clase para parsear el JSON y almacenar los datos del clima
class weather
{

private:
    // Definimos los atributos que necesitamos para definir el tiempo en una localizacion
    double latitude;
    double longitude;
    double altitude;
    std::string city;

    //Estructura con los atributos propios que vendrán de la API
    Current currentData;
public:

    weather(double latitude_, double longitude_, double altitude_, std::string city_) : 
            latitude(latitude_), longitude(longitude_), altitude(altitude_), city(city_){};

    void get_API_current_data(const std::string&); //Funcion para recoger los datos devueltos por la API 
    Current get_current_data(){return currentData;};

};

#endif