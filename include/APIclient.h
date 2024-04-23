/*
Class that implements everything related to API calls.
*/

#include <iostream>
#include <curl/curl.h>

class ApiClient
{
    private:
    std::string API_KEY;
    std::string URL;
    std::string response_data;

/**
 * Write function to receive data from the HTTP request. 
 * By declaring "write_callback" as a private static function inside the ApiClient class, 
 * it can be used inside the ApiHandler function without scope issues.
 * 
*/
    static size_t write_callback(char *ptr, size_t size, size_t nmemb, std::string *data) 
    {
        data->append(ptr, size * nmemb);
        return size * nmemb;
    }
    
    public:
    //The class constructor takes the API KEY and the API URL as parameters
    ApiClient(std::string API_KEY_, std::string URL_) : API_KEY(API_KEY_), URL(URL_){};

    // Method which returns the URL
    std::string Get_URL() {return URL;}

    
    //Method for handlign everything related with API calls and received data    
    void ApiHandler();

    //Method which retrieves API response
    std::string get_ResponseData(){return response_data;}

};



    



