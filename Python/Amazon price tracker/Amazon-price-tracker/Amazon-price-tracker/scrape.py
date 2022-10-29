import requests
from bs4 import BeautifulSoup
import smtplib

URL='https://www.amazon.in/ASIAN-Sports-Walking-Training-Running/dp/B07FS84W9B?ref_=Oct_BSellerC_1983550031_3&pf_rd_p=fd10b272-e847-5a1f-9652-87095446274c&pf_rd_s=merchandised-search-6&pf_rd_t=101&pf_rd_i=1983550031&pf_rd_m=A1VBAL9TL5WCBF&pf_rd_r=GC2F9ECTRYDCD4QHAJFM&pf_rd_r=GC2F9ECTRYDCD4QHAJFM&pf_rd_p=fd10b272-e847-5a1f-9652-87095446274c'

headers={"User-Agent":'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.132 Safari/537.36'}

def check_price():
    page =requests.get(URL,headers=headers)

    soup =BeautifulSoup(page.content,'html.parser')

    title =soup.find(id="productTitle").get_text()
    price= soup.find(id="priceblock_ourprice").get_text()
    converted_price= float(price[2:5])

    if(converted_price< 400.0):
            send_mail()
    print(title.strip())
    print(converted_price)
    if(converted_price> 400.0):
        send_mail()


def send_mail():
    server = smtplib.SMTP('smtp.gmail.com',587)
    server.ehlo()
    server.starttls()
    server.ehlo()

    server.login('rishabhsp98@gmail.com','flpdhnrltaafjpiy')

    subject ='Price fell dowm!'
    body = 'Check out the link https://www.amazon.in/ASIAN-Sports-Walking-Training-Running/dp/B07FS84W9B?ref_=Oct_BSellerC_1983550031_3&pf_rd_p=fd10b272-e847-5a1f-9652-87095446274c&pf_rd_s=merchandised-search-6&pf_rd_t=101&pf_rd_i=1983550031&pf_rd_m=A1VBAL9TL5WCBF&pf_rd_r=GC2F9ECTRYDCD4QHAJFM&pf_rd_r=GC2F9ECTRYDCD4QHAJFM&pf_rd_p=fd10b272-e847-5a1f-9652-87095446274c'
    msg = f"Subject: {subject}\n\n{body}"

    server.sendmail(
        'rishabhsp98@gmail.com',
        'rish6501@gmail.com',
        msg
    )
    print('Hey Email has been SENT!!!')
    server.quit()


check_price()