#include <stdio.h>
#include <stdlib.h>

// Przygotuj program który pozwoli na zagranie w papier, kamień, nożyce.
// Natomiast program ma zapisywać wyniki oraz ruchy w poszczególnych rundach w tablicy oraz pozwalać na zwrócenie ich do terminala, po wpisaniu przez użytkownika odpowiedniej komendy jak na przykład scores czy analogicznej.

char *convert_choice(char choice)
{
  switch (choice)
  {
  case '1':
    return "Papier";
  case '2':
    return "Kamien";
  case '3':
    return "Nozyce";
  }
  return "";
}

int main()
{
  printf("Gra w papier/kamień/nozyce. \n ");

  char choice = 'x';
  int round = 0;

  char scores[10][3];

  while (1)
  {
    printf("----------------------------- \n");
    printf("Runda: %d \n", round + 1);
    printf("Wybierz opcję: \n");
    printf("1. Papier \n");
    printf("2. Kamień \n");
    printf("3. Nozyce \n");
    printf("w. Tablica wynikow \n");
    printf("e. Wyjście \n");

    scanf("%c", &choice);
    getchar();
    printf("Wybrales: %c \n", choice);

    int computer_choice = rand() % 3 + 1 + '0';
    int player_won = 0;

    switch (choice)
    {
    case '1':
    case '2':
    case '3':
      printf("Komputer wybral %s \n", convert_choice(computer_choice));

      switch (computer_choice)
      {
      case '1':
        if (choice == '1')
        {
          printf("Remis \n");
        }
        else if (choice == '2')
        {
          printf("Przegrales \n");
        }
        else if (choice == '3')
        {
          printf("Wygrales \n");
          player_won = 1;
        }
        break;
      case '2':
        if (choice == '1')
        {
          printf("Wygrales \n");
          player_won = 1;
        }
        else if (choice == '2')
        {
          printf("Remis \n");
        }
        else if (choice == '3')
        {
          printf("Przegrales \n");
        }
        break;
      case '3':
        if (choice == '1')
        {
          printf("Przegrales \n");
        }
        else if (choice == '2')
        {
          printf("Wygrales \n");
          player_won = 1;
        }
        else if (choice == '3')
        {
          printf("Remis \n");
        }
        break;
      }

      if (round == 10)
      {
        round = 0;
      }
      else
      {
        round++;
      }

      scores[round][0] = player_won;
      scores[round][1] = choice;
      scores[round][2] = computer_choice;

      continue;
    case 'w':
      printf("Tablica wynikow (ostatnie 10 rund): \n");
      for (int i = 0; i < 10; i++)
      {
        printf("--- Runda: #%d \n", i + 1);
        printf("Wynik: %s \n", scores[i][0] ? "wygrana" : "przegrana");
        printf("* Twoj wybor: %s \n", convert_choice(scores[i][1]));
        printf("* wybor komputera: %s \n", convert_choice(scores[i][2]));
      }
      continue;
    case 'e':
      printf("Koniec gry \n");
      break;
    }

    return 0;
  }
}
