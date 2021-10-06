def dog_age(human_age):
	assert(human_age>=0)
	return str((human_age)*10.5-((human_age-2)>0)*(human_age-2)*6.5)+' years'
