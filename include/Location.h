#include <iostream>

class Location
{
private:

    double latitude;
    double longitude;
    double altitude;
    std::string place;

public:

    Location(double lat, double lon, double alt, std::string pla) : 
                latitude(lat), longitude(lon), altitude(alt), place(pla){};

    ~Location();


};

