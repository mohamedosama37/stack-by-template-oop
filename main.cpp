#include <iostream>
#include <conio.h>

using namespace std;
template  <class T>
class Stack
{
private:
    int top;
    int Size;
    T *st;
    static int counter;

public :
    Stack();
    Stack(int n)
    {
        this->Size=n;
        top=0;
        st=new T[ this->Size];
    }
    ~Stack()
    {
        delete[]st;
    }
    Stack(Stack&);
    void push (T num);
    T pop ();

    Stack& operator=(Stack&);
    int getcounter()
    {
        return counter;
    }

};
template <class T>
int Stack <T>::counter=0;
template <class T>

void Stack<T>::push (T num)
{
    if(this->top < this->Size)
    {
        this->st[this->top++]=num;
        counter++;
    }
    else
    {
        cout<<"stack is full\n";
    }
}

template<class T>
T Stack<T>::pop ()
{
    T num;
    if(this->top >0)
    {
       num=(this->st[--this->top]);
       counter--;
    }
    else
    {
        num=-1;
        cout<<"stack is full\n";
    }
    return num;
}
template<class T>
Stack <T> :: Stack()
{
    top=0;
    Size=10;
    st=new T[Size];
    counter++;
}








int main()
{
    Stack<int> s1(5);
    cout<<"number of integer stack is"<<s1.getcounter()<<endl;
    s1.push(10);
    s1.push(3);
    s1.push(2);
    cout<<"1 st integar\n"<<s1.pop()<<endl;
    cout<<"2 nd integar"<<s1.pop()<<endl;
    Stack<char> s2;
    cout<<"the number of character is"<<s2.getcounter()<<endl;
    s2.push('q');
    s2.push('r');
    s2.push('s');
    cout<<"1 st charcter\n"<<s2.pop()<<endl;
    cout<<"2 nd character\n"<<s2.pop()<<endl;
    return 0;
}


