#include <iostream>

struct string{
  char* ptr;
  int l;

  string(char* source){
    l = 0;
    while((int)(*(source + l)) != 0) l++;
    //std::cout << source << " " << l << std::endl;
    ptr = new char[l];
    for(int i = 0; i < l; i++)  *(ptr + i) = *(source + i);
  }
  bool operator==(string& a){
    bool t = true;
    if (this->l == a.l){
      for(int i = 0; i < a.l; i++){
        if(*(this->ptr + i) != *(a.ptr + i)){
          t = false;
          break;
        }
      }
    }
    else t = false;
    return t;
  }

/*~string(){
    for(int i = 0; i < this -> l; i++) delete(ptr + i);
  }*/

};

string operator+ (string& a, string& b){
    int l = a.l + b.l;
    char* tmp = new char[l];
    for(int i = 0; i < a.l; i++) *(tmp + i) = *(a.ptr + i);
    for(int i = a.l; i < l; i++) *(tmp + i)  = *(b.ptr + i - a.l);

  return string(tmp);
}




int main(){



  string a = string((char*)"nvihbvir");
  string b = string((char*)"nvihbvir");
  std::cout << (a==b);
  return 0;

}
