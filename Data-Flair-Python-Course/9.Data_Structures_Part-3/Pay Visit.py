def pay_visit(hour,weekday):
	return (not(weekday) and hour>=2 and hour<5) or (weekday and (hour<2 or hour>=5))
