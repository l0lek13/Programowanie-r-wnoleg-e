#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int zmienna_wspolna=0;

struct Trzy_pola
{
  int jeden;
  int dwa ;
  int trzy;
};



void * zadanie_watku (void * arg_wsk)
{
  pthread_testcancel();
  struct Trzy_pola  moj_arg;
  moj_arg = *( (struct Trzy_pola *) arg_wsk );

  printf("%d ,%d, %d", moj_arg.jeden, moj_arg.dwa, moj_arg.trzy); 
  return(NULL);
}

int main()
{
  struct Trzy_pola struct1 = {1,2,3};
  
	pthread_t tid;
	pthread_attr_t attr;
	void *wynik;
	int i;

	pthread_t tab[1000];
	int arg[1000];
	
	for( i =0;i<2;i++)
	  {
	    arg[i]=i;
	    pthread_create(&tab[i] , NULL, zadanie_watku, &struct1);

	  }
	for(i=0;i<2;i++)
	  {
	    pthread_join(tab[i],NULL);
	  }

}


