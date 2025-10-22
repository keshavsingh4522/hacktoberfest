# import os
from Sakha import app
# from Sakha.config import DevelopmentConfig, ProductionConfig


# env = os.getenv('ENV')

# if env == 'dev': app.config.from_object(DevelopmentConfig)
# elif env == 'prod': app.config.from_object(ProductionConfig)


if __name__=="__main__":
    app.run()