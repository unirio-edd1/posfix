#include <iostream>
#include <cstdlib>
using namespace std;
#include "posfixada.h"

int main()
{
    posfixada ExpressaoPosFix;
    
    ExpressaoPosFix.le_expressao();
    if (ExpressaoPosFix.avalia_expressao())
        ExpressaoPosFix.imprime_resultado();
    system("PAUSE");
    return 0;
}
