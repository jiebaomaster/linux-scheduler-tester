#include <unistd.h>
#include <sched.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

static const long long pagesize = 1024 * 4;
static const long long pagenum = 500;

void Run(int idx)
{
  if (idx % 5)
  {
    int a, b;
    for (int j = 0; j < 20; j++)
    {
      for (int i = 0; i < 120000000; i++)
      {
        a = b;
      }
    }
  }
  else
  {
    int a, b;
    for (int j = 0; j < 20; j++)
    {
      for (int i = 0; i < 120000000; i++)
      {
        a = b;
      }
      if (j % 10 == 0)
      {
        char *p = (char *)malloc(pagesize * pagenum);
        memset(p, 1, pagesize * pagenum);
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  cpu_set_t mask;
  CPU_ZERO(&mask);
  CPU_SET(2, &mask);
  sched_setaffinity(0, sizeof(cpu_set_t), &mask);
  for (int i = 0; i < 30; i++)
  {
    if (fork() == 0)
    {
      Run(i);
      break;
    }
    else
    {
    }
  }
  int status = 0;
  int corpse;

  while ((corpse = waitpid(0, &status, 0)) > 0)
    return 0;
}