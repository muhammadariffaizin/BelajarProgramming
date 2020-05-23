#include <stdio.h>
#include <stdbool.h>

int adj[20][20];
int way[25];

int main ()
{
  int V;
  int E;
  int Vi;
  int Vj;
  int X;
  int i = 0;
  int j = 0;
  int isi = 0;

  scanf("%d %d", &V, &E);

  while (E--)
  {
    scanf("%d %d", &Vi, &Vj);
    
    adj[Vi][Vj] = 1;
  }

  scanf("%d", &X);

  way[isi] = X;
  way[isi + 1] = -1;
  isi++;

  for (i = 0; i < V; i++)
  {
    if (adj[X][i] == 1)
    {
      way[isi] = i;
      way[isi + 1] = -1;
      isi++;
    }
  }

  i = 0;

  while (j < V)
  {
    if (way[j] != -1)
    {
      for (i = 0; i < V; i++)
      {
        if (adj[way[j]][i] == 1)
        {
          int k = 0;
          int marker = 0;

          for (; k < isi; k++)
          {
            if (i == way[k])
            {
              marker = 1;
              break;
            }
          }

          if (marker == 0)
          {
            way[isi] = i;
            way[isi + 1] = -1;
            isi++;
          }
        }
      }
    }
    else
      break;

    j++;
  }
  

  for (i = 0; i < isi; i++)
    printf("%d -> ", way[i]);
  printf("END\n");

	return 0;
}