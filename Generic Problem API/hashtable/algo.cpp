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
  Hashtable(int hmax, unsigned int (*h)(Tkey));

  ~Hashtable();

  void put(Tkey key, Tvalue value);

  void modify(Tkey key, Tvalue value);

  void remove(Tkey key);

  Tvalue get(Tkey key);

  bool has_key(Tkey key);
};

  template <typename Tkey, typename Tvalue>
  Hashtable<Tkey, Tvalue>::Hashtable(int hmax, unsigned int (*h)(Tkey)) {
    this->HMAX = hmax;
    this->hash = h;
    H = new std::list<struct elem_info<Tkey, Tvalue> >[HMAX];
  }

  template <typename Tkey, typename Tvalue>
  Hashtable<Tkey, Tvalue>::~Hashtable() {
    delete[] H;
  }

  template <typename Tkey, typename Tvalue>
  void Hashtable<Tkey, Tvalue>::put(Tkey key, Tvalue value) {
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

  template <typename Tkey, typename Tvalue>
  void Hashtable<Tkey, Tvalue>::modify(Tkey key, Tvalue value) {
    int hashValue = hash(key) % HMAX;
    typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
    for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
        if (i->key == key) {
            i->value = value;
        }
    }
  }

  template <typename Tkey, typename Tvalue>
  void Hashtable<Tkey, Tvalue>::remove(Tkey key) {
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

  template <typename Tkey, typename Tvalue>
  Tvalue Hashtable<Tkey, Tvalue>::get(Tkey key) {
    int hashValue = hash(key) % HMAX;
    typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
    for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
        if (i->key == key) {
            return i->value;
        }
    }
    return Tkey();
 }
 
  template <typename Tkey, typename Tvalue>
  bool Hashtable<Tkey, Tvalue>::has_key(Tkey key) {
      int hashValue = hash(key) % HMAX;
      typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
      for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
          if (i->key == key) {
              return true;
          }
      }
      return false;
  }

#endif
