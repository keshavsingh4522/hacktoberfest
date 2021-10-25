#include <cstdio>
#include <cstdlib>

#define SIZE 100

int p[SIZE] = {0}, pi = 0;

void push(int);
int pop();

int solve(char [SIZE]);
int izracunaj(int, char, int);

int main(void) {
	char s[SIZE] = {0};
	scanf("%s", s);
	int r = solve(s);
	printf("%d\n", r);
	return EXIT_SUCCESS;
}

void push(int x) {
	p[pi] = x;
	pi++;
}

int pop() {
	pi--;
	return p[pi];
}

int solve(char s[SIZE]) {
	for (int i = SIZE; i >= 0; --i) {
		if (s[i] == 0) {
			continue;
		}
		if (s[i] >= '0' && s[i] <= '9') {
			int x = s[i] - '0';
			push(x);
		} else {
			int x = pop();
			int y = pop();
			char operacija = s[i];
			int z = izracunaj(x, operacija, y);
			push(z);
		}
	}
	return p[0];
}

int izracunaj(int x, char operacija, int y) {
	if (operacija == '+') {
		return x + y;
	} else if (operacija == '-') {
		return x - y;
	} else if (operacija == '*') {
		return x * y;
	} else {
		return x / y;
	}
}