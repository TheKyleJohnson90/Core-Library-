#include"GenericTypes.h"
#include "Type.h"
#include "Const.h"

//Vector (majority of code learned from Accelerated C++ by Andrew Koenig and Barbara E. Moo)
template <class T> void Vector<T>::create(){
	data = avail = limit = 0;
}
template <class T> void Vector<T>::create(size_type n, const T& val){
	data = alloc.allocate(n);
	limit = avail =  data+n;
	//uninitialized_fill(data,limit,val);
}
template <class T> void Vector<T>::create(const_iterator i, const_iterator j){
	data = alloc.allocate(j-i);
	//avail = limit = unintialized_copy(i,j,data);
}
template <class T> void Vector<T>::uncreate(){
	if(data ){
		iteraotr it=avail;
		while (it!=0)
			alloc.destory(--it);

		alloc.dellocate(data,limit-data);
	}
	data=limit=avail=0;
}
template <class T> void Vector<T>::grow(){
	size_type new_size=max(2* (limit-data),ptrdiff_t(1));
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail=unitilized_copy(data,avail,new_data);

	uncreate();
	data=new_data;
	avail=new_avail;
	limit=data+new_size;
}
template <class T> void Vector<T>::unchecked_append(const T& val){
	alloc.construct(avail++,val);
}
//Pointers, Refrences, and Handles
template <class T> Handle<T>& Handle<T>::operator=(const Handle& rhs){
	if (&rhs !=this){
		delete p;
		p=rhs.p ? rhs.p->clone():0;
	}
	return *this;
}
template <class T> T& Handle<T>::operator*() const{
	if(p)
		return *p;
	throw runtime_error("unbound Handle");
}
template <class T> T* Handle<T>::operator->() const{
	if(p)
		return *p;
	throw runtime_error("unbound Handle");
}                                                                                                                                                                                                               
template <class T> Ref_Handle<T>& Ref_Handle<T>::operator=(const Ref_Handle& rhs) {
	++*rhs.reptr;
	if(--*refptr==0){
		delete refptr;
		delete p;
	}

	refptr=rhs.refptr;
	p=rhs.p;
	return *this;
}
template <class T> Ref_Handle<T>::~Ref_Handle(){
	if(--*refptr==0){
		delete refptr;
		delete p;
	}
}
template <class T> T* clone(const T* rhs){
	return rhs->clone();
}
template <class T> void Ptr<T>::make_unique(){
	if(*refptr!=1){
		--*refptr;
		refptr=new size_t(1);
		p=p? clone(p):0;
	}
}
//this a str function?
template <class T> Vector<char>* clone(const Vector<char>* vp){
	return new Vector<char>(*vp);
}