#include <stdio.h>
#include <stdint.h>

#define _CONCAT(x, y) x ## y
#define CONCAT(x, y) _CONCAT(x, y)
#define BITMASK(bits) ((1ull << (bits)) - 1)
// similar to x[hi:lo] in Verilog
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1))
#define DEF_WIRE(name, w) uint64_t name : w

#define DEF_REG(name, w)            \
 	uint64_t name : w;                \
	uint64_t CONCAT(name, _next) : w; \
	uint64_t CONCAT(name, _update) : 1

#define EVAL(c, name, val)          \
	do {                              \
		c->CONCAT(name, _next) = (val); \
		c->CONCAT(name, _update) = 1;   \
	} while (0)

#define UPDATE(c, name)                 \
	do {                                  \
		if (c->CONCAT(name, _update)) {     \
			c->name = c->CONCAT(name, _next); \
		}	                                  \
	} while (0)

/*
typedef struct {
	DEF_WIRE(clk, 1);
	DEF_WIRE(rst, 1);
	DEF_REG(led, 16);
	DEF_REG(count, 32);
} Circuit;

static void cycle(Circuit *c) {
	c->led_update = 0;
	c->count_update = 0;
	if (c->rst) {
		EVAL(c, led, 1);
		EVAL(c, count, 0);
	} else {
		if (c->count == 0) {
			EVAL(c, led, (BITS(c->led, 14, 0) << 1) | BITS(c->led, 15, 15));
		}
		EVAL(c, count, c->count >= 500000 ? 0 : c->count + 1);
	}
	UPDATE(c, led);
	UPDATE(c, count);
}
*/

typedef struct {
	uint64_t clk : 1;
	uint64_t rst : 1;
	uint64_t led : 16;
	uint64_t led_next : 16;
	uint64_t led_update : 1;
	uint64_t count : 32;
	uint64_t count_next : 32;
	uint64_t count_update : 1;
} Circuit;
static Circuit circuit;

static void cycle(Circuit *c) {
	c->led_update = 0;
	c->count_update = 0;
	if (c->rst) {
		c->led_next = 1;
		c->led_update = 1;
		c->count_next = 0;
		c->count_update = 1;
	} else {
		if (c->count == 0) {
			c->led_next = (BITS(c->led, 14, 0) << 1) | BITS(c->led, 15, 15);
			c->led_update = 1;
		}
		c->count_next = c->count >= 500000 ? 0 : c->count + 1;
		c->count_update = 1;
	}
	if (c->led_udpate) {
		c->led = c->led_next;
	}
	if (c->count_update) {
		c->count = c->count_next;
	}
}

static void reset(Circuit *c) {
	c->rst = 1;
	cycle(c);
	c->rst = 0;
}

static void display(Circuit *c) {
	static uint16_t last_led = 0;
	if (last_led != c->led) {
		for (int i = 0; i < 16; i++) {
			putchar(BITS(c->led, i, i) ? 'o' : '.');
		}
		putchar('\r');
		fflush(stdout);
		last_led = c->led;
	}
}

int main() {
	reset(&circuit);
	while (1) {
		cycle(&circuit);
		display(&circuit);
	}
	return 0;
}
