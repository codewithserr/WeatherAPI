/*
    Fichero donde se incluiran las funciones que pueden ser utilies para 
    la funcionalidad de la aplicación.
*/

#include <iostream>
#include <fstream>
#include <string>

// Función que lee la API Key de un fichero aparte
std::string readAPIkeyFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::string APIkey;

    if(file.is_open())
    {
        getline(file, APIkey);
        file.close();
    }
    else
    {
        std::cerr << "Error al abrir el archivo " << filename << std::endl;
    }

    return APIkey;
}