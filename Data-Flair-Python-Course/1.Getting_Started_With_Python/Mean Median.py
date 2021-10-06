def mean_median(scores):
	mean=sum(scores)/len(scores)
	median=sorted(scores)[int(len(scores)/2)]
	if median>mean: return True
	return False
