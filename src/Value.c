#include "Value.h"

#include "Utils.h"

#include <string.h>
#include <stdio.h>

/**
 * Cette fonction met dans la chaîne de caractères
 * `buffer` la valeur `v` sous forme de texte.
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les valeurs.
 *
 * La fonction retourne un pointeur vers la fin du buffer.
 */
char * value_to_string(Value v, char * buffer) {
    switch(v) {
        case ACE: buffer = strcpy(buffer, "ace"); break;
        case TWO: buffer = strcpy(buffer, "two"); break;
        case THREE: buffer = strcpy(buffer, "three"); break;
        case FOUR: buffer = strcpy(buffer, "four"); break;
        case FIVE: buffer = strcpy(buffer, "five"); break;
        case SIX: buffer = strcpy(buffer, "six"); break;
        case SEVEN: buffer = strcpy(buffer, "seven"); break;
        case EIGHT: buffer = strcpy(buffer, "eight"); break;
        case NINE: buffer = strcpy(buffer, "nine"); break;
        case TEN: buffer = strcpy(buffer, "ten"); break;
        case JACK: buffer = strcpy(buffer, "jack"); break;
        case QUEEN: buffer = strcpy(buffer, "queen"); break;
        case KING: buffer = strcpy(buffer, "king"); break;
        default: buffer = strcpy(buffer, "unknown"); break;
    }
    return buffer + strlen(buffer);
}

/**
 * Cette fonction met dans la chaîne de caractères
 * `buffer` le symbole correspondant à la valeur `v`.
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les valeurs.
 *
 * La fonction retourne un pointeur vers la fin du buffer.
 */
char * value_to_symbol(Value v, char * buffer) {
    switch(v) {
        case ACE: buffer = strcpy(buffer, "A"); break;
        case TWO: buffer = strcpy(buffer, "2"); break;
        case THREE: buffer = strcpy(buffer, "3"); break;
        case FOUR: buffer = strcpy(buffer, "4"); break;
        case FIVE: buffer = strcpy(buffer, "5"); break;
        case SIX: buffer = strcpy(buffer, "6"); break;
        case SEVEN: buffer = strcpy(buffer, "7"); break;
        case EIGHT: buffer = strcpy(buffer, "8"); break;
        case NINE: buffer = strcpy(buffer, "9"); break;
        case TEN: buffer = strcpy(buffer, "10"); break;
        case JACK: buffer = strcpy(buffer, "J"); break;
        case QUEEN: buffer = strcpy(buffer, "Q"); break;
        case KING: buffer = strcpy(buffer, "K"); break;
        default: buffer = strcpy(buffer, "?"); break;
    }
    return buffer + strlen(buffer);
}

/**
 * Cette fonction affiche directement la valeur `v`
 * sous forme lisible.
 */
void print_value(Value v) {
    char buffer[MAX_STR];
    value_to_string(v, buffer);
    printf("%s", buffer);
}