#ifndef _QUEUE_
#define _QUEUE_

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

template < class Object >
class Queue
{
	private:
		// Class variables
		Object * myQueue;
		size_t queueSize;
		size_t queueCapacity;
		int first;
		int last;

	public:
		// Class constructor
		Queue (size_t = 20);

		~Queue () { delete [] myQueue; } 

		// Basic members
		void enqueue ( const Object & x );
		Object dequeue ( );
		Object getFront ( ) const;
		bool isEmpty ( ) const;
		void makeEmpty ( );
		// Only to be used in class
		void doubleSize ();
		bool find( const Object & x );

	friend std::ostream & operator<< ( std::ostream & _os, const Queue & _ms )
	{
		
		int num_elements;

		if ( _ms.first == -1 )
			num_elements = 0;
		else
			num_elements = ( _ms.last + _ms.queueCapacity - _ms.first ) % _ms.queueCapacity + 1;

		int k = _ms.first;

		_os << "[ ";

		for ( int i(0); i < num_elements ; ++i ){
			_os << _ms.myQueue[k] << " ";
			k = (k + 1) % _ms.queueCapacity;
		}

		_os << "]\n\n";
		
		return _os;
	}
};

#include "queue.inl"

#endif