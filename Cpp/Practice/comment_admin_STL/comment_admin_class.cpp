#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <list>
#include <string>
#include "comment_admin_class.hpp"
using namespace std;

void CommentAdmin::printChat() {
    list<string>::iterator it;
    int i = 0;
    cout << endl;
    for (it=chats.begin(); it!=chats.end(); it++){
        cout << i++ << " " << *it << endl;
    }
    cout << "> ";
}

// Add _chat into chats
// If it fails, return false; otherwise, return true
bool CommentAdmin::addChat(string& _chat) {
    /*TODO*/
    chats.push_back(_chat);
    return true;
    // returns true when adding chat is succeeded
}

// Remove the chat at _index from chats
// if _index does not exists, return false; otherwise, return true
bool CommentAdmin::removeChat(int _index) {
    if (_index >= chats.size())
        return false;
    // returns true when removing chat is succeeded
    list<string>::iterator it = chats.begin();
    advance(it, _index);
    it = chats.erase(it);
    /*TODO*/
    return true;
}

// Remove the comments at indices form _indices[0] to _indices[_count-1] 
// (inclusive)
// Return true if at least one is removed; false otherwise
// Do nothing if an index does not exist
bool CommentAdmin::removeChat(list<int>& _indices) {
    bool isRemoved = false;
    _indices.sort();
    list<string>::iterator it = chats.begin();
    list<int>::iterator iit = _indices.begin();
    /* TODO */
    list<string> chats_copied = chats;
    for (int i=0; i<=_indices.size(); i++){
        it = chats.begin();
        advance(it, *(iit++));
        chats.remove(*it);
    }
    isRemoved = true;
    return isRemoved;
}

// Remove the comments at indices from _start to _end in chats
// Return true if at least one is removed.
// If _start is a negative number or _end >= NUM_CHATS,
// remove only the chats at valid indices.
bool CommentAdmin::removeChat(int _start, int _end) {
    /* TODO */
    if (_start < 0) _start = 0;
    if (_end > chats.size()) _end = chats.size();

    list<string>::iterator it = chats.begin(), it2 = chats.begin();
    advance(it, _start);
    advance(it2, _end);
    for (; it != it2;){
        it = chats.erase(it);
    }
    it = chats.erase(it);
    return true;
}
