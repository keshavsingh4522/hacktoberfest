def rolls(names):
	roll_nums={sorted(names).index(name)+1:name.split(' ')[0] for name in sorted(names)}
	for roll in sorted(roll_nums): print (roll,roll_nums[roll])
