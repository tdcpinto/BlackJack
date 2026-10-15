#ifndef VALUE_H_
#define VALUE_H_

/**
 * Votre énumération pour les valeurs d'une carte.
 * Les valeurs possibles sont :
 *  - As (Ace)
 *  - Deux (Two)
 *  - Trois (Three)
 *  - Quatre (Four)
 *  - Cinq (Five)
 *  - Six (Six)
 *  - Sept (Seven)
 *  - Huit (Eight)
 *  - Neuf (Nine)
 *  - Dix (Ten)
 *  - Valet (Jack)
 *  - Dame (Queen)
 *  - Roi (King)
 */
typedef enum Value {
    EMPTY_VALUE
} Value;

/**
 * Cette fonction met dans la chaîne de caractères
 * `buffer` la valeur `v` sous forme de texte.
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les valeurs.
 *
 * La fonction retourne un pointeur vers la fin du buffer.
 */
char * value_to_string(Value v, char * buffer);

/**
 * Cette fonction met dans la chaîne de caractères
 * `buffer` le symbole correspondant à la valeur `v`.
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les valeurs.
 *
 * La fonction retourne un pointeur vers la fin du buffer.
 */
char * value_to_symbol(Value v, char * buffer);

/**
 * Cette fonction affiche directement la valeur `v`
 * sous forme lisible.
 */
void print_value(Value v);

#endif