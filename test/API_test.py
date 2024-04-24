import unittest
import subprocess
import requests

# This is a simple test which test the API connection method
class APIconnectionTest(unittest.TestCase):
    def test_APIConnection(self):

        #Get API KEY from the separated file
        with open("API_KEY", "r") as key:
            api_key = key.readline().strip()

        # OpenWeatherMap API URL
        api_url = "http://api.openweathermap.org/data/2.5/weather?q=Madrid&appid=" + api_key

        # Do a GET request to the API
        response = requests.get(api_url)

        # Verify if the API response is correct (code 200)
        self.assertEqual(response.status_code, 200)

        # Verificar si la respuesta contiene datos válidos del clima (por ejemplo, verificar si hay datos en el campo "main")
        weather_data = response.json()
        self.assertIn("weather", weather_data, "Test has been executed")

if __name__ == '__main__':
    unittest.main(verbosity=2)