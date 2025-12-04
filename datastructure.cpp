//#include <iostream>
//using namespace std;
//class node 
//{
//public:
//	int data;
//	node* next;
//};
//class singlelinkedlist
//{
//public:
//	node* head = NULL;
//	node* tail = NULL;
//	
//	void addEnd(int value)
//	{
//		node* newNode = new node;
//		newNode->data = value;
//		newNode->next = NULL;
//
//		if (head == NULL)
//		{
//			head = newNode;
//			tail = newNode;
//		}
//		else
//		{
//			tail->next = newNode;
//			tail = newNode;
//		}
//	}
//	void addFrist(int val)
//	{
//		node* newNode = new node;
//		newNode->data = val;
//		newNode->next = NULL;
//		if (head == NULL)
//		{
//			head = newNode;
//			tail = newNode;
//		}
//		else 
//		{
//			newNode->next = head;
//			head = newNode;
//
//		}
//
//
//
//	}
//	void assendelete(int v)
//	{
//		if (head->data == v)
//		{
//			node* ret = head;
//			head = head->next;
//			delete ret;
//			return;
//		}
//		node* c = head;
//		node* p = head;
//
//		while (c->next != NULL)
//		{
//			if (c->data == v)
//			{
//				p->next = c->next;
//				delete c;
//				return;
//			}
//			else
//			{
//				p = c;
//				c = c->next;
//			}
//
//		}
//
//	}
//
//	void display()
//	{
//		node* print = head;
//		while (print != NULL)
//		{
//			cout << print->data << " ";
//			print = print->next;
//		}
//		cout << endl;
//
//	}
//
//	void insertNodeFromEnd()
//	{
//		int num; cout << "Enter limit of single linked list : "; cin >> num; cout << "===================================\n";
//		for (int i = 1; i <= num; i++)
//		{
//			int val; cin >> val;
//			addEnd(val);
//		}
//	}
//	void insertNodeFromBigg()
//	{
//		int num; cout << "how many numbers u want add from bigging in single linked list : "; cin >> num; cout << "===================================\n";
//		for (int i = 1; i <= num; i++)
//		{
//			int val; cin >> val;
//			addFrist(val);
//		}
//	}
//
//	void del()
//	{
//		int deletee; cout << "Enter the element u need delete \n"; cin >> deletee;
//		assendelete(deletee);
//		cout << endl;
//	}
//
//	void addAfter(int e, int x)
//	{
//		node* newNode = new node;
//		newNode->data = x;
//		newNode->next = NULL;
//		node* i = head;
//		while (i != NULL) 
//		{
//			if (i->data==e)
//			{
//				newNode->next = i->next;
//				i->next = newNode;
//				return;
//			}
//			else
//			{
//				i = i->next;
//			}
//
//		}
// 
//	}
//	string searchfor(int x)
//	{
//		node* i = head;
//		while (i != NULL)
//		{
//			if (i->data == x)
//			{
//			 return "Found" ;
//			}
//			else
//			{
//				i = i->next;
//			}
//
//		}
//		return "Not Found";
//
//	}
//	void search()
//	{	
//		int n;
//		cout << "Enter the number u want to search about : "; cin >> n;
//		cout<<searchfor(n);
//	}
//	
//
//};
//
//int main()
//{
//	singlelinkedlist list;
//	list.insertNodeFromEnd();
//	list.display();
//	list.display();
//	list.del();
//	list.display();
//	list.insertNodeFromBigg();
//	list.display();
//	list.addAfter(3, 8);
//	list.display();
//	list.search();
//}
//	



