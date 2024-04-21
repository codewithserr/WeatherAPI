// How to make Weather App using Openweathermap API | Javascript - Responsive Website
// https://youtu.be/6trGQWzg2AI?si=Kb3GmmcHD8dZnstd
// This video is donde with html, CSS and JS. We will use C++ an python in this project

/*The objetctive of this project is to make an application in C++ and Python which takes data 
from Openweathermap API and presents it to the user

*/
#include <iostream>
#include <cstring>
#include "include/weather.h"
#include "include/utils.h"

int main()
{

    //Read API KEY from separated file
    std::string API_KEY = readAPIkeyFromFile("API_KEY");

    //Asks the user the name of the location
    std::string City;
    std::cout << "Introducir el nombre de la ciudad: " << std::endl;
    std::getline(std::cin, City);

    //Class weather objecto for the input city
    Weather weatherCity(City);

    // Call APIs management function
    weatherCity.APIsManagement(weatherCity, API_KEY);

    return 0;
}