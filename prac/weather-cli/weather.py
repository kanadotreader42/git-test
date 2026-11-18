"""
Terminal Weather Application

Fetches current weather and today's forecast
using the Open-Meteo API.
"""

import argparse
import json
import sys

from typing import Any
from urllib.error import HTTPError, URLError
from urllib.parse import urlencode
from urllib.request import Request, urlopen


GEOCODING_URL = "https://geocoding-api.open-meteo.com/v1/search"
FORECAST_URL = "https://api.open-meteo.com/v1/forecast"

WEATHER_CODES = {
    0: "Clear sky",
    1: "Mainly clear",
    2: "Partly cloudy",
    3: "Overcast",
    45: "Fog",
    48: "Depositing rime fog",
    51: "Light drizzle",
    53: "Moderate drizzle",
    55: "Dense drizzle",
    61: "Slight rain",
    63: "Moderate rain",
    65: "Heavy rain",
    71: "Slight snow",
    73: "Moderate snow",
    75: "Heavy snow",
    80: "Rain showers",
    81: "Moderate rain showers",
    82: "Heavy rain showers",
    95: "Thunderstorm",
    96: "Thunderstorm with hail",
    99: "Thunderstorm with heavy hail",
}


def get_json(url: str, params: dict[str, Any]) -> dict[str, Any]:

    request_url = f"{url}?{urlencode(params)}"

    request = Request(
        request_url,
        headers={"User-Agent": "TerminalWeather/2.0"}
    )

    try:

        with urlopen(request, timeout=15) as response:
            data = json.loads(response.read().decode("utf-8"))

    except HTTPError as error:
        raise RuntimeError(
            f"HTTP Error: {error.code}"
        ) from error

    except (URLError, TimeoutError) as error:
        raise RuntimeError(
            f"Connection failed: {error}"
        ) from error

    except (UnicodeDecodeError, json.JSONDecodeError) as error:
        raise RuntimeError(
            "Invalid API response."
        ) from error

    if not isinstance(data, dict):
        raise RuntimeError("Unexpected API response.")

    if data.get("error"):
        raise RuntimeError(
            data.get("reason", "API error.")
        )

    return data


def get_city(city: str) -> dict[str, Any]:

    result = get_json(
        GEOCODING_URL,
        {
            "name": city,
            "count": 5,
            "language": "en",
            "format": "json",
        }
    )

    locations = result.get("results", [])

    if not isinstance(locations, list) or not locations:
        raise RuntimeError(
            f"No location found for '{city}'."
        )

    if len(locations) == 1:
        return locations[0]

    print("\nMultiple locations found:\n")

    for index, location in enumerate(locations, start=1):

        name = location.get("name", "Unknown")
        region = location.get("admin1", "")
        country = location.get("country", "")

        print(
            f"{index}. {name}, {region}, {country}"
        )

    while True:

        try:

            choice = int(
                input("\nSelect a location: ")
            )

            if 1 <= choice <= len(locations):
                return locations[choice - 1]

            print("Invalid selection.")

        except ValueError:
            print("Enter a valid number.")


def get_weather(location: dict[str, Any]) -> dict[str, Any]:

    return get_json(
        FORECAST_URL,
        {
            "latitude": str(location["latitude"]),
            "longitude": str(location["longitude"]),
            "current": (
                "temperature_2m,"
                "relative_humidity_2m,"
                "apparent_temperature,"
                "precipitation,"
                "wind_speed_10m,"
                "weather_code"
            ),
            "daily": (
                "temperature_2m_max,"
                "temperature_2m_min,"
                "sunrise,"
                "sunset"
            ),
            "timezone": "auto",
        }
    )


def display_weather(
    location: dict[str, Any],
    forecast: dict[str, Any]
) -> None:

    current = forecast["current"]
    daily = forecast["daily"]

    code = int(current["weather_code"])

    place = ", ".join(
        part for part in (
            location.get("name"),
            location.get("admin1"),
            location.get("country")
        )
        if part
    )

    print("\n" + "=" * 40)
    print(f"       WEATHER REPORT")
    print("=" * 40)

    print(f"\nLocation: {place}")

    print(
        f"Updated: {current['time']}"
    )

    print(
        f"Timezone: {forecast['timezone']}"
    )

    print("\nCURRENT CONDITIONS")
    print("-" * 40)

    print(
        f"Weather: {WEATHER_CODES.get(code, 'Unknown')}"
    )

    print(
        f"Temperature: {current['temperature_2m']} °C"
    )

    print(
        f"Feels like: {current['apparent_temperature']} °C"
    )

    print(
        f"Humidity: {current['relative_humidity_2m']}%"
    )

    print(
        f"Wind speed: {current['wind_speed_10m']} km/h"
    )

    print(
        f"Precipitation: {current['precipitation']} mm"
    )

    print("\nTODAY'S FORECAST")
    print("-" * 40)

    print(
        f"Maximum: {daily['temperature_2m_max'][0]} °C"
    )

    print(
        f"Minimum: {daily['temperature_2m_min'][0]} °C"
    )

    print(
        f"Sunrise: {daily['sunrise'][0]}"
    )

    print(
        f"Sunset: {daily['sunset'][0]}"
    )

    print("\n" + "=" * 40)


def main() -> int:

    parser = argparse.ArgumentParser(
        description="Terminal Weather Application",
        epilog="Example: python weather.py Jodhpur"
    )

    parser.add_argument(
        "city",
        nargs="?",
        help="Name of the city"
    )

    args = parser.parse_args()

    city = (
        args.city or input("Enter city name: ")
    ).strip()

    if not city:
        parser.error("City name cannot be empty.")

    try:

        location = get_city(city)

        forecast = get_weather(location)

        display_weather(location, forecast)

    except (
        RuntimeError,
        KeyError,
        IndexError,
        TypeError,
        ValueError
    ) as error:

        print(
            f"\nError: {error}",
            file=sys.stderr
        )

        return 1

    return 0


if __name__ == "__main__":
    raise SystemExit(main())