//********************************************************************
template <typename T>
Queue<T>::Queue(): bottom(NULL), itemNum(0){}

//********************************************************************
template <typename T>
Queue<T>::~Queue()
{
    Clear();
}

//********************************************************************
template <typename T>
Queue<T>::Queue(const Queue<T> &q): bottom(NULL), itemNum(0)
{
    *this = q;
}

//********************************************************************
template <typename T>
Queue<T> & Queue<T>::operator=(const Queue<T> &q)
{
    if(this == &q) return *this;
    Clear();
    if(!q.ItsEmpty()){
        Item *aux = q.bottom -> next;
        do{
            Add(aux -> value);
            aux = aux -> next;
        }while(aux != q.bottom -> next);
    }
    return *this;
}

//********************************************************************
template <typename T>
void Queue<T>::Add(const T &value)
{
    Item *newItem = new Item(value, ItsEmpty() ? NULL : bottom -> next);
    ItsEmpty() ? newItem -> next = newItem : bottom -> next = newItem;
    bottom = newItem;
    ++itemNum;
}

//********************************************************************
template <typename T>
void Queue<T>::Remove()
{
    if(ItsEmpty()) throw "It's empty";
    Item *aux = bottom -> next;
    itemNum == 1 ? bottom = NULL : bottom->next = aux->next;
    delete aux;
    --itemNum;
}

//********************************************************************
template <typename T>
T Queue<T>::GetFirst()
{
    return bottom -> next -> value;
}

//********************************************************************
template <typename T>
unsigned Queue<T>::GetLast()
{
    return bottom -> value;
}

//********************************************************************
template <typename T>
bool Queue<T>::ItsEmpty() const
{
    return bottom == NULL;
}

//********************************************************************
template <typename T>
void Queue<T>::Clear()
{
    while(!ItsEmpty())
    {
        Remove();
    }
}

//*******************************************************************
template <typename T>
unsigned Queue<T>::GetSize()
{
    return itemNum;
}

//*******************************************************************
template <typename T>
void Queue<T>::Print()
{
    if(ItsEmpty()) std::cout << "None" << std::endl;
    else{
        Item *aux = bottom -> next;
        do{
            std::cout << aux -> value << std::endl;
            aux = aux -> next;
        }while(aux != bottom -> next);
        std::cout << "\b\b\b   " << std::endl;
    }
}
//*******************************************************************
