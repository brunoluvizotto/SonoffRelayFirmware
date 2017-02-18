#ifndef TASK_HPP
#define TASK_HPP

namespace Luvitronics
{
    class Task
    {
    public: 
        virtual ~Task() {}
        
        virtual void process() = 0;
    };
}

#endif //TASK_HPP
