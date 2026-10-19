#include <stdio.h>

#include "Action.h"
#include "Suit.h"
#include "Value.h"
#include "Utils.h"

int main() {
    // on teste l'affichage des actions
    for(Action a = HIT; a <= STAND; a++) {
        char buffer[MAX_STR];
        action_to_string(a, buffer);
        printf("%s\n", buffer);
    }

    // on teste l'affichage des couleurs
    for(Suit s = SPADES; s <= HEARTS; s++) {
        char buffer[MAX_STR];
        suit_to_string(s, buffer);
        printf("%s\n", buffer);
    }
    
    // on teste l'affichage des valeurs
    for(Value v = ACE; v <= KING; v++) {
        char buffer[MAX_STR];
        value_to_string(v, buffer);
        printf("%s\n", buffer);
    }
    return 0;
}