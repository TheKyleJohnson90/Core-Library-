#pragma once
#include "Const.h"
#include "Type.h"
//need to make my own assert()
#include <cassert>
//Returns Max
template<class TYPE> TYPE max(const TYPE& left, const TYPE& right){
	return left>right?left:right;
}
//Returns Min
template<class TYPE> TYPE min(const TYPE& left, const TYPE& right){
	return left<right?left:right;
}
//Used to quickly swap  
template<class TYPE> void swap(const TYPE& left, const TYPE& right){
	if(left!=right){
	TYPE temp=left;
	left=right;
	right=temp;
	}
}
//Find
template<class In,class X> In find(In Begin, In end, const X& x){
	while(begin!=end&&*begin!=x)
		++begin;
	return begin;
}
//Copy
template<class In,class Out> Out copy(In Begin, In end, Out dest){
	while(begin!=end)
		*dest++=*begin++;
	return dest;
}
//Replace
template<class For,class X> void replace(For begin,For end, const X& x, const X& y){
	while(begin!=end)
		if(*begin==x)
			*begin=y;
	++begin;
}
//
// Allocator
// (class template)
// ----------
// + allocate(size_t):TYPE*
// ----------
// + deallocate(TYPE*, size_t): void
// + construct(TYPE*, size_t): void
// + destroy(TYPE*, size_t): void
// ----------
//
template <class TYPE> class Allocator{
public:
	TYPE* allocate(size_t);
	void deallocate(TYPE*, size_t);
	void construct(TYPE*,TYPE);
	void destroy(TYPE*);

};
//
// Vector
// (class template)
// ----------
// + iterator :typedef TYPE*
// + const_iterator :typedef const TYPE*
// + sizetype :typedef size_t
// + value_type :typedef TYPE
// + 	Vector()
// + 	explicit Vector(size_type n, const TYPE& t=TYPE())
// + 	Vector(const Vector& v) 
// + 	Vector& operator=(const Vector&); 
// + 	~Vector()

// + 	TYPE& operator[] (size_type i)
// + 	const TYPE& operator[] (size_type i)const 
// + 	void push_back(const TYPE& t)

