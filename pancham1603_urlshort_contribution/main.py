from flask import Flask, request, render_template, flash, redirect
from pymongo import MongoClient
import requests

client = MongoClient('mongodb+srv://admin:admin@pancham.vxuje.mongodb.net/myFirstDatabase?retryWrites=true&w=majority')
db = client.urlshort
url_collection = db['urls']

app = Flask(__name__)
app.secret_key = 'subhogay'

@app.route('/', methods=['GET','POST'])
def create_url():
    return render_template('index.html')

@app.route('/create', methods=['POST', 'GET'])
def verify_url():
    if request.method == 'POST':
        data = request.form
        long_url = data['long_url']
        short_url = data['short_url']
        try:
            requests.get(long_url)
        except requests.ConnectionError:
            flash('The given parameter is not an active/working domain')
            return render_template('index.html')
        if not url_collection.find_one({'_id':short_url}):
            url_collection.insert_one({'_id':short_url, 'redirect':long_url})
            flash('URL created', 'success')
            link = f'http://localhost:5000/{short_url}'
            return render_template('index.html', link=link)
        else:
            flash('This short URL already exists', 'error')
            return render_template('index.html')

@app.route('/<short>')
def redirect_to_long(short):
    url_data = url_collection.find_one({'_id':short})
    print(url_data)
    if url_data:
        return redirect(url_data['redirect'])
    else:
        return "This short URL doesdoes not exist"


if __name__ == '__main__':
    app.run(debug=True)
