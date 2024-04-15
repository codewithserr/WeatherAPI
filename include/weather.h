#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <cstring>
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
  
    //Estructura con los atributos propios que vendrán de la API del tiempo
    Current currentData;

    //Estructura con los atributos que vendrán de la API de geolocalización
    Location locationData;

public:

    weather(std::string city_) : city(city_){};

    void get_API_location_Data(const std::string&);//Funcion para recoger los datos devueltos por la API geolocalizacion
    void get_API_current_data(const std::string&); //Funcion para recoger los datos devueltos por la API del tiempo
    Current get_current_data(){return currentData;}
    Location get_location_data(){return locationData;}

    //Metodos GET para devolver valro atributos privados
    double get_Latitude(){return latitude;}
    double get_Longitude(){return longitude;}
    double get_Altitude(){return altitude;}
    std::string get_City(){return city;}
    std::string get_LatitudeString(double lat);
    std::string get_LongitudeString(double lon);

    //Metodos SET para setear valor a atributos
    void set_latitude(double lat){latitude = lat;}
    void set_longitude(double lon){longitude = lon;}
    void set_altitude(double alt){altitude = alt;}

    
};

#endif