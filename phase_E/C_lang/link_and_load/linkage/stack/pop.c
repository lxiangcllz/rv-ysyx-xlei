extern char stack[512];
extern int top;

char pop() {
	return stack[top--];
}
