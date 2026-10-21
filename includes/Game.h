#ifndef GAME_H_
#define GAME_H_

#include "Deck.h"
#include "Player.h"

/**
 * Cette structure représente une partie de BlackJack avec
 * plusieurs joueurs.
 * Une partie de BlackJack est composée de N joueurs (au moins 1).
 * En plus des joueurs, il y a un dealer.
 * Chaque joueur est indépendant des autres (ils ne jouent pas ensemble,
 * et ne joue pas contre les autres joueurs).
 * En revanche, chaque joueur joue contre le dealer.
 * Le but est d'avoir une main plus forte que celle du dealer, sans dépasser 21.
 * Si un joueur dépasse 21, il perd automatiquement.
 * Si le dealer dépasse 21, tous les joueurs n'ayant pas dépassé 21 gagnent.
 * Les cartes valent la valeur de leur chiffre, sauf les figures (valet, dame, roi) qui valent 10.
 * De plus, l'as vaut soit 1, soit 11, selon ce qui est le plus avantageux pour le joueur.
 *
 * On dispose d'un paquet de cartes commun à tous les joueurs et au dealer.
 * Pour chaque joueur, on distribue deux cartes au début de la partie face visible.
 * De plus, on distribue deux cartes au dealer, mais seulement une face visible.
 * Ensuite, chaque joueur joue un tour complet.
 * Tant que le joueur n'a pas dépassé 21, il peut choisir de tirer une carte (HIT) 
 * ou de ne rien faire (STAND).
 * Dans le premier cas, il reçoit une nouvelle carte et peut continuer à jouer.
 * Dans le second cas, son tour est fini et on passe au joueur suivant.
 *
 * Une fois que tous les joueurs ont joué, le dealer joue son tour.
 * Le dealer doit tirer une carte tant que sa main est inférieure à 17.
 * Une fois que le dealer a fini de jouer, on compare la main de chaque joueur avec celle du dealer.
 * Si la main du joueur est plus forte que celle du dealer, le joueur gagne.
 * Si la main du joueur est égale à celle du dealer, 
 * c'est une égalité et le joueur ne gagne ni ne perd.
 * Si la main du joueur est plus faible que celle du dealer, le joueur perd.
 *
 * En plus de tout cela, les joueurs peuvent miser de l'argent avant de jouer.
 * Les joueurs doivent miser *avant* de voir leurs deux premières cartes.
 * S'ils ne misent rien, ils ne jouent pas cette manche.
 * S'ils misent de l'argent, ils perdent tout en cas de défaite, et gagnent
 * le double de leur mise en cas de victoire.
 * En cas d'égalité, le joueur récupère sa mise.
 *
 * Après chaque manche, le jeu de carte n'est pas modifié (les cartes déjà tirées
 * ne sont pas remises dans le paquet).
 * Lorsque le paquet est vide, on reprend toutes les cartes déjà tirées, on les mélange
 * et on les remet dans le paquet.
 * Attention : les cartes en jeu au moment où le paquet est vide ne sont pas remises dans le paquet.
 */
typedef struct Game {
    Player players[MAX_PLAYERS];
    unsigned int bets[MAX_PLAYERS];
    Player dealer;
    unsigned int num_players;
    Deck deck;
    Deck in_play_deck;
    Deck discarded_deck;
} Game;

/**
 * Cette fonction crée une nouvelle partie de BlackJack avec les joueurs donnés.
 */
Game create_game(Player * players, unsigned int num_players);

/**
 * Cette fonction détermine quelle mise chaque joueur
 * place pour cette manche.
 * Si la mise est zéro, on considère que le joueur
 * ne participe pas à la manche.
 * La fonction retourne le nombre de joueurs ayant placé une mise non nulle.
 */
unsigned set_bets(Game * game);

/**
 * Cette fonction ajoute une carte à la liste de carte en jeu.
 */
void add_in_play_card(Game * game, Card c);

/**
 * Cette fonction ajoute une carte au paquet de cartes défaussées.
 */
void add_discarded_card(Game * game, Card c);

/**
 * Cette fonction permet de piocher une carte du paquet en jeu.
 * La fonction retourne la carte piochée.
 * Si le paquet est vide, toutes les cartes déjà tirées sont remises
 * dans le paquet en jeu et le paquet est mélangé.
 */
Card get_card(Game * game);

/**
 * Cette fonction distribue deux cartes à chaque joueur,
 * ainsi qu'au dealer.
 * Attention, les cartes distribuées sont visibles de tous (en jeu),
 * sauf la seconde carte du dealer.
 * La fonction retourne la carte cachée du dealer.
 */
Card deal_initial_cards(Game * game);

/**
 * Cette fonction fait jouer chaque joueur jusqu'à ce
 * que chacun décide de s'arrêter (STAND).
 */
void play_players(Game * game);

/**
 * Cette fonction fait jouer le dealer jusqu'à
 * ce qu'il dépasse 17 points.
 * Cette fonction prend en paramètre la carte pas encore
 * révélée du dealer.
 */
void play_dealer(Game * game, Card hidden);

/**
 * Cette fonction compare le score de chaque joueur a celui
 * du dealer.
 * Tout joueur ayant un scorep lus faible que le dealer,
 * ou supérieur à 21 perd sa mise.
 * Tout joueur ayant exactement le score du dealer, sans dépasser 21
 * ne gagnent et ne perdent rien.
 * Les autres gagnent leurs mises.
 */
void end_round(Game * game);

/**
 * Cette fonction vide les mains de tous les joueurs actifs, ainsi
 * que celle du dealer.
 * De plus, elle ajoute les cartes actuellement en jeu au paquet de cartes déjà tirées.
 * Cette fonction ne doit pas mélanger le paquet restant ou le modifier.
 */
void clear_hands(Game * game);

/**
 * Cette fonction joue une manche complète de BlackJack avec les joueurs et le dealer.
 * Elle distribue les cartes, fait jouer chaque joueur, puis le dealer,
 * et enfin mets à jour les mises des joueurs en fonction du résultat de la manche.
 *
 * Si un joueur n'a plus d'argent, il est éliminé de la partie et ne joue plus.
 * S'il n'y a pas de joueurs restant, cette fonction ne fait rien.
 */
void play_round(Game * game);

/**
 * Cette fonction affiche les informations de tous les joueurs de la partie.
 * Pour chaque joueur, on affiche son nom et son argent actuel.
 */
void show_players(Game game);

#endif