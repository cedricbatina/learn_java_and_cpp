#include "Personnes.h"

int main(int argc, char const *argv[])
{
 /*code */
 Personnes Kimbangu("Nvuluzi", "Kimbangu", "1887");
 Kimbangu.un_test();

 Personnes *ppersonnes;
 ppersonnes = new Personnes("Batina", "Cedric", "1980");
 ppersonnes->un_test();
 delete ppersonnes;

 return 0;
}
