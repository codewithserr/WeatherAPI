#include "../include/weather.h"
#include "../include/json.hpp"

using json = nlohmann::json;

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
