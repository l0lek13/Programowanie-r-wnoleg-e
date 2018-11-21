#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int zmienna_wspolna=0;


void * zadanie_watku (void * arg_wsk)
{
  pthread_testcancel();
  int moj_arg;
  moj_arg = *( (int *) arg_wsk );

  printf("Moj id z metody self %ld \n",pthread_self());
  printf("Id z argumentu przekaznaego %d \n",moj_arg);
  return(NULL);
}

int main()
{
	pthread_t tid;
	pthread_attr_t attr;
	void *wynik;
	int i;

	pthread_t tab[1000];
	int arg[1000];
	
	for( i =0;i<1000;i++)
	  {
	    arg[i]=i;
	    pthread_create(&tab[i] , NULL, zadanie_watku, &arg[i]);

	  }
	for(i=0;i<1000;i++)
	  {
	    pthread_join(tab[i],NULL);
	  }

}


