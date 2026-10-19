#ifndef ACTION_H_
#define ACTION_H_

/**
 * Votre énumération pour les actions possibles d'un joueur.
 * Les actions possibles au BlackJack sont :
 * - HIT : le joueur demande une carte supplémentaire
 * - STAND : le joueur ne demande pas de carte supplémentaire 
 *           (et ne pourra plus en demander avant la prochaine manche)
 */
typedef enum Action {
    HIT,
    STAND
} Action;

/**
 * Cette fonction met dans la chaîne de caractères
 * `buffer` l'action `action` sous forme de texte.
 * On suppose que le buffer donné en entrée est
 * suffisamment grand pour accueillir toutes
 * les actions.
 * Cette fonction retourne un pointeur vers la fin du buffer.
 */
char * action_to_string(Action action, char * buffer);

/**
 * Cette fonction affiche directement l'action `action`
 * sous forme lisible.
 */
void print_action(Action action);

#endif