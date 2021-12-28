/*************************************************************************
        Copyright © 2021 Konstantinidis Konstantinos

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int QueueElementType;
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode{
    QueueElementType Data; //Data of the node
    QueuePointer Next; //Pointer that shows the next node
} QueueNode;

typedef struct{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);

main(){
    QueueElementType i;
    QueueType Queue;
    QueuePointer CurPtr, PredPtr;
    int number, no_of_execution, j=1;

    CreateQ(&Queue); //Create the queue

    printf("Insert the number of the prisoners: ");
    scanf("%d", &number);

    for(i=1; i<=number; i++)
        AddQ(&Queue, i); //Add the prisoners in the queue

    printf("Insert the number of the execution cycle: ");
    scanf("%d", &no_of_execution);

    CurPtr = Queue.Front;

    while(j < number){
        for(i=1; i<=no_of_execution; i++){
            printf("%d, ", CurPtr->Data); //Show the prisoner number
            if(i!=no_of_execution){
                PredPtr = CurPtr;
                CurPtr = CurPtr->Next; //Change the current pointer to the next one
            }
        }
        PredPtr->Next = CurPtr->Next; //Give the value of the next pointer to pred pointer next
        printf("EXECUTED: %d\n", CurPtr->Data); //Show the current pointer data
        free(CurPtr); //Free the current pointer
        CurPtr = PredPtr->Next; //Give back the value of the pred next pointer to the current one

        j++;
    }
    printf("SURVIVED: %d\n", CurPtr->Data); //Show the survivor

    system("PAUSE");
}

void CreateQ(QueueType *Queue){
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue){
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item){
    QueuePointer TempPtr;

    TempPtr = (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if(Queue->Front==NULL) //If queue is empty
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
    Queue->Rear->Next = Queue->Front;
}
