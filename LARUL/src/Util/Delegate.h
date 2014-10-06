#ifndef LARUL_DELEGATE_H
#define LARUL_DELEGATE_H

/*
* Delegates, with regards to LARUL, are flexible function pointers. They allow you to make callbacks to member functions or otherwise non-compatible functions through the use of closures.
* For example:
=================================

// MyCallback declaration

void MyCallback ();

// Elsewhere, we make a delegate.

GlobalDelegate0 <void> * MyCallbackDelegate = new GlobalDelegate0 <void> ( & MyCallback );
Caller.SetCallback ( MyCallbackDelegate );

=================================
* Note that it's important to heap-allocate a delegate you expect to be called after leaving a function you set it as a callback in, lest we avoid killing the stack.
*/

/*
* Generic interfaces to allow for closures.
* The name signifies how many parameters the delegate is supposed to take.
* Call (...); functions just like operator() in case you don't like to use that overload.
*
* We probably won't ever need more than 5 arguments in a callback, right? (( counting objects for member delegates ))
*/

template <typename Return>
class IDelegate0
{
public:
	
	virtual Return operator() () = 0;
	virtual Return Call () = 0;
	
	virtual ~IDelegate0 () {};
	
};

template <typename Return, typename Arg1>
class IDelegate1
{
public:
	
	virtual Return operator() ( Arg1 ) = 0;
	virtual Return Call ( Arg1 ) = 0;
	
	virtual ~IDelegate1 () {};
	
};

template <typename Return, typename Arg1, typename Arg2>
class IDelegate2
{
public:
	
	virtual Return operator() ( Arg1, Arg2 ) = 0;
	virtual Return Call ( Arg1, Arg2 ) = 0;
	
	virtual ~IDelegate2 () {};
	
};

template <typename Return, typename Arg1, typename Arg2, typename Arg3>
class IDelegate3
{
public:
	
	virtual Return operator() ( Arg1, Arg2, Arg3 ) = 0;
	virtual Return Call ( Arg1, Arg2, Arg3 ) = 0;
	
	virtual ~IDelegate3 () {};
	
};

template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class IDelegate4
{
public:
	
	virtual Return operator() ( Arg1, Arg2, Arg3, Arg4 ) = 0;
	virtual Return Call ( Arg1, Arg2, Arg3, Arg4 ) = 0;
	
	virtual ~IDelegate4 () {};
	
};

template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class IDelegate5
{
public:
	
	virtual Return operator() ( Arg1, Arg2, Arg3, Arg4, Arg5 ) = 0;
	virtual Return Call ( Arg1, Arg2, Arg3, Arg4, Arg5 ) = 0;
	
	virtual ~IDelegate5 () {};
	
};

/*
* Member delegates are just like normal ones, but they are for member functions, so you must call with a specific instace of the class for scope.
* Technically and logically speaking, they conform to the prototype of a delegate with 1+ argument than themself, so why not, right?
*/

template <typename Class, typename Return>
class IMemberDelegate0 : IDelegate1 <Return, Class>
{
public:
	
	virtual Return operator() ( Class * ) = 0;
	virtual Return Call ( Class * ) = 0;
	
	virtual ~IMemberDelegate0 () {};
	
};

template <typename Class, typename Return, typename Arg1>
class IMemberDelegate1 : IDelegate2 <Return, Class, Arg1>
{
public:
	
	virtual Return operator() ( Class *, Arg1 ) = 0;
	virtual Return Call ( Class *, Arg1 ) = 0;
	
	virtual ~IMemberDelegate1 () {};
	
};

template <typename Class, typename Return, typename Arg1, typename Arg2>
class IMemberDelegate2 : IDelegate3 <Return, Class, Arg1, Arg2>
{
public:
	
	virtual Return operator() ( Class *, Arg1, Arg2 ) = 0;
	virtual Return Call ( Class *, Arg1, Arg2 ) = 0;
	
	virtual ~IMemberDelegate2 () {};
	
};

