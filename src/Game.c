#include "Game.h"
#include "Deck.h"
#include "Player.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Cette fonction crée une nouvelle partie de BlackJack avec les joueurs donnés.
 */
Game create_game(Player * players, unsigned int num_players) {
    Game game;
    game.num_players = num_players;
    for(unsigned int i = 0; i < num_players; i++) {
        game.players[i] = players[i];
    }
    game.in_play_deck = create_empty_deck();
    game.discarded_deck = create_empty_deck();
    game.deck = create_standard_deck();
    game.dealer = create_player("Dealer", NULL, NULL, 0);
    return game;
}

/**
 * Cette fonction détermine quels joueurs veulent jouer la
 * la manche suivante.
 * Pour ce faire, elle demande à chaque joueur quelle mise ils
 * souhaitent parier, et si leur mise est égale à zéro, ils ne jouent pas cette manche.
 * Les joueurs jouant la manche sont stockés dans le tableau de joueurs
 * `active_players` donné en paramètre.
 * La fonction renvoie le nombre de joueurs actifs.
 */
unsigned int set_bets(Game * game) {
    unsigned int count = 0;
    for(unsigned int i = 0; i < game->num_players; i++) {
        Player player = game->players[i];
        unsigned int bet = player.choose_bet(game->discarded_deck, player.money);
        if(bet > player.money) bet = 0;
        game->bets[i] = bet;
        if(bet > 0) count++;
    }
    return count;
}

/**
 * Cette fonction ajoute une carte à la liste de carte en jeu.
 */
void add_in_play_card(Game * game, Card c) {
    add_card(&(game->in_play_deck), c);
}

/**
 * Cette fonction ajoute une carte au paquet de cartes défaussées.
 */
void add_discarded_card(Game * game, Card c) {
    add_card(&(game->discarded_deck), c);
}

/**
 * Cette fonction permet de piocher une carte du paquet en jeu.
 * La fonction retourne la carte piochée.
 * Si le paquet est vide, toutes les cartes déjà tirées sont remises
 * dans le paquet en jeu et le paquet est mélangé.
 */
Card get_card(Game * game) {
    if(is_deck_empty(game->deck)) {
        game->deck = merge_decks(game->deck, game->discarded_deck);
        game->discarded_deck = create_empty_deck();
        shuffle_deck(&(game->deck));
    }
    return draw_card(&(game->deck));
}

/**
 * Cette fonction distribue deux cartes à chaque joueur,
 * ainsi qu'au dealer.
 * Attention, les cartes distribuées sont visibles de tous (en jeu),
 * sauf la seconde carte du dealer.
 */
Card deal_initial_cards(Game * game) {
    for(unsigned int i = 0; i < game->num_players; i++) {
        if(game->bets[i] == 0) continue;
        Player * player = &(game->players[i]);
        Card a = get_card(game);
        Card b = get_card(game);
        give_card(player, a);
        give_card(player, b);
        add_in_play_card(game, a);
        add_in_play_card(game, b);
    }
    Card a = get_card(game);
    Card b = get_card(game);
    give_card(&(game->dealer), a);
    add_in_play_card(game, a);
    return b;
}

/**
 * Cette fonction fait jouer un joueur jusqu'à ce
 * qu'il décide de s'arrêter (STAND).
 * Le joueur actuel est celui passé en paramètre (`active_player`).
 */
void play_players(Game * game) {
    for(unsigned int i = 0; i < game->num_players; i++) {
        if(game->bets[i] == 0) continue;
        Player * player = &(game->players[i]);
        Deck known_cards = merge_decks(game->in_play_deck, game->discarded_deck);
        Deck hand = player->hand;
        while(get_score(*player) <= 21 && player->choose_action(hand, known_cards) == HIT) {
            Card a = get_card(game);
            give_card(player, a);
            add_in_play_card(game, a);
            known_cards = merge_decks(game->in_play_deck, game->discarded_deck);
            hand = player->hand;
        }
    }
}

/**
 * Cette fonction fait jouer le dealer jusqu'à
 * ce qu'il dépasse 17 points.
 */
void play_dealer(Game * game, Card hidden) {
    Player * dealer = &(game->dealer);
    give_card(dealer, hidden);
    add_in_play_card(game, hidden);
    while(get_score(*dealer) < 17) {
        Card c = get_card(game);
        give_card(dealer, c);
        add_in_play_card(game, c);
    }
}

/**
 * Cette fonction compare le score de chaque joueur a celui
 * du dealer.
 * Tout joueur ayant un score plus faible que le dealer,
 * ou supérieur à 21 perd sa mise.
 * Les autres gagnent leurs mises.
 */
void end_round(Game * game) {
    unsigned int dealer_score = get_score(game->dealer);
    for(unsigned int i = 0; i < game->num_players; i++) {
        if(game->bets[i] == 0) continue;
        Player * player = &(game->players[i]);
        unsigned int score = get_score(*player);
        if(score <= 21 && score > dealer_score) {
            player->money = player->money + game->bets[i];
        } else if(score > 21 || score < dealer_score) {
            player->money = player->money - game->bets[i];
        }
    }
}

/**
 * Cette fonction vide les mains de tous les joueurs actifs, ainsi
 * que celle du dealer.
 * De plus, elle ajoute les cartes actuellement en jeu au paquet de cartes déjà tirées.
 * Cette fonction ne doit pas mélanger le paquet restant ou le modifier.
 */
void clear_hands(Game * game) {
    for(unsigned int i = 0; i < game->num_players; i++) {
        empty_hand(&(game->players[i]));
    }
    empty_hand(&(game->dealer));
    game->discarded_deck = merge_decks(game->discarded_deck, game->in_play_deck);
    game->in_play_deck = create_empty_deck();
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
    unsigned int active_players = set_bets(game);
    if(active_players == 0) return;
    Card hidden = deal_initial_cards(game);
    play_players(game);
    play_dealer(game, hidden);
    end_round(game);
    clear_hands(game);
}

/**
 * Cette fonction affiche les informations de tous les joueurs de la partie.
 * Pour chaque joueur, on affiche son nom et son argent actuel.
 */
void show_players(Game game) {
    for(unsigned int i = 0; i < game.num_players; i++) {
        printf("Nom: %s (%u)\n", game.players[i].name, game.players[i].money);
    }
}