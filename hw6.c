#include <stdio.h>
int arr[25][25], loc[25];
  char tmp1[3], tmp3[3];
int main()
{
  
  int tmp2, tmp4;
  int num, k, r, W, m, M;
  while (scanf("%d", &num) != EOF)
  {
    for (int i = 0; i < 25; ++i)
    {
      for (int j = 0; j < 25; ++j)
      {
        if (j != 0)
        {
          arr[i][j] = 100;
        }
        else
        {
          arr[i][j] = i;
        }
      }
    }
    for (int i = 0; i < 25; ++i)
    {
      loc[i] = i;
    }
    while (scanf("%s", tmp1), tmp1[0] != 'q')
    {
      scanf("%d", &tmp2);
      scanf("%s", tmp3);
      scanf("%d", &tmp4);
      //printf("%c%c\n",tmp1[2],tmp3[1]);
      if (tmp1[2] == 'v' && tmp3[1] == 'n')
      {

        if (tmp2 != tmp4 && loc[tmp2] != loc[tmp4])
        {
          for (int l = 0; l < num; ++l)
          {
            if (arr[loc[tmp2]][l] == tmp2)
            {
              k = l;
              break;
            }
          }
          int x = k;
          //printf("%d\n",arr[loc[tmp2]][k+1]);
          while (arr[loc[tmp2]][k] != 100)
          {

            if (k != x)
            {
              arr[arr[loc[tmp2]][k]][0] = arr[loc[tmp2]][k];
              loc[arr[loc[tmp2]][k]] = arr[loc[tmp2]][k];
              //puts("gg");
            }
            k++;
          }
          for (int E = x + 1; E <= k; E++)
          {
            arr[loc[tmp2]][E] = 100;
          }
          for (int l = 0; l < num; ++l)
          {
            if (arr[loc[tmp4]][l] == tmp4)
            {
              k = l;

              break;
            }
          }
          int y = k;
          while (arr[loc[tmp4]][k] != 100)
          {
            if (k != y)
            {
              arr[arr[loc[tmp4]][k]][0] = arr[loc[tmp4]][k];
              loc[arr[loc[tmp4]][k]] = arr[loc[tmp4]][k];
            }
            k++;
          }
          for (int E = y + 1; E <= k; E++)
          {
            arr[loc[tmp4]][E] = 100;
          }
          arr[loc[tmp4]][y + 1] = tmp2;
          arr[loc[tmp2]][x] = 100;
          loc[tmp2] = loc[tmp4];
        }
      }
      else if (tmp1[2] == 'v' && tmp3[1] == 'v')
      {
        //puts("gg");
        if (tmp2 != tmp4 && loc[tmp2] != loc[tmp4])
        {
          for (int l = 0; l < num; ++l)
          {
            if (arr[loc[tmp2]][l] == tmp2)
            {
              k = l;
              break;
            }
          }
          int x = k;
          //printf("%d\n",arr[loc[tmp2]][k+1]);
          while (arr[loc[tmp2]][k] != 100)
          {

            if (k != x)
            {
              arr[arr[loc[tmp2]][k]][0] = arr[loc[tmp2]][k];
              loc[arr[loc[tmp2]][k]] = arr[loc[tmp2]][k];
              //puts("gg");
            }
            k++;
          }
          for (int E = x + 1; E <= k; E++)
          {
            arr[loc[tmp2]][E] = 100;
          }
          for (int i = 0; i < num; ++i)
          {
            if (arr[loc[tmp4]][i] == 100)
            {
              r = i;
              break;
            }
          }

          arr[loc[tmp4]][r] = tmp2;
          arr[loc[tmp2]][x] = 100;
          loc[tmp2] = loc[tmp4];
        }
      }
      else if (tmp1[2] == 'l' && tmp3[1] == 'n')
      {
        if (tmp2 != tmp4 && loc[tmp2] != loc[tmp4])
        {
          for (int l = 0; l < num; ++l)
          {
            if (arr[loc[tmp4]][l] == tmp4)
            {
              k = l;

              break;
            }
          }
          int y = k;
          while (arr[loc[tmp4]][k] != 100)
          {
            if (k != y)
            {
              arr[arr[loc[tmp4]][k]][0] = arr[loc[tmp4]][k];
              loc[arr[loc[tmp4]][k]] = arr[loc[tmp4]][k];
            }
            k++;
          }
          for (int E = y + 1; E <= k; E++)
          {
            arr[loc[tmp4]][E] = 100;
          }
          for (int eee = 0; eee < num; eee++)
          {
            if (arr[loc[tmp2]][eee] == tmp2)
            {
              k = eee;
              break;
            }
          }
          int EEE = k;
          int tmp_tmp2 = loc[tmp2];
          for (int ee = EEE; ee < num; ee++)
          {
            if (arr[tmp_tmp2][ee] == 100)
            {
              break;
            }
            arr[loc[tmp4]][y + 1] = arr[tmp_tmp2][ee];
            loc[arr[tmp_tmp2][ee]] = loc[tmp4];
            y++;
          }
          for (int q = EEE; q <= y; q++)
          {
            arr[tmp_tmp2][q] = 100;
          }
        }
      }
      else if (tmp1[2] == 'l' && tmp3[1] == 'v')
      {
        if (tmp2 != tmp4 && loc[tmp2] != loc[tmp4])
        {
          for (int i = 0; i < num; i++)
          {
            if (arr[loc[tmp4]][i] == 100)
            {
              m = i;
              break;
            }
          }
          for (int qp = 0; qp < num; qp++)
          {
            if (arr[loc[tmp2]][qp] == tmp2)
            {
              M = qp;
              break;
            }
          }
          int evantmp2 = loc[tmp2];
          for (int evan = M; evan < num; evan++)
          {
            if (arr[evantmp2][evan] == 100)
            {
              break;
            }
            arr[loc[tmp4]][m] = arr[evantmp2][evan];
            loc[arr[evantmp2][evan]] = loc[tmp4];
            m++;
          }
          for (int q = M; q < num; q++)
          {
            arr[evantmp2][q] = 100;
          }
        }
      }
    }
    for (int i = 0; i < num; ++i)
    {
      printf("%d: ", i);
      for (int j = 0; j < num; ++j)
      {
        if (arr[i][j] == 100)
        {
          continue;
        }

        printf("%d ", arr[i][j]);
      }
      printf("\n");
    }
    //for (int p = 0; p < num; p++)
    //{
      //printf("%d ", loc[p]);
    //}
  }
  return 0;
}
