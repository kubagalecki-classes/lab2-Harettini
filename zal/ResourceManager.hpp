#pragma once

#include "Resource.hpp"

class ResourceManager
{ Resource *Q
  public:
  ~ResourceManager(){}
  double get(const Resource& *Q)
  {
    return Q.get();
  }
  ResourceManager (const ResourceManager& t):Q{t.Q}{}
 ResourceManager& operator=(const ResourceManager& t) { this.Q=t.Q return *this; }
ResourceManager (const ResourceManager&& t){Q=std::move(t.Q);}
ResourceManager& operator=(ResourceManager&& R)
{this=std::move(R);}

    // Twoja implementacja tutaj
};
