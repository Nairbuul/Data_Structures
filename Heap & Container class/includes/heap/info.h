#ifndef INFO_H
#define INFO_H

template <typename T>
struct info{
    T item;
    int priority;
    int time_stamp; 

    info():item(T()), priority(0), time_stamp(0){}
    info(T i, int p, int f):item(i), priority(p), time_stamp(f){}

    friend ostream& operator <<(ostream& outs, const info<T>& print_me){
        const bool tldr = true;
        outs << "Item: " << print_me.item << "\t" << "Priority: " << print_me.priority << endl;
        return outs;
    }

    friend bool operator <(const info<T>& lhs, const info<T>& rhs){
       if(lhs.priority == rhs.priority){
            if(lhs.time_stamp > rhs.time_stamp){
                return true;
            }
            return false;
       }
        if(lhs.priority < rhs.priority){
            return true;
        }
        return false;
    }
    friend bool operator >(const info<T>& lhs, const info<T>& rhs){
        if(lhs.priority == rhs.priority){
            if(lhs.time_stamp < rhs.time_stamp){
                return true;
            }
            return false;
        }
        if(lhs.priority > rhs.priority){
            return true;
        }
        return false;
    }
    
    friend bool operator ==(const info<T>& lhs, const info<T>& rhs){
        if(lhs.priority == rhs.priority){
            return true;
        }
        return false;
    }

    friend bool operator <=(const info<T>& lhs, const info<T>& rhs){
        if(lhs.priority == rhs.priority){
            if(lhs.time_stamp > rhs.time_stamp){
                return true;
            }
            return false;
        }
        if(lhs.priority <= rhs.priority){
            return true;
        }
        return false;
    }
    friend bool operator >=(const info<T>& lhs, const info<T>& rhs){
        if(lhs.priority == rhs.priority){
            if(lhs.time_stamp < rhs.time_stamp){
                return true;
            }
            return false;
        }
        if(lhs.priority >= rhs.priority){
            return true;
        }
        return false;
    }
    friend bool operator !=(const info<T>& lhs, const info<T>& rhs){
        if(lhs.priority != rhs.priority){
            return true;
        }
        return false;
    }
};

#endif