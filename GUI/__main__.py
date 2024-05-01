import subprocess
import threading
import tkinter as tk

def run_cpp_app(city, text_widget):
    #Call the C++ application and give it an argument
    subprocess.run(["./weather_app", city])

    # Clean the box after run the app
    text_widget.delete("1.0", tk.END)  

    # Read the content of the received report file, and show it on a text box.
    with open("reports/text/report.txt", "r") as file:
        report = file.read()
        text_widget.insert(tk.END, report)

def on_button_click(entry_widget, text_widget):

    #Run CPP application in another trhead, with given arguments
    city = entry_widget.get()
    cpp_thread = threading.Thread(target=run_cpp_app, args=(city, text_widget))
    cpp_thread.start()


def run_gui():
    root = tk.Tk()

    # Put a tittle onto the window
    root.title("Weather App")

    # Create a label and a text box
    label = tk.Label(root, text="Introduce the City:")
    label.pack()

    entry = tk.Entry(root)
    entry.pack()

    # Create a text box for showing the report results
    text = tk.Text(root)
    text.pack()

    # Create a button for initalizing C++ application
    button = tk.Button(root, text="Receive data", command=lambda: on_button_click(entry, text))
    button.pack()

    # Init the GUI main loop
    root.mainloop()

if __name__ == "__main__":
    # Initizalize the GUI in the main thread
    run_gui()