extern char stack[512];
extern int top;

int is_empty() {
	return top == -1;
}
