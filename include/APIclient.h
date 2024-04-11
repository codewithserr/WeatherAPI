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
    std::string response_data;

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
    void ApiHandler();

    //Funcion que devuelve la respuesta de la API
    std::string get_ResponseData(){return response_data;}

};



    



