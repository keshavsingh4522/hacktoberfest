def get_data(tesla, start_date, end_date):
    """
    Get data from Yahoo Finance
    symbol: stock symbol
    start_date: start date for data
    end_date: end date for data 
    """
    import pandas_datareader.data as web
    df = web.DataReader(tesla, "yahoo", start_date, end_date)
    return df
