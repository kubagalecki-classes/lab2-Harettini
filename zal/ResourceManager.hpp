#pragma once

#include "Resource.hpp"
#include <utility>
class ResourceManager
{ 
  Resource* Q;

  public:
    ResourceManager() {Q=new Resource;}
    ~ResourceManager() {delete Q;}
    double get()
    {
      return Q[0].get();
    }
    ResourceManager(const ResourceManager& aa) : Q{aa.Q} {}
    ResourceManager& operator=(const ResourceManager& aa) 
  {
    Q = aa.Q; 
    return *this; 
  }
  ResourceManager (const ResourceManager&& aa) noexcept : Q ( std::exchange(aa.Q,nullptr) ) {}
  ResourceManager& operator=(ResourceManager&& aa) noexcept
  {delete Q;
    Q = (aa.Q);
    aa.Q=nullptr;
    return *this;
  }
};
