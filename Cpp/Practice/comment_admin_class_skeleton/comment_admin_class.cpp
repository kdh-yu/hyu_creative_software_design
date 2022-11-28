#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include "comment_admin_class.hpp"
using namespace std;

CommentAdmin::CommentAdmin() {
    chats = new string[NUM_CHATS];
}
    
CommentAdmin::~CommentAdmin() {
    delete chats;
}

int CommentAdmin::getChatCount() {
    int i;
    for(i = 0; i < NUM_CHATS; ++i)
    {
        string s = chats[i];
        if(s.empty() == true) break;
    }
    return i;
}

void CommentAdmin::printChat()
{
    cout << endl;
    int count = getChatCount();
    for(int i = 0; i < count; ++i)
    {
        cout << i << " " << chats[i] << endl;
    }
}

// Add _chat into chats
// If it fails, return false; otherwise, return true
bool CommentAdmin::addChat(string& _chat) {
    /* TODO */
    int _index = getChatCount();
    if (_index >= NUM_CHATS)
        return false;
    chats[_index] = _chat;
    return true;
    // returns true when adding chat is succeeded
}

// Remove the chat at _index from chats
// if _index does not exists, return false; otherwise, return true
bool CommentAdmin::removeChat(int _index) {
    if (_index >= NUM_CHATS)
        return false;
    // returns true when removing chat is succeeded
    /* TODO */
    int length = getChatCount();
    for (int i=_index; i<length; i++)
        chats[i] = chats[i+1];

    return true;
}

// Remove the comments at indices form _indices[0] to _indices[_count-1] 
// (inclusive)
// Return true if at least one is removed; false otherwise
// Do nothing if an index does not exist
bool CommentAdmin::removeChat(int* _indices, int _count) {
    bool isRemoved = false;
    /* TODO */
    string duplicated_chats[NUM_CHATS];
    int rmv_index;

    for (int i=0; i<getChatCount(); i++)
        duplicated_chats[i] = chats[i];

    if (_count > 0){
        for (int i=0; i<=_count; i++){
            for (int j=0; j<getChatCount(); j++){
                if (chats[j] == duplicated_chats[_indices[i]]){
                    rmv_index = j;
                    break;
                }
            }
            for (int k=rmv_index; k<getChatCount(); k++)
                chats[k] = chats[k+1];
        }
        isRemoved = true;
    }

    return isRemoved;

}

// Remove the comments at indices from _start to _end in chats
// Return true if at least one is removed.
// If _strat is a negative number or _end >= NUM_CHATS,
// remove only the chats at valid indices.
bool CommentAdmin::removeChat(int _start, int _end) {
    bool isRemoved = false;
    /* TODO */
    if (_start < 0)
        _start = 0;
    if (_end > getChatCount())
        _end = getChatCount();
    int length = _end - _start + 1;
    for (int i=_start; i<=_end; i++){
        chats[i] = chats[i + length];
    }
    isRemoved = true;
    return isRemoved;
}

