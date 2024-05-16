/*
Project name : To-Do List
Written on: 20th Feb 2024
By Neha Biswas
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max_task 50
#define maxtasklen 100

//struct for task
struct task
{
    char taskname[20];
    char taskdes[maxtasklen];
    int comp;
};

struct task tasks[max_task];
int numtask=0;

//For user: display menu

void menu() {
    printf("\n----- To-Do List Menu -----\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Edit Task\n");
    printf("4. To Mark The Task as Completed\n");
    printf("5. Delete Task\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

//func to add task

void addtask() {
    if(numtask<max_task)
    {
        printf("Enter task name: ");
        scanf(" %[^\n]s",tasks[numtask].taskname);
        printf("Description of your task: ");
        scanf(" %[^\n]s", tasks[numtask].taskdes);
     //  " %[^\n]s " is used to read a string that may contain spaces or char until a newline characteris encountered
        tasks[numtask].comp=0;  //as the task in not completed
        numtask ++;       //to inc var value for further tasks
        printf("task added successfully :>\n");

    }
    else{ 
      printf("Task limit reached. Cannot add more tasks :< \n");
    }
}

//func to view task

void viewtask()
{
    if (numtask == 0) {
        printf("No tasks available :> \n");
    }
    else {
        printf("\n----- Tasks -----\n");
        for (int i = 0; i < numtask; i++)
        printf("%d. %s : %s\n", i + 1,tasks[i].taskname, tasks[i].taskdes);  // will print task no with decs and name
    }     

}

//to edit the existing task

void editTask() {
  viewtask();
  
    int taskindex;
  if(numtask==0)
  {
    printf("you cant edit your task as no task is available :<");
  }
  else{
    
  
    printf("Enter the task number you want to edit: ");
    scanf("%d", &taskindex);

    if (taskindex >= 1 && taskindex <= numtask) {
      printf("Enter the new task name: ");
      scanf(" %[^\n]s", tasks[taskindex - 1].taskname);
      
        printf("Enter the new task description: ");
        scanf(" %[^\n]s", tasks[taskindex - 1].taskdes);
        printf("Task edited successfully!\n");
    } else {
        printf("Invalid task number :< \n");
    }
  viewtask();
  
}
}
//func to delete existing task

void deletetask() {
  if(numtask==0)
  {
    printf("no task is available to delete");
  }
  else
  {
  printf("Enter the task number you want to delete: ");
  int deleteindex;
  scanf("%d", &deleteindex);
    
    if (deleteindex>= 1 && deleteindex <= numtask) {
        // Shift tasks to fill the gap
        for (int i = deleteindex - 1; i < numtask - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        // Decrement the number of tasks
        numtask--;

        printf("Task %d deleted successfully!\n",deleteindex);
    } 
    else {
        printf("Invalid task number. Task not deleted.\n");
    }
}
}
//for mark as complete. in case user just want to mark as complete but not delete

void markcomp(int index) {
    if (index >= 1 && index <= numtask) {
        tasks[index - 1].comp = 1; // Set isCompleted to 1 to mark the task as complete
        printf("Task %d marked as complete!\n", index);
    } else {
        printf("Invalid task number. Task not marked as complete.\n");
    }
}

int main() {
    int ch;

    do {
        menu();
        scanf("%d", &ch);
      while ((getchar()) != '\n');
        switch (ch) {
            case 1:
                addtask();
                break;
            case 2:
                viewtask();
                break;
            case 3:
                editTask();
                break;
            case 4:
                printf("Enter the task number you want to mark as complete: ");
                int markcompindex;
                scanf("%d", &markcompindex);
                markcomp(markcompindex);
                break;
            case 5:
                
                
                deletetask();
                break;
              
          
            case 6:
                printf("Exiting the program. bye! :< \n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (ch!= 6);

    return 0;
}