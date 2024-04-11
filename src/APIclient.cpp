#include "../include/APIclient.h"

void ApiClient::ApiHandler()
{
    // Inicializar libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();

    if (curl) 
    {
        // Establecer la URL de la API
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

        // Establecer la función de escritura para manejar los datos recibidos
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

        // Realizar la solicitud HTTP GET
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) 
        {
            std::cerr << "Error en la solicitud HTTP: " << curl_easy_strerror(res) << std::endl;
        } else 
        {
            std::cout << "Datos recibidos:" << std::endl;
            std::cout << response_data << std::endl;
        }

        // Limpiar y cerrar libcurl
        curl_easy_cleanup(curl);
    } 
    else 
    {
        std::cerr << "Error al inicializar libcurl" << std::endl;
    }

    // Limpiamos y cerramos los recursos globales utilizados por la libreria curl
    curl_global_cleanup();
}