#include <stdio.h>

#include "queue.h"

int main(void) //test
{
   EnQueue((QData){"a"});
   EnQueue((QData){"b"});
   EnQueue((QData){"c"});

   puts(DeQueue().name);
   puts(DeQueue().name);
   puts(DeQueue().name);
   puts(DeQueue().name);

}