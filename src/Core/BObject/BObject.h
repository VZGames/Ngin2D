#ifndef BOBJECT_H
#define BOBJECT_H


class BObject
{
public:
    BObject();

    template <typename PointerToMemberFunction>
    static bool connect(const BObject *sender, PointerToMemberFunction signal, const BObject *receiver, PointerToMemberFunction slot)
    {
        (*signal)();
        (*slot)();
        return 1;
    }

};

#endif // BOBJECT_H
