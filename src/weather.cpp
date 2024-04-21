#include <fstream>


#include "../include/weather.h"
#include "../include/json.hpp"

using json = nlohmann::json;

void Weather::get_API_location_Data(const std::string& jsonDATA)
{
    json data = json::parse(jsonDATA);

    //Send the JSON data to a separated file. Open file for writing JSON.
    std::ofstream outputFile("JSON/LOCATIONresponse.json");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output JSON file." << std::endl;
    }

    // Put JSON object in the file and close the file
    outputFile << std::setw(4) << data << std::endl;
    outputFile.close();

    try 
    {
        // Obtener los valores relevantes del JSON y asignarlos a la estructura WeatherData
        locationData.name = data[0]["name"];
        locationData.latitude = data[0]["lat"];
        locationData.longitude = data[0]["lon"];
        locationData.altitude = data[0]["alt"];
    } catch (const std::exception &e) 
    {
        std::cerr << "Error al parsear el JSON respuesta GEOLOCALIZACIón: " << e.what() << std::endl;
    }

};


void Weather::get_API_current_data(const std::string& jsonDATA)
{
    json data = json::parse(jsonDATA);

   try 
   {

        //Send the JSON data to a separated file. Open file for writing JSON.
        std::ofstream outputFile("JSON/APIresponse.json");
        if (!outputFile.is_open()) {
            std::cerr << "Error opening output JSON file." << std::endl;
        }

        // Put JSON object in the file and close the file
        outputFile << std::setw(4) << data << std::endl;
        outputFile.close();

        // Fill the structure with data from JSON
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

        // Acceder a la sección "weather" dentro de "current"
        currentData.weatherData.description = data["current"]["weather"][0]["description"];
        currentData.weatherData.icon = data["current"]["weather"][0]["icon"];
        currentData.weatherData.id = data["current"]["weather"][0]["id"];
        currentData.weatherData.main = data["current"]["weather"][0]["main"];

        


        // Take data from JSON and save it each struct
       /* for(auto& [key, value] : data["current"].items())
        {
            if (key == "dt") currentData.dt = value;
            else if (key == "sunrise") currentData.sunrise = value;
            else if (key == "sunset") currentData.sunset = value;
            else if (key == "temp") currentData.temp = value;
            else if (key == "feels_like") currentData.feels_like = value;
            else if (key == "pressure") currentData.pressure = value;
            else if (key == "humidity") currentData.humidity = value;
            else if (key == "dew_point") currentData.dew_point = value;
            else if (key == "uvi") currentData.uvi = value;
            else if (key == "clouds") currentData.clouds = value;
            else if (key == "visibility") currentData.visibility = value;
            else if (key == "wind_speed") currentData.wind_speed = value;
            else if (key == "wind_deg") currentData.wind_deg = value;
            else if (key == "wind_gust") currentData.wind_gust = value;
            else if (key == "weather") 
            {
                for(auto& [subKey, subValue] : value.items())
                {
                    if(subKey == "id") currentData.weatherData.id = subValue;
                    if(subKey == "main") currentData.weatherData.main = subValue;
                    if(subKey == "clouds") currentData.weatherData.clouds = subValue;
                    if(subKey == "icon") currentData.weatherData.icon = subValue;
                }
            }
            else if (key == "minutely") 
            {
                for(auto& [subKey, subValue] : value.items())
                {
                    if(subKey == "dt") currentData.minutelyData.dt = value;
                    else if(subKey == "precipitation") currentData.minutelyData.precipitation = value;
                }
            }
            else if (key == "hourly") 
            {
                for(auto& [subKey, subValue] : value.items())
                {
                    if(subKey == "dt") currentData.hourlyData.dt = value;
                    else if(subKey == "sunrise") currentData.hourlyData.sunrise = value;
                    else if(subKey == "sunset") currentData.hourlyData.sunset = value;
                    else if(subKey == "temp") currentData.hourlyData.temp = value;
                    else if(subKey == "feels_like") currentData.hourlyData.feels_like = value;
                    else if(subKey == "pressure") currentData.hourlyData.pressure = value;
                    else if(subKey == "humidity") currentData.hourlyData.humidity = value;
                    else if(subKey == "dew_point") currentData.hourlyData.dew_point = value;
                    else if(subKey == "clouds") currentData.hourlyData.clouds = value;
                    else if(subKey == "visibility") currentData.hourlyData.visibility = value;
                    else if(subKey == "wind_speed") currentData.hourlyData.wind_speed = value;
                    else if(subKey == "wind_deg") currentData.hourlyData.wind_deg = value;
                    else if(subKey == "wind_deg") currentData.hourlyData.wind_deg = value;
                    else if (key == "weather") 
                    {
                        for(auto& [subKey, subValue] : value.items())
                        {
                            if(subKey == "id") currentData.hourlyData.weatherHourly.id = value;
                            if(subKey == "main") currentData.hourlyData.weatherHourly.main = value;
                            if(subKey == "clouds") currentData.hourlyData.weatherHourly.clouds = value;
                            if(subKey == "icon") currentData.hourlyData.weatherHourly.icon = value;
                        }
                    }   
                    if(subKey == "pop") currentData.hourlyData.pop = value;
                }
            }
            else if(key == "daily")
            {
                for(auto& [subKey, subValue] : value.items())
                {
                    if(subKey == "dt") currentData.dailyData.dt = value;
                    else if(subKey == "sunrise") currentData.dailyData.sunrise = value;
                    else if(subKey == "sunset") currentData.dailyData.sunset = value;
                    else if(subKey == "moonrise") currentData.dailyData.moonrise = value;
                    else if(subKey == "moonset") currentData.dailyData.moonset = value;
                    else if(subKey == "moon_phase") currentData.dailyData.moon_phase = value;
                    else if(subKey == "summary") currentData.dailyData.summary = value;
                    else if (subKey == "temp") 
                    {
                        for(auto& [subKey, subValue] : value.items())
                        {
                            if(subKey == "day") currentData.dailyData._tempDaily.day = value;
                            if(subKey == "min") currentData.dailyData._tempDaily.min = value;
                            if(subKey == "max") currentData.dailyData._tempDaily.max = value;
                            if(subKey == "night") currentData.dailyData._tempDaily.night = value;
                            if(subKey == "eve") currentData.dailyData._tempDaily.eve = value;
                            if(subKey == "morn") currentData.dailyData._tempDaily.morn = value;
                        }
                    }
                    else if (subKey == "feels_like") 
                    {
                        for(auto& [subKey, subValue] : value.items())
                        {
                            if(subKey == "day") currentData.dailyData._feels_like_Daily.day = value;
                            if(subKey == "night") currentData.dailyData._feels_like_Daily.night = value;
                            if(subKey == "eve") currentData.dailyData._feels_like_Daily.eve = value;
                            if(subKey == "morn") currentData.dailyData._feels_like_Daily.morn = value;
                        }
                    }  
                    else if(subKey == "pressure") currentData.dailyData.pressure = value;
                    else if(subKey == "humidity") currentData.dailyData.humidity = value;
                    else if(subKey == "dew_point") currentData.dailyData.dew_point = value;
                    else if(subKey == "wind_speed") currentData.dailyData.wind_speed = value;
                    else if(subKey == "wind_deg") currentData.dailyData.wind_deg = value;
                    else if(subKey == "wind_gust") currentData.dailyData.wind_gust = value;
                    else if (subKey == "weather") 
                    {
                        for(auto& [subKey, subValue] : value.items())
                        {
                            if(subKey == "id") currentData.dailyData.weatherDaily.id = value;
                            if(subKey == "main") currentData.dailyData.weatherDaily.main = value;
                            if(subKey == "clouds") currentData.dailyData.weatherDaily.clouds = value;
                            if(subKey == "icon") currentData.dailyData.weatherDaily.icon = value;
                        }
                    }
                    else if(subKey == "clouds") currentData.dailyData.clouds = value;
                    else if(subKey == "pop") currentData.dailyData.pop = value;
                    else if(subKey == "rain") currentData.dailyData.rain = value;
                    else if(subKey == "uvi") currentData.dailyData.uvi = value;   
                }
            }
        }*/
    
    } catch (const std::exception &e) 
    {
        std::cerr << "Error al parsear el JSON respuesta del tiempo: " << e.what() << std::endl;
    }

};


