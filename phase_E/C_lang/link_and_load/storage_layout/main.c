#include <stdio.h>
#include <stdlib.h>

/*
 * 存储位置由「存储期 + 是否有初值 + 是否只读」决定。
 *
 * 会出现在可执行文件磁盘映像里：
 *   .rodata  只读，文件里有内容     nm 标记 R
 *   .data    已初始化可写，文件里有内容  nm 标记 D/d
 *   .bss     未初始化可写；文件里不占空间（NOBITS），加载时清零  nm 标记 B/b
 *
 * 只在进程运行时存在，不进 ELF 文件：
 *   栈   自动变量（含局部数组）
 *   堆   malloc
 *   寄存器  编译器分配，不能取地址
 */

const int const_global = 10;	/* .rodata */
int init_global = 20;		/* .data */
static int file_static = 30;	/* .data，内部链接 */
int uninit_global;		/* .bss */
static int uninit_static;	/* .bss，内部链接 */

int main(void)
{
	static int func_static = 40;	/* .data，函数静态，程序生命周期 */
	char stack_arr[] = "Hello";	/* 数组在栈；字面量可能在 .rodata */
	register int reg_var = 50;	/* 建议放寄存器；C 不允许 &reg_var */
	int stack_local = 60;		/* 栈 */
	const char *literal = "world";	/* 指针在栈，指向 .rodata */
	int *heap_buf = malloc(sizeof(int));

	if (heap_buf != NULL)
		*heap_buf = 70;

	puts("nm  name            addr                value");
	printf("R   const_global    %p  %d\n", (void *)&const_global, const_global);
	printf("D   init_global     %p  %d\n", (void *)&init_global, init_global);
	printf("d   file_static     %p  %d\n", (void *)&file_static, file_static);
	printf("d   func_static     %p  %d\n", (void *)&func_static, func_static);
	printf("B   uninit_global   %p  %d\n", (void *)&uninit_global, uninit_global);
	printf("b   uninit_static   %p  %d\n", (void *)&uninit_static, uninit_static);
	printf("R   literal         %p  %s\n", (void *)literal, literal);
	puts("--  runtime only --");
	printf("    stack_arr       %p  %s\n", (void *)stack_arr, stack_arr);
	printf("    stack_local     %p  %d\n", (void *)&stack_local, stack_local);
	printf("    heap_buf        %p  %d\n", (void *)heap_buf, heap_buf ? *heap_buf : -1);
	printf("    reg_var         (no address)    %d\n", reg_var);

	free(heap_buf);
	return 0;
}
