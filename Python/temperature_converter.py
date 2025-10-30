"""
🌡️ Temperature Converter CLI Tool
---------------------------------
A simple Python script to convert temperatures between
Celsius, Fahrenheit, and Kelvin.

🎯 Author: Aditya Rana
🗓️ For: Hacktoberfest 2025
"""

def celsius_to_fahrenheit(c):
    """Convert Celsius to Fahrenheit."""
    return (c * 9/5) + 32

def fahrenheit_to_celsius(f):
    """Convert Fahrenheit to Celsius."""
    return (f - 32) * 5/9

def celsius_to_kelvin(c):
    """Convert Celsius to Kelvin."""
    return c + 273.15

def kelvin_to_celsius(k):
    """Convert Kelvin to Celsius."""
    return k - 273.15


def main():
    print("🌡️ Temperature Converter")
    print("---------------------------")
    print("1. Celsius → Fahrenheit")
    print("2. Fahrenheit → Celsius")
    print("3. Celsius → Kelvin")
    print("4. Kelvin → Celsius")

    choice = input("Choose an option (1–4): ")

    try:
        temp = float(input("Enter temperature value: "))
    except ValueError:
        print("❌ Invalid input! Please enter a numeric value.")
        return

    if choice == "1":
        print(f"{temp}°C = {celsius_to_fahrenheit(temp):.2f}°F")
    elif choice == "2":
        print(f"{temp}°F = {fahrenheit_to_celsius(temp):.2f}°C")
    elif choice == "3":
        print(f"{temp}°C = {celsius_to_kelvin(temp):.2f}K")
    elif choice == "4":
        print(f"{temp}K = {kelvin_to_celsius(temp):.2f}°C")
    else:
        print("❌ Invalid option selected!")


if __name__ == "__main__":
    main()
