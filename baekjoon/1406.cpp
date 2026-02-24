#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    
    // string을 char 단위로 분해
    list<char> editor(s.begin(), s.end()); 
    auto cursor = editor.end();
    int len;
    cin >> len;
    while(len--)
    {
        char cmd;
        cin >> cmd;
        switch(cmd)
        {
            case 'L': // movleft
                if(cursor != editor.begin()) cursor--;
                break;
            case 'D': // movright
                if(cursor != editor.end()) cursor++;
                break;
            case 'B': // del
                if(cursor != editor.begin()) 
                    cursor = editor.erase(--cursor);
                break;
            case 'P': 
                char c;
                cin >> c; 
                editor.insert(cursor, c);
                break;
        }
    }
    
    for(char c : editor) cout << c;
}