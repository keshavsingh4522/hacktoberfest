int BinarySearchIndexOfMinimumRotatedArray(int A[], int l, int r)
{
	int m;

	if( A[l] >= A[r] )
		return l;

	while( l <= r )
	{
		if( l == r )
			return l;

		m = l + (r-l)/2; // 'm' can fall in first pulse,

		if( A[m] < A[r] )
			r = m;
		else
			l = m+1;
	}

	return -1;
}

int BinarySearchIndexOfMinimumRotatedArray(int A[], int size)
{
	return BinarySearchIndexOfMinimumRotatedArray(A, 0, size-1);
}
