#pragma once

#include "Resource.hpp"
#include <utility>
class ResourceManager
{
    Resource* Q;

public:
    ResourceManager() { Q=new Resource;}
    ~ResourceManager() { delete Q; }
    double get() { return Q->get(); }
    ResourceManager(const ResourceManager& aa)
     {
 Q=new Resource;
 Q=aa.Q;

     }
    ResourceManager& operator=(const ResourceManager& aa)
    { if(this!=&aa)
        {delete Q;
        Q=new Resource;
        Q = aa.Q;}
        return *this;
        
    }
    ResourceManager(const ResourceManager&& aa) 
    {
      Q=new Resource;
      Q=aa.Q;
      aa.Q  =0;
    }
    ResourceManager& operator=(const ResourceManager&& aa)
    { if(this!=&aa)
    {   delete Q;
        Q=new Resource;
        Q=aa.Q;
        aa.Q = 0; }
        return *this;
       
   
    }
};
