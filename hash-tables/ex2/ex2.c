#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  // YOUR CODE HERE
  // populate the ht with all the ticketes - loop through array of tickets
  for (int i = 0; i < length; i++)
  {
    // check if the source of a ticket is "NONE"
    if (strcmp(tickets[i]->source, "NONE") == 0)
    {
      // this will be the starting destination
      // initialize route[0] = ticket[i]->destination
      route[0] = tickets[i]->destination;
    }
    else
    {
      // else, insert into the ht
      hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
    }
  }

  // reconstruct the trip using the info in the ht, loop through length again
  for (int i = 1; i < length; i++)
  {

    // retrieve key/value pair associated with destination in route[0]
    char *next_destination = hash_table_retrieve(ht, route[i - 1]);
    if (next_destination != NULL)
    {
      // add the value as the next element in the route array
      route[i] = next_destination;
    }
    else
    {
      // last ticket
      route[i] = "NONE";
    }
  }

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%s\n", route[i]);
  }
}

#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
