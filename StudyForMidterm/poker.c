//
//  poker.c
//  
//
//  Created by Derek Rodriguez on 9/28/16.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

// Externals

void read_cards(int *num_in_rank, int *num_in_suit);
void analyze_hand(int *num_in_rank, int *num_in_suit, bool *straight, bool *flush, bool *four, bool *three, int *pairs);
void print_result(bool *straight, bool *flush, bool *four, bool *three, int *pairs);

int main() {
    
    int num_in_rank[NUM_RANKS];
    int num_in_suit[NUM_SUITS];
    bool straight, flush, four, three;
    int pairs;
    
    for (;;) {
        
        read_cards(num_in_rank, num_in_suit);
        analyze_hand(num_in_rank, num_in_suit, &straight, &flush, &four, &three, &pairs);
        print_result(&straight, &flush, &four, &three, &pairs);
        
    }
}

void read_cards(int *num_in_rank, int *num_in_suit) {
    
    bool cards_exist[NUM_RANKS][NUM_SUITS];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;
    
    for (rank = 0; rank < NUM_RANKS; rank++) {
        
        num_in_rank[rank] = 0;
        
        for (suit = 0; suit < NUM_SUITS; suit++) {
            
            cards_exist[rank][suit] = 0;
            
        }
        
    }
    
    for (suit = 0; suit < NUM_SUITS; suit++) {
        
        num_in_suit[suit] = 0;
        
    }
        
    while (cards_read < NUM_CARDS) {
        
        bad_card = false;
        
    }
    
    printf("Enter a card: ");
    
    rank_ch = getchar();
    
    switch (rank_ch) {
            
        case '0': exit(EXIT_SUCCESS);
        case '2': rank = 0; break;
        case '3': rank = 1; break;
        case '4': rank = 2; break;
        case '5': rank = 3; break;
        case '6': rank = 4; break;
        case '7': rank = 5; break;
        case '8': rank = 6; break;
        case '9': rank = 7; break;
        case 't': case 'T': rank = 8; break;
        case 'j': case 'J': rank = 9; break;
        case 'q': case 'Q': rank = 10; break;
        case 'k': case 'K': rank = 11; break;
        case 'a': case 'A': rank = 12; break;
        default: bad_card = 1;
            
    }
 
    suit_ch = getchar();
    
    switch(suit_ch) {
            
        case 'c': case 'C': suit = 0; break;
        case 'd': case 'D': suit = 1; break;
        case 'h': case 'H': suit = 2; break;
        case 's': case 'S': suit = 3; break;
        default: bad_card = 1;
            
            
    }
    
    while ((ch = getchar()) != '\n') {
        
        if (ch != ' ') {
            
            bad_card = 1;
            
        }
    }
    
    if (bad_card) {
        
        printf("Bad card, ignored. \n");
        
    } else if (cards_exist[rank][suit]) {
        
        printf("Duplicate card; ignored. \n");
        
    } else {
        
        num_in_rank[rank]++;
        num_in_suit[suit]++;
        cards_exist[rank][suit] = true;
        
        cards_read++;
        
    }
    
}

void analyze_hand(int *num_in_rank, int *num_in_suit, bool *straight, bool *flush, bool *four, bool *three, int *pairs) {
    
    *straight = false;
    *flush = false;
    *four = false;
    *three = false;
    *pairs = 0;
    int num_consec = 0;
    int rank, suit;
    //Straight, flush, four, three, pairs respectively
    
    // check for flush
    
    for (suit = 0; suit < NUM_SUITS; suit++) {
        
        if (num_in_suit[suit] == NUM_CARDS) {
            
            *flush = true;
            
        }
        
    }
    
    // check for straight
    
    rank = 0;
    
    while (num_in_rank[rank] == 0) {
        
        rank++;
        
    }
    
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++) {
        
        num_consec++;
        
    }
    
    if (num_consec == NUM_CARDS) {
        
        *straight = true;
        return;
        
    }
    
    // check for 4-of-a-kind, 3-of-a-kind, and pairs
    
    for (rank = 0; rank < NUM_RANKS; rank++) {
        
        if (num_in_rank[rank] == 4) {
            
            *four = true;
            
        }
        
        if (num_in_rank[rank] == 3) {
            
            *three = true;
            
        }
        
        if (num_in_rank[rank] == 2) {
            
            pairs++;
            
        }
        
    }
    
}

void print_result(bool *straight, bool *flush, bool *four, bool *three, int *pairs) {
    
    if (straight && flush) {
        
        printf("Straight flush! \n");
        
    } else if (four) {
        
        printf("Four of a kind! \n");
        
    } else if (three && *pairs == 1) {
        
        printf("Full house! \n");
        
    } else if (*straight) {
        
        printf("Straight! \n");
        
    } else if (*three) {
        
        printf("Three of a kind! \n");
        
    } else if (*pairs == 2) {
        
        printf("Two pairs! \n");
        
    } else if (*pairs == 1) {
        
        printf("Pair! \n");
        
    } else {
        
        printf("High card! \n");
        
    }
    
    printf("\n\n");
    
}