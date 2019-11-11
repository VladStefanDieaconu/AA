#ifndef ALGO_H
#define ALGO_H

#include <algorithm>
#include <iterator>
#include <list>

template <typename Tkey, typename Tvalue> struct elem_info {
  Tkey key;
  Tvalue value;
};

template <typename Tkey, typename Tvalue> class Hashtable {
private:
  std::list<struct elem_info<Tkey, Tvalue> > * H;
  int HMAX;
  unsigned int (*hash)(Tkey);

public:
  Hashtable(int hmax, unsigned int (*h)(Tkey)) {
    this->HMAX = hmax;
    this->hash = h;
    H = new std::list<struct elem_info<Tkey, Tvalue> >[HMAX];
  }

  ~Hashtable() {
    delete[] H;
  }

  void put(Tkey key, Tvalue value) {
    int hashValue = hash(key) % HMAX;
    struct elem_info<Tkey, Tvalue> newElem;
    newElem.key = key;
    newElem.value = value;
    bool found = false;
    typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
    for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
        if (i->key == key) {
            found = true;
            break;
        }
    }
    if (!found) {
        H[hashValue].push_back(newElem);
    }
  }

  void modify(Tkey key, Tvalue value) {
    int hashValue = hash(key) % HMAX;
    typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
    for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
        if (i->key == key) {
            i->value = value;
        }
    }
  }

  void remove(Tkey key) {
    int hashValue = hash(key) % HMAX;
    typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
    for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
        if(i->key == key) {
            break;
        }
    }
    if (i != H[hashValue].end()) {
        H[hashValue].erase(i);
    }
  }

  Tvalue get(Tkey key) {
    int hashValue = hash(key) % HMAX;
    typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
    for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
        if (i->key == key) {
            return i->value;
        }
    }
    return Tkey();
 }
 
  bool has_key(Tkey key) {
      int hashValue = hash(key) % HMAX;
      typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
      for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
          if (i->key == key) {
              return true;
          }
      }
      return false;
  }
};

#endif
