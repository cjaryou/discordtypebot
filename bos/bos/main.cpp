#include <iostream>
#include <Windows.h>

void simulateMouseClick(int x, int y) {
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}

void simulateKeyPress(const char* key) {
    INPUT inputs[2] = {};
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = 0;
    inputs[1] = inputs[0];
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

    
    const char* textToType = "type here";
    for (int i = 0; i < strlen(textToType); i++) {
        inputs[0].ki.wVk = VkKeyScan(textToType[i]);
        SendInput(1, &inputs[0], sizeof(INPUT));
        SendInput(1, &inputs[1], sizeof(INPUT));  
        Sleep(50);  
    }

    // Press Enter key
    inputs[0].ki.wVk = VK_RETURN;
    SendInput(1, &inputs[0], sizeof(INPUT));
    inputs[1].ki.wVk = VK_RETURN;
    SendInput(1, &inputs[1], sizeof(INPUT));  
}

int main() {
    while (true) {
        simulateMouseClick(407, 998);
        Sleep(3000);

        simulateKeyPress("osurdum");
        Sleep(3000);

        if (GetAsyncKeyState(VK_INSERT) & 0x8000) {
            break;
        }
    }

    return 0;
}
