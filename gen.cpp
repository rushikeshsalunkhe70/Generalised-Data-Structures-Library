#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//
//  Class :         QueueX
//  Description :   Generic implementation of queue
//  Author :        Rushikesh Gajanan Salunkhe
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template <class T>
class QueueX
{
    private:
        struct Queuenode<T> *first;
        int iCount;

    public:
        QueueX();
        void Enqueue(
                       T
                    );

        T Dequeue();

        void Display();

        int Count();
};
//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	QueueX
//	Function Date			:	18/09/2025
//	Function Author			:	Rushikesh Gajanan Salunkhe
//	Parameters  			:   NONE
//	Description             :   This is constructor of class QueueX
//  Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Enqueue
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added in the queue.
//
//	Description:
//		This function adds element in the in the queue.
//
//	Returns:
//		None
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void QueueX<T> :: Enqueue(
                            T no
                        ) 
{
    struct Queuenode<T> *temp = NULL;
    struct Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Dequeue
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Deletes the element from the queue.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T QueueX<T> :: Dequeue()         
{
    struct Queuenode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to remove as queue is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        delete temp;

        iCount--;

        return value;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Displays elements from the Queue.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void QueueX<T> :: Display()
{
    struct Queuenode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function is used to count the elemnts from the Queue.
//
//	Returns:
//		Count of the elements present in the Queue.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int QueueX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         StackX
//  Description :   Generic implementation of stack
//  Author :        Rushikesh Gajanan Salunkhe
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

template<class T>
class StackX
{
    private:
        struct Stacknode<T> *first;
        int iCount;

    public:
        StackX();
        void Push(
                   T
                );
        T Pop();
        void Display();
        int Count();
};

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	StackX
//	Function Date			:	18/09/2025
//	Function Author			:	Rushikesh Gajanan Salunkhe
//	Parameters  			:   NONE
//	Description             :   This is constructor of class StackX
//  Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Push
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added in the stack.
//
//	Description:
//		This function adds element in the stack.
//
//	Returns:
//		None
//
//////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void StackX<T> :: Push(
                        T no
                    )  
{
    struct Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Pop
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Deletes the element from the stack.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T StackX<T> :: Pop()         // DeleteFirst
{
    struct Stacknode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to pop as stack is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        delete temp;

        iCount--;

        return value;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Displays elements from Stack.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void StackX<T> :: Display()
{
    struct Stacknode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	15/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function is used to count the elemnts from the stack.
//
//	Returns:
//		Count of the elements present in the stack.
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int StackX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyCLL
//  Description :   Generic implementation of singly circular linked list
//  Author :        Rushikesh Gajanan Salunkhe
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(
                          T no
                        );

        void InsertLast( 
                         T no
                        );

        void DeleteFirst();

        void DeleteLast();

        void Display();

        int Count();

        void DeleteAtPos(
                          int pos
                        );

        void InsertAtPos(
                          T no, 
                          int pos
                        );
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SinglyCLL
//	Function Date			:	18/09/2025
//	Function Author			:	Rushikesh Gajanan Salunkhe
//	Parameters  			:   NONE
//	Description             :   This is constructor of class SinglyCLL
//  Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added first.
//
//	Description:
//		This function adds element in the first of the linked list.
//
//	Returns:
//		None
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added last.
//
//	Description:
//		This function adds element at the last of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Deletes the first node of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function deletes the last node of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Displays elements from the Linked List.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function is used to count the elemnts from the linked list.
//
//	Returns:
//		Count of the elements present in the linked list.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] int pos.
//		Holds the entry at which position to be deleted.
//
//	Description:
//		This function deletes the node at given position from the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteAtPos(
                                int pos
                            )
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added last.
//      [IN] int pos.
//      Holds the entry at which position to be added.
//
//	Description:
//		This function inserts the element in the linked list at given position.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertAtPos(
                                T no, 
                                int pos
                            )
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyCLL
//  Description :   Generic implementation of doubly cirular Linked List
//  Author :        Rushikesh Gajanan Salunkhe
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template <class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();

        void Display();

        int Count();

        void InsertFirst(
                          T
                        );

        void InsertLast( 
                          T
                        );

        void InsertAtPos(
                          T,
                          int
                        );
        
        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(
                          int
                        );
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyCLL
//	Function Date			:	18/09/2025
//	Function Author			:	Rushikesh Gajanan Salunkhe
//	Parameters  			:   NONE
//	Description             :   This is constructor of class DoublyCLL
//  Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside Constructor\n";
    
    first = NULL;
    last = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added first.
//
//	Description:
//		This function adds element in the first of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T> :: InsertFirst(
                                  T no
                                )
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    } 

    last->next = first;
    first->prev = last;

    iCount++;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added last.
//
//	Description:
//		This function adds element at the last of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        last->next = newn;
        newn->prev = last;

        last = newn;
    } 

    last->next = first;
    first->prev = last;
    
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Displays elements from the Linked List.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    cout<<"Elements of the LinkedList are : \n";

    temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"LinkedList is empty\n";
        return;
    }

    do
    {
        cout<<"| "<< temp->data <<" | <=> ";
        temp = temp->next;   
    } while (temp != first);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function is used to count the elemnts from the linked list.
