#include<iostream>
#include <ostream>
#include <vector>

class listdl{
  public:
    listdl();
    listdl(const listdl& l);
    ~listdl();
    void append(int e);
    void prepend(int e);
    void print_forward() const;
    void print_reversed() const;

    void read_list();

    void remove(int e);
    void remove_all(int e);
    void flush();

    const listdl& operator=(const listdl& l);
    listdl operator+(const listdl& l) const;
    listdl operator*(int n) const;
    listdl operator-(const listdl& l) const;
    


  private:
    struct celldl{
      int info;
      celldl* next;
      celldl* prev;
    };

    celldl* head;
    celldl* tail;
    void flush(celldl* p);

};


//Do not change
listdl::listdl() {
  head = tail = nullptr;
}


//Do not change
listdl::listdl(const listdl& l) {
  head = tail = nullptr;
  celldl* pc = l.head;
  while (pc!=nullptr) {
    append(pc->info);
    pc = pc->next;
  }
}


//Do not change
void listdl::append(int e) {
  celldl* newcell = new celldl{e, nullptr, tail};

  if (tail!=nullptr) 
    tail->next = newcell;
  else
    head=newcell;
  
  tail = newcell; 
}



//Do not change
void listdl::prepend(int e) {
  celldl* newcell = new celldl{e, head, nullptr};

  if (head!=nullptr) 
    head->prev = newcell;
  else
    tail=newcell;
  
  head = newcell; 
}


//Do not change
void listdl::print_forward() const {
  celldl* pc = head;
  while (pc) {
    std::cout<<pc->info<<" ";
    pc = pc->next;
  }
  std::cout << std::endl;
}


//Do not change
void listdl::print_reversed() const {
  celldl* pc = tail;
  while (pc) {
    std::cout << pc->info <<" ";
    pc = pc->prev;
  }
  std::cout << std::endl;
}



//Do not change
void listdl::read_list() {
   flush(head);
   head = tail = nullptr; //start with empty list
   int elements;
   std::cin >> elements;

   while (elements>0) {
     int info;
     std::cin>>info;
     append(info);
     elements--;
   }
}


//Do not change
void listdl::flush(celldl* p) {
  if (p!=nullptr) {
    flush(p->next);
    delete p;
  }
}



//Do not change
listdl::~listdl() {
  flush(head);
}



//Do not change
void listdl::remove(int e) {
  celldl* pc = head;
  bool found = false;
  while (pc!=nullptr && !found) {
    if (pc->info == e)
      found = true;
    else 
      pc = pc->next;
  }
  if (pc!=nullptr) {
    if (pc->prev && pc->next) {
      pc->prev->next = pc->next;
      pc->next->prev = pc->prev;
      delete pc;
    }
    else if (!pc->prev && pc->next) { //first element of the list
      pc->next->prev = nullptr;
      head = pc->next;
      delete pc;
    }
    else if (pc->prev && !pc->next) { //last element of the list
      pc->prev->next = nullptr;
      tail = pc->prev;
      delete pc;
    }
    else { //last elemet of the list
      delete pc;
      head = tail = nullptr;
    }
  }
}


//Do not change
const listdl& listdl::operator=(const listdl& l) {
  if (this!=&l) {
    flush(head);
    head=tail=nullptr;
    celldl* pc = l.head;
    while (pc) {
      append(pc->info);
      pc = pc->next;
    }
  }
  return *this;
}


//Do not change
listdl listdl::operator+(const listdl& l) const {
  listdl res{*this};
  celldl* pc = l.head;
  while (pc) {
    res.append(pc->info);
    pc = pc->next;
  }
  return res;
}


//Exercise 1:

void listdl::remove_all(int e) {
  celldl* current = head;

  while (current != nullptr) {
    if (current->info == e) {
      celldl* to_delete = current;
      if (current->prev)
        current->prev->next = current->next;
      else 
        head = current->next;

      if (current->next)
        current->next->prev = current->prev;
      else 
        tail = current->prev;

      current = current->next;
      delete to_delete;
    } else {
      current = current->next;
    }
  }
}

//Exercise 2:
listdl listdl::operator*(int n) const {
  listdl res;
  return res;
}





//Exercise 3
listdl listdl::operator-(const listdl& l) const {
    listdl res(*this); 

    celldl* pc = l.head;
    while (pc != nullptr) {
        res.remove_all(pc->info);
        pc = pc->next;
    }

    return res;
}


int main() {
    listdl l1;
    listdl l2;
    listdl l;
    
    l1.read_list(); 
    l2.read_list();
  
    l = l1-l2;
  
    l.print_forward();
    l.print_reversed();
  
    return 0;
  }