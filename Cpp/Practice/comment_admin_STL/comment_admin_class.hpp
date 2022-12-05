#ifndef COMMENT_ADMIN_CLASS_H
#define COMMENT_ADMIN_CLASS_H
#include <list>
using namespace std;
const int NUM_CHATS = 200;

class CommentAdmin {
private:
    list<string> chats;
public:
    int getChatCount();
    void printChat();
    bool addChat(string&);
    bool removeChat(int);
    bool removeChat(list<int>&);
    bool removeChat(int, int);
    void shift(int);
};
#endif
