def highest_salary(salaries):
	return [employee for employee,salary in salaries.items() if salary==max(salaries.values())][0]+' is the boss'