//
//	Returns:
//		Count of the elements present in the linked list.
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T> :: Count()
{
    return iCount;  
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Deletes the first node of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete first;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        first = first -> next;
        delete first->prev;     // delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function deletes the last node of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete last;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        last = last -> prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added last.
//      [IN] int pos.
//      Holds the entry at which position to be added.
//
//	Description:
//		This function inserts the element in the linked list at given position.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertAtPos(
                                  T no, 
                                  int pos
                                )
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] int pos.
//		Holds the entry at which position to be deleted.
//
//	Description:
//		This function deletes the node at given position from the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyLLL 
//  Description :   Generic implementation of singly linear Linked List
//  Author :        Rushikesh Gajanan Salunkhe
//
///////////////////////////////////////////////////////////////////////


template <class T>
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode<T>* next;
};

template <class T>
class SinglyLLL
{
private:
   struct  SinglyLLLnode<T>* first;
    int iCount;

public:
    SinglyLLL();
    
    void InsertFirst(
                      T no
                    );

    void InsertLast(
                      T no
                    );

    void InsertAtPos(
                      T no,
                      int pos
                    );

    void DeleteFirst();

    void DeleteLast();

    void DeleteAtPos(
                      int pos
                    );

    void Display();

    int Count();
};

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SinglyLLL
//	Function Date			:	18/09/2025
//	Function Author			:	Rushikesh Gajanan Salunkhe
//	Parameters  			:   NONE
//	Description             :   This is constructor of class SinglyLLL
//  Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyLLL<T>::SinglyLLL()
{
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added first.
//
//	Description:
//		This function adds element in the first of the linked list.
//
//	Returns:
//		None
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertFirst(
                                T no
                            )
{
    struct SinglyLLLnode<T> * newn = NULL;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)                         // LL is Empty
    {
        first = newn;
    }
    else 
    {
        newn->next = first;
        first = newn;
    }

    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added last.
//
//	Description:
//		This function adds element at the last of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertLast(
                               T no
                            )
{
    struct SinglyLLLnode<T> * newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)                         
    {
        first = newn;
    }
    else                                    
    {
        temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added last.
//      [IN] int pos.
//      Holds the entry at which position to be added.
//
//	Description:
//		This function inserts the element in the linked list at given position.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertAtPos(
                                T no, 
                                int pos
                            )
{
    int i = 0;
    struct SinglyLLLnode<T> * temp = NULL;
    struct SinglyLLLnode<T> * newn = NULL;

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;

        for(i = 1; i <= pos-2; i++)
        {
            temp = temp -> next;
        }

        newn = new struct SinglyLLLnode<T>;

        newn-> data = no;
        newn -> next = NULL;

        newn-> next = temp -> next;
        temp -> next = newn;
    }

    
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Deletes the first node of the linked list.
//
//	Returns:
//		None
//
//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    struct SinglyLLLnode<T> * temp = NULL;

    if(first == NULL)                      
    {
        return;
    }
    else if(first -> next == NULL)            
    {
        delete first;
        first = NULL;
    }
    else                          
    {
        temp = first;

        first = first -> next;

        delete temp;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function deletes the last node of the linked list.
//
//	Returns:
//		None
//
/////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteLast()
{
     struct SinglyLLLnode<T> * temp = NULL;

    if(first == NULL)           
    {
        return;
    }
    else if(first -> next == NULL)          
    {
        delete first;
        first = NULL;
    }
    else                             
    {
        temp = first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp->next = NULL;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] int pos.
//		Holds the entry at which position to be deleted.
//
//	Description:
//		This function deletes the node at given position from the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteAtPos( 
                               int pos
                            )
{
   int i = 0;
    struct SinglyLLLnode<T> * temp = NULL;
    struct SinglyLLLnode<T> * target = NULL;

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i <= pos-2; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp -> next = target -> next;         
        delete target;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Displays elements from the Linked List.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::Display()
{
    struct SinglyLLLnode<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function is used to count the elemnts from the linked list.
//
//	Returns:
//		Count of the elements present in the linked list.
//
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyLLL 
//  Description :   Generic implementation of doubly linear Linked List
//  Author :        Rushikesh Gajanan Salunkhe
//
///////////////////////////////////////////////////////////////////////


template <class T>
struct DoublyLLLnode
{
    T data;
    struct  DoublyLLLnode<T>* next;
    struct  DoublyLLLnode<T>* prev;
};

template <class T>
class DoublyLLL
{
private:
    struct DoublyLLLnode<T>* first;
    int iCount;

public:
    DoublyLLL();

    void Display();

    int Count();

    void InsertFirst(
                      T no
                    );

    void InsertLast(
                      T no
                    );

    void InsertAtPos(
                      T no,  
                      int pos
                    );

    void DeleteFirst();

    void DeleteLast();

    void DeleteAtPos(
                     int pos
                    );
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyLLL
//	Function Date			:	18/09/2025
//	Function Author			:	Rushikesh Gajanan Salunkhe
//	Parameters  			:   NONE
//	Description             :   This is constructor of class DoublyLLL
//  Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLLL<T>::DoublyLLL()
{
  this->first = NULL;
  this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Displays elements from the Linked List.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::Display()
{
    cout<<" NULL -> ";
    while(first != NULL)
    {
        cout<<"| "<<first->data<<" | -> ";
        first = first->next;
    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function is used to count the elemnts from the linked list.
//
//	Returns:
//		Count of the elements present in the linked list.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added first.
//
//	Description:
//		This function adds element in the first of the linked list.
//
//	Returns:
//		None
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::InsertFirst(
                                T no
                            )
{
    struct DoublyLLLnode<T> * newn = NULL;

    newn = new struct DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;             

    if(first == NULL)                 
    {
        first = newn;
    }
    else                                 
    {
        newn->next = first;
        first-> prev = newn;            
        first = newn;
    }

    iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added last.
//
//	Description:
//		This function adds element at the last of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::InsertLast(
                              T no
                            )
{
    struct DoublyLLLnode<T> * newn = NULL;
    struct DoublyLLLnode<T> * temp = NULL;

    newn = new struct DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;             

    if(first == NULL)                 
    {
        first = newn;
    }
    else                                 
    {
        temp = first;

        while(temp-> next != NULL)
        {
            temp = temp -> next;
        }

        newn -> prev = temp;             
        temp -> next = newn;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no.
//		Holds the entry which is to be added last.
//      [IN] int pos.
//      Holds the entry at which position to be added.
//
//	Description:
//		This function inserts the element in the linked list at given position.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    int iCnt = 0;
    struct DoublyLLLnode<T> * newn = NULL;
    struct DoublyLLLnode<T> * temp = NULL;

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyLLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn-> next = temp -> next;
        newn-> next->prev = newn;                  
        temp-> next = newn;
        newn-> prev = temp;                         
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Deletes the first node of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if((first)-> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first -> next;  
        delete first-> prev;             
        first-> prev = NULL;             
    } 
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function deletes the last node of the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::DeleteLast()
{
     struct DoublyLLLnode<T> * temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first-> next == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp-> next != NULL)           
        {
            temp = temp-> next;
        }

        temp-> prev-> next = NULL;           
        delete temp;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] int pos.
//		Holds the entry at which position to be deleted.
//
//	Description:
//		This function deletes the node at given position from the linked list.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::DeleteAtPos(
                                int pos
                            )
{
 int iCnt = 0;
    struct DoublyLLLnode<T> * temp = NULL;
    struct DoublyLLLnode<T> * target = NULL;

    if((pos < 1) || (pos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp-> next;
        }

        target = temp -> next;
        temp-> next = target -> next;
        target-> next -> prev = temp;         
        delete target;
    }   
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         BST 
//  Description :   Generic implementation of Binary Search Tree
//  Author :        Rushikesh Gajanan Salunkhe
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct BSTnode
{
    T data;
    BSTnode<T>* lchild;
    BSTnode<T>* rchild;
};

////////////////////////////////////////////////////////////////////////////////////
//
//  Class :         BST
//  Description :   Generic Binary Search Tree
//
////////////////////////////////////////////////////////////////////////////////////

template <class T>
class BST
{
private:
    BSTnode<T>* root;

    void InorderX(
                    BSTnode<T>* temp
                );

    void PreorderX(
                        BSTnode<T>* temp
                    );

    void PostorderX(
                        BSTnode<T>* temp
                    );

    bool SearchX(
                    BSTnode<T>* temp, 
                    T no
                );

    int CountX(
                    BSTnode<T>* temp
                );

    int CountLeafNodesX(
                            BSTnode<T>* temp
                        );

    int CountParentNodesX(
                            BSTnode<T>* temp
                        );

public:
    BST();

    void Insert(
                    T no
                );

    void Inorder();

    void Preorder();

    void Postorder();

    bool Search(
                    T no
                );

    int Count();

    int CountLeafNodes();

    int CountParentNodes();
};

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : BST (Constructor)
//  Description   : Initializes the root pointer to nullptr
//  Author        : Rushikesh Gajanan Salunkhe
//  Date          : 18/09/2025
//
////////////////////////////////////////////////////////////////////////////////////

template <class T>
BST<T>::BST()
{
    root = nullptr;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Insert
//  Description   : Inserts a new element into the BST
//  Author        : Rushikesh Gajanan Salunkhe
//  Date          : 18/09/2025
//
////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Insert(
                        T no
                    )
{
    BSTnode<T>* newn = new BSTnode<T>{no, nullptr, nullptr};

    if (root == nullptr)
    {
        root = newn;
        return;
    }

    BSTnode<T>* temp = root;
    while (true)
    {
        if (no == temp->data)
        {
            cout << "Duplicate element: Unable to insert node\n";
            delete newn;
            break;
        }
        else if (no < temp->data)
        {
            if (temp->lchild == nullptr)
            {
                temp->lchild = newn;
                break;
            }
            temp = temp->lchild;
        }
        else
        {
            if (temp->rchild == nullptr)
            {
                temp->rchild = newn;
                break;
            }
            temp = temp->rchild;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Inorder
//  Description   : Displays elements in Inorder traversal
//  Author        : Rushikesh Gajanan Salunkhe
//  Date          : 18/09/2025
//
////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Inorder()
{
    InorderX(root);
    cout << endl;
}

template <class T>
void BST<T>::InorderX(
                        BSTnode<T>* temp
                    )
{
    if (temp != nullptr)
    {
        InorderX(temp->lchild);
        cout << temp->data << "\t";
        InorderX(temp->rchild);
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Preorder
//  Description   : Displays elements in Preorder traversal
//  Author        : Rushikesh Gajanan Salunkhe
//  Date          : 18/09/2025
//
////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Preorder()
{
    PreorderX(root);
    cout << endl;
}

template <class T>
void BST<T>::PreorderX(
                            BSTnode<T>* temp
                        )
{
    if (temp != nullptr)
    {
        cout << temp->data << "\t";
        PreorderX(temp->lchild);
        PreorderX(temp->rchild);
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Postorder
//  Description   : Displays elements in Postorder traversal
//  Author        : Rushikesh Gajanan Salunkhe
//  Date          : 18/09/2025
//
////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Postorder()
{
    PostorderX(root);
    cout << endl;
}

template <class T>
void BST<T>::PostorderX(
                            BSTnode<T>* temp
                        )
{
    if (temp != nullptr)
    {
        PostorderX(temp->lchild);
        PostorderX(temp->rchild);
        cout << temp->data << "\t";
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Search
//  Description   : Searches for an element in the BST
//  Author        : Rushikesh Gajanan Salunkhe
//  Date          : 18/09/2025
//
////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool BST<T>::Search(
                        T no
                    )
{
    return SearchX(root, no);
}

template <class T>
bool BST<T>::SearchX(
                        BSTnode<T>* temp, 
                        T no
                    )
{
    int steps = 0;

    while (temp != nullptr)
    {
        if (no == temp->data)
        {
            cout << "Time Complexity of search: " << steps << endl;
            return true;
        }
        else if (no < temp->data)
        {
            temp = temp->lchild;
        }
        else
        {
            temp = temp->rchild;
        }
        steps++;
    }

    cout << "Time Complexity of search: " << steps << endl;
    return false;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns the total number of nodes in the BST
//  Author        : Rushikesh Gajanan Salunkhe
//  Date          : 18/09/2025
//
////////////////////////////////////////////////////////////////////////////////////

template <class T>
int BST<T>::Count()
{
    return CountX(root);
}

template <class T>
int BST<T>::CountX(
                        BSTnode<T>* temp
                    )
{
    if (temp == nullptr) return 0;
    return 1 + CountX(temp->lchild) + CountX(temp->rchild);
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : CountLeafNodes
//  Description   : Returns the number of leaf nodes in the BST
//  Author        : Rushikesh Gajanan Salunkhe
//  Date          : 18/09/2025
//
////////////////////////////////////////////////////////////////////////////////////

template <class T>
int BST<T>::CountLeafNodes()
{
    return CountLeafNodesX(root);
}

template <class T>
int BST<T>::CountLeafNodesX(BSTnode<T>* temp)
{
    if (temp == nullptr) return 0;
    if (temp->lchild == nullptr && temp->rchild == nullptr) return 1;

    return CountLeafNodesX(temp->lchild) + CountLeafNodesX(temp->rchild);
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : CountParentNodes
//  Description   : Returns the number of parent (non-leaf) nodes in the BST
//  Author        : Rushikesh Gajanan Salunkhe
//  Date          : 18/09/2025
//
////////////////////////////////////////////////////////////////////////////////////

template <class T>
int BST<T>::CountParentNodes()
{
    return CountParentNodesX(root);
}

template <class T>
int BST<T>::CountParentNodesX(
                                BSTnode<T>* temp
                            )
{
    if (temp == nullptr) return 0;

    if (temp->lchild != nullptr || temp->rchild != nullptr)
        return 1 + CountParentNodesX(temp->lchild) + CountParentNodesX(temp->rchild);

    return CountParentNodesX(temp->lchild) + CountParentNodesX(temp->rchild);
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         Sorting 
//  Description :   Generic implementation of sorting algorithms
//  Author :        Rushikesh Gajanan Salunkhe
//
///////////////////////////////////////////////////////////////////////

template <class T>
class Sorting      
{
    public:
        T *Arr;
        int iSize;
        bool Sorted;

        Sorting(
                    T no
                );

        ~Sorting();

        void Accept();

        void Display();

        void BubbleSort();

        void BubbleSortEfficient(); 
    
        void SelectionSort();

        void InsertionSort();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Sorting
//	Function Date			:	18/09/2025
//	Function Author			:	Rushikesh Gajanan Salunkhe
//	Parameters  			:   T no - It accepts the size of the array.
//	Description             :   This is constructor of class Sorting
//  Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Sorting<T> :: Sorting(
                        T no
                    )
{
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~Sorting
//	Function Date			:	18/09/2025
//	Function Author			:	Rushikesh Gajanan Salunkhe
//	Parameters  			:   None
//	Description             :   This is Destrcutor of class Sorting
//  Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Sorting<T>  :: ~Sorting()
{
    delete []Arr;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Accept
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Accepts elements and checks whether elements are sorted or not.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Sorting<T> :: Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<"Enter the elements no : "<<i+1<<"\n";

        cin>>Arr[i];

        if((i > 0) && (Sorted == true))    
        {
            //   ha i <  ha 0 ahe
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Displays elements within the array.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Sorting<T> ::  Display()
{
    cout<<"Elements of the array are : \n";
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BubbleSort
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function sorts the elements by using bubble sort algorithm
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Sorting<T> :: BubbleSort()     
{
    int i = 0, j = 0, temp = 0;

    if(Sorted == true)
    {
        return;
    }

    for(i = 0; i < iSize; i++)           //Outer loop
    { 
        for(j = 0; j < iSize - 1; j++)       //Inner loop
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }

        cout<<"Data after pass : "<<i+1<<"\n";

        Display();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BuubleSortEfficient
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function sorts the element with the efficient bubble sort technique.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Sorting<T> :: BubbleSortEfficient()     
{
    int i = 0, j = 0, temp = 0;
    bool bFlag = true;

    if(Sorted == true)
    {
        return;
    }

    for(i = 0; (i < iSize && bFlag == true) ; i++)           //Outer loop
    { 
        bFlag = false;

        for(j = 0; j < iSize - 1 - i; j++)       //Inner loop
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;

                bFlag = true;
            }
        }

        cout<<"Data after pass : "<<i+1<<"\n";

        Display();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SelectionSort
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function sorts the elements by using SelectionSort algorithm
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Sorting<T> :: SelectionSort()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    for(i = 0; i < iSize - 1; i ++)
    {
        for(j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertionSort
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function sorts the elements by using InsertionSort algorithm
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Sorting<T>  :: InsertionSort()
{
    int i = 0, j = 0, Selected = 0;

    for(i = 0; i < iSize; i++)
    {
        for(j = i - 1, Selected = Arr[i]; (j >= 0) && (Arr[j] > Selected); j--)
        {
            Arr[j+1] = Arr[j];
        }

        Arr[j+1] = Selected;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         Searching 
//  Description :   Generic implementation of searching algorithms
//  Author :        Rushikesh Gajanan Salunkhe
//
///////////////////////////////////////////////////////////////////////

template <class T>
class Searching       
{
    public:
        T *Arr;
        int iSize;
        bool Sorted;

        Searching(
                    T no
                );

        ~Searching();

        void Accept();

        void Display();

        bool LinearSearch(
                            T no
                        );    
        
        bool BiDirectionalSearch(
                                    T no
                                );   

        bool BinarySearchInc(
                                T no
                            );

        bool BinarySearchEfficientInc(
                                        T no
                                    );

        bool BinarySearchDec(
                                T no
                            );

        bool BinarySearchEfficientDec(
                                        T no
                                    );

        bool CheckSortedInc();

        bool CheckSortedDec();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Searching
//	Function Date			:	18/09/2025
//	Function Author			:	Rushikesh Gajanan Salunkhe
//	Parameters  			:   T no - It accepts the size of the array.
//	Description             :   This is constructor of class Searching
//  Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Searching<T> :: Searching(
                            T no
                        )
{
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~Searching
//	Function Date			:	18/09/2025
//	Function Author			:	Rushikesh Gajanan Salunkhe
//	Parameters  			:   None
//	Description             :   This is Destructor of class Searching
//  Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Searching<T> :: ~Searching()
{
    delete []Arr;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Accept
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Accepts elements and checks whether elements are sorted or not.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Searching<T> :: Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<"Enter the elements no : "<<i+1<<"\n";

        cin>>Arr[i];

        if((i > 0) && (Sorted == true))    
        {
            //   ha i <  ha 0 ahe
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	18/09/2025
//	Function Author		    :   Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		NONE
//
//	Description:
//		This function Displays elements within the array.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Searching<T> :: Display()
{
    cout<<"Elements of the array are : \n";
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	LinearSearch
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no 
//      Holds the value to be searched in the array.
//
//	Description:
//		This function is used to search linearly whether the element is present or not.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool Searching<T> :: LinearSearch(
                                    T no
                                )     
{
    int i = 0;
    bool bFlag = false;

    if(Sorted == true)           
    {
        cout<<"Data is sorted\n";

        return BinarySearchEfficientInc(no);
    }

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == no)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BiDirectionalSearch
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no 
//      Holds the value to be searched in the array.
//
//	Description:
//		This function searches the element from both the directions in the array.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool Searching<T> :: BiDirectionalSearch(
                                            T no
                                        )    
{
    int iStart = 0, iEnd = 0;
    bool bFlag = false;

    for(iStart = 0, iEnd = iSize-1; iStart <= iEnd; iStart++, iEnd--)
    {
        if(Arr[iStart] == no || Arr[iEnd])
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchInc
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no 
//      Holds the value to be searched in the array.
//
//	Description:
//		This function is used to check the element in the increasing order in the array.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool Searching<T> :: BinarySearchInc(
                                        T no
                                    )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])      //left side of array
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])       // right side of array
        {
            iStart = iMid + 1;
        }
    }//End of while

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchEfficientInc
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no 
//      Holds the value to be searched in the array.
//
//	Description:
//		This function is used to efficiently check the element in the increasing order.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool Searching<T> :: BinarySearchEfficientInc(
                                                T no
                                            )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    if(Sorted == false)          // new 
    {
        cout<<"Data is not sorted\n";
        return LinearSearch(no);           
    }

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))  
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])      //left side of array
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])       // right side of array
        {
            iStart = iMid + 1;
        }
    }//End of while

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchDec
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no 
//      Holds the value to be searched in the array.
//
//	Description:
//		This function is used to check the element in the decreasing order in the array.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool Searching<T> :: BinarySearchDec(
                                        T no
                                    )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid])      //left side of array
        {
            iEnd = iMid - 1;
        }
        else if(no < Arr[iMid])       // right side of array
        {
            iStart = iMid + 1;
        }
    }//End of while

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchEfficientDec
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no 
//      Holds the value to be searched in the array.
//
//	Description:
//		This function is used to efficiently check the element in the decreasing order.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool Searching<T> :: BinarySearchEfficientDec(
                                                T no
                                            )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))  
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])      //left side of array
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])       // right side of array
        {
            iStart = iMid + 1;
        }
    }//End of while

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CheckSortedInc
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no 
//      Holds the value to be searched in the array.
//
//	Description:
//		This function is used to check whether the array is sorted in the increasing format.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool Searching<T> :: CheckSortedInc()
{
    int i = 0;
    bool bFlag = true;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] > Arr[i+1])     
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CheckSortedDec
//	Function Date			:	18/09/2025
//	Function Author		    :	Rushikesh Gajanan Salunkhe
//	Parameters:
//
//		[IN] T no 
//      Holds the value to be searched in the array.
//
//	Description:
//		This function is used to check whether the array is sorted in the decreasing format.
//
//	Returns:
//		None
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool Searching<T> :: CheckSortedDec()
{
    int i = 0;
    bool bFlag = true;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] < Arr[i+1])    
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}


int main()
{
    
    return 0;
}