#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>

using namespace std;

const long long int MAX_NUMBER = 100000;
struct Node
{
	int data;
	Node* next;
};

void add_first_node(struct Node* list)
{
	srand(time(NULL));
	list->data = rand()% MAX_NUMBER + 1;
	list->next = NULL;
	return;
}

void add_node(struct Node* list)
{
	Node* temp = new Node;
	temp->data = rand() % MAX_NUMBER + 1;
	temp->next = NULL;
	if(list == NULL)
	{
		list = temp;
		return;
	}

	Node *l = list;
	while(l)
	{
		if(l->next == NULL)
		{
			l->next = temp;
			return;
		}
		l = l->next;
	}
}

double search_node(struct Node *list)
{
	int x = rand() % MAX_NUMBER + 1;

	//cout << x <<endl;
	clock_t t0 = clock();
	timeval tim;
    
    gettimeofday(&tim, NULL);
    double t1=tim.tv_sec+ (tim.tv_usec/1000000.0);
    
    Node *temp= list;
	while(temp)
	{
		if(temp->data == x)
		{
			gettimeofday(&tim, NULL);
    		double t2=tim.tv_sec+(tim.tv_usec/1000000.0);
			return (t2 - t1)*1000000.0;
		}
		temp = temp->next;
	}
	gettimeofday(&tim, NULL);
	double t2=tim.tv_sec+(tim.tv_usec/1000000.0);
	return (t2 - t1)*-1000000.0;
}

void print_ll(struct Node *list)
{
	Node *temp = list;
	while(temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
	return;
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		cout << "Please add the number of insertions and number of items to search" << endl;
		return 0;
	}
	long long int num_insert = stoi(argv[1]), num_search = stoi(argv[2]),i, x;
	double time_diff;
	
	struct Node *list = new Node;
	
	add_first_node(list);

	for(i=0;i<num_insert-1;i++)
	{
		add_node(list);
	}

	// cout << "Linked List: ";
	// print_ll(list);
	// cout << "Addition into Linked List Done\n" << endl;

	i = 0;
	double sum = 0.0;
	while(i++ < num_search)
	{
		time_diff = search_node(list);
		if(time_diff >= 0)
		{
			sum += time_diff;
			// printf("Found\n\nTime taken: %.6lf Micro seconds\n\n", time_diff);
		}
		else
		{
			sum += time_diff*-1;
			// printf("Not Found\n\nTime taken: %.6lf Micro seconds\n\n", time_diff*-1);
		}
	}

	cout << "Average Time in MicroSeconds: " << sum/num_search << endl;

	return 0;
}
