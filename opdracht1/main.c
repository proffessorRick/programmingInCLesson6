#include <stdio.h>
#include <stdlib.h>

typedef struct _listItem_ {
  void *data;
  struct _listItem_ *next;
} listItem;

typedef struct {
  listItem *head, *tail;
} list;

void listInit(list *tha_list);
void listAddToTail(void *data, list *tha_list);
void listPrint(list *tha_list);
void listFree(list *tha_list);

int main() {
  // Make A Few Capital Cities Variables //
  char *a = "London", *b = "Berlin", *c = "Madrid", *d = "Dublin";

  // Make A New List //
  list myList;

  // Initialize The List //
  listInit(&myList);

  // Add Some Stuff To The List //
  listAddToTail((void *)a, &myList);
  listAddToTail((void *)b, &myList);
  listAddToTail((void *)c, &myList);
  listAddToTail((void *)d, &myList);

  // Print The List On Screen //
  listPrint(&myList);
  listFree(&myList);

  return 0;
}

void listInit(list *tha_list) {
  tha_list->head = NULL;
  tha_list->tail = NULL;
}

// This May Work //
void listAddToTail(void *data, list *tha_list) {
  // printf("Function listAddToTail\n");

  // 1. Maak een nieuwe listItem aan met malloc()
  listItem *item = malloc(sizeof(listItem));

  // 2. Zet 'data' in de listItem en verwijs met next naar NULL
  item->data = data;
  item->next = NULL;

  // 3. Als de lijst leeg is:
  if (tha_list->head == NULL) {
    // Laat zowel de head- als de tail-pointer naar het nieuwe item wijzen
    tha_list->head=item;
    tha_list->tail=item;
  }
  // Als de lijst niet leeg is:
  else {
    // De next-pointer v.h. huidige laatste item moet naar het nieuwe laatste item gaan wijzen
    // De tail-pointer moet vervolgens ook naar het nieuwe laatste item gaan wijzen
    tha_list->tail->next = item;
    tha_list->tail = item;
  }
}

void listPrint(list *tha_list) {
  // Als de lijst niet leeg is:
  if (tha_list->head != NULL) {
    listItem *current = tha_list->head;

    // laat een langsloop-variabele wijzen naar de lead van de list zolang een langsloop variabele niet NULL is
    while (current) {
      // print het huidige data-item
      // laat de langsloop-variabele wijzen naar het item waar de next-pointer van het huidige item naar wijst
      char *value = current->data;
      printf("Item = %s\n", value);

      current = current->next;
    }
  }

  // Als de lijst leeg is:
  else {
    // print "de lijst is leeg"
    printf("de lijst is leeg\n");
  }
}

void listFree(list *tha_list) {
  listItem *current, *next;

  current = tha_list->head;

  while (current != NULL) {
    next = current->next;

    free(current);

    current = next;
  }

  listInit(tha_list);
}
