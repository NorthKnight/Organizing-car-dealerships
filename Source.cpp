#include<iostream>
#include<string>
#include<conio.h> 
#include <stdlib.h> 
using namespace std;
void addagency(string);
void addservice(string , string , string , string , string );
void addsubservice(string , string , string , string , string , string );
void addtoagency(string, string);
void remove(string, string);
void printagencieslist();
void printsubservice(string);
void printservices();
void swap(int*, int*);
int getrightchild(int[], int);
int getleftchild(int[], int);
int getparent(int[], int);
void maxheap(int[], int);
int extramax(int[]);
void increase_key(int[], int, int);
void insert(int[], int);
void printheap(int[]);
void process(int[]);
void printeachagency(string);
// Prioritization levels : necessary , required , normal .
void order_service(string, string, string);

typedef struct link
{
	struct service *data;
	struct link *next;
}link;
typedef struct service
{
	string sname;
	string typecar;
	string customexplain;
	string agencyexplain;
	string cost;
	struct service *next;
	struct service *down;
}service;

typedef struct agency
{
	string aname;
	struct agency *next;
	struct link *down;
}agency;

service *sstart;
agency *astart;
int necessary = 30 , required =20 ,normal = 10 , treearraysize=31;
int heap[31];
int heap_size = 0;


void main()
{
	////////////////////////////////////////////////////////////////////////
	addservice("lastick", "peride", "fffffff", "gggggggg", "1000000");
	addservice("badane", "samand", "lllllll", "eeeeeeee", "2000000");
	addservice("dakheli", "ford", "ooooooo", "rrrrrrrr", "3000000");
	addservice("motor", "bmw", "nnnnnnn", "tttttttt", "4000000");
	addservice("ghataat", "benz", "bbbbbbb", "uuuuuuuu", "5000000");
	addservice("anjektor", "audi", "vvvvvvv", "pppppppp", "6000000");
	////////////////////////////////////////////////////////////////////////
	addsubservice("lastick", "panchargiri", "tiba", "wwwwwww", "kkkkkkk", "1200000");
	addsubservice("lastick", "tanzimbad", "pejo", "zzzzzzz", "xxxxxxx", "7400000");
	addsubservice("lastick", "lent", "reno", "ccccccc", "gxgxgxg", "3500000");
	addsubservice("badane", "cheragh", "lambor", "vvvvvvv", "qzzqzqz", "7100000");
	addsubservice("badane", "zeh", "citreon", "hhhhhhh", "tututut", "5500000");
	addsubservice("badane", "gelgir", "volvo", "aaaaaaa", "ktktktk", "3300000");
	addsubservice("dakheli", "farman", "aston martin", "qqqqqqq", "mdmdmdm", "2700000");
	addsubservice("dakheli", "jolobandi", "cheverlot", "sssssss", "lslslsl", "2600000");
	addsubservice("dakheli", "sandali", "wagen", "ddddddd", "hahahah", "4400000");
	addsubservice("ghataat", "pasazforosh", "ferrari", "eeeeeee", "jkjkjkj", "9300000");
	addsubservice("ghataat", "yekbarmasraf", "santafe", "iiiiiii", "lrghfhj", "3700000");
	addsubservice("ghataat", "garanti", "cerato", "jjjjjjj", "nnbnbnn", "4600000");
	/////////////////////////////////////////////////////////////////////////
	addagency("sarsabz");
	addagency("satarkhan");
	addagency("pirozi");
	addagency("pasdaran");
	addagency("narmak");
	/////////////////////////////////////////////////////////////////////////
	addtoagency("lastick", "sarsabz");
	addtoagency("motor", "sarsabz");
	addtoagency("badane", "sarsabz");
	addtoagency("dakheli", "sarsabz");
	addtoagency("lastick", "satarkhan");
	addtoagency("ghataat", "satarkhan");
	addtoagency("dakheli", "satarkhan");
	addtoagency("lastick", "pirozi");
	addtoagency("badane", "pirozi");
	addtoagency("dakheli", "pirozi");
	addtoagency("motor", "pirozi");
	addtoagency("anjektor", "pirozi");
	addtoagency("lastick", "pasdaran");
	addtoagency("badane", "pasdaran");
	addtoagency("lastick", "narmak");
	addtoagency("badane", "narmak");
	addtoagency("dakheli", "narmak");
	addtoagency("ghataat", "narmak");
	//////////////////////////////////////////////////////////////////////////
	cout << "List of agency : "<<endl<<" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ "<<endl<<endl;
	printagencieslist();
	cout << endl << endl;
	cout << "List of service with subservices : " << endl << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ "<<endl<<endl;
	printservices();
	cout << endl << endl;
	printsubservice("lastick");
	cout << endl;
	printsubservice("badane");
	cout << endl;
	printsubservice("dakheli");
	cout << endl;
	printsubservice("motor");
	cout << endl;
	printsubservice("ghataat");
	cout << endl;
	printsubservice("anjektor");
	cout << endl;
	//////////////////////////////////////////////////////////////////////////
	order_service("sarsabz", "lastick","normal");
	order_service("sarsabz", "lastick", "required");
	order_service("sarsabz", "lastick", "normal");
	order_service("sarsabz", "lastick", "required");
	order_service("sarsabz", "lastick", "normal");
	order_service("sarsabz", "lastick", "required");
	order_service("sarsabz", "lastick", "normal");
	order_service("sarsabz", "lastick", "required");
	order_service("sarsabz", "lastick", "required");
	order_service("sarsabz", "lastick", "normal");
	order_service("sarsabz", "lastick", "required");
	order_service("sarsabz", "lastick", "normal");
	order_service("sarsabz", "lastick", "normal");
	order_service("sarsabz", "lastick", "required");
	order_service("sarsabz", "lastick", "necessary");
	order_service("sarsabz", "lastick", "necessary");
	order_service("sarsabz", "lastick", "normal");
	order_service("sarsabz", "lastick", "necessary");
	order_service("sarsabz", "lastick", "necessary");
	order_service("sarsabz", "lastick", "necessary");
	//////////////////////////////////////////////////////////////////////////
	cout << endl << endl;
	process(heap);
	cout << endl << endl<<endl;
	printeachagency("sarsabz");
	cout << endl << endl;
	printeachagency("satarkhan");
	cout << endl << endl;
	printeachagency("pirozi");
	cout << endl << endl;
	printeachagency("pasdaran");
	cout << endl << endl;
	printeachagency("narmak");
	cout << endl << endl;
	//////////////////////////////////////////////////////////////////////////
	remove("sarsabz", "lastick");
	remove("satarkhan","ghataat");
	remove("pasdaran", "badane");
	remove("narmak", "dakheli");
	////////////////////////////
	cout << endl << "list of agency with services after removing :" << endl << "--------------------------------------------";
	cout << endl << endl<<endl;
	printeachagency("sarsabz");
	cout << endl << endl;
	printeachagency("satarkhan");
	cout << endl << endl;
	printeachagency("pasdaran");
	cout << endl << endl;
	printeachagency("narmak");
	cout << endl << endl;
}

