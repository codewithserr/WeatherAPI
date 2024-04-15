#include "../include/weather.h"
#include "../include/json.hpp"

using json = nlohmann::json;

void weather::get_API_location_Data(const std::string& jsonDATA)
{
    try 
    {
        json data = json::parse(jsonDATA);

        // Obtener los valores relevantes del JSON y asignarlos a la estructura WeatherData
        locationData.latitude = data[0]["lat"];
        locationData.longitude = data[0]["lon"];
        locationData.altitude = data[0]["alt"];
    } catch (const std::exception& e) 
    {
        std::cerr << "Error al parsear el JSON: " << e.what() << std::endl;
    }

};

void weather::get_API_current_data(const std::string& jsonDATA)
{
    try 
    {
        json data = json::parse(jsonDATA);

        // Obtener los valores relevantes del JSON y asignarlos a la estructura WeatherData
        currentData.dt = data["current"]["dt"];
        currentData.sunrise = data["current"]["temp"];
        currentData.sunset = data["current"]["description"];
    } catch (const std::exception& e) 
    {
        std::cerr << "Error al parsear el JSON: " << e.what() << std::endl;
    }

};


std::string weather::get_LatitudeString(double lat)
{
    std::string _latitudeStr;

    // to_string(n) converts a double to a string
    _latitudeStr = std::to_string(lat);
    return _latitudeStr;
}

std::string weather::get_LongitudeString(double lon)
{
    std::string _LongitudeStr;

    // to_string(n) converts a double to a string
    _LongitudeStr = std::to_string(lon);
    return _LongitudeStr;
}
