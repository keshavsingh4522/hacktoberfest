def make_pairs(group1,group2):
	group1,group2=group1.split(','),group2.split(',')
	for pair in zip(group1,group2):
		print("%s is with %s" %(pair[0],pair[1]))
