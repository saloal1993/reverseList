#include <iostream>

using namespace std;


template <typename T>
class List{
public:
    List(const T* _data, const size_t _length){
        for(size_t i = 0; i < _length; ++i){
            data = *_data;
            if(_length == 1)
                next = nullptr;
            else
                next = new List(_data + 1, _length - 1);
        }
    }
    List(T first, ...){ //ToDo: not working
        T* elem = &first;
        while(*elem){
            cout << *elem << " ";
            elem++;
        }
        cout << endl;
    }

    List<T> reverse(){
        return *reverseList();
    }

    void print(){
        List<T>* cur = this;
        while(cur != nullptr){
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    List<T>* reverseList(List<T>* prev = nullptr){
        List<T>* last;
        if(next != nullptr)
            last = next->reverseList(this);
        else
            last = this;
        next = prev;
        return last;
    }
private:
    T data;
    List<T>* next;
};


int main(){
    char elems[] = {'H','e','l','l','o'};
    //List<char> l(elems, 5);
    List<size_t> l(1,2,3);
    //l.print();
    //auto rev_l = l.reverse();
    //rev_l.print();
    return 0;
}