#include <iostream>
#include <string>
using namespace std;

const int NUM_OF_CHAT = 200;

// return length
int getCount(string *_chatList)
{
    int i;
    for(i=0; i<NUM_OF_CHAT; ++i)
    {
        string s = _chatList[i];
        if(s.empty() == true) break;
    }
    return i;
}

// check whether string has particular char
bool check_(string idx, char chr){
    bool trf = false;
    for (int i = 0; i < idx.length(); i++){
        if (idx[i] == chr) trf = true;
    }
    return trf;
}

// Print chats in _chatList
void printChat(string *_chatList)
{
    cout << endl;
    int count = getCount(_chatList);
    for(int i=0; i<count; ++i)
    {
        cout << i << " " << _chatList[i] << endl;
    }
}

// Add a comment by entering a string.
// returns true when adding chat is succeeded
bool addChat(string *_chatList, string _chat){
    int i = getCount(_chatList);
    if (i >= NUM_OF_CHAT) return false;
    else{
        _chatList[i] = _chat;
        return true;
    }
}

// Remove chats by index, which has three options
bool removeChat(string *_chatList, int length, string idx_string){
    string idx_list[NUM_OF_CHAT], chat[NUM_OF_CHAT];
    int i_idx_list[NUM_OF_CHAT], rmv_index;
    bool comma = check_(idx_string, ',');
    bool dash = check_(idx_string, '-');

    // Make a list with indexes to remove
    for (int i=0, k=0; i<idx_string.length(); i++){
        if (idx_string.at(i) == ',');
        else if (idx_string.at(i) == '-');
        else {
            idx_list[k] = idx_string[i];
            k++;
        }
    }
    // change from char to int
    for (int i = 0; i<getCount(idx_list); i++){
        i_idx_list[i] = stoi(idx_list[i]);
    }

    // e.g. #remove 3,5
    if (comma == true && dash == false){
        for (int i = 0; i<getCount(idx_list); i++){
            chat[i] = _chatList[i_idx_list[i]];
        }
        for (int i=0; i<getCount(idx_list); i++){
            for (int j=0; j<length; j++){
                if (_chatList[j] == chat[i]){
                    rmv_index = j;
                    break;
                }
            }
            for (int k=rmv_index; k<length; k++) _chatList[k] = _chatList[k+1];
        }
    }

    // e.g. #remove 3-5
    else if (comma == false && dash == true){
        int remove_length = i_idx_list[1] - i_idx_list[0] + 1;
        for (int k = i_idx_list[0]; k < length; k++) _chatList[k] = _chatList[k + remove_length];
    }

    // e.g. #remove 2,3,4-5 . which raises error
    else if (comma == true && dash == true){
        cout << "Error: You cannot input ',' and '-' together" << endl;
    }

    // e.g. #remove 3
    else if (comma == false && dash == false){
        for (int i=i_idx_list[0]; i<length; i++) _chatList[i] = _chatList[i+1];
    }
    return true;
}

int main(void)
{
    string* chats = new string[NUM_OF_CHAT];

    addChat(chats, "Hello, Comment Administrator!");
    addChat(chats, "How have you been?");
    addChat(chats, "I am an undergraduate.");
    addChat(chats, "I am taking Creative Software Design.");
    addChat(chats, "This class is awesome.");
    printChat(chats);

    while(true){
        string command;
        cout << "> ";
        getline(cin, command);
        int ctlen = getCount(chats);

        if (command[0] == '#'){  // in case of command
            if(command.substr(1,5) == "quit") break;

            else if(command.substr(1,6) == "remove"){
                string idx_string = command.substr(8);
                removeChat(chats, ctlen, idx_string);
                printChat(chats);
            }

            else;
        }
        else if(addChat(chats, command)) printChat(chats);  // not command
    }
    
    // delete chatting list
    delete[] chats;
    
    return 0;
}

