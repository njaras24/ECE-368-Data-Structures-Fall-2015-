/*
Group Members:
1. Sthitapragyan Parida
2. Eric Lees
ECE 368 Project 1 (Spring 2015)
*/
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#ifndef EVENT_H
#define EVENT_H
typedef struct Event
{
	char event_type; // 'A' for arrival 'D' for departure
	int trigger_time;
	int priority; 
		
} Event;

typedef struct Node
{
	Event event;
	struct Node *link;
} Node;

Node *event_front,*event_rear;   /* Global Declarations */

void eventInsert(Event new_event)
{
	Node *temp, *iter, *iter_front; 
	temp = (Node *)malloc(sizeof(Node));

	//iter = (Node *)malloc(sizeof(Node));
	//iter_front = (Node *)malloc(sizeof(Node));

	if( temp == NULL)
	{
		printf(" Out of Memory !! Overflow !!!");
	}
	else
	{
		temp->event.event_type = new_event.event_type;
		temp->event.trigger_time = new_event.trigger_time;
		temp->event.priority = new_event.priority;
		//temp->event.priority = 0;

		temp->link = NULL;
		if(event_front == NULL)
		{
			event_front = event_rear = temp;
		}
		
		else if(event_front == event_rear)
		{
			if(temp->event.trigger_time > event_front->event.trigger_time)
			{
				event_rear->link=temp;
				event_rear = temp;
			}
			else
			{
				temp->link = event_front;
				event_front = temp;
			}
		}
		
		else
		{
			
			iter = event_front;
			iter_front = iter;
			if(temp->event.trigger_time <= event_front->event.trigger_time)
			{
				temp->link = event_front;
				event_front = temp;
			}
			else if(temp->event.trigger_time >= event_rear->event.trigger_time)
			{
				event_rear->link = temp;
				event_rear = temp;
			}
			else
			{
			while(iter != event_rear)
			{
	
					if(iter->event.trigger_time >= temp->event.trigger_time)
					{
						iter_front->link = temp;
						temp->link = iter;
						break;
					} 
					iter_front = iter;
					iter = iter->link;
				}
			}
			if (iter == event_rear)
			{
				iter_front->link =temp;
				temp->link = event_rear;
			}		
				
			//event_rear->link=temp;
			//event_rear = temp;
			
		}
	}
}
 
Event eventDelete()
{
	Event event;
	Node *temp;
	if(event_front ==  NULL) 
	{
		printf(" Underflow!!!");
		return;
	}
	else
	{
		temp=event_front;
		event.event_type = event_front->event.event_type;
		event.trigger_time = event_front->event.trigger_time;
		event.priority = event_front->event.priority;
		if(event_front == event_rear) event_rear=NULL;
		event_front=event_front->link;
		temp->link=NULL;
		free(temp);
		return(event);
	}
}
 
int getEventCount()
{
	Node *temp;
	if( event_front == NULL) return 0;
	else
	{
		temp=event_front;
		int count = 0;
		while(temp)
		{
			count = count + 1;
			temp=temp->link;
		}
	return count;
	}
}
#endif
