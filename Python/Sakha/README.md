# Sakha
It is social network web application which uses flask as backend.

## How to run it locally

### Clone the project
```bash
$ git clone https://github.com/Rahulbaran/Sakha.git
```

### Create the virtual environment

```bash
$ python3 -m venv <virtual environment name>
```

### Install all the packages using requirements.text
```bash
$ pip install -r requirements.txt
```

### Set the flask app and environment
#### Windows
```bash
> set FLASK_APP=run
> set FLASK_ENV=development

```

#### Mac/Linux
```shell
$ export FLASK_APP=run
$ export FLASK_ENV=development
```

### Run the application
```bash
$ flask run
```
