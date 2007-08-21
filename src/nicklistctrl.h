#ifndef SPRINGLOBBY_HEADERGUARD_NICKLISTCTRL_H
#define SPRINGLOBBY_HEADERGUARD_NICKLISTCTRL_H

#include <wx/listctrl.h>

class User;
class UserList;

class NickListCtrl : public wxListCtrl
{
  public:
    NickListCtrl( wxWindow* parent, bool show_header = true );
    ~NickListCtrl();

    void AddUser( User& user );
    void RemoveUser( const User& user );

    void UserUpdated( User& user );
    void UserUpdated( const int& index );

    int GetUserIndex( User& user );

    void ClearUsers();

  protected:
    UserList* m_users;
};

#endif // SPRINGLOBBY_HEADERGUARD_NICKLISTCTRL_H
