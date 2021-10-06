def shopping_list(groceries):
	items,prices=zip(*groceries)
	return list(items),list(prices)
