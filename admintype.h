#ifndef ADMINTYPE_H
#define ADMINTYPE_H

#include "accounttype.h"

// This class is a placeholder the application until it actually requires multiple admins or admin TYPES (system admin - whole control / doctors - who edits user info etc)
// Only reason I made this was to show extensive understanding of inheritance which admin users should have (user/pass are variables that both the admintype and usertype needs)

class adminType : public accountType
{
public:

    adminType();

private:

};

#endif // ADMINTYPE_H
