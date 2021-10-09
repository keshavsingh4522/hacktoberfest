from selenium import webdriver

driver = webdriver.Chrome()
driver.get('https://web.whatsapp.com/')

name = input('Enter the name of user or group:')
msg = input('Enter the message:')
count = int(input('Enter the number of message:'))


input('-*-*press enter for automation to start-*-*')

user = driver.find_element_by_xpath('//span[@title = "{}"]'.format(name))
user.click()


msg_box = driver.find_element_by_class_name('_3FeAD _1PRhq')

for i in range(count):
   msg_box.send_keys(msg)
   button = driver.find_element_by_class_name('_3M-N-')
   button.click()

