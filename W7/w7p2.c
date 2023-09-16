/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Temitope Oladimeji Samuel Adebayo

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LENGTH 70
#define MIN_LENGTH 10

#define PATH_MULTIPLE 5

#define MAX_NUM_LIVES 10
#define MIN_NUM_LIVES 1
#define MIN_MOVES 1

struct PlayerInfo
{
  int lives;
  char plyrChar;
  int numOfTreasures;
  int positionHis[MAX_LENGTH];
};

struct GameInfo
{
  int maxMoves;
  int pathLength;
  int bombs[MAX_LENGTH];
  int treasures[MAX_LENGTH];
};

int main(void)
{
  struct PlayerInfo player = {0, 0, 0, {0}};
  struct GameInfo game = {0, 0, {0}, {0}};
  int i, j, flag = 1, nextMove = 0, innerFlag, maxMoves, remainingMoves;

  printf("================================\n"
         "         Treasure Hunt!\n"
         "================================\n\n");

  printf("PLAYER Configuration\n"
         "--------------------\n");

  printf("Enter a single character to represent the player: ");
  scanf(" %c", &player.plyrChar);

  do
  {
    printf("Set the number of lives: ");
    scanf(" %d", &player.lives);

    if (player.lives < MIN_NUM_LIVES || player.lives > MAX_NUM_LIVES)
    {
      printf("     Must be between %d and %d!\n", MIN_NUM_LIVES, MAX_NUM_LIVES);
    }
    else
    {
      flag = 0;
      printf("Player configuration set-up is complete\n\n");
    }
  } while (flag == 1);

  for (i = 0; i < MAX_LENGTH; i++)
  {
    player.positionHis[i] = 0;
  }

  printf("GAME Configuration\n"
         "------------------\n");

  flag = 1;
  do
  {
    printf("Set the path length (a multiple of %d between %d-%d): ", PATH_MULTIPLE, MIN_LENGTH, MAX_LENGTH);
    scanf(" %d", &game.pathLength);

    if (game.pathLength < MIN_LENGTH || game.pathLength > MAX_LENGTH || game.pathLength % 5 != 0)
    {
      printf("     Must be a multiple of %d and between %d-%d!!!\n", PATH_MULTIPLE, MIN_LENGTH, MAX_LENGTH);
    }
    else
    {
      flag = 0;
    }
  } while (flag == 1);

  maxMoves = ((75 * game.pathLength) / 100);

  flag = 1;
  do
  {
    printf("Set the limit for number of moves allowed: ");
    scanf(" %d", &game.maxMoves);

    if (game.maxMoves < player.lives || game.maxMoves > maxMoves)
    {
      printf("    Value must be between %d and %d\n", player.lives, maxMoves);
    }
    else
    {
      flag = 0;
      putchar('\n');
    }
  } while (flag == 1);

  printf("BOMB Placement\n"
         "--------------\n");
  printf("Enter the bomb positions in sets of %d where a value\n"
         "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
         "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
         PATH_MULTIPLE, game.pathLength);

  for (i = 0; i < game.pathLength; i += PATH_MULTIPLE)
  {
    printf("   Positions [%2d-%2d]: ", i + 1, i + PATH_MULTIPLE);
    for (j = 0; j < PATH_MULTIPLE; j++)
    {
      scanf("%d", &game.bombs[i + j]);
    }
  }
  printf("BOMB placement set\n\n");

  printf("TREASURE Placement\n"
         "------------------\n");
  printf("Enter the treasure placements in sets of %d where a value\n"
         "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
         "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
         PATH_MULTIPLE, game.pathLength);

  for (i = 0; i < game.pathLength; i += PATH_MULTIPLE)
  {
    printf("   Positions [%2d-%2d]: ", i + 1, i + PATH_MULTIPLE);
    for (j = 0; j < PATH_MULTIPLE; j++)
    {
      scanf("%d", &game.treasures[i + j]);
    }
  }
  printf("TREASURE placement set\n\n");

  printf("GAME configuration set-up is complete...\n\n");

  printf("------------------------------------\n"
         "TREASURE HUNT Configuration Settings\n"
         "------------------------------------\n");
  printf("Player:\n");
  printf("   Symbol     : %c\n", player.plyrChar);
  printf("   Lives      : %d\n", player.lives);
  printf("   Treasure   : [ready for gameplay]\n");
  printf("   History    : [ready for gameplay]\n\n");

  printf("Game:\n");
  printf("   Path Length: %d\n", game.pathLength);
  printf("   Bombs      : ");
  for (i = 0; i < game.pathLength; i++)
  {
    printf("%d", game.bombs[i]);
  }

  printf("\n");

  printf("   Treasure   : ");
  for (i = 0; i < game.pathLength; i++)
  {
    printf("%d", game.treasures[i]);
  }

  printf("\n\n");

  printf("====================================\n"
         "~ Get ready to play TREASURE HUNT! ~\n"
         "====================================\n\n");

  remainingMoves = game.maxMoves;

  do
  {
    if (nextMove > 0)
    {
      for (i = 0; nextMove > i; i++)
      {
        printf(" ");
      }
      printf(" %c", player.plyrChar);
      printf("\n");
    }

    printf("  ");
    for (i = 0; i < game.pathLength; i++)
    {
      if (player.positionHis[i] == 0)
      {
        printf("-");
      }
      else if (player.positionHis[i] == 1)
      {
        printf("!");
      }
      else if (player.positionHis[i] == 2)
      {
        printf("$");
      }
      else if (player.positionHis[i] == 3)
      {
        printf("&");
      }
      else if (player.positionHis[i] == 4)
      {
        printf(".");
      }
    }
    printf("\n");

    printf("  ");
    for (i = 0; i < game.pathLength; i++)
    {
      if ((i + 1) % 10 != 0)
      {
        printf("|");
      }
      else
      {
        printf("%d", (i + 1) / 10);
      }
    }
    printf("\n");

    printf("  ");
    for (i = 0; i < game.pathLength; i++)
    {
      printf("%d", (i + 1) % 10);
    }
    printf("\n");

    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.numOfTreasures, remainingMoves);
    printf("+---------------------------------------------------+\n");

    innerFlag = 1;
    do
    {
      printf("Next Move [1-20]: ");
      scanf("%d", &nextMove);

      if (nextMove > game.pathLength || nextMove < MIN_MOVES)
      {
        printf("  Out of Range!!!\n");
      }
      else
      {
        innerFlag = 0;
        putchar('\n');
      }
    } while (innerFlag == 1);

    if (player.positionHis[(nextMove - 1)] < 1)
    {
      remainingMoves--;

      if ((game.bombs[(nextMove - 1)] == 1) && (game.treasures[(nextMove - 1)] == 1))
      {
        player.lives--;
        player.numOfTreasures++;
        player.positionHis[(nextMove - 1)] = 3;
        printf("===============> [&] !!! BOOOOOM !!! [&]\n"
               "===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
      }
      else if (game.bombs[(nextMove - 1)] == 1)
      {
        player.lives--;
        player.positionHis[(nextMove - 1)] = 1;
        printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
      }
      else if (game.treasures[(nextMove - 1)] == 1)
      {
        player.numOfTreasures++;
        player.positionHis[(nextMove - 1)] = 2;
        printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
      }
      else if ((game.bombs[(nextMove - 1)] == 0) && (game.treasures[(nextMove - 1)] == 0))
      {
        player.positionHis[(nextMove - 1)] = 4;
        printf("===============> [.] ...Nothing found here... [.]\n\n");
      }
    }
    else
    {
      if (player.positionHis[(nextMove - 1)] > 0)
      {
        printf("===============> Dope! You've been here before!\n\n");
      }
    }
  } while (remainingMoves > 0 && player.lives > 0);

  game.maxMoves = remainingMoves;

  if (player.lives < 1)
  {
    printf("No more LIVES remaining!\n\n");
  }

  if (game.maxMoves < 1)
  {
    printf("No more MOVES remaining!\n\n");
  }

  if (nextMove > 0)
  {
    for (i = 0; nextMove > i; i++)
    {
      printf(" ");
    }
    printf(" %c", player.plyrChar);
    printf("\n");
  }

  printf("  ");
  for (i = 0; i < game.pathLength; i++)
  {
    if (player.positionHis[i] == 0)
    {
      printf("-");
    }
    else if (player.positionHis[i] == 1)
    {
      printf("!");
    }
    else if (player.positionHis[i] == 2)
    {
      printf("$");
    }
    else if (player.positionHis[i] == 3)
    {
      printf("&");
    }
    else if (player.positionHis[i] == 4)
    {
      printf(".");
    }
  }
  printf("\n");

  printf("  ");
  for (i = 0; i < game.pathLength; i++)
  {
    if ((i + 1) % 10 != 0)
    {
      printf("|");
    }
    else
    {
      printf("%d", (i + 1) / 10);
    }
  }
  printf("\n");

  printf("  ");
  for (i = 0; i < game.pathLength; i++)
  {
    printf("%d", (i + 1) % 10);
  }
  printf("\n");

  printf("+---------------------------------------------------+\n");
  printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.numOfTreasures, game.maxMoves);
  printf("+---------------------------------------------------+\n\n");

  printf("##################\n"
         "#   Game over!   #\n"
         "##################\n\n");

  printf("You should play again and try to beat your score!\n\n");

  return 0;
}
