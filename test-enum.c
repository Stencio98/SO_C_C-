#include <stdio.h>

enum month {Gen, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
/*enum month {Gen=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec}; */
/* enum month {Gen=1, Feb, Mar, Apr=0, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};*/

int main()
{
	enum month var;

	var = May;
	printf("sizeof(var) = %li, var=%i\n", sizeof(var), var);
	var++;
	printf("sizeof(var) = %li, var=%i\n", sizeof(var), var);
	var *= 3;
	printf("sizeof(var) = %li, var=%i\n", sizeof(var), var);
	
}

