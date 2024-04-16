#include "../include/weather.h"
#include "../include/json.hpp"

using json = nlohmann::json;

void weather::get_API_location_Data(const std::string& jsonDATA)
{
    try 
    {
        json data = json::parse(jsonDATA);

        // Obtener los valores relevantes del JSON y asignarlos a la estructura WeatherData
        locationData.name = data[0]["name"];
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
        currentData.sunrise = data["current"]["sunrise"];
        currentData.sunset = data["current"]["sunset"];
        currentData.temp = data["current"]["temp"];
        currentData.feels_like = data["current"]["feels_like"];
        currentData.pressure = data["current"]["pressure"];
        currentData.humidity = data["current"]["humidity"];
        currentData.dew_point = data["current"]["dew_point"];
        currentData.uvi = data["current"]["uvi"];
        currentData.clouds = data["current"]["clouds"];
        currentData.visibility = data["current"]["visibility"]; 
        currentData.wind_speed = data["current"]["wind_speed"];
        currentData.wind_deg = data["current"]["wind_deg"];
        currentData.wind_gust = data["current"]["wind_gust"];

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

////////////////////////////////////////////////////////////////////////////
//    Function for managing what API needs to be called from Openweather    //
////////////////////////////////////////////////////////////////////////////

void weather::APIsManagement(weather _weather, std::string _API_KEY)
{
    //////////////////////////////////////////////////////////////////////////////////////
    //                                  GEOLOCALIZATION API                             //
    //////////////////////////////////////////////////////////////////////////////////////

    //Construimos la URL para la peticion a la API que nos devolverá la geolocalizacion
    std::string URL_GEO = "https://api.openweathermap.org/geo/1.0/direct?q=" + _weather.city + 
                                                           "&limit=1&appid=" + _API_KEY;

    //Creamos el objeto de la clase API para realizar peticiones
    ApiClient geoAPI(_API_KEY, URL_GEO);
    geoAPI.ApiHandler();

    // Guardo la respuesta de la API Geo en un string, y despues parseo el JSON y copio los datos de la API
    // en estructura local
    std::string geoResponse = geoAPI.get_ResponseData();
    _weather.get_API_location_Data(geoResponse);
    Location location = _weather.get_location_data();

    // Para la ciudad en cuestion, guardamos la respuesta de la API en su estructura
    _weather.set_latitude(location.latitude);
    _weather.set_longitude(location.longitude);
    _weather.set_altitude(location.altitude);


    //////////////////////////////////////////////////////////////////////////////////////
    //                                  WEATHER API                                     //
    //////////////////////////////////////////////////////////////////////////////////////
    //Construimos la URL para la petición a la API que nos devolverá los datos del
    std::string URL_WEATHER = "https://api.openweathermap.org/data/3.0/onecall?lat=" + _weather.get_LatitudeString(_weather.get_Latitude()) + 
                      "&lon=" + _weather.get_LongitudeString(_weather.get_Longitude()) + 
                      "&appid=" +_API_KEY;

    //Creamos el objeto de la clase API para realizar peticiones
    ApiClient weatherAPI(_API_KEY, URL_WEATHER);
    weatherAPI.ApiHandler();
    
    // Guardamos el JSON respuesta de la API en un string, parseo el JSON y copio los datos de la API en 
    // estructura local
    std::string jsonResponse = weatherAPI.get_ResponseData(); 
    _weather.get_API_current_data(jsonResponse);
    Current currentData_ = _weather.get_current_data();
    
    // Print weather actual data
    std::cout << "Ciudad seleccionada: " << location.name << std::endl;
    std::cout << "Latitud: " << location.latitude << std::endl;
    std::cout << "Longitud: " << location.longitude << std::endl;
    std::cout << "Temperatura: " <<  currentData_.temp << std::endl;

}
