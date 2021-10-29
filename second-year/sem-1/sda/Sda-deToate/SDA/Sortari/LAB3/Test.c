#include <stdio.h>
#define N 25000
typedef struct masuratori{
	int index;
	float weight;
	float height;

} masuratori;
masuratori M[25000];

void citire(){
	FILE *f;
	char buffer[200];
	f = fopen("hw_25000r.txt", "r");
	if (f == NULL)
	{
		printf("EROARE");
		fclose(f);
	}
	fgets(buffer, 200, f);
	int i = 0;
	while (!feof(f)){
		fscanf(f, "%d; ", &M[i].index);
		fscanf(f, "%f; ", &M[i].height);
		fscanf(f, "%f\n", &M[i].weight);
		i++;
	}

}

void afisare(){
	int i;
	for (i = 0; i < N; i++)
	{

		printf("%d ", M[i].index);
		printf("%f ", M[i].height);
		printf("%f\n", M[i].weight);

	}

}

void sortare_prin_selectie(masuratori M[25000], int n)
{
	int i, j, max; 
    masuratori temp;
	for (i = 0; i <= n; i++)
	{
		max = i; 
        temp = M[i];
		for (j = i + 1; j < n; j++)
			if (M[j].height>temp.height)
			{
				max = j; temp = M[j];
			}   
		    M[max] = M[i]; 
            M[i] = temp;
	}  
} 
int main(){
	citire();
	sortare_prin_selectie(M,N);
	afisare();

}