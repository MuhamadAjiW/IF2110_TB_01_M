/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../etc/boolean.h"

#define MARK '.'
/* State Mesin */
extern char currentChar;
extern boolean EOP;
#define ENTER '\n'

void START(char* location);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */


void START_I();
/* I.S. : sembarang
   F.S. : currentChar adalah karakter pertama dari input*/

void ADV_I();
/* Command dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != ENTER
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = ENTER
          Jika  currentChar = ENTER maka EOP akan menyala (true) */

#endif
