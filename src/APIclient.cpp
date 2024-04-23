#include "../include/APIclient.h"

void ApiClient::ApiHandler()
{
    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();

    if (curl) 
    {
        // Set API URL
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

        //Set the write function to handle the received data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

        // HTTP GET request
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) 
        {
            std::cerr << "Error in HTTP request: " << curl_easy_strerror(res) << std::endl;
        } else 
        {
            std::cout << "Data correctly received" << std::endl;
            // Descomentar la linea si queremos mostrar datos de respuesta
            //std::cout << response_data << std::endl;
        }

        // clean and close libcurl
        curl_easy_cleanup(curl);
    } 
    else 
    {
        std::cerr << "Error initializing libcurl" << std::endl;
    }

    // Limpiamos y cerramos los recursos globales utilizados por la libreria curl
    curl_global_cleanup();
}