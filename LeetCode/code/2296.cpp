#include<bits/stdc++.h>
using namespace std;
class TextEditor {
private:
    string beforeCursor;
    string afterCursor;
public:
    TextEditor() {

    }
    
    void addText(string text) {
        beforeCursor+=text;
    }
    
    int deleteText(int k) {
        int n=beforeCursor.length();
        int num=std::min(n,k);
        for(int i=0;i<k;i++){
            beforeCursor.pop_back();
        }
        return num;
    }
    
    string cursorLeft(int k) {
        for(int i=0;i<k;i++){
            if(beforeCursor.length()==0){
                break;
            }
            char c=beforeCursor[beforeCursor.length()-1];
            beforeCursor.pop_back();
            afterCursor.push_back(c);
        }
        if(beforeCursor.length()<=10){
            return beforeCursor;
        }
        int len=beforeCursor.length();
        return beforeCursor.substr(len-10,10);
    }
    
    string cursorRight(int k) {
        for(int i=0;i<k;i++){
            if(afterCursor.length()==0){
                break;
            }
            char c=afterCursor[afterCursor.length()-1];
            afterCursor.pop_back();
            beforeCursor.push_back(c);
        }
        if(beforeCursor.length()<=10){
            return beforeCursor;
        }
        int len=beforeCursor.length();
        return beforeCursor.substr(len-10,10);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */