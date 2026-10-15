#include "Game.h"

/**
 * Cette fonction crée une nouvelle partie de BlackJack avec les joueurs donnés.
 * En particulier, cette fonction crée un nouveau jeu de cartes
 * et le mélange.
 */
Game create_game(Player * players, unsigned int num_players) {
    Game g;
    return g;
}

/**
 * Cette fonction détermine quelle mise chaque joueur
 * place pour cette manche.
 * Si la mise est zéro, on considère que le joueur
 * ne participe pas à la manche.
 * La fonction retourne le nombre de joueurs ayant placé une mise non nulle.
 */
unsigned int set_bets(Game * game) {
    return 0;
}

/**
 * Cette fonction ajoute une carte à la liste de carte en jeu.
 */
void add_in_play_card(Game * game, Card c) {

}

/**
 * Cette fonction ajoute une carte au paquet de cartes défaussées.
 */
void add_discarded_card(Game * game, Card c) {

}

/**
 * Cette fonction permet de piocher une carte du paquet en jeu.
 * La fonction retourne la carte piochée.
 * Si le paquet est vide, toutes les cartes déjà défaussées sont remises
 * dans le paquet en jeu et le paquet est mélangé.
 */
Card get_card(Game * game) {
    Card c;
    return c;
}

/**
 * Cette fonction distribue deux cartes à chaque joueur,
 * ainsi qu'au dealer.
 * Attention, les cartes distribuées sont visibles de tous (en jeu),
 * sauf la seconde carte du dealer.
 * La fonction retourne la carte cachée du dealer.
 */
Card deal_initial_cards(Game * game) {
    Card c;
    return c;
}

/**
 * Cette fonction fait jouer chaque joueur jusqu'à ce
 * que chacun décide de s'arrêter (STAND).
 */
void play_players(Game * game) {

}

/**
 * Cette fonction fait jouer le dealer tant que sa main
 * ne vaut pas au moins 17 points.
 * Cette fonction prend en paramètre la carte pas encore
 * révélée du dealer.
 */
void play_dealer(Game * game, Card hidden) {

}

/**
 * Cette fonction compare le score de chaque joueur à celui
 * du dealer.
 * On applique les règles dans l'ordre suivant.
 * 1. Si le joueur a dépassé 21, il perd sa mise.
 * 2. Si le dealer a un score supérieur à 21,
 *    le joueur gagne sa mise.
 * 3. Si le dealer a un score inférieur ou égal à 21, 
 *    et que le joueur a un score inférieur à celui du dealer, 
 *    le joueur perd sa mise.
 * 4. Si le joueur a un score supérieur à celui du dealer, il gagne sa mise.
 * 5. Si le joueur a exactement le même score que le dealer, 
 *    il ne gagne ni ne perd sa mise.
 */
void end_round(Game * game) {

}

/**
 * Cette fonction vide les mains de tous les joueurs actifs, ainsi
 * que celle du dealer.
 * De plus, elle ajoute les cartes actuellement en jeu au paquet de cartes déjà tirées.
 * Cette fonction ne doit pas mélanger le paquet restant ou le modifier.
 */
void clear_hands(Game * game) {

}

/**
 * Cette fonction joue une manche complète de BlackJack avec les joueurs et le dealer.
 * Elle distribue les cartes, fait jouer chaque joueur, puis le dealer,
 * et enfin mets à jour les mises des joueurs en fonction du résultat de la manche.
 *
 * Si un joueur n'a plus d'argent, il est éliminé de la partie et ne joue plus.
 * S'il n'y a pas de joueurs restant, cette fonction ne fait rien.
 */
void play_round(Game * game) {

}

/**
 * Cette fonction affiche les informations de tous les joueurs de la partie.
 * Pour chaque joueur, on affiche son nom et son argent actuel.
 */
void show_players(Game game) {

}