void addagency(string str)
{
	if (astart == NULL)
	{
		astart = new agency;
		astart->aname = str;
		astart->down = NULL;
		astart->next = NULL;
	}
	else
	{
		agency *current = astart;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next= new agency;
		current->next->aname = str;
		current->next->down = NULL;
		current->next->next = NULL;
	}
}

void addservice(string name, string car, string cexplain, string aexplain, string price)
{
	if (sstart == NULL)
	{
		sstart =new service;
		sstart->sname = name;
		sstart->typecar = car;
		sstart->customexplain = cexplain;
		sstart->agencyexplain = aexplain;
		sstart->cost = price;
		sstart->next = NULL;
		sstart->down = NULL;
	
	}
	else
	{
		service *current = sstart;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next= new service;
		current->next->sname = name;
		current->next->typecar = car;
		current->next->customexplain = cexplain;
		current->next->agencyexplain = aexplain;
		current->next->cost = price;
		current->next->next = NULL;
		current->next->down = NULL;
	

	}
}


void addsubservice(string root, string name, string car, string cexplain, string aexplain, string price)
{
	service *current = sstart;
	while (current->sname != root)
	{
		current = current->next;
	}
	if (current->down==NULL)
	{
		current->down = new service;
		current->down->sname = name;
		current->down->typecar = car;
		current->down->customexplain = cexplain;
		current->down->agencyexplain = aexplain;
		current->down->cost = price;
		current->down->down = NULL;
		current->down->next = NULL;
	
	}
	else
	{
		current = current->down;
			while (current->next !=NULL)
			{
				current = current->next;
			}
			current->next=new service;
			current->next->sname = name;
			current->next->typecar = car;
			current->next->customexplain = cexplain;
			current->next->agencyexplain = aexplain;
			current->next->cost = price;
			current->next->down = NULL;
			current->next->next = NULL;
		
	}
}


void addtoagency(string servicename, string agancyname)
{
	service *current = sstart;
	while (current->sname != servicename )
	{
		current = current->next;
	}

	agency *c = astart;
	while (c->aname != agancyname)
	{
		c = c->next;
	}
	if (c->down==NULL)
	{
		c->down = new link;
		c->down->data = current;
		c->down->next = NULL;
	}
	else
	{
		link *pl = c->down;
		while (pl->next !=NULL)
		{
			pl = pl->next;
		}
		pl->next = new link;
		pl->next->data = current;
		pl->next->next = NULL;
	}
}

