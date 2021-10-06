def subscribers(netflix,hotstar):
    return len(set(netflix).union(set(hotstar)))
