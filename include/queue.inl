//Class methods implementation

template < class Object >
Queue< Object >::Queue (size_t _capacity) 
{
	if(_capacity == 0)
		throw std::out_of_range("Can't initiate with zero elements!");
	myQueue = new Object [_capacity];
	queueCapacity = _capacity;
	queueSize = 0;
	first = -1;
	last = -1;
}

template < class Object >
void Queue< Object >::enqueue ( const Object & _candidate )
{
	

	if(queueSize == queueCapacity)
	{
		doubleSize(); 
	}
	if(queueSize == 0)
	{
		myQueue[0] = _candidate;
		queueSize++;
		first++;
		last++;
	}
	else
	{
		myQueue[(last + 1) % queueCapacity] = _candidate;
		last = (last + 1) % queueCapacity;
		queueSize++;	
	}
}

template < class Object >
Object Queue< Object >::dequeue ( )
{
	if(queueSize == 0)
	{
		throw std::out_of_range ("There is no element to remove!");
	}

	Object tempObj = myQueue[first];
	first = (first + 1) % queueCapacity;
	queueSize--;
	
	if(queueSize == 0)
	{
		first = -1;
		last = -1;
	}

	return tempObj;
}

template < class Object >
Object Queue< Object >::getFront ( ) const
{
	return myQueue[first];
}


template < class Object >
bool Queue< Object >::isEmpty ( ) const
{
	return (queueSize == 0);
}

template < class Object >
void Queue< Object >::makeEmpty ( )
{
	queueSize = 0;
	first = -1;
	last = -1;
}

template < class Object >
void Queue< Object >::doubleSize( )
{
	Object * Q = new Object[queueCapacity * 2];

	if ( first < last )
	{
		for (int i = first; i <= last; ++i)
			Q[i] = myQueue[i];
	}
	
	else
	{
		for (int i = 0; i <= last; ++i)
			Q[i] = myQueue[i];

		for (int i = first; i < queueCapacity; ++i)
			Q[i + queueCapacity] = myQueue[i];

		first += queueCapacity;
	}

	delete [] myQueue;

	myQueue = Q;

	queueCapacity *= 2;
}

template < class Object >
bool Queue< Object >::find( const Object & x ){
	if(first < last)
	{
		for( auto i(first); i <= last; i++)
			if( myQueue[i] == x ) 
				return true;
	}
	else
	{
		for( auto i(0); i <= last; i++)
			if( myQueue[i] == x ) 
				return true;
				
		for(auto i (first); i < queueCapacity; ++i)
			if( myQueue[i] == x ) 
				return true;
	}
	return false;
}