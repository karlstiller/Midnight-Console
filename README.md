This project is an attempt to create a computer console game of my family game of Midnight. At the current stage the players 
don't follow the rules (yes I'm getting to that) and all players are.... stupid. The plan is to make them smarter over time and
use machine learning to make them better and better over time.

The rules are:
1.  Initial dealer is chosen at random deals one card to each player more than the previous round. First round starts with one 
    card. Second round 2 etc. Group decides to mark the halfway mark whereby the next round is one card less than the previous.
2.  Dealer turns one card up to show trump suit.
2.  Player to the right of the dealer estimates hoe many tricks he/she will win
3.  Estimates continue to the right of the previous player who estimated until it is the dealers turn to estimate.
3.  The total number of estimated tricks + the dealers estimate must not equal the number of tricks available.
4.  Player to the right leads with their first card.
5.  Player to the right of previous player must play suit of first players card. If player does not have the suit he/she is free
    to play any card of their choosing.
6.  Winner of the trick is the one with the highest card of the first played card, If trump suit cards have been played then the
    highest of these takes the trick.
7.  Winner of the previous trick plays leads card of the next trick
8.  When all cards have been played the round is over and the points are calculated.
9.  Players that have matched the number of tricks with the estimate earn 10x the estimate. e.g. estimate 1 = 10, 2 = 20, 3 = 30
    etc. If player estimated 0 player earns 5 points.
10. Players that have not matched the number of tricks lose 10x the difference between number of tricks won and estimate. e.g. 
    player estimates 3 tricks but wins 2 tricks has difference of 1 so loses 10 points. If player wins 1 tricks then has 
    diference of 2 so loses 20 points. If player wins 4 tricks then has diference of 1 and loses 10 points.
11. Game repeats returning to rule 1. Dealer changes to player to the right of the current dealer. If the previous game returned
    to 1 then the whole game is finished.
12. Winner is the player with the highest score.
