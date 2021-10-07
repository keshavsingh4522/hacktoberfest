import constants as keys
from telegram.ext import *
import responses as R
import requests, json, datetime

print("Bot is starting")


def start_command(update, context):
    update.message.reply_text('Yo, welcome to the Vaccine Tracker Kolkata Bot!')


def vaccine_command(update, context):
    district = '725'
    date = datetime.datetime.today()     # + datetime.timedelta(days=i)
    date = date.strftime("%d-%m-%Y")
    url = f'https://cdn-api.co-vin.in/api/v2/appointment/sessions/public/findByDistrict?district_id={district}&date={date}'
    browser_header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.76 Safari/537.36'}
    print(url)
    response = requests.get(url, headers=browser_header)
    print(response)
    json_data = response.json()
    final_text = ''
    if len(json_data['sessions']) == 0:
        print("\nSlots Not Available\n")
    else:
        for slots in json_data['sessions']:
            final_text = final_text + "\nName: " + str(slots['name']) + '\n' + "Available Capacity: " + str(
                slots['available_capacity']) + '\n' + "Min Age Limit: " + str(
                slots['min_age_limit']) + '\n' + "Vaccine: " + str(slots['vaccine']) + '\n'
            final_text = final_text + '----------------------------------------'
    update.message.reply_text(final_text)

def handle_message(update, context):
    text = str(update.message.text).lower()
    user = update.effective_user
    print(f"{user['username']}: {text}")
    response = R.sample_response(text)
    print(f'Bot: {response}')
    update.message.reply_text(response)


def error(update, context):
    print(f"Update {update} caused error {context.error}")


def main():
    updater = Updater(keys.API_KEY, use_context=True)
    dp = updater.dispatcher

    dp.add_handler(CommandHandler("start", start_command))
    # dp.add_handler(CommandHandler("help", help_command))
    dp.add_handler(CommandHandler("vaccine", vaccine_command))
    dp.add_handler(MessageHandler(Filters.text, handle_message))
    dp.add_error_handler(error)

    updater.start_polling()
    updater.idle()


main()
