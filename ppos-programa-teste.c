// Programa de testes baseado em pingpong-scheduler.c

#include <stdio.h>
#include <stdlib.h>
#include "ppos.h"

task_t Pang, Peng, Ping, Pong, Pung;

void Body(void *arg)
{
    int i ;

    printf ("%s: inicio (prioridade %d)\n", (char *) arg, task_getprio(NULL)) ;

    for (i=0; i<10; i++)
    {
        printf ("%s: %d\n", (char *) arg, i) ;
        task_yield ();
    }
    printf ("%s: fim\n", (char *) arg) ;
    task_exit (0) ;
}


int main (int argc, char *argv[])
{
  printf ("main: inicio\n");

  ppos_init () ;

  task_create (&Pang, Body, "    Pang") ;
  task_setprio (&Pang, 2);

  task_create (&Peng, Body, "        Peng") ;
  task_setprio (&Peng, 3);

  task_create (&Ping, Body, "            Ping") ;
  task_setprio (&Ping, 1);

  task_create (&Pong, Body, "                Pong") ;
  task_setprio (&Pong, 4);

  task_create (&Pung, Body, "                    Pung") ;
  task_setprio (&Pung, 5);

  task_join(&Pang);
  task_join(&Peng);
  task_join(&Ping);
  task_join(&Ping);
  task_join(&Pung);

  printf ("main: fim\n");
  exit (0) ;
}