#ifndef LARUL_PARAMETERCLOSURE_H
#define LARUL_PARAMETERCLOSURE_H

#include "Delegate.h"

// Default parameter closures allow you to fit simpler incompatible delegate types by defaulting some parameters.
// Please don't worry, i used a script to generate this code. I'm not completely insane.

template <typename Return, typename Arg1>
class DefaultParameterClosure1_1 : public IDelegate0 <Return>
{
public:
	
	DefaultParameterClosure1_1 ( IDelegate1 <Return, Arg1> * Callback, Arg1 DefaultArg1 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 )
	{
	};
	
	~DefaultParameterClosure1_1 () {};
	
	inline Return operator() ()
	{
		return Callback -> Call ( DefaultArg1 );
		
	};
	
	inline Return Call ()
	{
		return Callback -> Call ( DefaultArg1 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
private:
	
	IDelegate1 <Return, Arg1> * Callback;
	Arg1 DefaultArg1;
	
};


template <typename Return, typename Arg1, typename Arg2>
class DefaultParameterClosure2_12 : public IDelegate0 <Return>
{
public:
	
	DefaultParameterClosure2_12 ( IDelegate2 <Return, Arg1, Arg2> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 )
	{
	};
	
	~DefaultParameterClosure2_12 () {};
	
	inline Return operator() ()
	{
		return Callback -> Call ( DefaultArg1, DefaultArg2 );
		
	};
	
	inline Return Call ()
	{
		return Callback -> Call ( DefaultArg1, DefaultArg2 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
private:
	
	IDelegate2 <Return, Arg1, Arg2> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	
};


template <typename Return, typename Arg1, typename Arg2>
class DefaultParameterClosure2_2 : public IDelegate1 <Return, Arg1>
{
public:
	
	DefaultParameterClosure2_2 ( IDelegate2 <Return, Arg1, Arg2> * Callback, Arg2 DefaultArg2 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 )
	{
	};
	
	~DefaultParameterClosure2_2 () {};
	
	inline Return operator() ( Arg1 _1 )
	{
		
		return Callback -> Call ( _1, DefaultArg2 );
		
	};
	
	inline Return Call ( Arg1 _1 )
	{
		
		return Callback -> Call ( _1, DefaultArg2 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
private:
	
	IDelegate2 <Return, Arg1, Arg2> * Callback;
	Arg2 DefaultArg2;
	
};


template <typename Return, typename Arg1, typename Arg2>
class DefaultParameterClosure2_1 : public IDelegate1 <Return, Arg2>
{
public:
	
	DefaultParameterClosure2_1 ( IDelegate2 <Return, Arg1, Arg2> * Callback, Arg1 DefaultArg1 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 )
	{
	};
	
	~DefaultParameterClosure2_1 () {};
	
	inline Return operator() ( Arg2 _2 )
	{
		
		return Callback -> Call ( DefaultArg1, _2 );
		
	};
	
	inline Return Call ( Arg2 _2 )
	{
		
		return Callback -> Call ( DefaultArg1, _2 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
private:
	
	IDelegate2 <Return, Arg1, Arg2> * Callback;
	Arg1 DefaultArg1;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3>
class DefaultParameterClosure3_123 : public IDelegate0 <Return>
{
public:
	
	DefaultParameterClosure3_123 ( IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure3_123 () {};
	
	inline Return operator() ()
	{
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3 );
		
	};
	
	inline Return Call ()
	{
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3>
class DefaultParameterClosure3_23 : public IDelegate1 <Return, Arg1>
{
public:
	
	DefaultParameterClosure3_23 ( IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback, Arg2 DefaultArg2, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure3_23 () {};
	
	inline Return operator() ( Arg1 _1 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3 );
		
	};
	
	inline Return Call ( Arg1 _1 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3>
class DefaultParameterClosure3_13 : public IDelegate1 <Return, Arg2>
{
public:
	
	DefaultParameterClosure3_13 ( IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback, Arg1 DefaultArg1, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure3_13 () {};
	
	inline Return operator() ( Arg2 _2 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3 );
		
	};
	
	inline Return Call ( Arg2 _2 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback;
	Arg1 DefaultArg1;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3>
class DefaultParameterClosure3_3 : public IDelegate2 <Return, Arg1, Arg2>
{
public:
	
	DefaultParameterClosure3_3 ( IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure3_3 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3 );
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3>
class DefaultParameterClosure3_12 : public IDelegate1 <Return, Arg3>
{
public:
	
	DefaultParameterClosure3_12 ( IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 )
	{
	};
	
	~DefaultParameterClosure3_12 () {};
	
	inline Return operator() ( Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3 );
		
	};
	
	inline Return Call ( Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
private:
	
	IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3>
class DefaultParameterClosure3_2 : public IDelegate2 <Return, Arg1, Arg3>
{
public:
	
	DefaultParameterClosure3_2 ( IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback, Arg2 DefaultArg2 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 )
	{
	};
	
	~DefaultParameterClosure3_2 () {};
	
	inline Return operator() ( Arg1 _1, Arg3 _3 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg3 _3 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
private:
	
	IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback;
	Arg2 DefaultArg2;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3>
class DefaultParameterClosure3_1 : public IDelegate2 <Return, Arg2, Arg3>
{
public:
	
	DefaultParameterClosure3_1 ( IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback, Arg1 DefaultArg1 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 )
	{
	};
	
	~DefaultParameterClosure3_1 () {};
	
	inline Return operator() ( Arg2 _2, Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
private:
	
	IDelegate3 <Return, Arg1, Arg2, Arg3> * Callback;
	Arg1 DefaultArg1;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_1234 : public IDelegate0 <Return>
{
public:
	
	DefaultParameterClosure4_1234 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg3 DefaultArg3, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure4_1234 () {};
	
	inline Return operator() ()
	{
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, DefaultArg4 );
		
	};
	
	inline Return Call ()
	{
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, DefaultArg4 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_234 : public IDelegate1 <Return, Arg1>
{
public:
	
	DefaultParameterClosure4_234 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg2 DefaultArg2, Arg3 DefaultArg3, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure4_234 () {};
	
	inline Return operator() ( Arg1 _1 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, DefaultArg4 );
		
	};
	
	inline Return Call ( Arg1 _1 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, DefaultArg4 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_134 : public IDelegate1 <Return, Arg2>
{
public:
	
	DefaultParameterClosure4_134 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg1 DefaultArg1, Arg3 DefaultArg3, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure4_134 () {};
	
	inline Return operator() ( Arg2 _2 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, DefaultArg4 );
		
	};
	
	inline Return Call ( Arg2 _2 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, DefaultArg4 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg1 DefaultArg1;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_34 : public IDelegate2 <Return, Arg1, Arg2>
{
public:
	
	DefaultParameterClosure4_34 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg3 DefaultArg3, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure4_34 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, DefaultArg4 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, DefaultArg4 );
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_124 : public IDelegate1 <Return, Arg3>
{
public:
	
	DefaultParameterClosure4_124 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure4_124 () {};
	
	inline Return operator() ( Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, DefaultArg4 );
		
	};
	
	inline Return Call ( Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, DefaultArg4 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_24 : public IDelegate2 <Return, Arg1, Arg3>
{
public:
	
	DefaultParameterClosure4_24 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg2 DefaultArg2, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure4_24 () {};
	
	inline Return operator() ( Arg1 _1, Arg3 _3 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, DefaultArg4 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg3 _3 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, DefaultArg4 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg2 DefaultArg2;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_14 : public IDelegate2 <Return, Arg2, Arg3>
{
public:
	
	DefaultParameterClosure4_14 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg1 DefaultArg1, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure4_14 () {};
	
	inline Return operator() ( Arg2 _2, Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, DefaultArg4 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, DefaultArg4 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg1 DefaultArg1;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_4 : public IDelegate3 <Return, Arg1, Arg2, Arg3>
{
public:
	
	DefaultParameterClosure4_4 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure4_4 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return Callback -> Call ( _1, _2, _3, DefaultArg4 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return Callback -> Call ( _1, _2, _3, DefaultArg4 );
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_123 : public IDelegate1 <Return, Arg4>
{
public:
	
	DefaultParameterClosure4_123 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure4_123 () {};
	
	inline Return operator() ( Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, _4 );
		
	};
	
	inline Return Call ( Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, _4 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_23 : public IDelegate2 <Return, Arg1, Arg4>
{
public:
	
	DefaultParameterClosure4_23 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg2 DefaultArg2, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure4_23 () {};
	
	inline Return operator() ( Arg1 _1, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, _4 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, _4 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_13 : public IDelegate2 <Return, Arg2, Arg4>
{
public:
	
	DefaultParameterClosure4_13 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg1 DefaultArg1, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure4_13 () {};
	
	inline Return operator() ( Arg2 _2, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, _4 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, _4 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg1 DefaultArg1;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_3 : public IDelegate3 <Return, Arg1, Arg2, Arg4>
{
public:
	
	DefaultParameterClosure4_3 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure4_3 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, _4 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, _4 );
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_12 : public IDelegate2 <Return, Arg3, Arg4>
{
public:
	
	DefaultParameterClosure4_12 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 )
	{
	};
	
	~DefaultParameterClosure4_12 () {};
	
	inline Return operator() ( Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, _4 );
		
	};
	
	inline Return Call ( Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, _4 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_2 : public IDelegate3 <Return, Arg1, Arg3, Arg4>
{
public:
	
	DefaultParameterClosure4_2 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg2 DefaultArg2 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 )
	{
	};
	
	~DefaultParameterClosure4_2 () {};
	
	inline Return operator() ( Arg1 _1, Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, _4 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, _4 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg2 DefaultArg2;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
class DefaultParameterClosure4_1 : public IDelegate3 <Return, Arg2, Arg3, Arg4>
{
public:
	
	DefaultParameterClosure4_1 ( IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback, Arg1 DefaultArg1 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 )
	{
	};
	
	~DefaultParameterClosure4_1 () {};
	
	inline Return operator() ( Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, _4 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, _4 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
private:
	
	IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4> * Callback;
	Arg1 DefaultArg1;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_12345 : public IDelegate0 <Return>
{
public:
	
	DefaultParameterClosure5_12345 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg3 DefaultArg3, Arg4 DefaultArg4, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_12345 () {};
	
	inline Return operator() ()
	{
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, DefaultArg4, DefaultArg5 );
		
	};
	
	inline Return Call ()
	{
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, DefaultArg4, DefaultArg5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_2345 : public IDelegate1 <Return, Arg1>
{
public:
	
	DefaultParameterClosure5_2345 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg2 DefaultArg2, Arg3 DefaultArg3, Arg4 DefaultArg4, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_2345 () {};
	
	inline Return operator() ( Arg1 _1 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, DefaultArg4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg1 _1 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, DefaultArg4, DefaultArg5 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_1345 : public IDelegate1 <Return, Arg2>
{
public:
	
	DefaultParameterClosure5_1345 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg3 DefaultArg3, Arg4 DefaultArg4, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_1345 () {};
	
	inline Return operator() ( Arg2 _2 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, DefaultArg4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg2 _2 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, DefaultArg4, DefaultArg5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_345 : public IDelegate2 <Return, Arg1, Arg2>
{
public:
	
	DefaultParameterClosure5_345 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg3 DefaultArg3, Arg4 DefaultArg4, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_345 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, DefaultArg4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, DefaultArg4, DefaultArg5 );
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_1245 : public IDelegate1 <Return, Arg3>
{
public:
	
	DefaultParameterClosure5_1245 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg4 DefaultArg4, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg4 ( DefaultArg4 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_1245 () {};
	
	inline Return operator() ( Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, DefaultArg4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, DefaultArg4, DefaultArg5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg4 DefaultArg4;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_245 : public IDelegate2 <Return, Arg1, Arg3>
{
public:
	
	DefaultParameterClosure5_245 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg2 DefaultArg2, Arg4 DefaultArg4, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg4 ( DefaultArg4 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_245 () {};
	
	inline Return operator() ( Arg1 _1, Arg3 _3 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, DefaultArg4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg3 _3 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, DefaultArg4, DefaultArg5 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg2 DefaultArg2;
	Arg4 DefaultArg4;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_145 : public IDelegate2 <Return, Arg2, Arg3>
{
public:
	
	DefaultParameterClosure5_145 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg4 DefaultArg4, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg4 ( DefaultArg4 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_145 () {};
	
	inline Return operator() ( Arg2 _2, Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, DefaultArg4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg3 _3 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, DefaultArg4, DefaultArg5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg4 DefaultArg4;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_45 : public IDelegate3 <Return, Arg1, Arg2, Arg3>
{
public:
	
	DefaultParameterClosure5_45 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg4 DefaultArg4, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg4 ( DefaultArg4 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_45 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return Callback -> Call ( _1, _2, _3, DefaultArg4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg3 _3 )
	{
		
		return Callback -> Call ( -1, _2, _3, DefaultArg4, DefaultArg5 );
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg4 DefaultArg4;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_1235 : public IDelegate1 <Return, Arg4>
{
public:
	
	DefaultParameterClosure5_1235 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg3 DefaultArg3, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_1235 () {};
	
	inline Return operator() ( Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, _4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, _4, DefaultArg5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_235 : public IDelegate2 <Return, Arg1, Arg4>
{
public:
	
	DefaultParameterClosure5_235 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg2 DefaultArg2, Arg3 DefaultArg3, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_235 () {};
	
	inline Return operator() ( Arg1 _1, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, _4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, _4, DefaultArg5 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_135 : public IDelegate2 <Return, Arg2, Arg4>
{
public:
	
	DefaultParameterClosure5_135 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg3 DefaultArg3, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_135 () {};
	
	inline Return operator() ( Arg2 _2, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, _4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, _4, DefaultArg5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg3 DefaultArg3;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_35 : public IDelegate3 <Return, Arg1, Arg2, Arg4>
{
public:
	
	DefaultParameterClosure5_35 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg3 DefaultArg3, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_35 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, _4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, _4, DefaultArg5 );
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg3 DefaultArg3;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_125 : public IDelegate2 <Return, Arg3, Arg4>
{
public:
	
	DefaultParameterClosure5_125 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_125 () {};
	
	inline Return operator() ( Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, _4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, _4, DefaultArg5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_25 : public IDelegate3 <Return, Arg1, Arg3, Arg4>
{
public:
	
	DefaultParameterClosure5_25 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg2 DefaultArg2, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_25 () {};
	
	inline Return operator() ( Arg1 _1, Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, _4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, _4, DefaultArg5 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg2 DefaultArg2;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_15 : public IDelegate3 <Return, Arg2, Arg3, Arg4>
{
public:
	
	DefaultParameterClosure5_15 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_15 () {};
	
	inline Return operator() ( Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, _4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, _4, DefaultArg5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_5 : public IDelegate4 <Return, Arg1, Arg2, Arg3, Arg4>
{
public:
	
	DefaultParameterClosure5_5 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg5 DefaultArg5 ):
		Callback ( Callback ),
		DefaultArg5 ( DefaultArg5 )
	{
	};
	
	~DefaultParameterClosure5_5 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, _2, _3, _4, DefaultArg5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg3 _3, Arg4 _4 )
	{
		
		return Callback -> Call ( _1, _2, _3, _4, DefaultArg5 );
		
	};
	
	void SetDefaultArg5 ( Arg5 DefaultArg5 )
	{
		
		this -> DefaultArg5 = DefaultArg5;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg5 DefaultArg5;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_1234 : public IDelegate1 <Return, Arg5>
{
public:
	
	DefaultParameterClosure5_1234 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg3 DefaultArg3, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure5_1234 () {};
	
	inline Return operator() ( Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, DefaultArg4, _5 );
		
	};
	
	inline Return Call ( Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, DefaultArg4, _5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_234 : public IDelegate2 <Return, Arg1, Arg5>
{
public:
	
	DefaultParameterClosure5_234 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg2 DefaultArg2, Arg3 DefaultArg3, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure5_234 () {};
	
	inline Return operator() ( Arg1 _1, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, DefaultArg4, _5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, DefaultArg4, _5 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_134 : public IDelegate2 <Return, Arg2, Arg5>
{
public:
	
	DefaultParameterClosure5_134 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg3 DefaultArg3, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure5_134 () {};
	
	inline Return operator() ( Arg2 _2, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, DefaultArg4, _5 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, DefaultArg4, _5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_34 : public IDelegate3 <Return, Arg1, Arg2, Arg5>
{
public:
	
	DefaultParameterClosure5_34 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg3 DefaultArg3, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg3 ( DefaultArg3 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure5_34 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, DefaultArg4, _5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, DefaultArg4, _5 );
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg3 DefaultArg3;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_124 : public IDelegate2 <Return, Arg3, Arg5>
{
public:
	
	DefaultParameterClosure5_124 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure5_124 () {};
	
	inline Return operator() ( Arg3 _3, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, DefaultArg4, _5 );
		
	};
	
	inline Return Call ( Arg3 _3, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, DefaultArg4, _5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_24 : public IDelegate3 <Return, Arg1, Arg3, Arg5>
{
public:
	
	DefaultParameterClosure5_24 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg2 DefaultArg2, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure5_24 () {};
	
	inline Return operator() ( Arg1 _1, Arg3 _3, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, DefaultArg4, _5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg3 _3, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, DefaultArg4, _5 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg2 DefaultArg2;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_14 : public IDelegate3 <Return, Arg2, Arg3, Arg5>
{
public:
	
	DefaultParameterClosure5_14 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure5_14 () {};
	
	inline Return operator() ( Arg2 _2, Arg3 _3, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, DefaultArg4, _5 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg3 _3, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, DefaultArg4, _5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_4 : public IDelegate4 <Return, Arg1, Arg2, Arg3, Arg5>
{
public:
	
	DefaultParameterClosure5_4 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg4 DefaultArg4 ):
		Callback ( Callback ),
		DefaultArg4 ( DefaultArg4 )
	{
	};
	
	~DefaultParameterClosure5_4 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg3 _3, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, _2, _3, DefaultArg4, _5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg3 _3, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, _2, _3, DefaultArg4, _5 );
		
	};
	
	void SetDefaultArg4 ( Arg4 DefaultArg4 )
	{
		
		this -> DefaultArg4 = DefaultArg4;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg4 DefaultArg4;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_123 : public IDelegate2 <Return, Arg4, Arg5>
{
public:
	
	DefaultParameterClosure5_123 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure5_123 () {};
	
	inline Return operator() ( Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, _4, _5 );
		
	};
	
	inline Return Call ( Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, DefaultArg3, _4, _5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_23 : public IDelegate3 <Return, Arg1, Arg4, Arg5>
{
public:
	
	DefaultParameterClosure5_23 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg2 DefaultArg2, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure5_23 () {};
	
	inline Return operator() ( Arg1 _1, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, _4, _5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, DefaultArg3, _4, _5 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg2 DefaultArg2;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_13 : public IDelegate3 <Return, Arg2, Arg4, Arg5>
{
public:
	
	DefaultParameterClosure5_13 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure5_13 () {};
	
	inline Return operator() ( Arg2 _2, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, _4, _5 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, DefaultArg3, _4, _5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_3 : public IDelegate4 <Return, Arg1, Arg2, Arg4, Arg5>
{
public:
	
	DefaultParameterClosure5_3 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg3 DefaultArg3 ):
		Callback ( Callback ),
		DefaultArg3 ( DefaultArg3 )
	{
	};
	
	~DefaultParameterClosure5_3 () {};
	
	inline Return operator() ( Arg1 _1, Arg2 _2, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, _2, DefaultArg3, _4, _5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg2 _2, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( -1, _2, DefaultArg3, _4, _5 );
		
	};
	
	void SetDefaultArg3 ( Arg3 DefaultArg3 )
	{
		
		this -> DefaultArg3 = DefaultArg3;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg3 DefaultArg3;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_12 : public IDelegate3 <Return, Arg3, Arg4, Arg5>
{
public:
	
	DefaultParameterClosure5_12 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1, Arg2 DefaultArg2 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 ),
		DefaultArg2 ( DefaultArg2 )
	{
	};
	
	~DefaultParameterClosure5_12 () {};
	
	inline Return operator() ( Arg3 _3, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, _4, _5 );
		
	};
	
	inline Return Call ( Arg3 _3, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, DefaultArg2, _3, _4, _5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	Arg2 DefaultArg2;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_2 : public IDelegate4 <Return, Arg1, Arg3, Arg4, Arg5>
{
public:
	
	DefaultParameterClosure5_2 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg2 DefaultArg2 ):
		Callback ( Callback ),
		DefaultArg2 ( DefaultArg2 )
	{
	};
	
	~DefaultParameterClosure5_2 () {};
	
	inline Return operator() ( Arg1 _1, Arg3 _3, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, _4, _5 );
		
	};
	
	inline Return Call ( Arg1 _1, Arg3 _3, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( _1, DefaultArg2, _3, _4, _5 );
		
	};
	
	void SetDefaultArg2 ( Arg2 DefaultArg2 )
	{
		
		this -> DefaultArg2 = DefaultArg2;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg2 DefaultArg2;
	
};


template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
class DefaultParameterClosure5_1 : public IDelegate4 <Return, Arg2, Arg3, Arg4, Arg5>
{
public:
	
	DefaultParameterClosure5_1 ( IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback, Arg1 DefaultArg1 ):
		Callback ( Callback ),
		DefaultArg1 ( DefaultArg1 )
	{
	};
	
	~DefaultParameterClosure5_1 () {};
	
	inline Return operator() ( Arg2 _2, Arg3 _3, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, _4, _5 );
		
	};
	
	inline Return Call ( Arg2 _2, Arg3 _3, Arg4 _4, Arg5 _5 )
	{
		
		return Callback -> Call ( DefaultArg1, _2, _3, _4, _5 );
		
	};
	
	void SetDefaultArg1 ( Arg1 DefaultArg1 )
	{
		
		this -> DefaultArg1 = DefaultArg1;
		
	};
	
private:
	
	IDelegate5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5> * Callback;
	Arg1 DefaultArg1;
	
};

#endif