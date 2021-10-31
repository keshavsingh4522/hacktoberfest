import sqlite3   #Module for connecting to the database (.db) file

'''
Database connection is achieved in 3 steps:
1. Connect to the database.
2. Make a cursor object to execute SQL commands using python
3. Query about data and commit changes if any using the .commit() function.
'''
class make_db:
	def __init__(self,dbname):         
		self.dbname = dbname
		self.mydb = sqlite3.connect(self.dbname + '.db')

		self.cursor = self.mydb.cursor()

		self.cursor.execute("""CREATE TABLE IF NOT EXISTS DATA(QUESTION TEXT,RESULT TEXT""")
										
										
	def store_values(self,QUESTION,RESPONSE):
		self.cursor.execute("INSERT INTO DATA VALUES(:qn , :response)",{'qn':QUESTION , 'response' : RESPONSE })
		self.mydb.commit()
class get_response(make_db):
	def __init__(self,Database,query):
		self.query = query
		self.Database = Database
		super().__init__(Database)

	def get_data(self):
		try:
			self.cursor.execute(f'SELECT *FROM DATA WHERE QUESTION = :qns',{'qns':self.query})	
			data = self.cursor.fetchall()
			print(data)
		except:
			return('No Such Query Available Available')	
if __name__ == '__main__':
	# db = make_db('Databs') # Enter Database name
	# db.store_values('Bye','Ok Bye') # Enter Question and response			
	query = get_response('Databs','Bye').get_data()		
