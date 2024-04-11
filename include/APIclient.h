/*
    Clase que implementa todo lo relacionado a las llamadas a la API.

    En este fichero cabe la excepción de que existan funcionalidades en
    los metodos, no solo prototipos, pues es interesante para que exista
    portabilidad de código.

*/

#include <iostream>
#include <curl/curl.h>

class ApiClient
{
    private:
    std::string API_KEY;
    std::string URL;

    // Función de escritura para recibir datos de la solicitud HTTP
    // Al declarar "write_callback" como una función estática privada dentro de la clase ApiClient,
    // puede ser utilizada dentro de la función ApiHandler sin problemas de alcance.
    static size_t write_callback(char *ptr, size_t size, size_t nmemb, std::string *data) 
    {
        data->append(ptr, size * nmemb);
        return size * nmemb;
    }
    
    public:
    //El constructor de la clase toma como parametros el API LEY y la URL de la API
    ApiClient(std::string API_KEY_, std::string URL_) : API_KEY(API_KEY_), URL(URL_){};

    //Funcion que retorna la URL
    std::string Get_URL() {return URL;}

    // Funcion que maneja todo lo relacionado con las llamadas a la API y 
    // recepción de los datos de respuesta

    void ApiHandler()
    {
        // Inicializar libcurl
        curl_global_init(CURL_GLOBAL_ALL);
        CURL* curl = curl_easy_init();

        if (curl) 
        {
            // Establecer la URL de la API
            curl_easy_setopt(curl, CURLOPT_URL, URL);

            // Establecer la función de escritura para manejar los datos recibidos
            std::string response_data;
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

};



    



