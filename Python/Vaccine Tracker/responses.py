import requests, json, datetime


def sample_response(input_text):
    user_message = str(input_text).lower()
    print(user_message)
    # new_data = user_message.split(':')
    district = user_message.lower()
    date = datetime.datetime.today()  # + datetime.timedelta(days=i)
    date = date.strftime("%d-%m-%Y")

    if (district=='kolkata'):
        url = f'https://cdn-api.co-vin.in/api/v2/appointment/sessions/public/findByDistrict?district_id=725&date={date}'
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

        return final_text
    elif district=='north 24 parganas':
        url = f'https://cdn-api.co-vin.in/api/v2/appointment/sessions/public/findByDistrict?district_id=730&date={date}'
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

        return final_text

    else:
        return "Invalid input"