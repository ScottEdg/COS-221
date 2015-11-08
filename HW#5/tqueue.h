#pragma once
#include <string>
template <class T>
class Queue {
public:
	Queue();						// POST: empty queue is constructed of capacity 5
	Queue(T n);						// PRE: n > 0
									// POST: empty queue is constructed of capacity n
	Queue (const Queue& other);		// POST: deep copy constructor
	~Queue();						// POST: queue is destructed
	bool empty ( ) const;			// POST: return true if queue is empty
	bool full ( ) const;			// POST: return true if queue is full
	int count ( ) const;			// POST: return number of items in queue
	void enqueue (T item);			// PRE: queue is not full
									// POST: item is added to rear
	T getFront () const;			// PRE: queue is not empty
									// POST: return copy of front item
	void dequeue( );				// PRE: queue is not empty	
									// POST: item at front of queue is removed
									// POST: points to the previous element in queue (acts as a stack)
	T top();						// POST: returns the top of the stack

private:
	T * queue;						// pointer to array of items
    int front;						// index of front of queue				
    int rear;							// index of rear of queue
	int capacity;						// number of array elements
	int size;							// number of items in the queue
};


template <class T>
Queue<T>::Queue() 							 // POST: empty queue is constructed of size 5
{	
	capacity = 5;
	queue = new T [capacity];
	front = 0;
	rear = capacity-1;	
	size = 0;
}
template <class T>
Queue<T>::Queue(T n)						// PRE: n > 0
{										// POST: empty queue is constructed of capacity n
	capacity = n;
	queue = new T [capacity];
	front = 0;
	rear = capacity-1;	
	size = 0;
}

template <class T>
Queue<T>::Queue (const Queue& other)		// POST: deep copy constructor
{
	int i;
	capacity = other.capacity; // implement the deep copy constructor
	queue = new T [capacity];
	for(i=0;i<capacity + 1;i++){
		queue[i]=other.queue[i];
	}
	front = other.front;
	rear = other.rear;
	size = other.size;
}

template <class T>
Queue<T>::~Queue ()						// POST: destructor
{
	delete [] queue;						// implement the destructor function
}

template <class T>
void Queue<T>::enqueue (T item)	
// PRE:  	queue is not full
// POST: 	item is added to rear
// Add the code to double the capacity of the array if full
{
	size++;									
	if (rear == capacity-1) rear = 0;		
	else rear++;
	queue [rear] = item;						
}

template <class T>
void Queue<T>::dequeue( )		
// PRE:	queue is not empty	
// POST: 	item at front of queue is removed
{  	
	size--;											
	if (front == capacity-1) front = 0;			
	else front++;
}

template <class T>
T Queue<T>::getFront () const
// PRE:	queue is not empty
// POST: 	return copy of item at front of queue 
{	return queue[front];	}

template <class T>
bool Queue<T>::empty()	const
// POST: return true if queue is empty; else false
{  	return (size == 0); 	}

template <class T>
bool Queue<T>::full()	const
// POST: return true if queue is full; else false
{  	return (size == capacity); 	}

template <class T>
int Queue<T>::count( ) const
// POST:	return number of elements in queue
{	return size;	}
