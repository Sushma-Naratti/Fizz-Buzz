#include <stdio.h>
#include <string.h>
char **FizzBuzz(int n)
{
      char **answer = (char **)malloc(n * sizeof(char *));
      for (int i = 1; i <= n; i++)
      {
            if (i % 3 == 0 && i % 5 == 0)
            {
                  answer[i - 1] = (char *)malloc(9 * sizeof(char));
                  strcpy(answer[i - 1], "FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                  answer[i - 1] = (char *)malloc(5 * sizeof(char));
                  strcpy(answer[i - 1], "Fizz");
            }
            else if (i % 5 == 0)
            {
                  answer[i - 1] = (char *)malloc(5 * sizeof(char));
                  strcpy(answer[i - 1], "Buzz");
            }
            else
            {
                  int len = snprintf(NULL, 0, "%d", i) + 1;
                  answer[i - 1] = (char *)malloc(len * sizeof(char));
                  snprintf(answer[i - 1], len, "%d", i);
            }
      }
      return answer;
}
int main()
{
      int n;
      printf("Enter an integer number :");
      scanf("%d", &n);
      char **result = FizzBuzz(n);
      printf("[");
      for (int i = 0; i < n; i++)
      {
            printf("\"%s\"", result[i]);
            if (i != n - 1)
            {
                  printf(",");
            }
            free(result[i]);
      }
      printf("]");
      free(result);
      return 0;
}