// + 	size_type size() const 
// + 	iterator begin() 
// + 	const_iterator begin() const 
// + 	iterator end() 
// + 	const_iterator end() const 
// ----------
// - data: iterator 
// - avail: iterator 
// - limit: iterator 
// - alloc:Allocator<TYPE> 
// - create():void
// - create(size_type,const TYPE&):void
// - create(const_iterator, const_iterator):void
// - uncreate():void
// - grow():void
// - unchecked_append(const TYPE&):void
// ----------
//
template <class TYPE> class Vector{
public:
	typedef TYPE* iterator;
	typedef const TYPE* const_iterator;
	typedef size_t size_type;
	typedef TYPE value_type;

	Vector(){create();}
	explicit Vector(size_type n, const TYPE& t=TYPE()){create(n,t);}

	Vector(const Vector& v) {create(v.begin(),v.end());}
	Vector& operator=(const Vector&); 
	~Vector(){uncreate();}

	TYPE& operator[] (size_type i){return data[i];}
	const TYPE& operator[] (size_type i)const {return data[i];}

	void push_back(const TYPE& t){
		if(avail==limit)
			grow();
		unchecked_append(t);
	}

	size_type size() const {return avail-data;}
	iterator begin() {return data;}
	const_iterator begin() const {return data;}
	iterator end() {return avail;}
	const_iterator end() const {return avail;}
private:
	iterator data;
	iterator avail;
	iterator limit;

	Allocator<TYPE> alloc;

	void create();
	void create(size_type,const TYPE&);
	void create(const_iterator, const_iterator);

	void uncreate();
	void grow();
	void unchecked_append(const TYPE&);

};
//Pointers, Refrences, and Handles
//
// Handle
// (class template)
// ----------
// + Handle():
// + Handle(TYPE*t):
// + Handle(const Handle& h):
// + ~Handle()
// + operator=(const Handle&): Handle&
// + operator bool() const: Handle&
// + operator *() const: TYPE&
// + operator ->() const: TYPE
// ----------
// - p:TYPE&
// ----------
//
template <class TYPE> class Handle{
public:
	Handle():p(0){};
	Handle(const Handle& s): p(0) {if (s.p) p =s.p->clone();}
	Handle& operator=(const Handle&);
	~Handle() {delete p;}

	Handle(TYPE* t):p(t){}

	operator bool() const {return p;}
	TYPE& operator*() const;
	TYPE* operator->() const;
private:
	TYPE& p;
};
//
// Ref_Handle
// (class template)
// ----------
// + Ref_Handle():
// + Ref_Handle(TYPE*t):
// + Ref_Handle(const Ref_Handle& h):
// + ~Ref_Handle()
// + operator=(const Ref_Handle&): Ref_Handle&
// + operator bool() const: Ref_Handle&
// + operator *() const: TYPE&
// + operator ->() const: TYPE
// ----------
// - p:TYPE&
// ----------
//
template <class TYPE> class Ref_Handle{
public:
	Ref_Handle(): refptr(new size_t(1)),p(0){}
	Ref_Handle(TYPE* t):refptr(new size_t(1)),p(t){}
	Ref_Handle(const Ref_Handle& h):refptr(h.refptr),p(h.p){	++*refptr;}

	Ref_Handle& operator=(const Ref_Handle&);
	~Ref_Handle();
	//
	operator bool() const { return p;}
	TYPE& operator*() const{
		if(p)
			return *p;
		throw std::runtime_error(*unbound Ref_Handle*);
	}
	TYPE* operator->() const{
		if(p)
			return p;
		throw std::runtime_error(*unbound Ref_Handle*);
	}
private:
	TYPE* p;
	size_t refptr;
};
//
// Ptr
// (class template)
// ----------
// + make_unique(): void
// + Ptr():
// + Ptr(TYPE*t):
// + Ptr(const Ptr& h):
// + ~Ptr()
// + operator=(constPtr&): Ptr&
// + operator bool() const: Ptr&
// + operator *() const: TYPE&
// + operator ->() const: TYPE
// ----------
// 
// ----------
//
template <class TYPE> class Ptr{
public:
	void make_unique();
	//
	Ptr(): refptr(new size_t(1)),p(0){}
	Ptr(TYPE* t):refptr(new size_t(1)),p(t){}
	Ptr(const Ptr& h):refptr(h.refptr),p(h.p){	++*refptr;}

	Ptr& operator=(const Ptr&);
	~Ptr();
	operator bool() const {return p;}
	TYPE& operator*()const;
	TYPE*operator->() const;
	//
private:
	TYPE*p;
	size_t* refptr;
};