template <typename Class, typename Return, typename Arg1, typename Arg2, typename Arg3>
class IMemberDelegate3 : IDelegate4 <Return, Class, Arg1, Arg2, Arg3>
{
public:
	
	virtual Return operator() ( Class *, Arg1, Arg2, Arg3 ) = 0;
	virtual Return Call ( Class *, Arg1, Arg2, Arg3 ) = 0;
	
	virtual ~IMemberDelegate3 () {};
	
};

template <typename Class, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class IMemberDelegate4 : IDelegate5 <Return, Class, Arg1, Arg2, Arg3, Arg4>
{
public:
	
	virtual Return operator() ( Class *, Arg1, Arg2, Arg3, Arg4 ) = 0;
	virtual Return Call ( Class *, Arg1, Arg2, Arg3, Arg4 ) = 0;
	
	virtual ~IMemberDelegate4 () {};
	
};

//Alright, now for actual definitions. Simple stuff.

// Inheret prototype for polymorphic goodness.
template <typename Return>
class GlobalDelegate0 : public IDelegate0 <Return>
{
public:

	// Ah, function pointers.
	GlobalDelegate0 ( Return ( * Callback ) ( void ) ):
		Callback ( Callback )
	{
	};
	
	// How convenient!
	inline Return operator () ()
	{
		
		return ( * Callback ) ();
		
	};
	
	// Lame
	inline Return Call ()
	{
		
		return ( * Callback ) ();
		
	};
	
	~GlobalDelegate0 () {};
	
private:
	
	Return ( * Callback ) ( void );
	
};

template <typename Return, typename Arg1>
class GlobalDelegate1 : public IDelegate1 <Return, Arg1>
{
public:
	
	GlobalDelegate1 ( Return ( * Callback ) ( Arg1 ) ):
		Callback ( Callback )
	{
	};
	
	inline Return operator() ( Arg1 _1 )
	{
		
		return ( * Callback ) ( _1 );
		
	};
	
	inline Return Call ( Arg1 _1 )
	{
		
		return ( * Callback ) ( _1 );
		
	};
	
	~GlobalDelegate1 () {};
	
private:
	
	Return ( * Callback ) ( Arg1 );
	
};

template <typename Return, typename Arg1, typename Arg2>
class GlobalDelegate2 : public IDelegate2 <Return, Arg1, Arg2>
{
public:

	GlobalDelegate2 ( Return ( * Callback ) ( Arg1, Arg2 ) ):
		Callback ( Callback )
	{
	};
	
	inline Return operator() ( Arg1 _1, Arg2 _2 )
	{
		
		return ( * Callback ) ( _1, _2 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2 )
	{
		
		return ( * Callback ) ( _1, _2 );
		
	};
	
	~GlobalDelegate2 () {};
	
private:
	
	Return ( * Callback ) ( Arg1, Arg2 );
	
};

template <typename Return, typename Arg1, typename Arg2, typename Arg3>
class GlobalDelegate3 : public IDelegate3 <Return, Arg1, Arg2, Arg3>
{
public:

	GlobalDelegate3 ( Return ( * Callback ) ( Arg1, Arg2, Arg3 ) ):
		Callback ( Callback )
	{
	};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return ( * Callback ) ( _1, _2, _3 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return ( * Callback ) ( _1, _2, _3 );
		
	};
	
	~GlobalDelegate3 () {};
	
private:
	
