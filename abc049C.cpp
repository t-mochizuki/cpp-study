#include <stdio.h>
#include <string.h>

using namespace std;

int main() {

    char S[100001];
    scanf("%s", S);
    int end = (int)strlen(S);
    end--; // zero origin

    bool match = false;
    while (true) {
        if (end == -1) {
            match = true;
            break;
        }

        char c = S[end];
        if (c != 'r') {
            char dream1 = S[end - 4];
            char dream2 = S[end - 3];
            char dream3 = S[end - 2];
            char dream4 = S[end - 1];
            char dream5 = S[end];
            if (dream1 == 'd'
                && dream2 == 'r'
                && dream3 == 'e'
                && dream4 == 'a'
                && dream5 == 'm') {
                end -= 5;
                continue;
            }

            char erase1 = S[end - 4];
            char erase2 = S[end - 3];
            char erase3 = S[end - 2];
            char erase4 = S[end - 1];
            char erase5 = S[end];
            if (erase1 == 'e'
                && erase2 == 'r'
                && erase3 == 'a'
                && erase4 == 's'
                && erase5 == 'e') {
                end -= 5;
                continue;
            } else {
                break;
            }
        } else {
            c = S[end - 1];
            if (c == 'e') {
                char dreamer1 = S[end - 6];
                char dreamer2 = S[end - 5];
                char dreamer3 = S[end - 4];
                char dreamer4 = S[end - 3];
                char dreamer5 = S[end - 2];
                char dreamer6 = S[end - 1];
                char dreamer7 = S[end];
                if (dreamer1 == 'd'
                    && dreamer2 == 'r'
                    && dreamer3 == 'e'
                    && dreamer4 == 'a'
                    && dreamer5 == 'm'
                    && dreamer6 == 'e'
                    && dreamer7 == 'r') {
                    end -= 7;
                    continue;
                }

                char eraser1 = S[end - 5];
                char eraser2 = S[end - 4];
                char eraser3 = S[end - 3];
                char eraser4 = S[end - 2];
                char eraser5 = S[end - 1];
                char eraser6 = S[end];
                if (eraser1 == 'e'
                    && eraser2 == 'r'
                    && eraser3 == 'a'
                    && eraser4 == 's'
                    && eraser5 == 'e'
                    && eraser6 == 'r') {
                    end -= 6;
                    continue;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    if (match) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
