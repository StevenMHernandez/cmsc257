/*    
    this program demonstrates what happens when you shift a number too far 
    to the left or right.  
 */


/* Include Files */
#include <stdio.h>                                   

int main( void )
{
    int x = -11111;
    int y = 11111;
    unsigned int z = 11111;
    int i;

    printf("example of right shifts on negative number\n");
    for(i = 0; i < 16; i++)
        printf("%d\n", x >> i);

    printf("\nexample of left shifts on negative number\n");
    for(i = 0; i < 20; i++)
        printf("%d\n", x << i);

    printf("\nexample of right shifts on positive, signed number\n");
    for(i = 0; i < 16; i++)
        printf("%d\n", y >> i);

    printf("\nexample of left shifts on positive, signed number\n");
    for(i = 0; i < 20; i++)
        printf("%d\n", y << i);

    printf("\nexample of right shifts on unsigned number\n");
    for(i = 0; i < 16; i++)
        printf("%d\n", z >> i);

    printf("\nexample of left shifts on unsigned number\n");
    for(i = 0; i < 20; i++)
        printf("%d\n", z << i);
}

/***************************************************
*   output from Visual Studio 2005 on a machine
*   in which an int is 4 bytes

example of right shifts on negative number
-11111
-5556
-2778
-1389
-695
-348
-174
-87
-44
-22
-11
-6
-3
-2
-1
-1

example of left shifts on negative number
-11111
-22222
-44444
-88888
-177776
-355552
-711104
-1422208
-2844416
-5688832
-11377664
-22755328
-45510656
-91021312
-182042624
-364085248
-728170496
-1456340992
1382285312
-1530396672

example of right shifts on positive, signed number
11111
5555
2777
1388
694
347
173
86
43
21
10
5
2
1
0
0

example of left shifts on positive, signed number
11111
22222
44444
88888
177776
355552
711104
1422208
2844416
5688832
11377664
22755328
45510656
91021312
182042624
364085248
728170496
1456340992
-1382285312
1530396672

example of right shifts on unsigned number
11111
5555
2777
1388
694
347
173
86
43
21
10
5
2
1
0
0

example of left shifts on unsigned number
11111
22222
44444
88888
177776
355552
711104
1422208
2844416
5688832
11377664
22755328
45510656
91021312
182042624
364085248
728170496
1456340992
-1382285312
1530396672

*/