	Return ( * Callback ) ( Arg1, Arg2, Arg3 );
	
};

template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class GlobalDelegate4 : public IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4>
{
public:

	GlobalDelegate4 ( Return ( * Callback ) ( Arg1, Arg2, Arg3, Arg4 ) ):
		Callback ( Callback )
	{
	};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return ( * Callback ) ( _1, _2, _3, _4 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return ( * Callback ) ( _1, _2, _3, _4 );
		
	};
	
	~GlobalDelegate4 () {};
	
private:
	
	Return ( * Callback ) ( Arg1, Arg2, Arg3, Arg4 );
	
};

template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class GlobalDelegate5 : public IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5>
{
public:

	GlobalDelegate5 ( Return ( * Callback ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) ):
		Callback ( Callback )
	{
	};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4, Arg5 _5 )
	{
		
		return ( * Callback ) ( _1, _2, _3, _4, _5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4, Arg5 _5 )
	{
		
		return ( * Callback ) ( _1, _2, _3, _4, _5 );
		
	};
	
	~GlobalDelegate5 () {};
	
private:
	
	Return ( * Callback ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
	
};

template <typename Class, typename Return>
class MemberDelegate0 : public IMemberDelegate0 <Class, Return>
{
	
	MemberDelegate0 ( Return ( Class :: * Callback ) ( void ) ):
		Callback ( Callback )
	{
	};
	
	inline Return operator () ( Class * Object )
	{
		
		return ( Object ->* Callback );
		
	};
	
	inline Return Call ( Class * Object )
	{
		
		return ( Object ->* Callback );
		
	};
	
	~MemberDelegate0 () {};
	
private:
	
	Return ( Class :: * Callback ) ( void );
	
};

template <typename Class, typename Return, typename Arg1>
class MemberDelegate1 : public IMemberDelegate1 <Class, Return, Arg1>
{
	
	MemberDelegate1 ( Return ( Class :: * Callback ) ( Arg1 ) ):
		Callback ( Callback )
	{
	};
	
	inline Return operator () ( Class * Object, Arg1 _1 )
	{
		
		return ( Object ->* Callback ) ( _1 );
		
	};
	
	inline Return Call ( Class * Object, Arg1 _1 )
	{
		
		return ( Object ->* Callback ) ( _1 );
		
	};
	
	~MemberDelegate1 () {};
	
private:
	
	Return ( Class :: * Callback ) ( Arg1 );
	
};

template <typename Class, typename Return, typename Arg1, typename Arg2>
class MemberDelegate2 : public IMemberDelegate2 <Class, Return, Arg1, Arg2>
{
	
	MemberDelegate2 ( Return ( Class :: * Callback ) ( Arg1, Arg2 ) ):
		Callback ( Callback )
	{
	};
	
	inline Return operator () ( Class * Object, Arg1 _1, Arg2 _2 )
	{
		
		return ( Object ->* Callback ) ( _1, _2 );
		
	};
	
	inline Return Call ( Class * Object, Arg1 _1, Arg2 _2 )
	{
		
		return ( Object ->* Callback ) ( _1, _2 );
		
	};
	
	~MemberDelegate2 () {};
	
private:
	
	Return ( Class :: * Callback ) ( Arg1, Arg2 );
	
};

template <typename Class, typename Return, typename Arg1, typename Arg2, typename Arg3>
class MemberDelegate3 : public IMemberDelegate3 <Class, Return, Arg1, Arg2, Arg3>
{
	
	MemberDelegate3 ( Return ( Class :: * Callback ) ( Arg1, Arg2, Arg3 ) ):
		Callback ( Callback )
	{
	};
	
	inline Return operator () ( Class * Object, Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return ( Object ->* Callback ) ( _1, _2, _3 );
		
	};
	
	inline Return Call ( Class * Object, Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return ( Object ->* Callback ) ( _1, _2, _3 );
		
	};
	
	~MemberDelegate3 () {};
	
private:
	
	Return ( Class :: * Callback ) ( Arg1, Arg2, Arg3 );
	
};

template <typename Class, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class MemberDelegate4 : public IMemberDelegate4 <Class, Return, Arg1, Arg2, Arg3, Arg4>
{
	
	MemberDelegate4 ( Return ( Class :: * Callback ) ( Arg1, Arg2, Arg3, Arg4 ) ):
		Callback ( Callback )
	{
	};
	
	inline Return operator () ( Class * Object, Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return ( Object ->* Callback ) ( _1, _2, _3, _4 );
		
	};
	
	inline Return Call ( Class * Object, Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return ( Object ->* Callback ) ( _1, _2, _3, _4 );
		
	};
	
	~MemberDelegate4 () {};
	
private:
	
	Return ( Class :: * Callback ) ( Arg1, Arg2, Arg3, Arg4 );
	
};

#endif
