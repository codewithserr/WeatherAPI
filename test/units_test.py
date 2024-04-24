import unittest
import subprocess

# This is a simple test which test the units conversion from a methor written in C++
class UnitsConversionTest(unittest.TestCase):
    def test_UnitsConversion(self):
        # Define the input of the city for the program
        input_data = b"Madrid\n" 

        #Execute the C++ program and capture the Output
        input_temp = 300
        result = subprocess.run(['../weather_app', 'convertTemp', str(input_temp), 'Deg'], stdout=subprocess.PIPE)
        output = result.stdout.decode('utf-8') #Decode the output

        print(output)

        #Analize the output for verifying expected results
        expected_output = input_temp - 273.15

        # Round to the second decimal
        rounded_output = round(float(expected_output), 2)
        rounded_expected = round(expected_output, 2)

        # Verify the expected output
        self.assertEqual(rounded_output, rounded_expected)
    

if __name__ == '__main__':
    unittest.main(verbosity=2)