/*

🛠️ المطلوب منك تنفيذه (The Requirements):
البرنامج بتاعك لازم يكون فيه قايمة (Menu) بتظهر للمستخدم يختار منها:

Add New Task: يضيف مهمة جديدة (مثلاً: "Study C++", "Go to Gym"). (تضاف في آخر القائمة). DONEEEEEE

View All Tasks: يعرض كل المهام بالترتيب، وجنب كل واحدة حالتها (هل خلصت ولا لسه؟).DONEEEEEEEEEEE

Mark as Completed: المستخدم يدخل "رقم المهمة" (ID)، فالبرنامج يدور عليها ويغير حالتها لـ "Done" ✅.

Delete Task: المستخدم يدخل "رقم المهمة"، فالبرنامج يمسحها من القائمة تماماً (يربط اللي قبلها باللي بعدها).

Exit: يقفل البرنامج.

*/


#include <iostream>
#include <string>
using namespace std;
struct task
{
	int iD;
	bool isCompleted = false;
	string describe;
	task* next;
};

class ToDoList
{
private:
	task* head, * tail = NULL;
public:
	void addTask(int id, string descr)
	{
		task* newTask = new task;
		newTask->iD = id;
		newTask->describe = descr;
		newTask->next = NULL;
		if (head == NULL)
		{
			head = newTask;
			tail = newTask;
		}
		else
		{
			tail->next = newTask;
			tail = newTask;
		}
	}
	void markas(int targetId)
	{
		task* makeCom = head;

		while (makeCom != NULL)
		{
			if (targetId == makeCom->iD)
			{
				makeCom->isCompleted = true;
				cout << "task \"" << makeCom->describe << "\" is Done  "<<endl;
				return;
			}
			else
			{
				makeCom = makeCom->next;
			}
		}
		
			cout << "Failed to fined your task " << endl;
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "You have no tasks";
			return;
		}
		task* view = head;
		while (view != NULL)
		{
			cout << "Task id :" << view->iD << " & describe : " << view->describe << " & state : " << (view->isCompleted ? "DONE" : "Pending") << endl;
			view = view->next;
		}
		cout << "---------------------------------" << endl;
	}


	void del(int iid)
	{
		// if the task was the fisrt one 
		if (head->iD == iid)
		{
			task* hed = head;
			head = head->next;
			delete hed;
			return;
		}
		task* temp1 = head;
		task* temp2 = head;
		while (temp1 != NULL)
		{
			if (temp1->iD == iid)
			{
				temp2->next = temp1->next;
				//if the task was the last
				if (temp1 == tail)
				{
					tail = temp2;
				}
				delete temp1;
				return;
			}
			else
			{
				temp2 = temp1;
				temp1 = temp1->next;
			}


		}


	}

};

int main()
{
	cout << R"(

 __          __  _                            _         
 \ \        / / | |                          | |        
  \ \  /\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  
    \  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | 
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/  
                                                        
                                                        

  _ _   _______      _____          _      _     _     _ _ 
 ( | ) |__   __|    |  __ \        | |    (_)   | |   ( | )
  V V     | | ___   | |  | | ___   | |     _ ___| |_   V V 
          | |/ _ \  | |  | |/ _ \  | |    | / __| __|      
          | | (_) | | |__| | (_) | | |____| \__ \ |_       
          |_|\___/  |_____/ \___/  |______|_|___/\__|      
                                                           
                                                           


  __  __           _         __                 _                        _ 
 |  \/  |         | |       / _|          /\   | |                      | |
 | \  / | ___  ___| |_ __ _| |_ __ _     /  \  | |__  _ __ ___   ___  __| |
 | |\/| |/ _ \/ __| __/ _` |  _/ _` |   / /\ \ | '_ \| '_ ` _ \ / _ \/ _` |
 | |  | | (_) \__ \ || (_| | || (_| |  / ____ \| | | | | | | | |  __/ (_| |
 |_|  |_|\___/|___/\__\__,_|_| \__,_| /_/    \_\_| |_|_| |_| |_|\___|\__,_|
                                                                           
                                                                           

	)"<<endl;






	ToDoList task;
	task.addTask(1 , "Thinking in life");
	task.addTask(2 , "Study");
	task.display();
	task.markas(2);
	task.display();
	task.del(2);
	task.display();
	task.addTask(3, "about lotfy i miss him");
	task.display();
}



















