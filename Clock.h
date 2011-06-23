#pragma once
//
// Clock
// (abstract class template)
// ----------
// + getTime(): float
// + create(): static Clock*
// - Clock(Clock const&):
// + ~Clock():virtual
// - operator=(const Clock&): Clock&
// ----------
// = Clock()
// ----------
//
class Clock{
public:
	virtual~Clock()=0{}
	virtual float getTime()const=0;
	static Clock*create();
protected:
	Clock(){}
private:
	Clock(Clock const&){}
	Clock &operator=(Clock const&){return*this;}
};