std::string Weather::get_LatitudeString(double lat)
{
    std::string _latitudeStr;

    // to_string(n) converts a double to a string
    _latitudeStr = std::to_string(lat);
    return _latitudeStr;
}

std::string Weather::get_LongitudeString(double lon)
{
    std::string _LongitudeStr;

    // to_string(n) converts a double to a string
    _LongitudeStr = std::to_string(lon);
    return _LongitudeStr;
}

////////////////////////////////////////////////////////////////////////////
//    Function for managing what API needs to be called from Openweather    //
////////////////////////////////////////////////////////////////////////////

void Weather::APIsManagement(Weather _weather, std::string _API_KEY)
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
    // Construimos la URL para la petición a la API que nos devolverá los datos.
    // De momento, excluimos todos los datos que no sean actuales
    std::string exclude = "minutely,hourly,daily,alerts";
    std::string URL_WEATHER = "https://api.openweathermap.org/data/3.0/onecall?lat=" + _weather.get_LatitudeString(_weather.get_Latitude()) + 
                      "&exclude=" + exclude +
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
    std::cout << "/n" << std::endl;
    std::cout << "Current UTC Time: " <<  convertTime(currentData_.dt) << std::endl;
    std::cout << "Sunrise Time: " <<  convertTime(currentData_.sunrise) << std::endl;
    std::cout << "Sunset Time: " <<  convertTime(currentData_.sunset) << std::endl;
    std::cout << "Temperature: " <<  convertTemp(currentData_.temp, "Deg") << " ºC" <<std::endl;
    std::cout << "Pressure: " <<  currentData_.pressure << " HPa" <<std::endl;
    std::cout << "Humidity: " <<  currentData_.humidity << " %" <<std::endl;
    std::cout << "Dew Point: " <<  convertTemp(currentData_.dew_point, "Deg") << " ºC" << std::endl;
    std::cout << "UVI Index: " <<  currentData_.uvi << std::endl;
    std::cout << "Clouds: " <<  currentData_.clouds <<  " %" <<std::endl;
    std::cout << "Visibility: " <<  currentData_.visibility << " m" <<std::endl;
    std::cout << "Wind Speed: " <<  currentData_.wind_speed << " m/s" <<std::endl;
    std::cout << "Wind Direction: " <<  currentData_.wind_deg << "º" <<std::endl;
}

std::string Weather::convertTime(time_t datetime)
{
    std::string time = ctime(&datetime);
    return time;
}

double Weather::convertTemp(double temp, std::string UNIT)
{
    int units; //Deg=1, F=2 

    if(UNIT == "Deg") 
        units = 1;
    else if (UNIT == "F")
         units = 2;
    else
        std::cout << "Invalid temperature units" << std::endl;
    
    switch (units)
    {
        case 1: // K -> Deg
            temp = temp - 273.15;
            break;
        case 2: // K -> F
            temp = temp - 273.15;
            break;

        default:
            temp = 1.8 * (temp - 273.15) + 32;
            break;
    }

    return temp;
}

