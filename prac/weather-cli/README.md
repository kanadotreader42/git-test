# WeatherCLI

A command-line Python application for looking up weather information for a city.

Weather data is retrieved from the Open-Meteo services:
- Geocoding API: finds a location from a city name.
- Forecast API: retrieves weather data for the selected location.

## Requirements

- Python 3 installed and available from your terminal.
- An internet connection.

The project uses Python's standard library for its HTTP requests and command-line handling; no third-party packages are currently listed as required.

## Run

Open a terminal in this folder and check the available command-line options:

```powershell
python weather.py --help
```

Then run the program using the options shown by its help output. For example, if the program supports running without arguments:

```powershell
python weather.py
```

## APIs

- https://open-meteo.com/

Open-Meteo's geocoding and forecast APIs are used by the application.
