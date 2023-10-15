import time
import pyautogui

def send_message_with_delay(delay):
    time.sleep(delay)
    try:
        with open('message.txt', 'r') as text:
            for each_line in text:
                pyautogui.typewrite(each_line)
                pyautogui.press('enter')
                print(f"Sent: {each_line.strip()}")
    except FileNotFoundError:
        print("File 'message.txt' not found. Make sure the file exists in the current directory.")
    finally:
        text.close()

# Get user input for the delay
delay = int(input("Enter the delay time (in seconds): "))
send_message_with_delay(delay)
