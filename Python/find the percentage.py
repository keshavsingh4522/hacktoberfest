if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = str(input())
if query_name in student_marks:
    l=list(student_marks[query_name])
    sum=0
    for i in range(len(l)):
     sum= l[i]+sum
print("{:.2f}".format(sum/3))
     
