#include <iostream>
#include <string>
#include <tuple>

struct Location
{
    double latitude;
    double longitude;
    double altitude;
};

//Current weather data API response
struct Current
{
    int dt; //"dt":1684929490,
    int sunrise;// "sunrise":1684926645,
    int sunset;//"sunset":1684977332,
    double temp;//"temp":292.55,
    double feels_like; //"feels_like":292.87,
    int pressure; //"pressure":1014,
    int humidity;//"humidity":89,
    double dew_point; //"dew_point":290.69,
    double uvi;//"uvi":0.16,
    int clouds;//"clouds":53,
    int visibility; //"visibility":10000,
    double wind_speed;//"wind_speed":3.13,
    int wind_deg;//"wind_deg":93,
    double wind_gust;//"wind_gust":6.71,
    struct weather
    {
        int id;
        std::string main;
        std::string clouds;
        std::string icon;
    };
};

//Minute forecast weather data API response
struct minutely
{
    int dt; //Time of the forecasted data, unix, UTC
    float precipitation; //Precipitation, mm/h. 
};