#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
node* start = NULL;
void insert_beg()
{
	node* temp = new node();
	cout<<"\n\nEnter the value to insert at Beginning : ";
	cin>>temp->data;
	if(start == NULL)
	{
		start = temp;
		start->next = NULL;
		return;
	}
	node* ptr = start;
	start = temp;
	start->next = ptr;	
}
void insert_end()
{
	node* temp = new node();
	cout<<"\n\nEnter the value to insert at END : ";
	cin>>temp->data;
	if(start == NULL)
	{
		start = temp;
		start->next = NULL;
		return;
	}
	node* ptr = start;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
	temp->next = NULL;
}
void insert_pos()
{
	node*temp = new node();
	int p;
	cout<<"\n\nEnter specific position to enter data : ";
	cin>>p;
	if(p == 1){
		insert_beg();
		cout<<"\n\n\t\t\t***Node Inserted Successfully.***\n\n";
		return;
	}
	if(p == 0){
		cout<<"\n\nYou Entered Invalid Position.\n";
		return;
	}
	cout<<"\n\nEnter data to insert : ";
	cin>>temp->data;
	int i;
	node* ptr = start;
	for(i=2; i<p;i++)
	{
		ptr = ptr->next;	
	}
	temp->next = ptr->next;
	ptr->next = temp;
	cout<<"\n\n\t\t\t***Node Inserted Successfully.***\n\n";
}

void del_beg()
{
	if(start == NULL)
	{
		cout<<"\n\nList is Empty.\n\n";
		return;
	}
	node* ptr = start;
	start = ptr->next;
	delete ptr;
	cout<<"\n\nNode Deleted Successfully.\n\n";
	
}
void del_pos()
{
	if(start == NULL)
	{
		cout<<"\n\nList is Empty.\n\n\n";
		return;
	}
	cout<<"\n\t\t\t***Deleting From Specific Position Menu***";
	int p;
	cout<<"\n\nEnter the position of the node to delete : ";
	cin>>p;
	
	if(p == 0){
		cout<<"\n\nYou Entered Invalid Position.\n";
		return;
	}
	if(p == 1){
		del_beg();
		cout<<"\nNode Deleted Successfully.\n\n";
		return;
	}
	node* ptr = start;
	for(int i=2;i<p;i++)
	{
		ptr = ptr->next;
	}
	node* temp = ptr->next;
	ptr->next = ptr->next->next;
	delete temp;
	cout<<"\nNode Deleted Successfully.\n\n";
}
void del_end()
{
	if(start == NULL)
	{
		cout<<"\n\n\tList is Empty.\n";
		return;
	}
	node* ptr = start;
	while(ptr->next->next != NULL)
	{
		ptr = ptr->next;
	}
	node* temp = ptr->next;
	ptr->next = ptr->next->next;
	delete temp;
	cout<<"\n\t\t\t***Node Deleted Successfully.***\n\n";
	
}
void search()
{
	int item;
	cout<<"\n\nEnter Element to Search : ";
	cin>>item;
	node* ptr = start;
	int i = 1;
	while(ptr != NULL)
	{
		if(ptr->data == item)
		{
			cout<<"\n\nElement Found at Position "<<i;
			return;
		}
		ptr = ptr->next;
		i++;
	}
	cout<<"\n\nElement is Not Found in List"<<endl;
}
void sort_list()
{
	node* ptr1 = start;
	node* ptr2 = start;
	int value;
	
	while(ptr1 != NULL)
	{
		ptr2 = start;
		while(ptr2->next != NULL)
		{
			if(ptr1->data < ptr2->data)
			{
				value = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = value;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

void update()
{
	cout<<"\n\n\t\t\t***Updating Element Menu***\n\n";
	if(start==NULL){
		cout<<"Linked List is Empty.\n\n";
		return;
	}
	int p;
	int update;
	cout<<"Enter Position of Element to Update : ";
	cin>>p;
	cout<<"\n\nEnter Element to Update : ";
	cin>>update;
	if(p == 0){
		cout<<"You Entered Invalid Position.";
		return;
	}
	if(p == 1){
		start->data = update;
		cout<<"\nElement Updated Sucessfully.\n";
		return;
	}
	node* ptr = start;
	
	for(int i=2;i<=p;i++)
	{
		if(ptr == NULL){
			cout<<"You Entered Wrong Position.\n\n";
			return;
		}
		ptr = ptr->next;	
	}
	ptr->data = update;
	cout<<"\nElement Updated Sucessfully.\n\n";
	
}

void display()
{
	node* ptr = start;
	while(ptr!= NULL)
	{
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	cout<<"NULL\n\n";
}
int main()
{
	int choice;
	while("RAJA")
	{
		system("clear");
		cout<<"\n\t\t\t\t\t   ***MENU***\n";
		cout<<"\n\t\t\t  *****^^^*****^^^*****^^^*****^^^*****^^^*****^^^";
		cout<<"\n\n\t\t\t\t1	Insert Node at Start.";
		cout<<"\n\n\t\t\t\t2	Insert Node at Position.";
		cout<<"\n\n\t\t\t\t3	Insert Node at End.";
		cout<<"\n\n\t\t\t\t4	Delete Node from Start.";
		cout<<"\n\n\t\t\t\t5	Delete Node from a Position.";
		cout<<"\n\n\t\t\t\t6	Delete Node from End.";
		cout<<"\n\n\t\t\t\t7	Search a Specific Node.";
		cout<<"\n\n\t\t\t\t8	Sort Linked List.";
		cout<<"\n\n\t\t\t\t9	Update Element in Link List.";
		cout<<"\n\n\t\t\t\t10	Display List.";
		cout<<"\n\n\t\t\t  *****^^^*****^^^*****^^^*****^^^*****^^^*****^^^";
		cout<<"\n\nPlease, Enter Your Choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				system("clear");
				cout<<"\n\t\t\t***Inserting Node At Start.***";
				insert_beg();
				cout<<"\n\n\tNode Inserted Successfully.\n\n";
				system("pause");
				break;
			case 2:
				system("clear");
				cout<<"\n\t\t\t***Inserting Node at Positon.***";
				insert_pos();
				system("pause");
				break;
			case 3:
				system("clear");
				cout<<"\n\t\t\t***Inserting Node At End.***";
				insert_end();
				cout<<"\n\n\tNode Inserted Successfully.\n\n";
				system("pause");
				break;
			case 4:
				system("clear");
				del_beg();
				system("pause");
				break;
			case 5:
				system("clear");
				del_pos();
				system("pause");
				break;
			case 6:
				system("clear");
				cout<<"Linked list is as follows\n\n";
				display();
				cout<<"\n\t\t\t***Deleting  Node From End.***";
				del_end();
				system("clear");
				cout<<"\n\nAfter deleting Node from End\n\nUpdated list is as follows \n\n ";
				display();
				break;
			case 7:
				system("clear");
				cout<<"\n\n\t\t\t\t***Search Menu***\n\n";
				search();
				system("pause");
				break;
			case 8:
				system("clear");
				cout<<"\n\n\tSorting Linked List\n\n";
				sort_list();
				system("pause");
				break;
			case 9:
				system("clear");
				update();
				system("pause");
				break;
			case 10:
				system("clear");
				cout<<"\n\t\t\t***Displaying Linked List***\n\n";
				display();
				system("pause");
				break;
			default:
				system("clear");
				cout<<"\n\nErorr\n\tYou Entered Wrong Choice. Please Try Again.\n\n";
				system("pause");
		}
	}
	
}
