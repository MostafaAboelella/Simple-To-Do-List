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




















