#include "Player.h"

/**
 * Cette fonction crée un nouveau joueur.
 * En particulier, il faut lui fournir un nom, 
 * une fonction pour choisir l'action à effectuer,
 * une fonction pour choisir combien miser,
 * et une somme d'argent initiale.
 *
 * Si le concept des ActionFunction et BetFunction
 * est compliqué, vous pouvez simplement donner
 * `NULL` pour ces deux paramètres.
 */
Player create_player(
    char * name, 
    ActionFunction choose_action, 
    BetFunction choose_bet, 
    unsigned int money
) {
    Player p;
    return p;
}

/**
 * Cette fonction permet de donner une carte à un joueur.
 */
void give_card(Player * player, Card card) {

}

/**
 * Cette fonction retourne le score de la main du joueur.
 * Afin de calculer le score avec les AS, on peut suivre l'algorithme suivant :
 * 1. On calcule le score en considérant que tous les AS valent 11.
 *    De plus, on garde en mémoire le nombre total d'AS dans la main du joueur.
 * 2. Tant que le score du joueur est supérieur à 21, et qu'il reste au moins un AS
 *    dans sa main, on soustrait 10 du score et on décrémente le nombre d'AS.
 */
unsigned int get_score(Player player) {
    return 0;
}

/**
 * Cette fonction vide la main du joueur.
 */
void empty_hand(Player * player) {

}

/**
 * Cette fonction permet de récupérer le nom d'un joueur.
 * On suppose que le buffer fourni est suffisamment grand pour contenir le nom du joueur.
 */
void get_name(Player player, char * buffer) {

}

/**
 * Cette fonction retourne l'argent du joueur.
 */
unsigned int get_money(Player player) {
    return 0;
}

/**
 * Affiche les informations d'un joueur (nom, main, argent).
 */
void show_player(Player player) {
    
}