#pragma once

#include "Resource.hpp"

class ResourceManager
{ Resource *Q;
  public:
     ResourceManager() {}
    ~ResourceManager() { delete[] Q; }
    double get()
    {
        Q = new Resource[1];

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
