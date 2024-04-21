#include <iostream>
#include <string>
#include <tuple>
#include <vector>

struct Location
{
    std::string name;
    double latitude;
    double longitude;
    double altitude;
};

//Auxiliary structs of Current response
struct weather
{
    std::string description;
    std::string icon;
    int id;
    std::string main;
};

struct minutely
{
        int dt; //1684929540,
        int precipitation; //0
};

struct hourly
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
    weather weatherHourly;
    double pop; //0.15
};

struct tempDaily
{
    double day; //299.03,
    double min ; //290.69,
    double max ; //300.35,
    double night ; //291.45,
    double eve ; //297.51,
    double morn ; //292.55
};

struct feels_like_Daily
{
    double day; //299.03,
    double night ; //291.45,
    double eve ; //297.51,
    double morn ; //292.55
};

struct daily
{
    int dt; //"dt":1684929490,
    int sunrise;// "sunrise":1684926645,
    int sunset;//"sunset":1684977332,
    int moonrise; //   "moonrise":1684941060,
    int moonset; // "moonset":1684905480,
    int moon_phase;// "moon_phase":0.16,
    std::string summary; //:"Expect a day of partly cloudy with rain",
    tempDaily _tempDaily;
    feels_like_Daily _feels_like_Daily;
    int pressure; //"pressure":1014,
    int humidity;//"humidity":89,
    double dew_point; //"dew_point":290.69,
    double wind_speed;//"wind_speed":3.13,
    int wind_deg;//"wind_deg":93,
    double wind_gust;//"wind_gust":6.71,
    weather weatherDaily;
    int clouds; 
    double pop;  //       "pop":0.47,
    double rain; //"rain":0.15,
    double uvi;// "uvi":9.23
};


/////////////////////////////////////
//Current weather data API response//
/////////////////////////////////////
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
    weather weatherData;
    minutely minutelyData;
    hourly hourlyData;
    daily dailyData;
};

