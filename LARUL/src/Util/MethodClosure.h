#ifndef LARUL_METHODCLOSURE_H
#define LARUL_METHODCLOSURE_H

#include <stdbool.h>

#include "Delegate.h"

template <typename EnclosedClass, typename Return>
class MethodClosure0 : public IDelegate0 <Return>, public IMemberDelegate0 <EnclosedClass, Return>
{
public:
	
	MethodClosure0 ( Return ( EnclosedClass :: * Callback ) ( void ), EnclosedClass * DefaultObject, bool OverrideMethodContext = true ):
		Callback ( Callback ),
		DefaultObject ( DefaultObject ),
		OverrideMethodContext ( OverrideMethodContext )
	{	
	};
	
	~MethodClosure0 () {};
	
	Return operator() ()
	{
		
		return ( DefaultObject ->* Callback ) ();
		
	};
	
	Return Call ()
	{
		
		return ( DefaultObject ->* Callback ) ();
		
	};
	
	Return operator() ( EnclosedClass * Object )
	{
		
		if ( OverrideMethodContext )
			return ( DefaultObject ->* Callback ) ();
		
		return ( Object ->* Callback ) ();
		
	};
	
	Return Call ( EnclosedClass * Object )
	{
		
		if ( OverrideMethodContext )
			return ( DefaultObject ->* Callback ) ();
		
		return ( Object ->* Callback ) ();
		
	};
	
	inline void SetDefaultObject ( EnclosedClass * DefaultObject )
	{
		
		this -> DefaultObject = DefaultObject;
		
	};
	
private:
	
	Return ( EnclosedClass :: * Callback ) ( void );
	EnclosedClass * DefaultObject;
	bool OverrideMethodContext;
	
};

template <typename EnclosedClass, typename Return, typename Arg1>
class MethodClosure1 : public IDelegate1 <Return, Arg1>, public IMemberDelegate1 <EnclosedClass, Return, Arg1>
{
public:
	
	MethodClosure1 ( Return ( EnclosedClass :: * Callback ) ( Arg1 ), EnclosedClass * DefaultObject, bool OverrideMethodContext = true ):
		Callback ( Callback ),
		DefaultObject ( DefaultObject ),
		OverrideMethodContext ( OverrideMethodContext )
	{	
	};
	
	~MethodClosure1 () {};
	
	Return operator() ( Arg1 _1 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1 );
		
	};
	
	Return Call ( Arg1 _1 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1 );
		
	};
	
	Return operator() ( EnclosedClass * Object, Arg1 _1 )
	{
		
		if ( OverrideMethodContext )
			return ( DefaultObject ->* Callback ) ( _1 );
		
		return ( Object ->* Callback ) ( _1 );
		
	};
	
	Return Call ( EnclosedClass * Object, Arg1 _1 )
	{
		
		if ( OverrideMethodContext )
			return ( DefaultObject ->* Callback ) ( _1 );
		
		return ( Object ->* Callback ) ( _1 );
		
	};
	
	inline void SetDefaultObject ( EnclosedClass * DefaultObject )
	{
		
		this -> DefaultObject = DefaultObject;
		
	};
	
private:
	
	Return ( EnclosedClass :: * Callback ) ( Arg1 );
	EnclosedClass * DefaultObject;
	bool OverrideMethodContext;
	
};

template <typename EnclosedClass, typename Return, typename Arg1, typename Arg2>
class MethodClosure2 : public IDelegate2 <Return, Arg1, Arg2>, public IMemberDelegate2 <EnclosedClass, Return, Arg1, Arg2>
{
public:
	
	MethodClosure2 ( Return ( EnclosedClass :: * Callback ) ( Arg1, Arg2 ), EnclosedClass * DefaultObject, bool OverrideMethodContext = true ):
		Callback ( Callback ),
		DefaultObject ( DefaultObject ),
		OverrideMethodContext ( OverrideMethodContext )
	{
	};
	
	~MethodClosure2 () {};
	
	Return operator () ( Arg1 _1, Arg2 _2 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2 );
		
	};
	
	Return Call ( Arg1 _1, Arg2 _2 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2 );
		
	};
	
	Return operator () ( EnclosedClass * Object, Arg1 _1, Arg2 _2 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2 );
		
	};
	
	Return Call ( EnclosedClass * Object, Arg1 _1, Arg2 _2 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2 );
		
	};
	
	inline void SetDefaultObject ( EnclosedClass * DefaultObject )
	{
		
		this -> DefaultObject = DefaultObject;
		
	};
	
private:
	
	Return ( EnclosedClass :: * Callback ) ( Arg1, Arg2 );
	EnclosedClass * DefaultObject;
	bool OverrideMethodContext;
	
};
	

template <typename EnclosedClass, typename Return, typename Arg1, typename Arg2, typename Arg3>
class MethodClosure3 : public IDelegate3 <Return, Arg1, Arg2, Arg3>, public IMemberDelegate3 <EnclosedClass, Return, Arg1, Arg2, Arg3>
{
public:
	
	MethodClosure3 ( Return ( EnclosedClass :: * Callback ) ( Arg1, Arg2, Arg3 ), EnclosedClass * DefaultObject, bool OverrideMethodContext = true ):
		Callback ( Callback ),
		DefaultObject ( DefaultObject ),
		OverrideMethodContext ( OverrideMethodContext )
	{
	};
	
	~MethodClosure3 () {};
	
	Return operator () ( Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2, _3 );
		
	};
	
	Return Call ( Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2, _3 );
		
	};
	
	Return operator () ( EnclosedClass * Object, Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2, _3 );
		
	};
	
	Return Call ( EnclosedClass * Object, Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2, _3 );
		
	};
	
	inline void SetDefaultObject ( EnclosedClass * DefaultObject )
	{
		
		this -> DefaultObject = DefaultObject;
		
	};
	
private:
	
	Return ( EnclosedClass :: * Callback ) ( Arg1, Arg2, Arg3 );
	EnclosedClass * DefaultObject;
	bool OverrideMethodContext;
	
};
	

template <typename EnclosedClass, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class MethodClosure4 : public IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4>, public IMemberDelegate4 <EnclosedClass, Return, Arg1, Arg2, Arg3, Arg4>
{
public:
	
	MethodClosure4 ( Return ( EnclosedClass :: * Callback ) ( Arg1, Arg2, Arg3, Arg4 ), EnclosedClass * DefaultObject, bool OverrideMethodContext = true ):
		Callback ( Callback ),
		DefaultObject ( DefaultObject ),
		OverrideMethodContext ( OverrideMethodContext )
	{
	};
	
	~MethodClosure4 () {};
	
	Return operator () ( Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2, _3, _4 );
		
	};
	
	Return Call ( Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2, _3, _4 );
		
	};
	
	Return operator () ( EnclosedClass * Object, Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2, _3, _4 );
		
	};
	
	Return Call ( EnclosedClass * Object, Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return ( DefaultObject ->* Callback ) ( _1, _2, _3, _4 );
		
	};
	
	inline void SetDefaultObject ( EnclosedClass * DefaultObject )
	{
		
		this -> DefaultObject = DefaultObject;
		
	};
	
private:
	
	Return ( EnclosedClass :: * Callback ) ( Arg1, Arg2, Arg3, Arg4 );
	EnclosedClass * DefaultObject;
	bool OverrideMethodContext;
	
};


#endif
