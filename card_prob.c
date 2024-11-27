#include <stdio.h>
#include <stdlib.h>
/*
Given total cards in deck, number of target cards in deck, number of cards to mulligan, and turn you want to draw by, 
return the probability of drawing a target card by the given turn
*/

void isDrawGuarenteed(int total_cards, int hand_size, int mulligan, int draw_by_turn) {
/*
Sees if drawing the card is guaranteed; if it is, say so and exit the program
@total_cards is the number of cards in the deck
@hand_size is the size of the opening hand
@mulligan is the number of cards to mulligan
@draw_by_turn is the number of turns the user wants to draw the card by
*/
    if (total_cards - hand_size - mulligan <= 0) {
        printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is 1.00", draw_by_turn, mulligan);
        exit(0);
    }
    else if (total_cards - hand_size - draw_by_turn <= 0) {
        printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is 1.00", draw_by_turn, mulligan);
        exit(0);
    }
}

double probNoDrawOpeningHand(int total_cards, int target_cards, int hand_size){
/*
Find the probability that the target card will not be drawn in the opening hand
@total_cards is the number of cards in the deck
@target_cards is the number of target cards in the deck
@hand_size is the number of cards in the opening hand
@returns the probability that the target card will not be drawn in the opening hand    
*/
    double prob = 1;
    for (int card = 0; card < hand_size; ++card){
        double temp_prob;
        temp_prob = (double)(total_cards - card - target_cards) / (double)(total_cards - card);
        prob *= temp_prob;
    }
    return prob;
}

double probNoDrawMulligan(int total_cards, int target_cards, int hand_size, int mulligan) {
/*
Find the probability that the target card will not be drawn in the mulligan
@total_cards is the number of cards in the deck
@target_cards is the number of target cards in the deck
@hand_size is the number of cards in the opening hand
@mulligan is the number of cards to mulligan
@returns the probability that the target card will not be drawn in the mulligan
*/
    double prob = 1;
    for (int m = 0; m < mulligan; ++m) {
        int new_deck_size = total_cards - hand_size - m;
        double temp_prob = (double)(new_deck_size - target_cards) / new_deck_size;
        prob *= temp_prob;
    }
    return prob;
}

double probNoDrawTurn(int total_cards, int target_cards, int hand_size, int draw_by_turn){
/*
Find the probability that the target card will not be drawn in one of your turns
@total_cards is the number of cards in the deck
@target_cards is the number of target cards in the deck
@hand_size is the number of target cards in the deck
@draw_by_turn is the number of turns the user wants to draw their card by
@returns the probability that the target card will no tbe drawn in one of the turns
*/
    double prob = 1;
    for (int t = 0; t < draw_by_turn; ++t){
        int new_deck = total_cards - hand_size - t;
        double temp_prob;
        temp_prob = (double)(new_deck - target_cards)/(new_deck);
        prob *= temp_prob;
    }
    return prob;
}

int main() { 
    int total_cards, mulligan, hand_size, target_cards, draw_by_turn;
    double prob;

    printf("Enter how many total cards there are in the deck: ");
    scanf("%d", &total_cards);
    
    printf("Enter how many copies of the card that you are looking for are in the deck: ");
    scanf("%d", &target_cards);

    printf("Enter your initial hand size: ");
    scanf("%d", &hand_size);

    printf("Enter how many cards you are mulliganing: ");
    scanf("%d", &mulligan);

    printf("Enter what turn you want to draw the card by: ");
    scanf("%d", &draw_by_turn);

    isDrawGuarenteed(total_cards, hand_size, mulligan, draw_by_turn);

    double prob_no_draw_opening_hand, prob_no_draw_mulligan, prob_no_draw_turn;

    prob_no_draw_opening_hand = probNoDrawOpeningHand(total_cards, target_cards, hand_size);
    prob_no_draw_mulligan = probNoDrawMulligan(total_cards, target_cards, hand_size, mulligan);
    prob_no_draw_turn = probNoDrawTurn(total_cards, target_cards, hand_size, draw_by_turn);
    
    prob = 1 - (prob_no_draw_opening_hand * prob_no_draw_mulligan * prob_no_draw_turn);

    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf", draw_by_turn, mulligan, prob);
 
    return 0;
}