#include <stdio.h>
#include <string.h>

struct Contact
{
  char first_name[255];
  char last_name[255];
  char phone[255];
};

static int CONTACTS_LENGTH = 25;

void display_contacts(struct Contact *contacts)
{
  printf("Lista kontaktow:\n");

  for (int i = 0; i < CONTACTS_LENGTH; i++)
  {
    printf("Kontakt %d: %s %s, tel: %s", i + 1, contacts[i].first_name, contacts[i].last_name, contacts[i].phone);
    printf("\n");
  }
}

void add_contact(struct Contact *contacts, char *first_name, char *last_name, char *phone)
{
  for (int i = 0; i < CONTACTS_LENGTH; i++)
  {
    if (contacts[i].first_name[0] == '\0')
    {
      sprintf(contacts[i].first_name, "%s", first_name);
      sprintf(contacts[i].last_name, "%s", last_name);
      sprintf(contacts[i].phone, "%s", phone);
      return;
    }
  }
  printf("Brak miejsca na dodanie kontaktu\n");
  return;
}

struct Contact *find_contact(struct Contact *contacts, char *last_name)
{
  for (int i = 0; i < CONTACTS_LENGTH; i++)
  {
    if (strcmp(contacts[i].last_name, last_name) == 0)
    {
      return &contacts[i];
    }
  }
  return NULL;
}

void remove_contact(struct Contact *contacts, char *last_name)
{
  for (int i = 0; i < CONTACTS_LENGTH; i++)
  {
    if (strcmp(contacts[i].last_name, last_name) == 0)
    {
      contacts[i].first_name[0] = '\0';
      contacts[i].last_name[0] = '\0';
      contacts[i].phone[0] = '\0';
      return;
    }
  }
}

int main()
{
  struct Contact contacts[CONTACTS_LENGTH];

  for (int i = 0; i < CONTACTS_LENGTH; i++) {
    contacts[i].first_name[0] = '\0';
    contacts[i].last_name[0] = '\0';
    contacts[i].phone[0] = '\0';
  }

  for (int i = 0; i < 20; i++)
  {
    sprintf(contacts[i].first_name, "Imie%d", i);
    sprintf(contacts[i].last_name, "Nazwisko%d", i);
    sprintf(contacts[i].phone, "12345678%d", i);
  }

  char action[1];
  char first_name[255];
  char last_name[255];
  char phone[255];

  char loop = 1;

  while (loop == 1)
  {
    printf("### ### ### ### ### ### ### ### ### ### ### \n");
    printf("Wybierz akcje: A (dodaj kontakt), remove, find, exit\n");
    printf("* a (dodaj kontakt)\n");
    printf("* r (usuń kontakt)\n");
    printf("* f (znajdź kontakt)\n");
    printf("* l (wyświetl wszystkie kontakty)\n");
    printf("* e (wyjdź z programu)\n");
    scanf("%s", action);

    switch (action[0]) {
      case 'a':
        printf("Podaj imie: ");
        scanf("%s", first_name);
        printf("Podaj nazwisko: ");
        scanf("%s", last_name);
        printf("Podaj telefon: ");
        scanf("%s", phone);
        add_contact(contacts, first_name, last_name, phone);
        break;
      case 'r':
        printf("Podaj nazwisko: ");
        scanf("%s", last_name);
        remove_contact(contacts, last_name);
        break;
      case 'f':
        printf("Podaj nazwisko: ");
        scanf("%s", last_name);
        struct Contact *c = find_contact(contacts, last_name);
        if (c != NULL)
        {
          printf("Znaleziono: %s %s, tel: %s \n", c->first_name, c->last_name, c->phone);
        }
        else
        {
          printf("Nie znaleziono \n");
        }
        break;
      case 'l':
        display_contacts(contacts);
        break;
      case 'e':
        loop = 0;
        break;
      default:
        printf("Nieznana akcja\n");
    }
  }

  return 0;
}
