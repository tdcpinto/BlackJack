#include "Action.h"

#include "Utils.h"

#include <stdio.h>
#include <string.h>

/**
 * Cette fonction met dans la chaîne de caractères
 * `buffer` l'action `action` sous forme de texte.
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les actions.
 * Cette fonction retourne un pointeur vers la fin du buffer.
 */
char * action_to_string(Action action, char * buffer) {
    switch(action) {
        case HIT: strcpy(buffer, "HIT"); break;
        case STAND: strcpy(buffer, "STAND"); break;
        default: strcpy(buffer, "UNKNOWN"); break; 
    }
    return buffer + strlen(buffer);
}

/**
 * Cette fonction affiche directement l'action `action`
 * sous forme lisible.
 */
void print_action(Action action) {
    char buffer[MAX_STR];
    action_to_string(action, buffer);
    printf("%s", buffer);
}