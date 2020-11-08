#pragma once

#include "Resource.hpp"

class ResourceManager
{ double Q;
  public:
     ResourceManager() {}
    ~ResourceManager() {}
    double get()
    {
        return Q;
    }
    ResourceManager(const ResourceManager& aa) { Q = aa.Q; }
 ResourceManager& operator=(const ResourceManager& t) { Q=t.Q; return *this; }
ResourceManager (const ResourceManager&& t){Q=std::move(t.Q);}
ResourceManager& operator=(ResourceManager&& R)
{Q=std::move(t.Q);
return *this;}

    // Twoja implementacja tutaj
};
