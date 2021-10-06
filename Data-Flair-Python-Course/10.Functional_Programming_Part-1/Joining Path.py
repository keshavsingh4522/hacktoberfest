def join_path(*paths):
	return '/'.join([path.lstrip('/').rstrip('/') for path in paths])+'/'
