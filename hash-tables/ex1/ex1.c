#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  // store each weight in the input list as keys
  // store each weight's list index as its value, we can then check
  // to see if the hash table contains an entry for limit - weight
  if (length < 2)
  {
    return NULL;
  }
  for (int i = 0; i < length; i++)
  {
    if (weights[i] != NULL)
    {
      hash_table_insert(ht, weights[i], i);
      printf("+{KEY: %d: VALUE: %d}.\n", weights[i], i);
      int diff = weights[i] - i;
      printf("%d - %d = %d\n", weights[i], i, diff);
    }
  }

  printf("Length: %d\n", length);
  printf("Limit: %d\n", limit);
  printf(",,,,,.......--------=========--------.......,,,,,\n\n");

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3); // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4); // {6, 2}

  return 0;
}
#endif
