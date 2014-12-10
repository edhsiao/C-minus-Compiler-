#ifndef _wcglobaldefs
#define _wcglobaldefs

#define debug

#define buf_size 256
#define small_buf_size 16

#define true 1
#define TRUE 1
#define True 1
#define false 0
#define FALSE 0
#define False 0


#define unset -2
#define success 0
#define failure -1
#define fail -1
#define alloc_fail 1
#define empty 2
#define bad_input 3
#define got_null 4
#define not_null 5
#define is_null 6
#define null_next 7
#define null_prev 7
#define exiting 8

#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)

#ifdef debug
#define _num(x,y) printf("%s,%d: -%s: %g-\n", __FILE__, __LINE__ x, y); fflush(stdout);
#define _ptr(x,y) printf("%s,%d: -%s: %p-\n", __FILE__, __LINE__, x, y); fflush(stdout);
#define _str(x) printf("%s,%d: -%s-\n", __FILE__, __LINE__, x); fflush(stdout);
#define _loc printf("%s,%d: ", __FILE__, __LINE__); fflush(stdout);
#else
#define _num(x,y)
#define _ptr(x,y)
#define _str(x)
#define _loc
#endif

#endif
