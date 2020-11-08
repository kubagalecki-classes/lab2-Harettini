#pragma once

#include "Resource.hpp"

class ResourceManager
{ Resource *Q;

  public:
     ResourceManager() {Q=new Resource;}
    ~ResourceManager() {delete Q;}
    double get()
    {
        return Q[0].get();
    }
    ResourceManager(const ResourceManager& aa) { Q = aa.Q; }
 ResourceManager& operator=(const ResourceManager& t) { Q=t.Q; return *this; }
ResourceManager (const ResourceManager&& t){Q=std::move(t.Q);}
ResourceManager& operator=(ResourceManager&& R)
{Q=std::move(t.Q);
return *this;}

    // Twoja implementacja tutaj
};
