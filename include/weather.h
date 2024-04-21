#ifndef WEATHER_H
#define WEATHER_H

// System Includes
#include <iostream>
#include <cstring>
#include <time.h>

// App Includes
#include "API_struct.h"
#include "APIclient.h"
#include "json.hpp"

using json = nlohmann::json;


////////////////////////////////////////////////////
//                Weather Class                  ///
////////////////////////////////////////////////////

/*
    This class is used for Manage the application by itself.
    - Define the location for retrieving data from API
    - Manage what APIs needs to be called
*/

class Weather
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

    Weather(std::string city_) : city(city_){};

    // METHODOS FOR STORING APIs DATA
    void get_API_location_Data(const std::string&);//Store data retrieved from Geolocation API
    void get_API_current_data(const std::string&); //Store data retrieved from Weather API

    void validate_JSON_data(json); //Function for validating the structure of the received JSON.

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
    void APIsManagement(Weather, std::string _API_KEY);

    // METHOD FOR CONVERTING FROM UNIX UTC TIME TO HUMAN READABLE TIMESTAMP
    std::string convertTime(time_t datetime);

    // METHOD FOR CONVERTING TEMPERATURE UNITS
    double convertTemp(double temp, std::string UNIT);

};

#endif