//
// BSTNode
// (struct template)
// ----------
// + data:TYPE
// + up:BSTNode<TYPE>*
// + left:BSTNode<TYPE>*
// + right:BSTNode<TYPE>*
// + height:int
// ----------
// + BSTNode<TYPE>() {
// + BSTNode<TYPE>( new_data:const TYPE& , new_up BSTNode* )
// ----------
//
template <class TYPE>struct BSTNode{
	TYPE data;
	BSTNode<TYPE>* up;
	BSTNode<TYPE>* left;
	BSTNode<TYPE>* right;
	int height;
	BSTNode(){
		//////cout << "BSTNode()\n";
        data="";
        up=NULL;
        left=NULL;
        right=NULL;
        height=1;
	}
	BSTNode( TYPE const&new_data,BSTNode* new_up){
		//////cout << "BSTNode(new_data,new_up)\n";
        data=new_data;
        up=new_up;
        left=NULL;
        right=NULL;
        height=1;
	}
};
//
// BinarySearchTree
// (class template)
// ----------
// - root:BSTNode<TYPE>*
// - size:int
// ----------
// + BinarySearchTree ( )
// + virtual ~BinarySearchTree ( )
// + insert ( target:const TYPE& ): RetStat
// + search ( target:TYPE& ): RetStat
// + clear ( ): void
// + getSize ( ): int
// - ascend ( current:BSTNode<TYPE>* ): void
// - setNodeHeight ( current:BSTNode<TYPE>* ): int
// ----------
//
template <class TYPE>class BinarySearchTree{
private:
	BSTNode<TYPE>* root;
	int size;
	void ascend(BSTNode<TYPE>* current){
        //////cout << "ascend()\n";
		while(current!=NULL) {
            int difference=setNodeHeight(current);
            current=current->up;
        }
    }
	int setNodeHeight(BSTNode<TYPE>* current){
        //////cout << "setNodeHeight()\n";
		int highest=0;
        int difference=0;
        if(current->left!=NULL) {
            if(current->left->height>highest) {
                highest=current->left->height;
            }
            difference=current->left->height;
        }
        if(current->right!=NULL) {
            if(current->right->height>highest) {
                highest=current->right->height;
            }
            difference-=current->right->height;
        }
        current->height=highest+1;
        return difference;
    }
public:
	BinarySearchTree(){
        //////cout << "BinarySearchTree()\n";
        root=NULL;
        size=0;
    }
	virtual ~BinarySearchTree(){
        //////cout << "~BinarySearchTree()\n";
        clear();
    }
	RetStat insert(TYPE const& target){
		//////cout << "insert(), "<<target.c_str()<<"\n";
		 BSTNode<TYPE> *current=root;
        while(current!=NULL) {
            if(target==current->data) {
                // the key to insert is already in the BinarySearchTree...
                // as duplicates are not allowed,
                // we have us an error condition
                return DUPLICATE_ERROR;
            }
            if(target<current->data) {
                if(current->left==NULL) {
                    BSTNode<TYPE> * node=new BSTNode<TYPE>(target,current);
                    current->left=node;

                    // go back up the tree to make sure that
                    // all the node heights are correctly set
                    ascend(node);
                    size++;
                    return SUCCESS;
                }
                current=current->left;
            } else /* (target>current->data) */ {
                if(current->right==NULL) {
                    BSTNode<TYPE> * node=new BSTNode<TYPE>(target,current);
                    current->right=node;

                    // go back up the tree to make sure that
                    // all the node heights are correctly set
                    ascend(node);
                    size++;
                    return SUCCESS;
                }
                current=current->right;
            }
        }
        // the only way to get to this point is if root==NULL
        root = new BSTNode<TYPE>(target,NULL);
        size=1;
        return SUCCESS;
    }
	RetStat search(TYPE & target){
		//////cout << "search(), "<<target.c_str()<<"\n";
		 BSTNode<TYPE> * currNode;
        BSTNode<TYPE> * prevNode;

        prevNode=NULL;
        currNode=root;
        while(currNode!=NULL) {
            if(target==currNode->data) {
                return SUCCESS;
            }
            prevNode=currNode;
            if(target<currNode->data) {
                currNode=currNode->left;
            } else /* (target>currNode->data) */ {
                currNode=currNode->right;
            }
        }
        return FAIL;
    }
	void clear(){
        //////cout << "clear()\n";
		if(root==NULL) {
            return;
        }
        BSTNode<TYPE> *node=root;
        for(;;) {
            if(node->left!=NULL) {
                node=node->left;
            } else if(node->right!=NULL) {
                node=node->right;
            } else {
                // node->left==NULL && node->right==NULL
                //////cout << "clearing " << node->data << endl;
                BSTNode<TYPE> *next=node->up;
                if(next==NULL) {
                    root=NULL;
                    delete node;
                    break;
                }
                if(next->left==node) {
                    next->left=NULL;
                } else /* if(node->right==node) */ {
                    next->right=NULL;
                }
                delete node;
                node=next;
            }
        }
        size=0;
    }
	int getSize(){
        //////cout << "getSize()\n";
        return size;
    }
};
//
// ListN
// (class template)
// ----------
// + isEmpty:TYPE
// + isFull:BSTNode<TYPE>*
// + getLength:BSTNode<TYPE>*
// + getMaxSize:BSTNode<TYPE>*
// + InsertAt(const TYPE& t, int pos):int
// ----------
// + ~ListN() 
// + ListN(int listSize=10)
// ----------
// - m_MaxSize:int
// - m_Length:int
// - m_List:TYPE*
// 
template<class TYPE> class ListN{
public:
	bool isEmpty()const{
		return (m_Length==0);
	}
	bool isFull()const{
		return (m_Length==m_MaxSize);
	}
	int getLength()const{
		return m_Length;
	}
	int getMaxSize()const{
		return m_MaxSize;
	}
	//void sort();
	//void print() const;
	void InsertAt(const TYPE& t, int pos){
		assert(pos>=0&&pos<m_MaxSize);
		m_List[pos]=t;
		m_Length++;
	}
	ListN(int listSize=10){
		m_MaxSize=listSize;
		m_Length=0;
		m_List=new TYPE[MaxSize];
	}
	~ListN(){
		delete [] m_List;
	}
private:
	int m_MaxSize;
	int m_Length;
	TYPE * m_List;
};
//
// List
// (abstract base class)
// ----------
// # size:int
// ----------
// + List ( )
// + ~List ( )
// + getElement ( index:int, result:TYPE& ): RetStat
// + setElement ( index:int, result:const TYPE& ): RetStat
// + getSize ( ): int
// ----------
//
template <class TYPE>class ListAbstract{
protected:
	int size; 
public:
	ListAbstract(){
		//cout << "List()\n";
	}
	~ListAbstract(){
		//cout << "~List()\n";
	}
	virtual RetStat getElement(int index, TYPE& result)=0;
	virtual RetStat setElement(int index,const  TYPE& result)=0;
	int getSize(){
		return size;
	}
};
//
// ContiguousList
// (derives from List)
// ----------
// - array:TYPE*
// - size:int
// ----------
// + ContiguousList ( )
// + ContiguousList ( max:int )
// + ~ContiguousList ( )
// + getElement ( index:int, result:TYPE& ): RetStat
// + setElement ( index:int, result:const TYPE& ): RetStat
// ----------
//
template <class TYPE>class ContiguousList : public ListAbstract<TYPE>{
private:
	TYPE* array;
	int size;
public:
	ContiguousList(){
		array=TYPE[10];
		size=10;
	}
	ContiguousList(int max){
		if(max<2) {
			max=2;
		}
		array=TYPE[max];
		size=max;
	}
	~ContiguousList(){
		delete [] array;
	}
	RetStat getElement(int index, TYPE& result){
		if((index<0)||(index>=size)) {
		   return FAIL;
		}
		result=array[index];
		return SUCCESS;
	}
	RetStat setElement(int index,const TYPE& result){
		if((index<0)||(index>=size)) {
			return FAIL;
		}
		array[index]=result;
		return SUCCESS;
	}
};
//
// Vector
// (derives from List)
// ----------
// - array:TYPE*
// - size:int
// - alloc:int
// ----------
// + Vector ( )
// + Vector ( max:int )
// + ~Vector ( )
// + getElement ( index:int, result:TYPE& ): RetStat
// + setElement ( index:int, result:const TYPE& ): RetStat
// + pushBack ( result:const TYPE& ): RetStat
// ----------
//
//
template <class TYPE>class VectorN: public ListAbstract<TYPE>{
private:
	TYPE*array;
	int size;
	int alloc;
public:
	VectorN(){
		array=TYPE[10];
		size=0;
		alloc=10;
	}
	VectorN(int max)  {
		if(max<2) {
			max=2;
		}
		array=new TYPE[max];
		size=max;
		alloc=max;
	}
	~VectorN(){
			delete [] array;
}
	RetStat getElement(int index,TYPE&result){
		if((index<0)||(index>=size)) {
        return FAIL;
    }
    result=array[index];
    return SUCCESS;
}
	RetStat setElement(int index,TYPE const &result){
		if(size>=alloc) {
			// create a new array that is twice as big
			//cout << "pushBack(" << result.c_str() << "):  size=" << size << " oldAlloc=" << alloc  << "  newAlloc=" << (alloc*2) << endl;
			TYPE * newArray=new TYPE[alloc*2];
			// copy the contents of array[] into newArray[]
			for(int index=0;index<alloc;index++) {
				newArray[index]=array[index];
			}
			// null values for new alloc
			for(int index=alloc;(index<alloc*2);index++) {
				newArray[index]="";
			}
			// delete the old and replace with new
			delete [] array;
			array=newArray;
			alloc*=2;
		}else{
			//cout << "pushBack(" << result.c_str() << ")\n";
		}
		// save the new data at the end of array[] and bump the size
		array[size]=result;
		size++;
		return SUCCESS;
	}
	RetStat pushBack(TYPE const &result){
		if((index<0)||(index>=size)) {
			return FAIL;
		}
		array[index]=result;
		return SUCCESS;
	}
};
//
// DoublyLinkedNode
// ----------
// + key:TYPE
// + next:DoublyLinkedNode*
// + previous:DoublyLinkedNode*
// ----------
// + DoublyLinkedNode ( key:TYPE )
// + ~DoublyLinkedNode ( )
// ----------
//
template <class TYPE>class DoublyLinkedNode{
public:
	TYPE key;
	DoublyLinkedNode* next,*previous;
	DoublyLinkedNode(){
		////cout << "DoublyLinkedNode()\n";
		key=NULL;
		next=NULL;
		previous=NULL;
	}
	DoublyLinkedNode(TYPE newKey){
		////cout << "DoublyLinkedNode() : "<<newKey.c_str()<<"\n";
		key=newKey;
		next=NULL;
		previous=NULL;
	}
};	
//
// DoublyLinkedList
// (derives from List)
// ----------
// - front:DoublyLinkedNode*
// - back:DoublyLinkedNode*
// ----------
// + DoublyLinkedList ( )
// + ~DoublyLinkedList ( )
// + getElement ( index:int, key:TYPE& ): RetStat
// + setElement ( index:int, key:const TYPE& ): RetStat
// + pushBack ( key:const TYPE& ) : RetStat
// + pushFront ( key:const TYPE& ) : RetStat
// + popBack ( key:TYPE& ) : RetStat
// + popFront ( key:TYPE& ) : RetStat
// + getFront ( key:TYPE& ) : RetStat
// + getBack ( key:TYPE& ) : RetStat
// + clear ( ): RetStat
// + isEmpty ( ): bool
// + dump ( ): void
// + exercise ( ): static void
// ----------
//
template <class TYPE>class DoublyLinkedList:public ListAbstract<TYPE>{
private:
	DoublyLinkedNode *front,*back;
public:
	DoublyLinkedList(){
		////cout << "DoublyLinkedList()\n";
		size=0;
		front=NULL;
		back=NULL;
	}
	~DoublyLinkedList(){
		////cout << "~DoublyLinkedList()\n";
		if(!isEmpty()){
			////cout << "Clearing Nodes\n";
			clear();
		}else{
			////cout << "Empty List Destroyed\n";
		}
		
	}
	RetStat getElement(int index,TYPE& key){
		////cout << "getElement()\n";
        if((index < 0) || (index >= size)){
            return FAIL;
		}else{
			DoublyLinkedNode * current = front;
			for(int ii = 0; ii < index; ii++){
				current=current->next;
			}
			key = current->key;
			return SUCCESS;
		}
	}
	RetStat setElement(int index,const TYPE& key){
		////cout << "setElement()\n";
		if((index < 0) || (index >= size)){
            return FAIL;
		}else{
			DoublyLinkedNode * current = front;
			for(int ii = 0; ii < index; ii++){
				current=current->next;
			}
			current->key=key;
			return SUCCESS;
		}
	}
	RetStat pushBack(const TYPE& key){
		////cout << "pushBack()\n";
		DoublyLinkedNode *newNode=new DoublyLinkedNode(key);
		if(isEmpty()){
			front = back=newNode;
			size=1;
			return SUCCESS;
		}else{
			newNode->previous=back;
			back->next=newNode;
			back=newNode;
			size++;
			return SUCCESS;
		}
	}
	RetStat pushFront(const TYPE& key){
		////cout << "pushFront()\n";
		DoublyLinkedNode *newNode=new DoublyLinkedNode(key);
		if(isEmpty()){
			front = back=newNode;
			size=1;
			return SUCCESS;
		}else{
			newNode->next=front;
			front->previous=newNode;
			front=newNode;
			size++;
			return SUCCESS;
		}
	}
	RetStat popBack(TYPE& key){
		////cout << "popBack()\n";
		if(isEmpty()){
			return FAIL;
		}else{
			DoublyLinkedNode *oldNode=back;
			back->previous->next=NULL;
			back=back->previous;
			size--;
			if(size==0){
				front=back=NULL;
			}
			key=oldNode->key;
			delete oldNode;
			return SUCCESS;
		}
	}
	RetStat popFront(TYPE& key){
		////cout << "popFront()\n";
		if(isEmpty()){
			return FAIL;
		}else if(front == back) {
            key = front->key;
            delete front;
            front=back=NULL;
            size = 0;
            return SUCCESS;
        }else{
			DoublyLinkedNode *oldNode=front;
			front->next->previous=NULL;
			front=front->next;
			size--;
			if(size==0){
				back=front=NULL;
			}
			key=oldNode->key;
			delete oldNode;
			return SUCCESS;
		}
	}
	RetStat getFront(TYPE& key){
		////cout << "getFront()\n";
		if(isEmpty()){
			return FAIL;
		}else{
			key=front->key;
			return SUCCESS;
		}
	}
	RetStat getBack(TYPE& key){
		////cout << "getBack()\n";
		if(isEmpty()){
			return FAIL;
		}else{
			key=back->key;
			return SUCCESS;
		}
	}
	RetStat clear(){
		////cout << "clear()\n";
		DoublyLinkedNode *oldNode=front;
		while(oldNode!=NULL){
			front=oldNode->next;
			delete oldNode;
			oldNode=front;
		}
		size=0;
		front=back=NULL;
		return SUCCESS;
	}
	bool isEmpty(){
		////cout << "isEmpty()\n";
		if (front == NULL) {
            return true;
        }
        return false;
	}
	void dump(){
		////cout << "dump()\n";
		DoublyLinkedNode *current=front;
		////cout <<"FRONT->"<<front<<"\n";
		for(int ii=0;current!=NULL;ii++){
			current=current->next;
			////cout << "Node #"<<ii<<"\n";
			////cout << "*Previous=";
			if(current->previous==NULL){
				////cout <<"NULL";
			}else{
				////cout <<current->previous;
			}
			////cout << "\n*Next=";
			if(current->next==NULL){
				////cout <<"NULL";
			}else{
				////cout <<current->next;
			}
			////cout << "\nKey="<<current->key.c_str();
		}
		////cout << "BACK->"<<back<<"\n";
	}
	
};
//
// SinglyLinkedNode
// ----------
// + key:TYPE
// + next:SinglyLinkedNode*
// ----------
// + SinglyLinkedNode ( key:TYPE )
// + ~SinglyLinkedNode ( )
// ----------
template <class TYPE>class SinglyLinkedNode{
public:
	TYPE key;
	SinglyLinkedNode* next;
	SinglyLinkedNode(TYPE newKey){
		////cout << "SinglyLinkedNode() : "<<newKey.c_str()<<"\n";
		key=newKey;
	}
	~SinglyLinkedNode(){
		////cout << "~SinglyLinkedNode()\n";
	}
};
//
// SinglyLinkedList
// (derives from List)
// ----------
// - front:SinglyLinkedNode*
// - back:SinglyLinkedNode*
// ----------
// + SinglyLinkedList ( )
// + ~SinglyLinkedList ( )
// + getElement ( index:int, key:TYPE& ): RetStat
// + setElement ( index:int, key:const TYPE& ): RetStat
// + pushBack ( key:const TYPE& ) : RetStat
// + pushFront ( key:const TYPE& ) : RetStat
// + popBack ( key:TYPE& ) : RetStat
// + popFront ( key:TYPE& ) : RetStat
// + getFront ( key:TYPE& ) : RetStat
// + getBack ( key:TYPE& ) : RetStat
// + clear ( ): RetStat
// + isEmpty ( ): bool
// + dump ( ): void
// + exercise ( ): static void
// ----------
//
//
template <class TYPE>class SinglyLinkedList:public ListAbstract<TYPE>{
private:
	SinglyLinkedNode *front,*back;
public:
	SinglyLinkedList(){
		////cout << "SinglyLinkedList()\n";
	}
	~SinglyLinkedList(){
		////cout << "~SinglyLinkedList()\n";
	}
	RetStat getElement(int index,TYPE& key){
		////cout << "getElement()\n";
        if((index < 0) || (index >= size)){
            return FAIL;
		}else{
			SinglyLinkedNode * current = front;
			for(int ii = 0; ii < index; ii++){
				current=current->next;
			}
			key = current->key;
			return SUCCESS;
		}
	}
	RetStat setElement(int index,const TYPE& key){
		////cout << "setElement()\n";
		if((index < 0) || (index >= size)){
            return FAIL;
		}else{
			SinglyLinkedNode * current = front;
			for(int ii = 0; ii < index; ii++){
				current=current->next;
			}
			current->key=key;
			return SUCCESS;
		}
	}
	RetStat pushBack(const TYPE& key){
		////cout << "pushBack()\n";
		SinglyLinkedNode *newNode=new SinglyLinkedNode(key);
		if(isEmpty()){
			front=back=newNode;
			size=1;
			return SUCCESS;
		}else{
			//newNode->previous=back;
			back->next=newNode;
			back=newNode;
			size++;
			return SUCCESS;
		}
	}
	RetStat pushFront(const TYPE& key){
		////cout << "pushFront()\n";
		SinglyLinkedNode *newNode=new SinglyLinkedNode(key);
		if(isEmpty()){
			front = back=newNode;
			size=1;
			return SUCCESS;
		}else{
			newNode->next=front;
			//front->previous=newNode;
			front=newNode;
			size++;
			return SUCCESS;
		}
	}
	RetStat popBack(TYPE& key){
		////cout << "popBack()\n";
		if(isEmpty()){
			return FAIL;
		}else{
			SinglyLinkedNode *oldNode=back;
			//loop to find

			size--;
			if(size==0){
				front=back=NULL;
			}
			key=oldNode->key;
			delete oldNode;
			return SUCCESS;
		}
	}
	RetStat popFront(TYPE& key){
		////cout << "popFront()\n";
		if(isEmpty()){
			return FAIL;
		}else if(front == back) {
            key = front->key;
            delete front;
            front=back=NULL;
            size = 0;
            return SUCCESS;
        }else{
			SinglyLinkedNode *oldNode=front;
			//front->next->previous=NULL;
			front=front->next;
			size--;
			if(size==0){
				back=front=NULL;
			}
			key=oldNode->key;
			delete oldNode;
			return SUCCESS;
		}
	}
	RetStat getFront(TYPE& key){
		////cout << "getFront()\n";
		if(isEmpty()){
			return FAIL;
		}else{
			key=front->key;
			return SUCCESS;
		}
	}
	RetStat getBack(TYPE& key){
		////cout << "getBack()\n";
		if(isEmpty()){
			return FAIL;
		}else{
			key=back->key;
			return SUCCESS;
		}
	}
	RetStat clear(){
		////cout << "clear()\n";
		SinglyLinkedNode *oldNode=front;
		while (front != NULL) {
            oldNode = front;
            front = front->next;
            delete oldNode;
        }
		size=0;
		front=back=NULL;
		return SUCCESS;
	}
	bool isEmpty(){
		////cout << "isEmpty()\n";
		if (front == NULL) {
            return true;
        }
        return false;
	}
	void dump(){
		////cout << "dump()\n";
		SinglyLinkedNode *current=front;
		////cout <<"FRONT->"<<front<<"\n";
		for(int ii=0;current!=NULL;ii++){
			
			if(current->next==NULL){
				////cout <<"NULL";
			}else{
				////cout <<current->next;
				current=current->next;
				////cout << "Node #"<<ii<<"\n";
				////cout << "\n*Next=";
			}
			////cout << "\nKey="<<current->key.c_str();
		}
		////cout << "BACK->"<<back<<"\n";
	}
};
//
// StackAbstract
// (struct template)
// ----------
// + initializeStack():void
// + isEmptyStack():bool
// + isFullStack(); bool
// + push(TYPE): void
// + top(): TYPE
// + pop(): void
// ----------
//
template <class TYPE>struct StackAbstract{
	virtual void initializeStack()=0;
	virtual bool isEmptyStack()const =0;
	virtual bool isFullStack()const =0;
	virtual void push(const TYPE &newItem)=0
	virtual TYPE top()const=0;
	virtual void pop()=0;
};
//
// Stack
// (class template)
// ----------
// + initializeStack():void
// + isEmptyStack():bool
// + isFullStack(); bool
// + push(TYPE): void
// + top(): TYPE
// + pop(): void
// ----------
// + Stack(int newSize=10)
// + Stack(const Stack& other)
// + ~Stack()
// ----------
// - m_MaxSize: int
// - m_Top: int
// - m_List: TYPE*
// - copy(const Stack& other): void
//
template <class TYPE> class Stack:public StackAbstract<TYPE>{
public:
	void initializeStack(){m_Top=0;}
	bool isEmptyStack()const{return (m_Top==0);}
	bool isFullStack()const{return (m_Top==m_MaxSize);}
	void push(const TYPE &newItem){
		if (!isFullStack()){
			m_List[m_Top]=newItem;
			m_Top++;
		}
			//else //maybe put this into try and catch
	}
	TYPE top()const{
		assert(m_Top!= 0);
		return m_List[m_Top-1];
	}
	void pop(){
		if(!isEmptyStack())
			m_Top--;
	}
	Stack(int newSize){
		if(newSize<1)
			newSize=1;
		m_MaxSize=newSize;
		m_Top=0;
		m_List=new TYPE[m_MaxSize];
	}
	~Stack(){
		delete [] m_List;
	}
	Stack(const Stack<TYPE>& other){
		if(this!=other)
			copy(other);
	}
	const Stack<TYPE> operator=(const Stack<TYPE>& other){
		if(this!=other)
			copy(other);
		return *this;
	}
private:
	int m_MaxSize;
	int m_Top;
	TYPE * m_List;
	void copy(const Stack<TYPE>& other){
		delete [] m_List;
		m_MazSize=other.m_MaxSize;
		m_Top=other.m_Top;
		list= new TYPE[m_MaxSize];
		for(int j =;j<m_Top;j++)
			m_List[j]=other.m_List[j];
	}
	
};
//
// LinkedNode
// (struct template)
// ----------
// + key:TYPE
// + LinkedNode*: link
// + LinkedNode(TYPE newKey)
// + ~LinkedNode() 
// ----------
//
template <class TYPE>struct LinkedNode{
	TYPE key;
	LinkedNode* link;
	LinkedNode(TYPE newKey){
		////cout << "SinglyLinkedNode() : "<<newKey.c_str()<<"\n";
		key=newKey;
	}
	~LinkedNode(){
		////cout << "~SinglyLinkedNode()\n";
		delete [] link;
	}
};
//
// LinkedStack
// (struct template)
// ----------
// + initializeStack():void
// + isEmptyStack():bool
// + isFullStack(): bool
// + push(TYPE & newItem): void
// + top(): TYPE
// + pop(): void
// ----------
// + LinkedStack(int newSize=10)
// + LinkedStack(const Stack& other)
// + ~LinkedStack()
// ----------
//
template <class TYPE>class LinkedStack:public Stack<TYPE>{
public:
	void initializeStack(){
		LinkedNode<TYPE> * temp;
		while (m_Top!=NUll){
			temp=m_Top;
			m_Top=m_Top->link;
			delete temp;
		}
	}
	bool isEmptyStack()const{return (m_Top==NULL);}
	bool isFullStack()const{return false;}//Thinking Logically 
	void push(const TYPE &newItem){
		LinkedNode<TYPE> * newNode;
		newNode=new LinkedNode<TYPE>;
		newNode->key=newItem;
		newNode->link=m_Top;
		m_Top=newNode;
	}
	TYPE top()const{
		assert(m_Top!= NULL);
		return m_Top->key;
	}
	void pop(){
		LinkedNode<TYPE> * newNode;
		if(m_Top!=NULL){
			newNode=m_Top;
			m_Top=m_Top->link;
			delete newNode;
		}

	}
	LinkedStack(){
		m_Top=NULL;
	}
	LinkedStack(int newSize){
		if(newSize<1)
			newSize=1;
		m_MaxSize=newSize;
		m_Top=0;
		m_List=new TYPE[m_MaxSize];
	}
	~LinkedStack(){
		delete [] m_List;
	}
	LinkedStack(const LinkedStack<TYPE>& other){
		if(this!=other)
			copy(other);
	}
	const LinkedStack<TYPE> operator=(const LinkedStack<TYPE>& other){
		if(this!=other)
			copy(other);
		return *this;
	}
private:
	LinkedNode<TYPE> * m_Top;
	void copy(const LinkedStack<TYPE>& other){

		LinkedNode<TYPE> * newNode,*current,*last;
		if(m_Top!=NULL)
			initializeStack();
		if (other.m_Top==NULL)
			m_Top=NULL;
		else{
			current=other.m_Top;
			m_Top=new LinkedNode<TYPE>;
			//newNode=m_Top;
			m_Top->key=current->key;
			m_Top->link=current->link;
			last=m_Top;
			current=current->link;
			while (current!=NULL){
				newNode=new LinkedNode<TYPE>;
				newNode->key=current->key;
				newNode->link=NULL;
				last->link=newNode;
				last=newNode;
				current=current->link;
			}
		}
	}
	
};