#ifndef IREADABLE_COMPONENT_HPP
#define IREADABLE_COMPONENT_HPP

class IReadableComponent 
{    
  public:
    virtual void Init() = 0;
    virtual uint32_t Read() = 0;
};

#endif // IREADABLE_COMPONENT_HPP