void remove(string agancyname , string servicename)
{
	service *current = sstart;
	while (current->sname != servicename)
	{
		current = current->next;
	}
	agency *c = astart;
	while (c->aname != agancyname)
	{
		c = c->next;
	}
	if (c->down->data==current)
	{
		link *p = c->down;
		c->down = p->next;
		free(p);
	}
	else
	{
		link *pl = c->down;
		while (pl->next->data !=current)
		{
			pl = pl->next;
		}
		if (pl->next->next ==NULL)
		{
		//	free(pl->next);
			pl->next = NULL;
		}
		else
		{
			link *d = pl->next;
			pl->next = d->next;
			free(d);
		}
	}
}

void printagencieslist()
{
	agency *current = astart;
	while (current != NULL)
	{
		
		cout << current->aname << endl;
		current = current->next;
	}
}

void printsubservice(string std)
{
	service *current = sstart;
	while (current->sname !=std)
	{
		current = current->next;
	}
	current = current->down;
	cout << std << endl<<"----------------------------------------------------"<<endl<<endl;
	while (current!=NULL)
	{
		cout<< current->sname << " ---------- " << current->typecar << " ---------- " << current->customexplain << " --------- " << current->agencyexplain << " ---------- " << current->cost << endl;
		current = current->next;
	}
	cout << endl << "****************************************************" << endl<<endl;
}

void printservices()
{
	service *c = sstart;
	while (c!=NULL)
	{
		printsubservice(c->sname);
		c = c->next;
	}
}

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int getrightchild(int A[], int index) 
{
	if ((((2 * index) + 1) < treearraysize) && (index >= 1))
		return (2 * index) + 1;
	return -1;
}

int getleftchild(int A[], int index)
{
	if (((2 * index) < treearraysize) && (index >= 1))
		return 2 * index;
	return -1;
}


int getparent(int A[], int index)
{
	if ((index > 1) && (index < treearraysize)) {
		return index / 2;
	}
	return -1;
}


void maxheap(int A[], int index) 
{
	int left_child_index = getleftchild(A, index);
	int right_child_index = getrightchild(A, index);

	
	int largest = index;

	if ((left_child_index <= heap_size) && (left_child_index>0)) {
		if (A[left_child_index] > A[largest]) {
			largest = left_child_index;
		}
	}

	if ((right_child_index <= heap_size && (right_child_index>0))) {
		if (A[right_child_index] > A[largest]) {
			largest = right_child_index;
		}
	}

	
	if (largest != index) {
		swap(&A[index], &A[largest]);
		maxheap(A, largest);
	}
}

int extramax(int A[])
{
	int maxm = A[1];
	A[1] = A[heap_size];
	heap_size--;
	maxheap(A, 1);
	return maxm;
}

void increase_key(int A[], int index, int key)
{
	A[index] = key;
	while ((index>1) && (A[getparent(A, index)] < A[index])) {
		swap(&A[index], &A[getparent(A, index)]);
		index = getparent(A, index);
	}
}
void insert(int A[], int key) 
{
	heap_size++;
	A[heap_size] = -1 * 1000000;
	increase_key(A, heap_size, key);
}

void order_service(string agancy_name, string service_name, string prioritization)
{
	if (prioritization== "necessary" && necessary>20 )
	{
		insert(heap , necessary);
		cout << "your number in queue is :  " << necessary << " and you can take " << service_name << " in " << agancy_name << endl<<endl;
		necessary = necessary - 1;
	}

	if (prioritization == "required" && required>10)
	{
		insert(heap, required);
		cout << "your number in queue is :  " << required << " and you can take " << service_name << " in " << agancy_name << endl<<endl;
		required = required - 1;
	}

	if (prioritization == "normal" && normal>0)
	{
		insert(heap, normal);
		cout << "your number in queue is :  " << normal << " and you can take " << service_name << " in " << agancy_name << endl<<endl;
		normal = normal - 1;
	}

}

void printheap(int A[])
{
	for (int i = 1; i <= heap_size; i++) {
		cout << A[i];
	}
	cout << endl;
}

void process(int A[])
{
	while (heap_size>0)
	{
		cout << extramax(A) << endl;

	}
}

void printeachagency(string aname)
{
	cout << aname << " $$$$ ";
	agency *c = astart;
	while (c->aname != aname)
	{
		c = c->next;
	}
	link *c1 = c->down;
	while (c1 != NULL)
	{
		service *current = sstart;
		while (current != c1->data)
		{
			current = current->next;
		}
		cout << current->sname << " ----- ";
		c1 = c1->next;
	}

}



