#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <cstring>
#include "API_struct.h"
#include "APIclient.h"

////////////////////////////////////////////////////
//                Weather Class                  ///
////////////////////////////////////////////////////

/*
    This class is used for Manage the application by itself.
    - Define the location for retrieving data from API
    - Manage what APIs needs to be called
*/

class weather
{

private:
    // Location attributes
    double latitude, longitude, altitude;
    std::string city;
  
    // Structure with to fill with weather API data
    Current currentData;

    // Structure with to fill with geolocalization API data
    Location locationData;

public:

    weather(std::string city_) : city(city_){};

    void get_API_location_Data(const std::string&);//Store data retrieved from Geolocation API
    void get_API_current_data(const std::string&); //Store data retrieved from Weather API
    Current get_current_data(){return currentData;} //Returns weather API data in a struct
    Location get_location_data(){return locationData;} //Returns geo API data in a struct

    //GET METHODS
    double get_Latitude(){return latitude;}
    double get_Longitude(){return longitude;}
    double get_Altitude(){return altitude;}
    std::string get_City(){return city;}
    std::string get_LatitudeString(double lat);
    std::string get_LongitudeString(double lon);

    //SET METHODS
    void set_latitude(double lat){latitude = lat;}
    void set_longitude(double lon){longitude = lon;}
    void set_altitude(double alt){altitude = alt;}

    //MANAGE APIs
    void APIsManagement(weather, std::string _API_KEY);


    
};

#endif